#include "stdafx.h"

CImage::CImage(int width, int height){
	this->width = width;
	this->height = height;
	this->data = FreeImage_Allocate(this->width, this->height, 24);
}

void CImage::save(char* fname) {
	FreeImage_Save(FIF_BMP, data, fname);
};

void CImage::setPixel(int i, int j, RGBQUAD color){
	FreeImage_SetPixelColor(data, i, j, &color);
};