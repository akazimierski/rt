
/** Wirtualna klasa definuj¹ca obiekt
*/
class CObject {
public:
	int type; /**< rodzaj obiektu (OBJ_SPHERE, OBJ_TRIANGLE) */

	CObject() {
	}

	/** Obliczenie przeciêcia promienia z obiektem */
	virtual float intersect(CRay* ray) {
		return -1;
	}
	virtual vec3 getNormal() {
		return vec3(0);
	}
	virtual vec3 crossPoint(float t, CRay* ray) {
		return vec3(0);
	}
	virtual bool isCrossPoint(float t, CRay* ray) {
		return false;
	}
	virtual vec3 getPos() {
		return vec3(0,0,0);
	}
	virtual float getRefl() {
		return -1;
	}
	virtual float getShin() {
		return -1;
	}
	virtual vec3 getAmb() {
		return vec3(0, 0, 0);
	}
	virtual vec3 getDiff() {
		return vec3(0, 0, 0);
	}
	virtual vec3 getSpec() {
		return vec3(0, 0, 0);
	}
};

/** Klasa opisujaca obiekt - kula
*/
class CSphere : public CObject {
public:
	float r; /**< promien */
	vec3 pos; /**< polozenie srodka */
	float reflect;
	vec3 amb, diff, spec;
	float shininess;

	CSphere(vec3 pos, float r, float reflect, vec3 amb, vec3 diff, vec3 spec, float shininess);

	/** Obliczenie przeciêcia promienia z kula */
	float intersect(CRay* ray);
	vec3 getNormal();
	vec3 crossPoint(float t, CRay* ray);
	bool isCrossPoint(float t, CRay* ray);
	vec3 getPos();
	float getRefl();
	float getShin();
	vec3 getAmb();
	vec3 getDiff();
	vec3 getSpec();
};

/** Klasa opisujaca obiekt - triangle
*/
class CTriangle : public CObject {
public:
	vec3 pos0;
	vec3 pos1;
	vec3 pos2;
	float reflect;
	vec3 amb, diff, spec;
	float shininess;

	CTriangle(vec3 pos0, vec3 pos1, vec3 pos2, float reflect, vec3 amb, vec3 diff, vec3 spec, float shininess);

	/** Obliczenie przeciêcia promienia z kula */
	float intersect(CRay* ray);
	vec3 getNormal();
	vec3 crossPoint(float t, CRay* ray);
	bool isCrossPoint(float t, CRay* ray);
	vec3 getPos0();
	vec3 getPos1();
	vec3 getPos2();
	float getRefl();
	float getShin();
	vec3 getAmb();
	vec3 getDiff();
	vec3 getSpec();
};
