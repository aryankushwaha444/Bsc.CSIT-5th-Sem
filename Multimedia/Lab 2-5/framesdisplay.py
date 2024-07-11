import cv2

# Replace 'your_video.mp4' with the path to your video file
video_path = 'video1.mov'

# Create a video capture object
cap = cv2.VideoCapture(video_path)

# Check if video opened successfully
if not cap.isOpened():
    print("Error opening video stream or file")

# Define a frame counter
frame_count = 0

# Loop through frames
while True:
    # Capture frame-by-frame
    ret, frame = cap.read()

    # Check if the frame was read successfully
    if not ret:
        print("No more frames to read")
        break

    # Save the frame as an image (replace 'frame_%05d.jpg' with your desired naming convention)
    filename = f'frame_{frame_count:05d}.jpg'
    cv2.imwrite(filename, frame)

    # Increase frame counter
    frame_count += 1

# Release the capture and close all windows
cap.release()
cv2.destroyAllWindows()

print(f'Extracted {frame_count} frames')

