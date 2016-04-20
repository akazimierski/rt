#include "stdafx.h"


CRayTrace::CRayTrace(CScene& scene){
	this->scene = &scene;
	this->image = new CImage(this->scene->cam->width, this->scene->cam->height);
	
}

int CRayTrace::rayTrace(CRay &ray, COutput* res) 
{
	return 0;
}

/** Glowna petla ray tracera
*/
int CRayTrace::run() 
{
	mat3 uvo = scene->cam->computeUVO();
	RGBQUAD color;
	for (int y = 0; y < scene->cam->height; y++) {
		for (int x = 0; x < scene->cam->width; x++) {
			vec3 iTot = vec3(0,0,0);

			CRay* ray = new CRay(scene->cam->eyePoint, normalize(uvo * vec3(x, y, 1.f)));
			float raySize;

			int minIndex = -1;
			float minRaySize = 0;
			
			vector<float> nearest;
			for (int i = 0; i < scene->obj.size(); i++)
			{
				float intersection = scene->obj[i]->intersect(ray);
				if (intersection > 0)
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
				
				vec3 iAmb = scene->obj[minIndex]->getAmb();
				vec3 iSubTot = iAmb;
				for (int j = 0; j < scene->lightCount; j++)
				{
					vec3 crossPoint = (ray->position+(intersection * ray->direction));
					vec3 L = normalize(scene->lights[j]->pos - crossPoint);
					vec3 V = normalize(scene->cam->eyePoint - crossPoint);
					vec3 N = normalize(crossPoint - scene->obj[minIndex]->getPos());
					vec3 R = normalize(reflect(-L,N));
					//vec3 R = ((2.f*(N*L)* N) - L);
					//vec3 R = normalize(L - 2.0f * dot(N, L) * N);

					CRay* shadowRay = new CRay(crossPoint, L);
					vector<float> shadowNearest;
					for (int i = 0; i < scene->obj.size(); i++)
					{
						float intersection = scene->obj[i]->intersect(shadowRay);
						if (intersection > -0.005)
						{
							shadowNearest.push_back(intersection);
						}
					}
					if (shadowNearest.size() > 0) continue;
					vec3 iDiff = (scene->obj[minIndex]->getDiff() * scene->lights[j]->diff)
						* dot(L,N);
					vec3 iSpec = scene->obj[minIndex]->getSpec() * scene->lights[j]->spec
						* pow(dot(V, R), scene->obj[minIndex]->getShin());

					iSubTot += iDiff + iSpec;
					delete shadowRay;
				}
				iTot += clamp(iSubTot, vec3(0), vec3(1))*255.f;
				delete ray;
			}

			//iTot = scene->obj[minIndex]->calculateColor(*scene->lights, scene->lightCount);
			color.rgbRed = iTot.r;
			color.rgbGreen = iTot.g;
			color.rgbBlue = iTot.b;
			image->setPixel(x, scene->cam->height - y, color);
		}
	}
	image->save("gradient.bmp");
	return 0;
}