import tensorflow as tf
from src.data_loader import get_preprocessing_layer

def build_cnn_model(image_size=32, num_classes=10):
    """
    Builds a fine-tunable CNN model using a pre-trained ResNet50V2 backbone.
    """
    # --- Input and Preprocessing ---
    inputs = tf.keras.Input(shape=(32, 32, 3))
    preprocessing_layer = get_preprocessing_layer('cnn', image_size)
    x = preprocessing_layer(inputs)

    # --- Base Model (ResNet50V2) ---
    base_model = tf.keras.applications.ResNet50V2(
        include_top=False,
        weights='imagenet',
        input_shape=(image_size, image_size, 3)
    )
    # Freeze the base model to use its learned features
    base_model.trainable = False 
    
    # --- Connect Base to Input ---
    x = base_model(x, training=False) # In inference mode for the frozen layers

    # --- Classification Head ---
    x = tf.keras.layers.GlobalAveragePooling2D(name="avg_pool")(x)
    x = tf.keras.layers.Dropout(0.3, name="dropout")(x)
    outputs = tf.keras.layers.Dense(num_classes, activation="softmax", name="predictions")(x)

    # --- Create the Keras Model ---
    model = tf.keras.Model(inputs, outputs)
    
    return model

# --- Code Explanation ---
# 1. `get_preprocessing_layer`: Fetches the resizing and rescaling layers.
#    This makes the model self-contained. Input is raw pixels (0-255).
# 2. `tf.keras.applications.ResNet50V2`: Loads the powerful ResNet architecture
#    with weights trained on the massive ImageNet dataset.
# 3. `base_model.trainable = False`: This is the core of transfer learning. We
#    freeze the weights of the convolutional base. We only train the new
#    classification head.
# 4. `GlobalAveragePooling2D`: A standard way to convert the 4D feature map
#    from the CNN into a 2D vector for the final dense layer. It's more
#    efficient and less prone to overfitting than a `Flatten` layer.
# 5. `Dropout`: A regularization technique to prevent overfitting.
# 6. `tf.keras.Model`: Assembles the full computational graph.