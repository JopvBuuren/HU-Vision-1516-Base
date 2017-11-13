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


IntensityImage *Mask::useMaskOn(const IntensityImage & image, bool divideCal, bool isLaplacian)
{
	using namespace std;
	ofstream myfile;
	myfile.open("C:/Users/danie/git/HU-Vision-1516-JoDa/source/ExternalDLL/debug.txt");
	IntensityImageStudent image2(image);

	int imageWidth = image.getWidth();
	int imageHeight = image.getHeight();

	
	for (int currentHeight = 0; currentHeight < imageHeight; currentHeight++)
	{
		if ((currentHeight + maskWidth)> imageHeight)
		{
			break;
		}

		for (int currentWidth = 0; currentWidth < imageWidth; currentWidth++)
		{

			if ((currentWidth + maskWidth) > imageWidth) {
				break;
			}
			int trackerY = 0;
			int arr[9];
			

			for (int i = 0; i < maskWidth; i++)
			{
				arr[(i * maskWidth)] = image.getPixel(currentWidth, currentHeight + trackerY);
				arr[(i * maskWidth) + 1] = image.getPixel(currentWidth + 1, currentHeight + trackerY);
				arr[(i * maskWidth) + 2] = image.getPixel(currentWidth + 2, currentHeight + trackerY);
				trackerY++;
			}

			//Function calulate:
			int calculation = 0;
			int totalSomMask = 0;
			for (int k = 0; k <= (maskWidth*maskWidth) - 1; k++)
			{
				calculation = calculation + ((int)arr[k] * maskValues[k]);
				totalSomMask = totalSomMask + maskValues[k];
				//myfile << "Cal: " << calculation << "Nr:" << (int)arr[k] << endl;
			}
			if (divideCal){
				calculation = floor(calculation / totalSomMask);
			}
			if (isLaplacian){
				calculation = calculation + 195;
			}
			if (calculation <= 0){
				calculation = 0;
			}
			else if (calculation >= 255){
				calculation = 255;
			}
			image2.setPixel(currentWidth + floor(maskWidth / 2), currentHeight + floor(maskWidth / 2), calculation);
		}

	}
	cout << "IW: "<< imageWidth << " IH: " << imageHeight;
	//Making the witdh egde white
	for (int j = 0; j <= 3; j++){
		for (int i = 0; i <= imageWidth; i++){

			image2.setPixel(i, j, 0);
			image2.setPixel(i, imageHeight -j, 0);
			cout << i << endl;
		}
		//Making the height egde white
		for (int i = 0; i <= imageHeight; i++){
			image2.setPixel(j, i, 0);
			image2.setPixel(imageWidth - j, i, 0);

		}
	}
	IntensityImage* result = ImageFactory::newIntensityImage(image2);
	
	return result;
	
}