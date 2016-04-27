#include "stdafx.h"

CScene::CScene(CCamera* cam, vector<CObject*> obj){
	this->cam = cam;
	this->obj = obj;
	this->lights[0] = new CLight(vec3(-4, 4, -2), vec3(1, 1, 1), vec3(1, 1, 1), vec3(1, 1, 1));
	this->lights[1] = new CLight(vec3(1, 1, -10), vec3(1, 1, 1), vec3(1, 1, 1), vec3(1, 1, 1));
	this->lightCount = 2;
}

int CScene::parse(char* fname) {

	return 0;
}