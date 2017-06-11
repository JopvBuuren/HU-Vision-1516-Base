/*
* Copyright (c) 2015 DottedEye Designs, Alexander Hustinx, NeoTech Software, Rolf Smit - All Rights Reserved
* Unauthorized copying of this file, via any medium is strictly prohibited
* Proprietary and confidential
*/

#pragma once
#include "PreProcessing.h"
#include "Mask.h"
#include "ImageFactory.h"
class StudentPreProcessing : public PreProcessing {
public:
	IntensityImage * stepToIntensityImage(const RGBImage &image) const;
	IntensityImage * stepScaleImage(const IntensityImage &image) const;
	IntensityImage * stepEdgeDetection(const IntensityImage &image) const;
	IntensityImage * stepThresholding(const IntensityImage &image) const;

	IntensityImage * stepLaplacian(const IntensityImage &image) const;
	IntensityImage * stepGuassian(const IntensityImage &image) const;
	IntensityImage * stepHighPass(const IntensityImage &image) const;
	IntensityImage * stepSobel(const IntensityImage &image) const;
private:
	// current method
	int method = 0;
};