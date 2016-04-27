

/** Glowna klasa ray tracera
 */
class CRayTrace {
	
public:
	CScene* scene;
	CImage* image;

	CRayTrace(CScene& scene);

	vec3 rayTrace(CRay* ray, vec3 &color, float &energy);
	int run();
	
};




