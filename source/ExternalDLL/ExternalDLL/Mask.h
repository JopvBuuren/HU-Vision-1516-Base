#pragma once
#include "PreProcessing.h"
#include <string>
#include <math.h>
#include "ImageFactory.h"
#include "IntensityImage.h" 
#include "IntensityImageStudent.h" 
#include "ImageFactory.h"
#include "ImageIO.h"
class Mask
{
public:
	Mask(std::vector<int> maskValues, int maskWidth);
	~Mask();
	IntensityImage *useMaskOn(const IntensityImage &image, bool divideCAl, bool isLaplacian);


private:
	int currentRow;
	std::vector<int> maskValues;
	int maskWidth;
	int laplacianCorrection = 80;

};

