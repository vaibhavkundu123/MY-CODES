import tensorflow as tf
import matplotlib.pyplot as plt

# --- Augmentation Policies ---

def get_cnn_augmentations(image_size):
    return tf.keras.Sequential([
        tf.keras.layers.RandomFlip("horizontal"),
        tf.keras.layers.RandomRotation(0.1),
        tf.keras.layers.RandomZoom(0.1),
    ], name="cnn_augmentations")

def get_vit_augmentations(image_size):
    # ViTs benefit from stronger regularization and augmentation
    # like RandAugment or MixUp/CutMix. For simplicity, we'll use
    # a slightly stronger version of standard augmentations.
    # On a real project, consider tfa.image.randaugment.
    return tf.keras.Sequential([
        tf.keras.layers.RandomFlip("horizontal"),
        tf.keras.layers.RandomRotation(0.2),
        tf.keras.layers.RandomZoom(0.2),
        tf.keras.layers.RandomContrast(0.2),
    ], name="vit_augmentations")


def get_preprocessing_layer(model_type, image_size):
    """Returns a sequential model for resizing and normalization."""
    # Normalization is done within the model to make deployment easier.
    return tf.keras.Sequential([
        tf.keras.layers.Resizing(image_size, image_size),
        tf.keras.layers.Rescaling(1./255)
    ], name=f"{model_type}_preprocessing")


def load_and_prepare_dataset(model_type, image_size, batch_size, val_split=0.1):
    """Loads CIFAR-10, creates train/val splits, and prepares tf.data pipelines."""
    (x_train, y_train), (x_test, y_test) = tf.keras.datasets.cifar10.load_data()

    # Create validation split
    val_size = int(len(x_train) * val_split)
    x_val = x_train[-val_size:]
    y_val = y_train[-val_size:]
    x_train = x_train[:-val_size]
    y_train = y_train[:-val_size]
    
    print(f"Training samples: {len(x_train)}, Validation samples: {len(x_val)}, Test samples: {len(x_test)}")

    # Create tf.data.Dataset objects
    train_ds = tf.data.Dataset.from_tensor_slices((x_train, y_train))
    val_ds = tf.data.Dataset.from_tensor_slices((x_val, y_val))
    test_ds = tf.data.Dataset.from_tensor_slices((x_test, y_test))

    # Get the correct augmentation pipeline
    if model_type == 'cnn':
        augmentations = get_cnn_augmentations(image_size)
    elif model_type == 'vit':
        augmentations = get_vit_augmentations(image_size)
    else:
        raise ValueError("model_type must be 'cnn' or 'vit'")

    def apply_augmentations(image, label):
        return augmentations(image, training=True), label

    # Create efficient data pipelines
    AUTOTUNE = tf.data.AUTOTUNE
    train_ds = (
        train_ds
        .shuffle(batch_size * 10)
        .batch(batch_size)
        .map(apply_augmentations, num_parallel_calls=AUTOTUNE)
        .prefetch(AUTOTUNE)
    )
    val_ds = (
        val_ds
        .batch(batch_size)
        .prefetch(AUTOTUNE)
    )
    test_ds = (
        test_ds
        .batch(batch_size)
        .prefetch(AUTOTUNE)
    )
    return train_ds, val_ds, test_ds

# --- Dry-run Example (for a notebook) ---
def visualize_augmentations():
    (x_train, _), _ = tf.keras.datasets.cifar10.load_data()
    sample_images = x_train[:9]
    
    cnn_aug = get_cnn_augmentations(32)
    vit_aug = get_vit_augmentations(72) # ViT uses a larger image size
    
    plt.figure(figsize=(10, 10))
    plt.suptitle("Original Images", fontsize=16)
    for i in range(9):
        plt.subplot(3, 3, i + 1)
        plt.imshow(sample_images[i])
        plt.axis("off")
    plt.show()

    plt.figure(figsize=(10, 10))
    plt.suptitle("CNN Augmentations (32x32)", fontsize=16)
    for i in range(9):
        augmented_image = cnn_aug(tf.expand_dims(sample_images[i], 0), training=True)
        plt.subplot(3, 3, i + 1)
        plt.imshow(tf.squeeze(augmented_image) / 255.0)
        plt.axis("off")
    plt.show()
    
    plt.figure(figsize=(10, 10))
    plt.suptitle("ViT Augmentations (Resized to 72x72)", fontsize=16)
    resizer = tf.keras.layers.Resizing(72, 72)
    for i in range(9):
        resized_image = resizer(tf.expand_dims(sample_images[i], 0))
        augmented_image = vit_aug(resized_image, training=True)
        plt.subplot(3, 3, i + 1)
        plt.imshow(tf.squeeze(augmented_image) / 255.0)
        plt.axis("off")
    plt.show()

# If running this file directly, execute the visualization
if __name__ == '__main__':
    visualize_augmentations()