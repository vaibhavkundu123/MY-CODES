# src/models/vit.py

import tensorflow as tf
from tensorflow.keras import layers
from src.data_loader import get_preprocessing_layer

class Patches(layers.Layer):
    """Splits an image into patches and flattens them."""
    def __init__(self, patch_size, **kwargs):
        super().__init__(**kwargs)
        self.patch_size = patch_size

    def call(self, images):
        batch_size = tf.shape(images)[0]
        patches = tf.image.extract_patches(
            images=images,
            sizes=[1, self.patch_size, self.patch_size, 1],
            strides=[1, self.patch_size, self.patch_size, 1],
            rates=[1, 1, 1, 1],
            padding="VALID",
        )
        patch_dims = patches.shape[-1]
        patches = tf.reshape(patches, [batch_size, -1, patch_dims])
        return patches

class PatchEncoder(layers.Layer):
    """Projects patches to a latent dim and adds positional embeddings."""
    def __init__(self, num_patches, projection_dim, **kwargs):
        super().__init__(**kwargs)
        self.num_patches = num_patches
        self.projection = layers.Dense(units=projection_dim)
        self.position_embedding = layers.Embedding(
            input_dim=num_patches, output_dim=projection_dim
        )

    def call(self, patch):
        positions = tf.range(start=0, limit=self.num_patches, delta=1)
        encoded = self.projection(patch) + self.position_embedding(positions)
        return encoded

def build_vit_model(
    image_size=72,
    patch_size=6,
    num_classes=10,
    projection_dim=128,
    num_heads=8,
    transformer_layers=6,
    mlp_head_units=[256, 128],
):
    """
    Builds a Vision Transformer model that also outputs attention scores.
    """
    num_patches = (image_size // patch_size) ** 2
    transformer_units = [projection_dim * 2, projection_dim]
    
    inputs = layers.Input(shape=(32, 32, 3))
    preprocessing_layer = get_preprocessing_layer('vit', image_size)
    x = preprocessing_layer(inputs)
    patches = Patches(patch_size)(x)
    encoded_patches = PatchEncoder(num_patches, projection_dim)(patches)

    attention_scores = None 
    for i in range(transformer_layers):
        x1 = layers.LayerNormalization(epsilon=1e-6)(encoded_patches)
        
        return_attention = (i == transformer_layers - 1)
        
        attention_output, scores = layers.MultiHeadAttention(
            num_heads=num_heads, key_dim=projection_dim, dropout=0.1,
            name=f"multi_head_attention_{i}"
        )(x1, x1, return_attention_scores=return_attention)
        
        if return_attention:
            attention_scores = scores

        x2 = layers.Add()([attention_output, encoded_patches])
        x3 = layers.LayerNormalization(epsilon=1e-6)(x2)
        x3 = layers.Dense(transformer_units[0], activation=tf.nn.gelu)(x3)
        x3 = layers.Dropout(0.1)(x3)
        x3 = layers.Dense(transformer_units[1], activation=tf.nn.gelu)(x3)
        x3 = layers.Dropout(0.1)(x3)
        encoded_patches = layers.Add()([x3, x2])

    representation = layers.LayerNormalization(epsilon=1e-6)(encoded_patches)
    representation = layers.GlobalAveragePooling1D()(representation)
    representation = layers.Dropout(0.5)(representation)
    
    features = representation
    for units in mlp_head_units:
        features = layers.Dense(units, activation=tf.nn.gelu)(features)
        features = layers.Dropout(0.5)(features)
    
    logits = layers.Dense(num_classes, activation="softmax", name="logits")(features)

    model = tf.keras.Model(inputs=inputs, outputs=[logits, attention_scores])
    return model