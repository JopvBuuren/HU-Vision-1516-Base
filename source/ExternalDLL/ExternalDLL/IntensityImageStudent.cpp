#include "IntensityImageStudent.h"

IntensityImageStudent::IntensityImageStudent() : IntensityImage() {
	std::cout << "IntensityImageStudent() is called!" << std::endl;
}

IntensityImageStudent::IntensityImageStudent(const IntensityImageStudent &other) : IntensityImage(other.getWidth(), other.getHeight()) {
	std::cout << "IntensityImageStudent(IntensityImageStudent &other) is called!" << std::endl;
	container = other.container;
}

IntensityImageStudent::IntensityImageStudent(const int width, const int height) : IntensityImage(width, height) {
	std::cout << "IntensityImageStudent(width, height) is called!" << std::endl;
	std::fflush;
	int max = height * width;
	for (int i = 0; i < max; i++){
		container[i] = Intensity();
	}
}

IntensityImageStudent::~IntensityImageStudent() {
	//int throwError = 0, e = 1 / throwError;
	//TODO: delete allocated objects
}

void IntensityImageStudent::set(const int width, const int height) {
	std::cout << "set(width, height) is called!" << std::endl;
	std::vector<Intensity> tmpCont;
	for (int y = 0; y < width; y++){
		for (int x = 0; x < width; x++){
			Intensity pixel = this->getPixel(x, y);
			container[y * width + x] = pixel;
		}
	}
	
	IntensityImage::set(width, height);
	container = tmpCont;
}

void IntensityImageStudent::set(const IntensityImageStudent &other) {
	std::cout << "set(IntensityImageStudent &other) is called!" << std::endl;
	int width = other.getWidth();
	int height = other.getHeight();
	std::vector<Intensity> tmpCont;
	for (int y = 0; y < width; y++){
		for (int x = 0; x < width; x++){
			Intensity pixel = this->getPixel(x, y);
			container[y * width + x] = pixel;
		}
	}
	container = tmpCont;
	IntensityImage::set(other.getWidth(), other.getHeight());
}

void IntensityImageStudent::setPixel(int x, int y, Intensity pixel) {
	if (y <= this->getHeight() && (x <= this->getWidth())){
		int i = y * this->getWidth() + x;
		container[i] = pixel;
	}
	else{
		int throwError = 0, e = 1 / throwError;
	}
}

void IntensityImageStudent::setPixel(int i, Intensity pixel) {
	
	if (i < container.size()){
		container[i] = pixel;
	}
	else{
		int throwError = 0, e = 1 / throwError;
	}
}

Intensity IntensityImageStudent::getPixel(int x, int y) const {
	if (y <= this->getHeight() && (x <= this->getWidth())){
		int i = y * this->getWidth() + x;
		return container[i];
		//return absolute black if x/y is out off bounds
	}
	else{
		return Intensity(255);
	}
}

Intensity IntensityImageStudent::getPixel(int i) const {
	int max = this->getWidth() * this->getHeight();
	if (i < max){
		return container[i];
	}
	else{
		//return absolute black if i is out off bounds
		return Intensity(255);
	}
}