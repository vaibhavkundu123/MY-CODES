# src/train.py

import argparse
import os
import tensorflow as tf
import matplotlib.pyplot as plt

from src.data_loader import load_and_prepare_dataset
from src.models.cnn import build_cnn_model
from src.models.vit import build_vit_model
from src.utils import set_seed
import src.config as config

def run_training(model_type):
    """Main function to run the training pipeline."""
    set_seed()
    os.makedirs("outputs/models", exist_ok=True)
    os.makedirs("outputs/figures", exist_ok=True)

    if model_type == 'cnn':
        print("--- Training CNN Model ---")
        image_size = config.CNN_IMAGE_SIZE
        model_path = config.CNN_MODEL_PATH
        lr = config.CNN_LEARNING_RATE
        
        model = build_cnn_model(image_size=image_size, num_classes=config.NUM_CLASSES)
        train_ds, val_ds, _ = load_and_prepare_dataset(
            'cnn', image_size, config.BATCH_SIZE, config.VAL_SPLIT
        )
        optimizer = tf.keras.optimizers.Adam(learning_rate=lr)

        model.compile(
            optimizer=optimizer,
            loss=tf.keras.losses.SparseCategoricalCrossentropy(),
            metrics=[
                tf.keras.metrics.SparseCategoricalAccuracy(name="accuracy"),
                tf.keras.metrics.SparseTopKCategoricalAccuracy(k=5, name="top-5-accuracy"),
            ],
        )
        monitor_metric = "val_accuracy"

    elif model_type == 'vit':
        print("--- Training ViT Model ---")
        image_size = config.VIT_IMAGE_SIZE
        model_path = config.VIT_MODEL_PATH
        lr = config.VIT_LEARNING_RATE
        
        model = build_vit_model(
            image_size=image_size,
            patch_size=config.VIT_PATCH_SIZE,
            num_classes=config.NUM_CLASSES,
            projection_dim=config.VIT_PROJECTION_DIM,
            num_heads=config.VIT_NUM_HEADS,
            transformer_layers=config.VIT_TRANSFORMER_LAYERS,
        )
        train_ds, val_ds, _ = load_and_prepare_dataset(
            'vit', image_size, config.BATCH_SIZE, config.VAL_SPLIT
        )
        # CHANGE HERE: Use the built-in AdamW optimizer
        optimizer = tf.keras.optimizers.AdamW(
            learning_rate=lr, weight_decay=config.VIT_WEIGHT_DECAY
        )

        final_attention_layer_name = f"multi_head_attention_{config.VIT_TRANSFORMER_LAYERS - 1}"
        model.compile(
            optimizer=optimizer,
            loss={
                "logits": tf.keras.losses.SparseCategoricalCrossentropy(),
                final_attention_layer_name: None,
            },
            metrics={
                "logits": [
                    tf.keras.metrics.SparseCategoricalAccuracy(name="accuracy"),
                    tf.keras.metrics.SparseTopKCategoricalAccuracy(k=5, name="top-5-accuracy"),
                ]
            },
        )
        monitor_metric = "val_logits_accuracy"
    else:
        raise ValueError("Invalid model type specified.")

    model.summary()
    
    checkpoint_callback = tf.keras.callbacks.ModelCheckpoint(
        model_path,
        monitor=monitor_metric,
        save_best_only=True,
        save_weights_only=False,
    )
    early_stopping_callback = tf.keras.callbacks.EarlyStopping(
        monitor=monitor_metric,
        patience=10,
        restore_best_weights=True,
    )

    history = model.fit(
        train_ds,
        epochs=config.EPOCHS,
        validation_data=val_ds,
        callbacks=[checkpoint_callback, early_stopping_callback],
    )
    
    acc_key = 'accuracy' if model_type == 'cnn' else 'logits_accuracy'
    val_acc_key = 'val_accuracy' if model_type == 'cnn' else 'val_logits_accuracy'
    loss_key = 'loss' if model_type == 'cnn' else 'logits_loss'
    val_loss_key = 'val_loss' if model_type == 'cnn' else 'val_logits_loss'

    plt.figure(figsize=(12, 5))
    plt.subplot(1, 2, 1)
    plt.plot(history.history[acc_key], label='Train Accuracy')
    plt.plot(history.history[val_acc_key], label='Val Accuracy')
    plt.title(f'{model_type.upper()} Accuracy')
    plt.legend()
    
    plt.subplot(1, 2, 2)
    plt.plot(history.history[loss_key], label='Train Loss')
    plt.plot(history.history[val_loss_key], label='Val Loss')
    plt.title(f'{model_type.upper()} Loss')
    plt.legend()
    
    plt.savefig(f"outputs/figures/{model_type}_training_curves.png")
    print(f"Training curves saved to outputs/figures/{model_type}_training_curves.png")

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Train a CNN or ViT model.")
    parser.add_argument("--model", type=str, required=True, choices=['cnn', 'vit'],
                        help="The type of model to train ('cnn' or 'vit').")
    args = parser.parse_args()
    run_training(args.model)