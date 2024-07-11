import cv2

def convert_to_grayscale(image_path, output_path):
  """Converts a JPEG image to grayscale and saves it.

  Args:
    image_path: Path to the input JPEG image.
    output_path: Path to save the grayscale image.
  """
  img = cv2.imread(image_path)
  grayscale_img = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)  # BGR to grayscale
  cv2.imwrite(output_path, grayscale_img)

# Example usage
image_path = "image.png"
output_path = "grayscale_image_cv-A.jpg"
convert_to_grayscale(image_path, output_path)
