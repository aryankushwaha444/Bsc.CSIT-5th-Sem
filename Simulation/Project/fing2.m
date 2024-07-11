% Full script for fingerprint recognition

% Step 1: Load the fingerprint image
fingerprintImage = imread('fingerprint.jpg');
figure;
imshow(fingerprintImage);
title('Original Fingerprint Image');

% Step 2: Preprocess the image
grayImage = rgb2gray(fingerprintImage);
adjustedImage = imadjust(grayImage);
filteredImage = medfilt2(adjustedImage, [3 3]);

% Display preprocessed image
figure;
imshow(filteredImage);
title('Preprocessed Fingerprint Image');

% Step 3: Binarize the image
binaryImage = imbinarize(filteredImage);

% Display binary image
figure;
imshow(binaryImage);
title('Binarized Fingerprint Image');

% Step 4: Thin the image
thinImage = bwmorph(binaryImage, 'thin', Inf);

% Display thinned image
figure;
imshow(thinImage);
title('Thinned Fingerprint Image');

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
fingerprintImage2 = imread('fingerprint22.jpg');
grayImage2 = rgb2gray(fingerprintImage2);
adjustedImage2 = imadjust(grayImage2);
filteredImage2 = medfilt2(adjustedImage2, [3 3]);
binaryImage2 = imbinarize(filteredImage2);
thinImage2 = bwmorph(binaryImage2, 'thin', Inf);
minutiae2 = extractMinutiae(thinImage2);

% Display second fingerprint image and its minutiae points
figure;
imshow(thinImage2);
hold on;
[y2, x2] = find(minutiae2.endings);
plot(x2, y2, 'ro'); % Endings in red
[y2, x2] = find(minutiae2.bifurcations);
plot(x2, y2, 'go'); % Bifurcations in green
hold off;
title('Minutiae Points for Second Fingerprint');

% Perform matching with visualization
tolerance = 15; % Set a tolerance value for matching
angleStep = 5;  % Set the step for rotation in degrees
isMatch = matchFingerprints(minutiae, minutiae2, tolerance, angleStep);

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

% Function to match fingerprints with visualization
function isMatch = matchFingerprints(minutiae1, minutiae2, tolerance, angleStep)
    [y1, x1] = find(minutiae1.endings);
    [y2, x2] = find(minutiae2.endings);

    x1 = x1 - mean(x1);
    y1 = y1 - mean(y1);
    x2 = x2 - mean(x2);
    y2 = y2 - mean(y2);

    isMatch = false;
    figure;

    for angle = 0:angleStep:360
        theta = deg2rad(angle);
        rotationMatrix = [cos(theta) -sin(theta); sin(theta) cos(theta)];
        rotatedMinutiae2 = rotationMatrix * [x2'; y2'];

        distances = pdist2([x1 y1], rotatedMinutiae2');
        matchCount = sum(min(distances, [], 2) < tolerance);

        % Visualize the matching process
        subplot(1, 2, 1);
        imshow(minutiae1.endings + minutiae1.bifurcations);
        hold on;
        plot(x1 + mean(x1), y1 + mean(y1), 'ro');
        hold off;
        title('Fingerprint 1 Minutiae Points');

        subplot(1, 2, 2);
        imshow(minutiae2.endings + minutiae2.bifurcations);
        hold on;
        plot(rotatedMinutiae2(1,:) + mean(x2), rotatedMinutiae2(2,:) + mean(y2), 'go');
        hold off;
        title(['Fingerprint 2 Minutiae Points (Rotated ', num2str(angle), '°)']);

        drawnow;

        if matchCount > length(x1) / 2
            isMatch = true;
            break;
        end
    end
end
