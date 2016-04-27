#include "stdafx.h"

CRay::CRay(vec3 position, vec3 direction){
	this->direction = direction;
	this->position = position;
}

vec3 CRay::computeDir(mat3 uvo, vec3 pos){
	return uvo * pos;
}