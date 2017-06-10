#include "IntensityImageStudent.h"

IntensityImageStudent::IntensityImageStudent() : IntensityImage() {
	pixelmap = new Intensity[0];
}

IntensityImageStudent::IntensityImageStudent(const IntensityImageStudent &other) : IntensityImage(other.getWidth(), other.getHeight()) {
	pixelmap = new Intensity[other.getWidth() * other.getHeight()];
	for (int i = 0; i < this->getWidth() * this->getHeight(); i++) {
		pixelmap[i] = other.getPixel(i);
	}
}

IntensityImageStudent::IntensityImageStudent(const IntensityImage &other) : IntensityImage{ other.getWidth(), other.getHeight() } {
	pixelmap = new Intensity[other.getWidth() * other.getHeight()];
	for (int i = 0; i < this->getWidth() * this->getHeight(); i++) {
		pixelmap[i] = other.getPixel(i);
	}
}

IntensityImageStudent::IntensityImageStudent(const int width, const int height) : IntensityImage(width, height) {
	pixelmap = new Intensity[width * height]();
}

IntensityImageStudent::~IntensityImageStudent() {
	delete[] pixelmap;
}

void IntensityImageStudent::set(const int width, const int height) {
	delete[] pixelmap;
	IntensityImage::set(width, height);
	pixelmap = new Intensity[width * height];
}

void IntensityImageStudent::set(const IntensityImageStudent &other) {
	delete[] pixelmap;
	IntensityImage::set(other.getWidth(), other.getHeight());
	for (int i = 0; i < this->getHeight()*this->getWidth(); i++) {
		pixelmap[i] = other.getPixel(i);
	}
}

void IntensityImageStudent::setPixel(int x, int y, Intensity pixel) {
	if (x < 0 || x >= getWidth() || y < 0 || y >= getHeight()) return; //should throw error
	pixelmap[y*this->getWidth() + x] = pixel;
}

void IntensityImageStudent::setPixel(int i, Intensity pixel) {
	if (i < 0 || i >= getHeight() * getWidth()) return;
	pixelmap[i] = pixel;
}

Intensity IntensityImageStudent::getPixel(int x, int y) const {
	x = x < 0 ? 0 : x;
	y = y < 0 ? 0 : y;
	x = x >= getWidth() ? getWidth() - 1 : x;
	y = y >= getHeight() ? getHeight() - 1 : y;
	return pixelmap[y*this->getWidth() + x];
}

Intensity IntensityImageStudent::getPixel(int i) const {
	i = i < 0 ? 0 : i;
	i = i >= getHeight()*getWidth() ? getHeight() * getWidth() - 1 : i;
	return pixelmap[i];
}