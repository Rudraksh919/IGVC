import cv2
import numpy as np


image_path = 'TESTT.jpg' 

def extract_lane_markings(image_path):
    # Load image
    image = cv2.imread(image_path)
    hsv = cv2.cvtColor(image, cv2.COLOR_BGR2HSV)
    
    # Define color thresholds
    white_lower = np.array([0, 0, 200], dtype=np.uint8)
    white_upper = np.array([255, 50, 255], dtype=np.uint8)
    yellow_lower = np.array([15, 100, 100], dtype=np.uint8)
    yellow_upper = np.array([35, 255, 255], dtype=np.uint8)
    
    # Create masks
    white_mask = cv2.inRange(hsv, white_lower, white_upper)
    yellow_mask = cv2.inRange(hsv, yellow_lower, yellow_upper)
    
    # Highlight detected lane markings on the original image
    highlighted = image.copy()
    highlighted[white_mask > 0] = [255, 255, 255]  # White
    highlighted[yellow_mask > 0] = [0, 255, 255]  # Yellow
    
    return white_mask, yellow_mask, highlighted


white_mask, yellow_mask, highlighted = extract_lane_markings(image_path)

cv2.imwrite('white_lane.png', white_mask)
cv2.imwrite('yellow_lane.png', yellow_mask)
cv2.imwrite('highlighted.png', highlighted)