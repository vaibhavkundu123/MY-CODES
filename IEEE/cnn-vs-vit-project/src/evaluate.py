# src/evaluate.py

import argparse
import tensorflow as tf
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns
from sklearn.metrics import classification_report, confusion_matrix

from src.data_loader import load_and_prepare_dataset
from src.utils import make_gradcam_heatmap, superimpose_gradcam
import src.config as config
from src.models.vit import Patches, PatchEncoder

def run_evaluation(model_type):
    """Loads a trained model and evaluates it on the test set."""
    if model_type == 'cnn':
        print("--- Evaluating CNN Model ---")
        model_path = config.CNN_MODEL_PATH
        image_size = config.CNN_IMAGE_SIZE
        custom_objects = {}
    elif model_type == 'vit':
        print("--- Evaluating ViT Model ---")
        model_path = config.VIT_MODEL_PATH
        image_size = config.VIT_IMAGE_SIZE
        # CHANGE HERE: AdamW is no longer a custom object.
        custom_objects = {"Patches": Patches, "PatchEncoder": PatchEncoder}
    else:
        raise ValueError("Invalid model type.")

    model = tf.keras.models.load_model(model_path, custom_objects=custom_objects)
    
    _, _, test_ds = load_and_prepare_dataset(model_type, image_size, config.BATCH_SIZE, val_split=0)
    
    print("Evaluating on test set...")
    results = model.evaluate(test_ds, return_dict=True)
    print("Evaluation results:", results)

    if model_type == 'cnn':
        loss = results['loss']
        accuracy = results['accuracy']
        top5_accuracy = results['top-5-accuracy']
    else:
        loss = results['logits_loss']
        accuracy = results['logits_accuracy']
        top5_accuracy = results['logits_top-5-accuracy']

    print(f"Test Loss: {loss:.4f}")
    print(f"Test Accuracy: {accuracy:.4f}")
    print(f"Test Top-5 Accuracy: {top5_accuracy:.4f}")

    print("Generating classification report and confusion matrix...")
    _, (x_test, y_test_raw) = tf.keras.datasets.cifar10.load_data()
    
    if model_type == 'cnn':
        predictions = model.predict(x_test, batch_size=config.BATCH_SIZE)
    else:
        predictions, _ = model.predict(x_test, batch_size=config.BATCH_SIZE)

    y_pred = np.argmax(predictions, axis=1)
    y_true = y_test_raw.flatten()
    
    class_names = ['airplane', 'automobile', 'bird', 'cat', 'deer', 'dog', 'frog', 'horse', 'ship', 'truck']
    
    report = classification_report(y_true, y_pred, target_names=class_names)
    print("\nClassification Report:")
    print(report)

    cm = confusion_matrix(y_true, y_pred)
    plt.figure(figsize=(12, 10))
    sns.heatmap(cm, annot=True, fmt='d', cmap='Blues', xticklabels=class_names, yticklabels=class_names)
    plt.xlabel("Predicted")
    plt.ylabel("True")
    plt.title(f"Confusion Matrix for {model_type.upper()}")
    plt.savefig(f"outputs/figures/{model_type}_confusion_matrix.png")
    plt.close()
    print(f"Confusion matrix saved to outputs/figures/{model_type}_confusion_matrix.png")

    if model_type == 'cnn':
        print("Generating Grad-CAM visualizations...")
        last_conv_layer_name = "conv5_block3_out" 
        sample_images = x_test[:4]
        
        plt.figure(figsize=(10, 5))
        for i, img in enumerate(sample_images):
            img_array = np.expand_dims(img, axis=0)
            heatmap = make_gradcam_heatmap(img_array, model, last_conv_layer_name)
            superimposed_img = superimpose_gradcam(img, heatmap)
            
            plt.subplot(2, 4, i + 1)
            plt.imshow(img)
            plt.title("Original")
            plt.axis("off")
            
            plt.subplot(2, 4, i + 5)
            plt.imshow(superimposed_img)
            plt.title("Grad-CAM")
            plt.axis("off")
            
        plt.tight_layout()
        plt.savefig(f"outputs/figures/{model_type}_gradcam_examples.png")
        plt.close()
        print(f"Grad-CAM visualizations saved to outputs/figures/{model_type}_gradcam_examples.png")

    elif model_type == 'vit':
        print("Generating ViT attention map visualizations...")
        sample_images = x_test[:4]
        
        _, attention_scores = model.predict(sample_images)

        num_patches = (config.VIT_IMAGE_SIZE // config.VIT_PATCH_SIZE) ** 2
        grid_size = int(np.sqrt(num_patches))

        plt.figure(figsize=(10, 10))
        plt.suptitle("ViT Attention Maps (from center patch)", fontsize=16)
        for i, img in enumerate(sample_images):
            attention_map = np.mean(attention_scores[i], axis=0)
            center_patch_index = (grid_size * grid_size) // 2
            patch_attention = attention_map[center_patch_index, :].reshape((grid_size, grid_size))
            
            resized_img = tf.image.resize(img, (config.VIT_IMAGE_SIZE, config.VIT_IMAGE_SIZE)).numpy()
            
            plt.subplot(4, 3, i*3 + 1)
            plt.imshow(resized_img.astype('uint8'))
            plt.title("Original Resized")
            plt.axis('off')
            
            plt.subplot(4, 3, i*3 + 2)
            plt.imshow(patch_attention, cmap='inferno')
            plt.title("Attention Heatmap")
            plt.axis('off')

            plt.subplot(4, 3, i*3 + 3)
            plt.imshow(resized_img.astype('uint8'))
            plt.imshow(patch_attention, cmap='inferno', alpha=0.6)
            plt.title("Overlay")
            plt.axis('off')

        plt.tight_layout(rect=[0, 0.03, 1, 0.95])
        plt.savefig(f"outputs/figures/{model_type}_attention_maps.png")
        plt.close()
        print(f"Attention map visualizations saved to outputs/figures/{model_type}_attention_maps.png")

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Evaluate a trained model.")
    parser.add_argument("--model", type=str, required=True, choices=['cnn', 'vit'],
                        help="The type of model to evaluate ('cnn' or 'vit').")
    args = parser.parse_args()
    run_evaluation(args.model)