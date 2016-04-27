// rt.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"

void main(int argc, char* argv[])
{
	
	/*CCamera* camera = new CCamera(1000, 800, vec3(0, 0, -10), vec3(0, 0, 0), vec3(0, 1, 0), 50.f);

	vector<CObject*> objVec;
	objVec.push_back(new CSphere(vec3(2, 2, 0), 1.f, 0, vec3(0.01f, 0.01f, 0.01f), vec3(0.01f, 0.8f, 0.01f), vec3(0.01f, 0.01f, 0.01f), 20.f));
	objVec.push_back(new CSphere(vec3(0, 0, 0), 2.f, 0, vec3(0.01f, 0.01f, 0.01f), vec3(0.8f, 0.01f, 0.01f), vec3(0.8f, 0.8f, 0.8f), 20.f));
	
	CScene* scene = new CScene(camera, objVec);*/
	
	CCamera* camera1 = new CCamera(1000, 800, vec3(3, 15, -16), vec3(0, 0, 0), vec3(0, 1, 0), 50.f);
	vector<CObject*> objVec1;
	objVec1.push_back(new CSphere(vec3(2, 2, 0), 1.f, 0, vec3(0.01f, 0.01f, 0.01f), vec3(0.01f, 0.8f, 0.01f), vec3(0.01f, 0.01f, 0.01f), 20.f));
	objVec1.push_back(new CSphere(vec3(0, 0, 0), 2.f, 0, vec3(0.01f, 0.01f, 0.01f), vec3(0.8f, 0.01f, 0.01f), vec3(0.8f, 0.8f, 0.8f), 20.f));
	/* Odwrócony Y!!!! */
	objVec1.push_back(new CTriangle(vec3(-5, 4, -5), vec3(-5, 4, 5), vec3(5, 4, 5), 1.f, vec3(0.01, 0.01, 0.01), vec3(0.01, 0.01, 0.6), vec3(0.01, 0.01, 0.01), 20.f));
	objVec1.push_back(new CTriangle(vec3(5, 4, 5), vec3(5, 4, -5), vec3(-5, 4, -5), 1.f, vec3(0.01, 0.01, 0.01), vec3(0.01, 0.01, 0.6), vec3(0.01, 0.01, 0.01), 20.f));
	
	CScene* scene1 = new CScene(camera1, objVec1);
	
	CRayTrace* raytracer = new CRayTrace(*scene1);
	raytracer->run();

	
	return;
}