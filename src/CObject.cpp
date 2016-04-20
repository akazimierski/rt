#include "stdafx.h"



CSphere::CSphere(vec3 pos, float r, float reflect, vec3 amb, vec3 diff, vec3 spec, float shininess) {
	type = OBJ_SPHERE;
	this->r = r;
	this->pos = pos;
	this->reflect = reflect;
	this->amb = amb;
	this->diff = diff;
	this->spec = spec;
	this->shininess = shininess;
}

float CSphere::intersect(CRay* ray) {
	float delta, t, t1;
	vec3 v = ray->position-this->pos;
	float A = dot(ray->direction, ray->direction);
	float B = dot(v*2.f, ray->direction);
	float C = dot(v, v) - (this->r * this->r);
	
	delta = (B*B) - (4*A*C);

	if (delta > 0)
	{
		t = (-B + sqrt(delta)) / (2 * A);
		t1 = (-B - sqrt(delta)) / (2 * A);
		if (t1 < t)
		{
			t = t1;
		}
	}
	else
	{
		t = -1;
	}

	return t;
}

vec3 CSphere::getPos() {
	return this->pos;
}
float CSphere::getShin() {
	return this->shininess;
}
vec3 CSphere::getAmb() {
	return this->amb;
}
vec3 CSphere::getDiff() {
	return this->diff;
}
vec3 CSphere::getSpec() {
	return this->spec;
}



CTriangle::CTriangle() {
	type = OBJ_TRIANGLE;
}

float CTriangle::intersect(CRay* ray) {
	float t = -1;
	return t;
}