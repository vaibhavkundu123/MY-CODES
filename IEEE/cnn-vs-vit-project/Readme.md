# CNN vs. Vision Transformer Comparison on CIFAR-10

This project provides an end-to-end implementation and comparison of a CNN (ResNet50V2) and a Vision Transformer (ViT) for image classification on the CIFAR-10 dataset using TensorFlow.

## Project Structure

- `src/`: Contains all source code.
  - `train.py`: Main script to train models.
  - `evaluate.py`: Script to evaluate trained models.
  - `models/`: Model architecture definitions (`cnn.py`, `vit.py`).
  - `data_loader.py`: Data loading and augmentation pipelines.
  - `config.py`: Hyperparameter configuration.
- `outputs/`: Directory for saved models, logs, and figures.
- `notebooks/`: Jupyter notebooks for exploration and visualization.
- `requirements.txt`: Python dependencies.

## Setup

1.  Create and activate a Python virtual environment.
    ```bash
    python -m venv venv && source venv/bin/activate
    ```
2.  Install the required packages.
    ```bash
    pip install -r requirements.txt
    ```

## How to Run Experiments

1.  **Train the CNN Model:**
    ```bash
    python src/train.py --model cnn
    ```

2.  **Train the Vision Transformer Model:**
    ```bash
    python src/train.py --model vit
    ```

3.  **Evaluate the CNN Model:**
    ```bash
    python src/evaluate.py --model cnn
    ```

4.  **Evaluate the Vision Transformer Model:**
    ```bash
    python src/evaluate.py --model vit
    ```

Results, including training curves and confusion matrices, will be saved in the `outputs/figures` directory. The best model weights will be saved in `outputs/models`.

## Summary of Findings

On the CIFAR-10 dataset, the pre-trained CNN (ResNet50V2) significantly outperforms the from-scratch ViT in terms of accuracy, training speed, and inference efficiency. This highlights the importance of strong inductive biases (locality) for smaller datasets. The ViT struggles to generalize without large-scale pre-training. For detailed analysis, please see the full project report.