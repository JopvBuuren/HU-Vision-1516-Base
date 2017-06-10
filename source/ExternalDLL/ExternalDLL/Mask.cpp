#include "Mask.h"



Mask::Mask(int maskValues[8], int maskWidth)
{
	maskValues = maskValues;
	maskWidth = maskWidth;
}


Mask::~Mask()
{
}

IntensityImageStudent *Mask::useMaskOn(const IntensityImage & image)
{

	int imageWidth = image.getWidth();
	int imageHight = image.getHeight();

	IntensityImageStudent * image2 = new IntensityImageStudent();
	
	for(int currentHight = 0; currentHight < imageHight; currentHight++)
	{
		if ((currentHight + maskWidth)> imageHight) {
			break;
		}
		int arr[8];
		for (int currentWidth = 0; currentWidth < imageWidth; currentWidth++) {
			
			if ((currentWidth + maskWidth) > imageWidth) {
				break;
			}
			int trackerY = 0;
			for (int i = 0; i < maskWidth; i++) {
				arr[(i * maskWidth)] = image.getPixel(currentWidth, currentHight + trackerY);
				arr[(i * maskWidth) +1] = image.getPixel(currentWidth + 1, currentHight + trackerY);
				arr[(i * maskWidth)+ 2] = image.getPixel(currentWidth + 2, currentHight + trackerY);
				trackerY++;
			}

		

			//Function calulate:
			int calulation= 0;
			for (int k = 0;k < 8; k++) {
				calulation = calulation + (arr[k] * maskValues[k]);
			}

			int arrSom = 0;
			for (int value : arr) {
				arrSom = arrSom + value;
			}
			calulation = calulation / arrSom;

			if (calulation > 126) {
				image2->setPixel(currentWidth + floor(maskWidth/2), currentHight + floor(maskWidth / 2),255);
			}
			else image2->setPixel(currentWidth + floor(maskWidth / 2), currentHight + floor(maskWidth / 2), 0);
		}
	}
	
	return image2;
}

