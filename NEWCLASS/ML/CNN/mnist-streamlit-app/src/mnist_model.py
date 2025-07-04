import tensorflow as tf
import os

IMG_HEIGHT = 28
IMG_WIDTH = 28

def create_model():
    model = tf.keras.Sequential([
        tf.keras.layers.Input(shape=(IMG_HEIGHT, IMG_WIDTH, 1)),
        tf.keras.layers.Conv2D(32, (3, 3), activation='relu'),
        tf.keras.layers.MaxPooling2D((2, 2)),
        tf.keras.layers.Conv2D(64, (3, 3), activation='relu'),
        tf.keras.layers.MaxPooling2D((2, 2)),
        tf.keras.layers.Flatten(),
        tf.keras.layers.Dense(64, activation='relu'),
        tf.keras.layers.Dense(10, activation='softmax')
    ])
    model.compile(
        optimizer='adam',
        loss=tf.keras.losses.SparseCategoricalCrossentropy(),
        metrics=['accuracy']
    )
    return model

def load_model(model_path='src/mnist_model.h5'):
    import os
    if os.path.exists(model_path):
        model = tf.keras.models.load_model(model_path)
        print("Model loaded successfully.")
        return model
    else:
        print("Model file not found.")
        return None

def train_model(train_dataset, validation_dataset, epochs=5, model_path='mnist_model.h5'):
    model = create_model()
    history = model.fit(
        train_dataset,
        validation_data=validation_dataset,
        epochs=epochs
    )
    model.save(model_path)
    return model, history

def predict(model, images):
    # images: np.array or tf.Tensor of shape (batch, 28, 28) or (batch, 28, 28, 1)
    # Ensure images are float32 and normalized
    images = tf.convert_to_tensor(images, dtype=tf.float32)
    if images.shape.rank == 3:
        images = tf.expand_dims(images, -1)
    images = images / 255.0 if tf.reduce_max(images) > 1.0 else images
    predictions = model.predict(images)
    predicted_classes = tf.argmax(predictions, axis=1)
    return predicted_classes.numpy()