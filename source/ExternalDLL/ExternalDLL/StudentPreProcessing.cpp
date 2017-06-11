#include "StudentPreProcessing.h"


IntensityImage * StudentPreProcessing::stepToIntensityImage(const RGBImage &image) const {
	return nullptr;
}

IntensityImage * StudentPreProcessing::stepScaleImage(const IntensityImage &image) const {
	//if ((200 * 200) > (image.getWidth() * image.getHeight())) {
	//	IntensityImage * result = ImageFactory::newIntensityImage(image);
	//	return result;
	//}
	IntensityImage * result = ImageFactory::newIntensityImage(200, image.getHeight() * ((double)200 / (double)image.getWidth()));

	if (true) {	//Using backward mapping
		for (int y = 0; y < result->getHeight(); y++) {
			for (int x = 0; x < result->getWidth(); x++) {

				if (true) {//First order
					double scaled_x = (double)(x * image.getWidth()) / (double)result->getWidth();
					double scaled_y = (double)(y * image.getHeight()) / (double)result->getHeight();
					//std::cout << result->getWidth() << "  " << scaled_y << "\n";
					//result->setPixel(x, y, ImageUtils::interpolate_first_order(&image, scaled_x, scaled_y));
				}
				else { //zero order (nearest neighbour)
					double scaled_x = (double)(x * image.getWidth()) / (double)result->getWidth();
					double scaled_y = (double)(y * image.getHeight()) / (double)result->getHeight();
					result->setPixel(x, y, image.getPixel(floor(scaled_x), floor(scaled_y)));
				}
			}
		}
	}
	else { //Forward mapping
		for (int y = 0; y < image.getHeight(); y++) {
			for (int x = 0; x < image.getWidth(); x++) {

				int scaled_x = floor((x * result->getWidth()) / image.getWidth());
				int scaled_y = floor((y * result->getHeight()) / image.getHeight());
				result->setPixel(scaled_x, scaled_y, image.getPixel(x, y));

			}
		}
	}

	return result;

}

/* Swicth on methods, defined in header (config file would prevent rebuild)
	1	Laplacian
	2	Laplacian Guassian
	3	Sobel
*/
IntensityImage * StudentPreProcessing::stepEdgeDetection(const IntensityImage &image) const {
	switch (method){
		case 1:
			// Laplacian
			return stepLaplacian(image);
			break;
		case 2:
			// Laplacian + Guassian
			return stepLaplacian(*stepGuassian(image));
			break;
		case 3:
			// Sobel
			return stepSobel(image);
			break;
		default:
			std::cout << "Unknown chosen method: " << method << "!" << std::endl;
			return nullptr;
			break;
	}

	/*
	//std::cout << "Test1";
	int imageHight = image.getHeight();
	int imageWidth = image.getWidth();
	
	int arr[9];
	arr[0] = -1; arr[1] = -1; arr[2] = -1;
	arr[3] = -1; arr[4] =  8; arr[5] = -1;
	arr[6] = -1; arr[7] = -1; arr[8] = -1;
	std::cout << "Test2";
	
	
	Mask* mask = new Mask(arr, 3);

	
	IntensityImageStudent* student_result = mask->useMaskOn(image);
	std::cout << "Test3";
	
	IntensityImage * result = ImageFactory::newIntensityImage(*student_result);
	*/

}

IntensityImage * StudentPreProcessing::stepThresholding(const IntensityImage &image) const {
	return nullptr;
}

IntensityImage * StudentPreProcessing::stepLaplacian(const IntensityImage &image) const {
	return nullptr;
}
IntensityImage * StudentPreProcessing::stepGuassian(const IntensityImage &image) const {
	return nullptr;
}

IntensityImage * StudentPreProcessing::stepSobel(const IntensityImage &image) const {
	std::cout << "Using Sobel" << std::endl;
	SumMask* mask = new SumMask(this->sobelMaskHor, this->sobelMaskVer, 3);
	IntensityImageStudent* student_result = mask->useMaskOn(image);
	IntensityImage * result = ImageFactory::newIntensityImage(*student_result);
	return result;
}