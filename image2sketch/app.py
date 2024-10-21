import streamlit as st
import cv2
import numpy as np
from PIL import Image
import io

def pencil_sketch(image):
    gray_image = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
    inverted_image = cv2.bitwise_not(gray_image)
    blurred_image = cv2.GaussianBlur(inverted_image, (21, 21), sigmaX=0, sigmaY=0)
    inverted_blurred = cv2.bitwise_not(blurred_image)
    sketch = cv2.divide(gray_image, inverted_blurred, scale=256.0)
    return sketch

def convert_to_bytes(image):
    img = Image.fromarray(image)
    buf = io.BytesIO()
    img.save(buf, format='PNG')
    return buf.getvalue()

st.title("Image to Pencil Sketch Converter")

uploaded_file = st.file_uploader("Choose an image...", type=["jpg", "jpeg", "png"])

if uploaded_file is not None:
    # Read the uploaded image
    image = Image.open(uploaded_file)
    image_cv = np.array(image)

    # Check if the uploaded image is already a sketch
    if np.mean(image_cv) < 128:  # Assuming a sketch will be predominantly lighter
        st.warning("This image appears to be a sketch. Please upload a regular image.")
    else:
        # Convert the image to pencil sketch
        sketch = pencil_sketch(image_cv)

        # Create two columns for side-by-side display
        col1, col2 = st.columns(2)

        with col1:
            st.image(image, caption='Original Image', use_column_width=True)
            original_bytes = convert_to_bytes(image_cv)
            st.download_button("Download Original Image", original_bytes, "original_image.png")

        with col2:
            st.image(sketch, caption='Pencil Sketch', use_column_width=True)
            sketch_bytes = convert_to_bytes(sketch)
            st.download_button("Download Pencil Sketch", sketch_bytes, "pencil_sketch.png")

        if st.button("Print Pencil Sketch"):
            st.markdown('<script>window.print();</script>', unsafe_allow_html=True)
