#include "stdafx.h"

CLight::CLight(vec3 pos, vec3 amb, vec3 diff, vec3 spec)
{
	this->pos = pos;
	this->amb = amb;
	this->diff = diff;
	this->spec = spec;
}