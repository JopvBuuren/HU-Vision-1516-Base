#include "Mask.h"
#include <iostream>
#include <fstream>

Mask::Mask(std::vector<int> maskValues, int maskWidth)
{
	this->maskValues = maskValues;
	this->maskWidth = maskWidth;
}


Mask::~Mask()
{
}

IntensityImage *Mask::useMaskOn(const IntensityImage & image, bool devideCal)
{
	using namespace std;
	int imageWidth = image.getWidth();
	int imageHeight = image.getHeight();

	IntensityImageStudent image2(image);

	for (int currentHeight = 0; currentHeight < imageHeight; currentHeight++)
	{
		if ((currentHeight + maskWidth)> imageHeight) {
			break;
		}

		for (int currentWidth = 0; currentWidth < imageWidth; currentWidth++) {

			if ((currentWidth + maskWidth) > imageWidth) {
				break;
			}
			int trackerY = 0;
			int arr[9];
			cout << " ch: " << currentHeight << " cw: " << currentWidth << endl;
			for (int i = 0; i < maskWidth; i++) {
				arr[(i * maskWidth)] = image.getPixel(currentWidth, currentHeight + trackerY);
				arr[(i * maskWidth) + 1] = image.getPixel(currentWidth + 1, currentHeight + trackerY);
				arr[(i * maskWidth) + 2] = image.getPixel(currentWidth + 2, currentHeight + trackerY);
				trackerY++;
			}

			//Function calulate:
			int calulation = 0;
			for (int k = 0; k <= (maskWidth*maskWidth) - 1; k++) {
				calulation = calulation + ((int)arr[k] * maskValues[k]);

			}
			if (devideCal){
				calulation = calulation / (maskWidth * maskWidth);
			}
			
			if (calulation < 0){
				calulation = 0;
			}
			else if (calulation > 255){
				calulation = 255;
			}
			image2.setPixel(currentWidth + floor(maskWidth / 2), currentHeight + floor(maskWidth / 2), calulation);
			

		}
	}
	IntensityImage* result = ImageFactory::newIntensityImage(image2);

	return result;
}
