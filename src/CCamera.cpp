#include "stdafx.h"

CCamera::CCamera(int width, int height, vec3 eyePoint, vec3 lookPoint, vec3 up, float fov){
	this->width = width;
	this->height = height;
	this->eyePoint = eyePoint;
	this->lookPoint = lookPoint;
	this->up = up;
	this->fov = radians(fov);
}

mat3 CCamera::computeUVO(){
	vec3 look = lookPoint - eyePoint;
	vec3 u = normalize(cross(up, look));
	vec3 v = normalize(cross(u, look));
	vec3 o = normalize(look)*(float)(width / (2 * tan(fov / 2))) - ((float)(width / 2)*u) - ((float)(height / 2)*v);
	return mat3(u, v, o);
}