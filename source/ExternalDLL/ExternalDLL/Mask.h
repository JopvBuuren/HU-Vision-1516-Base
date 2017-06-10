#pragma once
#include "PreProcessing.h"
#include <string>
#include <math.h>
#include "IntensityImage.h" 
#include "IntensityImageStudent.h" 
class Mask
{
public:
	Mask(int maskValues[8], int maskWidth);
	~Mask();

	IntensityImageStudent *useMaskOn(const IntensityImage &image);

private:
	int currentRow;
	int maskValues[8];
	int maskWidth;

};

