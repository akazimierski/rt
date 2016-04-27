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

vec3 CSphere::getNormal() {
	return vec3(0);
}

vec3 CSphere::crossPoint(float t, CRay* ray) {
	return (ray->position + (t * ray->direction));
}

bool CSphere::isCrossPoint(float t, CRay* ray) {
	return true;
}

vec3 CSphere::getPos() {
	return this->pos;
}
float CSphere::getRefl()
{
	return this->reflect;
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



CTriangle::CTriangle(vec3 pos0, vec3 pos1, vec3 pos2, float reflect, vec3 amb, vec3 diff, vec3 spec, float shininess) {
	type = OBJ_TRIANGLE;
	this->pos0 = pos0;
	this->pos2 = pos1;
	this->pos1 = pos2;
	this->reflect = reflect;
	this->amb = amb;
	this->diff = diff;
	this->spec = spec;
	this->shininess = shininess;
}

float CTriangle::intersect(CRay* ray) {
	vec3 N = getNormal();
	float D = dot(N, pos1);
	float t = (dot(N, ray->position) + D) / dot(N, ray->direction);
	if (t > -0.005f)
		return t;
	else
		return -1;
}

vec3 CTriangle::getNormal() {
	vec3 A = pos1 - pos0;
	vec3 B = pos2 - pos0;
	vec3 C = cross(A, B);
	return normalize(C);
}

vec3 CTriangle::crossPoint(float t, CRay* ray) {
	return ray->position + (t * ray->direction);
}

bool CTriangle::isCrossPoint(float t, CRay* ray) {
	vec3 P = crossPoint(t, ray);
	vec3 N = getNormal();
	vec3 edge0 = pos1 - pos0;
	vec3 edge1 = pos2 - pos1;
	vec3 edge2 = pos0 - pos2;
	vec3 C0 = P - pos0;
	vec3 C1 = P - pos1;
	vec3 C2 = P - pos2;
	if (dot(N, cross(edge0, C0)) > 0 &&
		dot(N, cross(edge1, C1)) > 0 && 
		dot(N, cross(edge2, C2)) > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

vec3 CTriangle::getPos0()
{
	return this->pos0;
}
vec3 CTriangle::getPos1()
{
	return this->pos1;
}
vec3 CTriangle::getPos2()
{
	return this->pos2;
}
float CTriangle::getRefl()
{
	return this->reflect;
}
float CTriangle::getShin()
{
	return this->shininess;
}
vec3 CTriangle::getAmb()
{
	return this->amb;
}
vec3 CTriangle::getDiff()
{
	return this->diff;
}
vec3 CTriangle::getSpec()
{
	return this->spec;
}