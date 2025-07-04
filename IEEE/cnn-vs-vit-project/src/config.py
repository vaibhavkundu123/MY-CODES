# src/config.py
# Shared settings
NUM_CLASSES = 10
VAL_SPLIT = 0.1
EPOCHS = 50
BATCH_SIZE = 128

# CNN settings
CNN_MODEL_PATH = "outputs/models/cnn_model.h5"
CNN_IMAGE_SIZE = 32
CNN_LEARNING_RATE = 1e-3

# ViT settings
VIT_MODEL_PATH = "outputs/models/vit_model.h5"
VIT_IMAGE_SIZE = 72 # ViTs perform better with larger images
VIT_PATCH_SIZE = 6
VIT_PROJECTION_DIM = 128
VIT_NUM_HEADS = 8
VIT_TRANSFORMER_LAYERS = 6
VIT_LEARNING_RATE = 1e-3
VIT_WEIGHT_DECAY = 1e-4