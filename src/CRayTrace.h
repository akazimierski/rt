

/** Glowna klasa ray tracera
 */
class CRayTrace {
	
public:
	CScene* scene;
	CImage* image;

	CRayTrace(CScene& scene);

	int rayTrace(CRay &ray, COutput* res);
	int run();
	
};




