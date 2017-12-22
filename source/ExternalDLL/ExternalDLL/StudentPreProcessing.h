/*
* Copyright (c) 2015 DottedEye Designs, Alexander Hustinx, NeoTech Software, Rolf Smit - All Rights Reserved
* Unauthorized copying of this file, via any medium is strictly prohibited
* Proprietary and confidential
*/

#pragma once
#include "PreProcessing.h"
#include "Mask.h"
#include "SumMask.h"
#include "ImageFactory.h"
#include <vector>
#include "ImageIO.h"

class StudentPreProcessing : public PreProcessing {
public:
	IntensityImage * stepToIntensityImage(const RGBImage &image) const;
	IntensityImage * stepScaleImage(const IntensityImage &image) const;
	IntensityImage * stepEdgeDetection(const IntensityImage &image) const;
	IntensityImage * stepThresholding(const IntensityImage &image) const;

	IntensityImage * stepLaplacian(const IntensityImage &image) const;
	IntensityImage * stepHighPass(const IntensityImage &image) const;
	IntensityImage * stepGuassian(const IntensityImage &image) const;
	IntensityImage * stepSobel(const IntensityImage &image) const;
private:
	/* current method
		1	Laplacian
		2	Laplacian Guassian
		3   Highpass
		4   Highpass Gaussian
		5	Sobel
		6   Sobel + Gaussian
	*/
	int method = 6;

	int treshhold = 40;

	// Default sobel masks
	std::vector<int> sobelMaskHor = std::vector<int>{
		1, 0, -1,
		2, 0, -2,
		1, 0, -1 
	};
	
	std::vector<int> sobelMaskVer = std::vector<int>{
		1, 2, 1,
		0, 0, 0,
		-1, -2, -1 
	};
	std::vector<int> guassianMaskVer = std::vector<int>{
		1, 2, 1,
		2, 4, 2,
		1, 2, 1
	};
	std::vector<int> highpassMaskVer = std::vector<int>{
		0, 9, 0,
		9, -36, 9,
		0, 9, 0

	};
	std::vector<int> laplacianMaskVer = std::vector<int>{
		-1, -1, -1,
		-1, 8, -1,
		-1, -1, -1

	};
};

