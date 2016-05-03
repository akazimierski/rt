#include "stdafx.h"


CRayTrace::CRayTrace(CScene& scene){
	this->scene = &scene;
	this->image = new CImage(this->scene->cam->width, this->scene->cam->height);
	
}

vec3 CRayTrace::rayTrace(CRay* ray, vec3 &color, float &energy) 
{
	float raySize;

	int minIndex = -1;
	float minRaySize = 0;
			
	vector<float> nearest;
	for (int i = 0; i < scene->obj.size(); i++)
	{
		float intersection = scene->obj[i]->intersect(ray);
		bool isIn = scene->obj[i]->isCrossPoint(intersection, ray);
		if (intersection > -0.005f && isIn)
		{
			nearest.push_back(intersection);
		}
	}
	if (nearest.size() > 0)
	{
		float intersection = *min_element(begin(nearest), end(nearest));
			for (int i = 0; i < scene->obj.size(); i++)
			{
				if ((raySize = scene->obj[i]->intersect(ray)) != -1 && raySize > 0)
					if (raySize == intersection) minIndex = i;
			}
		if (minIndex == -1)
		{
			return color;
		}
		vec3 iAmb = scene->obj[minIndex]->getAmb();
		color = iAmb;
		vec3 V;
		vec3 N;
		vec3 R;
		vec3 crossPoint = scene->obj[minIndex]->crossPoint(intersection, ray);
		for (int j = 0; j < scene->lightCount; j++)
		{
			vec3 L = normalize(scene->lights[j]->pos - crossPoint);
			V = normalize(ray->position - crossPoint);
			if (scene->obj[minIndex]->type == OBJ_SPHERE)
			{
				N = normalize(crossPoint - scene->obj[minIndex]->getPos());
			}
			else
			{
				N = scene->obj[minIndex]->getNormal();
			}
			R = normalize(reflect(-L, N));
			//vec3 R = ((2.f*(N*L)* N) - L);
			//vec3 R = normalize(L - 2.0f * dot(N, L) * N);

			CRay* shadowRay = new CRay(crossPoint, L);
			vector<float> shadowNearest;
			for (int i = 0; i < scene->obj.size(); i++)
			{
				float intersection = scene->obj[i]->intersect(shadowRay);
				if (intersection > -0.005f && scene->obj[i]->isCrossPoint(intersection, shadowRay))
				{
					if (scene->obj[i]->type == OBJ_SPHERE)
					{
						shadowNearest.push_back(intersection);
					}
					else if (scene->obj[i]->type == OBJ_TRIANGLE && minIndex != i)
					{
						shadowNearest.push_back(intersection);
					}
				}
			}
			if (shadowNearest.size() > 0) continue;
			delete shadowRay;

			vec3 iDiff = (scene->obj[minIndex]->getDiff() * scene->lights[j]->diff)
				* dot(L, N);
			vec3 iSpec = scene->obj[minIndex]->getSpec() * scene->lights[j]->spec
				* pow(dot(V, R), scene->obj[minIndex]->getShin());
			color += energy*(iDiff + iSpec);
		}
		energy *= 0.5f*scene->obj[minIndex]->getRefl();
		if (energy < 0.2f)
		{
			return color;
		}
		vec3 dir = normalize(V + (2.f * V * N) * N);
		CRay* secRay = new CRay(crossPoint, dir);
		rayTrace(secRay, color, energy);
	}
	return color;
}

/** Glowna petla ray tracera
*/
int CRayTrace::run(char* fileName) 
{
	mat3 uvo = scene->cam->computeUVO();
	RGBQUAD color;
	for (int y = 0; y < scene->cam->height; y++) {
		for (int x = 0; x < scene->cam->width; x++) {

			vec3 iTot = vec3(0,0,0);
			float energy = 1.0f;

			CRay* ray = new CRay(scene->cam->eyePoint, normalize(uvo * vec3(x, y, 1.f)));
			vec3 iSubTot = rayTrace(ray, vec3(0), energy);
			
			iTot += clamp(iSubTot, vec3(0), vec3(1))*255.f;
			delete ray;

			color.rgbRed = iTot.r;
			color.rgbGreen = iTot.g;
			color.rgbBlue = iTot.b;
			image->setPixel(x, scene->cam->height - y, color);
		}
	}
	image->save(fileName);
	return 0;
}

