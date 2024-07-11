from PIL import Image

def convert_to_grayscale(image_path, output_path):
    """Converts an image to grayscale and saves it.

    Args:
        image_path (str): Path to the input image.
        output_path (str): Path to save the grayscale image.
    """

    img = Image.open(image_path)

    # Check for and convert RGBA mode before saving
    if img.mode == 'RGBA':
        img = img.convert('RGB')

    img.convert('L').save(output_path)  # Convert to grayscale and save

def crop_image(image_path, crop_box, output_path):
    """Crops an image based on the provided bounding box and saves it.

    Args:
        image_path (str): Path to the input image.
        crop_box (tuple): A 4-tuple representing the top-left,
                          bottom-right coordinates of the crop area (left, upper, right, lower).
        output_path (str): Path to save the cropped image.
    """

    img = Image.open(image_path)
    cropped_img = img.crop(crop_box)

    # Check for and convert RGBA mode before saving
    if cropped_img.mode == 'RGBA':
        cropped_img = cropped_img.convert('RGB')

    cropped_img.save(output_path)

# Example usage (grayscale conversion)
#image_path = "image.jpg"
#output_path = "grayscale_image_test.jpg"
#convert_to_grayscale(image_path, output_path)

# Example usage (cropping)
image_path = "image.png"
crop_box = (300, 300, 900, 1500)
output_path = "cropped_image-A.jpg"
crop_image(image_path, crop_box, output_path)

print("Image processing completed!")

