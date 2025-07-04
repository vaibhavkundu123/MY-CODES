def load_and_preprocess_image(image):
    """Load and preprocess a single image for the model."""
    image = tf.image.resize(image, [28, 28])  # Resize to 28x28
    image = tf.cast(image, tf.float32) / 255.0  # Normalize to [0, 1]
    image = tf.expand_dims(image, axis=0)  # Add batch dimension
    return image

def load_images_from_directory(directory):
    """Load images from a specified directory."""
    image_dataset = tf.keras.utils.image_dataset_from_directory(
        directory,
        labels=None,
        color_mode='grayscale',
        image_size=(28, 28),
        batch_size=1  # Load one image at a time
    )
    return image_dataset

def display_predictions(predictions, class_names):
    """Display the predictions in a user-friendly format."""
    predicted_classes = np.argmax(predictions, axis=1)
    return [class_names[i] for i in predicted_classes]