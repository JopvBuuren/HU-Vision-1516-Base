#include "StudentPreProcessing.h"
#include <iostream>
#include <fstream>

IntensityImage * StudentPreProcessing::stepToIntensityImage(const RGBImage &image) const {
	return nullptr;
}

IntensityImage * StudentPreProcessing::stepScaleImage(const IntensityImage &image) const {
	return nullptr;
}

/* Swicth on methods, defined in header (config file would prevent rebuild)
	1	Laplacian
	2	Laplacian Guassian
	3	Sobel
*/
IntensityImage * StudentPreProcessing::stepEdgeDetection(const IntensityImage &image) const {
	using namespace std;
	ofstream myfile;
	myfile.open("C:/Users/danie/git/HU-Vision-1516-JoDa/source/ExternalDLL/debug2.txt");
	myfile << "Line 1" << endl;
	IntensityImage* result;
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
		case 4:
			myfile << "Line 2" << endl;
			result = stepGuassian(image);
			myfile << "Line 3" << endl;
			return result; break;
		default:
			std::cerr << "Unknown chosen method: " << method << "!" << std::endl;
			return nullptr;
			break;
	}

}

IntensityImage * StudentPreProcessing::stepThresholding(const IntensityImage &image) const {
	int imageWidth = image.getWidth();
	int imageHight = image.getHeight();
	IntensityImageStudent image2(image);
	IntensityImage* result2 = ImageFactory::newIntensityImage(image);
	for (int x = 0; x < imageWidth; x++){
		for (int y = 0; y < imageHight; y++){
			if (image.getPixel(x,y) > treshhold) {
				image2.setPixel(x, y, 0);
			}
			else image2.setPixel(x, y, 255);
		}
	}
	IntensityImage* result = ImageFactory::newIntensityImage(image2);
	return result;

}

IntensityImage * StudentPreProcessing::stepLaplacian(const IntensityImage &image) const {
	return nullptr;
}
IntensityImage * StudentPreProcessing::stepGuassian(const IntensityImage &image) const {
	
		
	//IntensityImageStudent image2 = image;
	IntensityImage* image2 = ImageFactory::newIntensityImage(image);
	int maskWidth = 3;
	std::vector<int> maskValues = guassianMaskVer;
	Mask* highpassMask = new Mask(highpassMaskVer,maskWidth);
	Mask* gausianMask = new Mask(guassianMaskVer, maskWidth);
	image2 = gausianMask->useMaskOn(*image2, true);
	image2 = highpassMask->useMaskOn(*image2, false);
	IntensityImage* result = ImageFactory::newIntensityImage(*image2);
	return result;
}

IntensityImage * StudentPreProcessing::stepSobel(const IntensityImage &image) const {
	SumMask* mask = new SumMask(this->sobelMaskHor, this->sobelMaskVer, 3);
	IntensityImageStudent* student_result = mask->useMaskOn(image);
	IntensityImage * result = ImageFactory::newIntensityImage(*student_result);
	return result;
}