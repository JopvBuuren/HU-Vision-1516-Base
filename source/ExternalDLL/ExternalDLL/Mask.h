#pragma once
#include "PreProcessing.h"
#include <string>
#include <math.h>
#include "ImageFactory.h"
#include "IntensityImage.h" 
#include "IntensityImageStudent.h" 
class Mask
{
public:
	Mask(std::vector<int> maskValues, int maskWidth);
	~Mask();

	IntensityImage *useMaskOn(const IntensityImage &image, bool devideCall);

private:
	int currentRow;
	std::vector<int> maskValues;
	int maskWidth;

};

