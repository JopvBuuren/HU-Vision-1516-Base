#include "RGBImageStudent.h"

RGBImageStudent::RGBImageStudent() : RGBImage() {
	//int throwError = 0, e = 1 / throwError; //Throws error without the need to include a header
	//TODO: Nothing
	std::cout << "I am called!" << std::endl;
}

RGBImageStudent::RGBImageStudent(const RGBImageStudent &other) : RGBImage(other.getWidth(), other.getHeight()) {
	container = other.container;
}


RGBImageStudent::RGBImageStudent(const int width, const int height) : RGBImage(width, height) {
	std::cout << "this is called!" << std::endl;
	std::fflush;
	int max = height * width;
	for (int i = 0; i < max; i++){
		container[i] = RGB();
	}
}

RGBImageStudent::~RGBImageStudent() {
	std::cout << "Nothing to delete!" << std::endl;
}

void RGBImageStudent::set(const int width, const int height) {
	std::vector<RGB> tmpCont;
	for (int y = 0; y < width; y++){
		for (int x = 0; x < width; x++){
			RGB pixel = this->getPixel(x, y);
			container[y * width + x] = pixel;
		}
	}
	RGBImage::set(width, height); //not needed
	container = tmpCont;
}

void RGBImageStudent::set(const RGBImageStudent &other) {
	int width = other.getWidth();
	int height = other.getHeight();
	std::vector<RGB> tmpCont;
	for (int y = 0; y < width; y++){
		for (int x = 0; x < width; x++){
			RGB pixel = this->getPixel(x, y);
			container[y * width + x] = pixel;
		}
	}
	RGBImage::set(width, height); //not needed
	container = tmpCont;
}

void RGBImageStudent::setPixel(int x, int y, RGB pixel) {
	if (y <= this->getHeight() && (x <= this->getWidth())){
		int i = y * this->getWidth() + x;
		container[i] = pixel;
	}
	else{
		int throwError = 0, e = 1 / throwError;
	}
}

void RGBImageStudent::setPixel(int i, RGB pixel) {
	if (i < container.size()){
		container[i] = pixel;
	}
	else{
		int throwError = 0, e = 1 / throwError;
	}
}

RGB RGBImageStudent::getPixel(int x, int y) const {
	if (y <= this->getHeight() && (x <= this->getWidth())){
		int i = y * this->getWidth() + x;
		return container[i];
		//return absolute black if x/y is out off bounds
	}
	else{
		return RGB(255, 255, 255);
	}
}

RGB RGBImageStudent::getPixel(int i) const {
	int max = this->getWidth() * this->getHeight();
	if (i < max){
		return container[i];
	}
	else{
		//return absolute black if i is out off bounds
		return RGB(255, 255, 255);
	}
}