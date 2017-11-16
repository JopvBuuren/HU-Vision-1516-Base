#include "StudentPreProcessing.h"
#include <iostream>
#include <fstream>
ofstream myfile;
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
	
	myfile.open("C:/Users/Jop van Buuren/Documents/text.txt");
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
			// Highpass
			result = stepHighPass(image);
			return result; break;
		case 4:
			// Highpass + Gaussian
			result = stepHighPass(*stepGuassian(image));
			return result; break;
		case 5:
			// Sobel
			myfile << "Start test" << std::endl;
			return stepSobel(image);
			myfile << "Stop test" << std::endl;
			break;
		case 6: 
			// Sobel + Gaussian
			return stepSobel(*stepGuassian(image));
			break;
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
	IntensityImage* image2 = ImageFactory::newIntensityImage(image);
	int maskWidth = 3;
	Mask* laplacianMask = new Mask(laplacianMaskVer, maskWidth);
	image2 = laplacianMask->useMaskOn(*image2, false, true);
	IntensityImage* result = ImageFactory::newIntensityImage(*image2);
	return result;
}

IntensityImage * StudentPreProcessing::stepHighPass(const IntensityImage &image) const {
	IntensityImage* image2 = ImageFactory::newIntensityImage(image);
	int maskWidth = 3;
	Mask* laplacianMask = new Mask(highpassMaskVer, maskWidth);
	image2 = laplacianMask->useMaskOn(*image2, false, false);
	IntensityImage* result = ImageFactory::newIntensityImage(*image2);
	return result;
}

IntensityImage * StudentPreProcessing::stepGuassian(const IntensityImage &image) const {
	IntensityImage* image2 = ImageFactory::newIntensityImage(image);
	int maskWidth = 3;
	std::vector<int> maskValues = guassianMaskVer;
	Mask* gausianMask = new Mask(guassianMaskVer, maskWidth);
	image2 = gausianMask->useMaskOn(*image2, true, false);
	IntensityImage* result = ImageFactory::newIntensityImage(*image2);
	return result;
}

IntensityImage * StudentPreProcessing::stepSobel(const IntensityImage &image) const {

	myfile << "so far" << std::endl;
	SumMask * mask = new SumMask(this->sobelMaskHor, this->sobelMaskVer, 3);
	myfile << "This far" << std::endl;
	IntensityImageStudent * student_result = mask->useMaskOn(image);
	myfile << "here realy" << std::endl;
	IntensityImage * result = ImageFactory::newIntensityImage(*student_result);
	myfile << "hacks" << std::endl;

	return result;
}