import cv2
import matplotlib.pyplot as plt
from skimage.morphology import skeletonize
from skimage.feature import corner_harris, corner_peaks
import numpy as np
from scipy.spatial.distance import cdist

# Load and preprocess the fingerprint image
def preprocess_image(image_path):
    fingerprint_image = cv2.imread(image_path, cv2.IMREAD_GRAYSCALE)
    adjusted_image = cv2.equalizeHist(fingerprint_image)
    filtered_image = cv2.medianBlur(adjusted_image, 3)
    _, binary_image = cv2.threshold(filtered_image, 0, 255, cv2.THRESH_BINARY + cv2.THRESH_OTSU)
    binary_image_inverted = np.invert(binary_image)
    thin_image = skeletonize(binary_image_inverted // 255)
    return thin_image

# Extract minutiae points from the thinned image
def extract_minutiae(thin_image):
    corners = corner_peaks(corner_harris(thin_image), min_distance=5)
    return corners

# Match two sets of minutiae points
def match_fingerprints(minutiae1, minutiae2, tolerance):
    distances = cdist(minutiae1, minutiae2)
    match_count = np.sum(distances.min(axis=1) < tolerance)
    is_match = match_count > len(minutiae1) / 2
    return is_match

# Main function
def main():
    thin_image1 = preprocess_image('fingerprint.jpg')
    minutiae_points1 = extract_minutiae(thin_image1)
    
    thin_image2 = preprocess_image('fingerprint2.jpg')
    minutiae_points2 = extract_minutiae(thin_image2)
    
    # Perform matching
    tolerance = 15  # Set a tolerance value for matching
    is_match = match_fingerprints(minutiae_points1, minutiae_points2, tolerance)
    
    if is_match:
        print('Fingerprints match!')
    else:
        print('Fingerprints do not match.')

    # Display the thinned image and minutiae points for both fingerprints
    plt.subplot(1, 2, 1)
    plt.imshow(thin_image1, cmap='gray')
    plt.scatter(minutiae_points1[:, 1], minutiae_points1[:, 0], c='red', s=5)
    plt.title('Fingerprint 1 Minutiae Points')
    
    plt.subplot(1, 2, 2)
    plt.imshow(thin_image2, cmap='gray')
    plt.scatter(minutiae_points2[:, 1], minutiae_points2[:, 0], c='red', s=5)
    plt.title('Fingerprint 2 Minutiae Points')
    
    plt.show()

if __name__ == "__main__":
    main()
