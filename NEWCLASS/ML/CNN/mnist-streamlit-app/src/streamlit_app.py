import streamlit as st
import numpy as np
from PIL import Image
import tensorflow as tf
from mnist_model import load_model, predict

# Load the pre-trained model
model = load_model()
if model is None:
    st.error("Model file not found. Please train and save the model first (mnist_model.h5).")
    st.stop()

# Set up the Streamlit app
st.title("MNIST Digit Classification")
st.write("Upload an image of a handwritten digit (0-9) to classify.")

# File uploader for image input
uploaded_file = st.file_uploader("Choose an image...", type=["png", "jpg", "jpeg"])

if uploaded_file is not None:
    # Load and preprocess the image
    image = Image.open(uploaded_file).convert("L")  # Convert to grayscale
    image = image.resize((28, 28))  # Resize to 28x28
    image_array = np.array(image) / 255.0  # Normalize the image
    image_array = image_array.reshape(1, 28, 28, 1)  # Reshape for the model

    # Display the uploaded image
    st.image(image, caption='Uploaded Image', use_column_width=True)

    # Make a prediction
    prediction = predict(model, image_array)
    st.write(f"Predicted Digit: {prediction[0]}")  # Display the predicted digit

# Add a footer
st.write("Made with ❤️ using Streamlit and TensorFlow")