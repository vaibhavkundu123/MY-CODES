# MNIST Streamlit App

This project is a Streamlit application that allows users to upload images of handwritten digits and get predictions from a Convolutional Neural Network (CNN) model trained on the MNIST dataset.

## Project Structure

```
mnist-streamlit-app
├── src
│   ├── mnist_model.py      # Contains the CNN model definition and training functions
│   ├── streamlit_app.py     # Main entry point for the Streamlit application
│   └── utils.py            # Utility functions for image preprocessing and dataset loading
├── requirements.txt        # Lists the dependencies required to run the project
└── README.md               # Documentation for the project
```

## Setup Instructions

1. **Clone the repository:**
   ```bash
   git clone <repository-url>
   cd mnist-streamlit-app
   ```

2. **Create a virtual environment (optional but recommended):**
   ```bash
   python -m venv venv
   source venv/bin/activate  # On Windows use `venv\Scripts\activate`
   ```

3. **Install the required dependencies:**
   ```bash
   pip install -r requirements.txt
   ```

## Usage

1. **Run the Streamlit application:**
   ```bash
   streamlit run src/streamlit_app.py
   ```

2. **Upload an image of a handwritten digit:**
   - The application will display the predicted digit based on the uploaded image.

## Dependencies

- Streamlit
- TensorFlow
- NumPy
- Matplotlib

## Contributing

Feel free to submit issues or pull requests if you have suggestions or improvements for the project.

## License

This project is licensed under the MIT License. See the LICENSE file for details.