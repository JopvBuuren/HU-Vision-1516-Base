#pragma once
#include "PreProcessing.h"
#include <string>
#include <math.h>
#include "IntensityImage.h" 
#include "IntensityImageStudent.h" 
using namespace std;
class SumMask
{
public:
	SumMask(const std::vector<int> horizontalMask, const std::vector<int> verticalMask, int maskWidth);
	~SumMask();

	IntensityImageStudent *useMaskOn(const IntensityImage &image);
	int getHighestValue(std::vector<int> mask);
private:
	int currentRow;
	std::vector<int> horizontalMask;
	std::vector<int> verticalMask;
	int maskWidth;
	int threshold;

};

