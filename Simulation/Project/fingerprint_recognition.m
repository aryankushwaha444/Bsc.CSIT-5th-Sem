% Full script for fingerprint recognition

% Step 1: Load the fingerprint image
fingerprintImage = imread('fig.jpg');
figure;
imshow(fingerprintImage);
title('Original Fingerprint Image');

% Step 2: Preprocess the image
grayImage = rgb2gray(fingerprintImage);
adjustedImage = imadjust(grayImage);
filteredImage = medfilt2(adjustedImage, [3 3]);

% Step 3: Binarize the image
binaryImage = imbinarize(filteredImage);

% Step 4: Thin the image
thinImage = bwmorph(binaryImage, 'thin', Inf);

% Step 5: Extract minutiae points
minutiae = extractMinutiae(thinImage);

% Display minutiae points
figure;
imshow(thinImage);
hold on;
[y, x] = find(minutiae.endings);
plot(x, y, 'ro'); % Endings in red
[y, x] = find(minutiae.bifurcations);
plot(x, y, 'go'); % Bifurcations in green
hold off;
title('Minutiae Points');

% Step 6: Load another fingerprint image for matching
fingerprintImage2 = imread('fig2.jpg');
grayImage2 = rgb2gray(fingerprintImage2);
adjustedImage2 = imadjust(grayImage2);
filteredImage2 = medfilt2(adjustedImage2, [3 3]);
binaryImage2 = imbinarize(filteredImage2);
thinImage2 = bwmorph(binaryImage2, 'thin', Inf);
minutiae2 = extractMinutiae(thinImage2);

% Perform matching
tolerance = 15; % Set a tolerance value for matching
isMatch = matchFingerprints(minutiae, minutiae2, tolerance);

if isMatch
    disp('Fingerprints match!');
else
    disp('Fingerprints do not match.');
end

% Function to extract minutiae points
function [minutiae] = extractMinutiae(thinImage)
    minutiae.endings = bwmorph(thinImage, 'endpoints');
    minutiae.bifurcations = bwmorph(thinImage, 'branchpoints');
end

% Function to match fingerprints
function isMatch = matchFingerprints(minutiae1, minutiae2, tolerance)
    [y1, x1] = find(minutiae1.endings);
    [y2, x2] = find(minutiae2.endings);
    distances = pdist2([x1 y1], [x2 y2]);
    matchCount = sum(distances(:) < tolerance);
    isMatch = matchCount > size(x1, 1) / 2;
end
