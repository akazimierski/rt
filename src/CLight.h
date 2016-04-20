
/** Definicja zrodla swiatla
*/
class CLight  {
public:
	vec3 pos;
	vec3 amb;
	vec3 diff;
	vec3 spec;
	CLight(vec3 pos, vec3 amb, vec3 diff, vec3 spec);
};
