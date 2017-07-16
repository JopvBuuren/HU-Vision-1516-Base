#include "StudentPreProcessing.h"


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
			std::cerr << "Unknown chosen method: " << method << "!" << std::endl;
			return nullptr;
			break;
	}

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
	SumMask* mask = new SumMask(this->sobelMaskHor, this->sobelMaskVer, 3);
	IntensityImageStudent* student_result = mask->useMaskOn(image);
	IntensityImage * result = ImageFactory::newIntensityImage(*student_result);
	return result;
}