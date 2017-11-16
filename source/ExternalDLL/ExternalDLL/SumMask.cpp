#include "SumMask.h"
#include <iostream>
#include <fstream>

SumMask::SumMask(const std::vector<int> hMask, const std::vector<int> vMask, int maskWidth)
{
	this->horizontalMask = hMask;
	this->verticalMask = vMask;
	this->maskWidth = maskWidth;
	threshold = floor(
		(3/4) * (
			abs(getHighestValue(hMask)) + abs(getHighestValue(vMask)
		)
	));
}

int SumMask::getHighestValue(std::vector<int> mask){
	int val = 0;
	int maxV = 255;
	for (int i = 0; i < maskWidth * maskWidth; i++){
		if (mask.at(i) > 0){
			val += (mask.at(i) * maxV);
		}
	}
	return val;
}

SumMask::~SumMask()
{

}

IntensityImageStudent *SumMask::useMaskOn(const IntensityImage & image){
	using namespace std;
	ofstream myfile;
	myfile.open("C:/Users/Jop van Buuren/Documents/text1.txt");
	int imageWidth = image.getWidth();
	int imageHeight = image.getHeight();

	IntensityImageStudent * image2 = new IntensityImageStudent();
	image2->set(imageWidth, imageHeight);
	for (int currentHeight = 0; currentHeight < imageHeight; currentHeight++)
	{
		if ((currentHeight + maskWidth)> imageHeight) {
			break;
		}

		for (int currentWidth = 0; currentWidth < imageWidth; currentWidth++) {
			if ((currentWidth + maskWidth) > imageWidth) {
				break;
			}
			int size = maskWidth*maskWidth;
			int calx = 0;
			int caly = 0;

			for (int x = 0; x < maskWidth; x++) {
				for (int y = 0; y < maskWidth; y++) {
					int v = image.getPixel(currentWidth + x, currentHeight + y);
					int p = y * maskWidth + x;
					calx = calx + (v * horizontalMask[p]);
					caly = caly + (v * verticalMask[p]);
					myfile << "calx: " << calx << ", caly:" << caly << std::endl;
				}
			}

			//int value = (abs(calx) + abs(caly));
			int value = sqrt(calx*calx + caly*caly);
			if (value > 100){
				image2->setPixel(currentWidth + floor(maskWidth / 2), currentHeight + floor(maskWidth / 2), 255);
			}
			else{
				image2->setPixel(currentWidth + floor(maskWidth / 2), currentHeight + floor(maskWidth / 2), 0);
			}

			
		}
	}
	return image2;
}
