/** Klasa opisujaca promien
*/
class CRay{
public:
	vec3 direction;
	vec3 position;

	CRay(vec3 position, vec3 direction);
	vec3 computeDir(mat3 uvo, vec3 pos);
};