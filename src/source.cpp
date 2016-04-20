// rt.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"

void main(int argc, char* argv[])
{
	
	CCamera* camera = new CCamera(1000, 800, vec3(0, 0, -10), vec3(0, 0, 0), vec3(0, 1, 0), 50.f);

	vector<CObject*> objVec;
	//CObject* obj = new CSphere(vec3(0, 0, 0), 2.f);
	objVec.push_back(new CSphere(vec3(2, 2, 0), 1.f, 0, vec3(0.01f, 0.01f, 0.01f), vec3(0.01f, 0.8f, 0.01f), vec3(0.01f, 0.01f, 0.01f), 20));
	objVec.push_back(new CSphere(vec3(0, 0, 0), 2.f, 0, vec3(0.01f, 0.01f, 0.01f), vec3(0.8f, 0.01f, 0.01f), vec3(0.8f, 0.8f, 0.8f), 20));
	

	CScene* scene = new CScene(camera, objVec);
	CRayTrace* raytracer = new CRayTrace(*scene);
	raytracer->run();
	return;
}