#ifndef _CCAMERA_H_
#define _CCAMERA_H_

/** Klasa opisujaca parametry kamery
*/
class CCamera {
public:
	int width;
	int height;

	vec3 eyePoint;
	vec3 lookPoint;
	vec3 up;
	float fov;

public:
	CCamera(int width, int height, vec3 eyePoint, vec3 lookPoint, vec3 up, float fov);
	mat3 computeUVO();
};

#endif