
/** Typy obiektow
*/
#define OBJ_SPHERE 0
#define OBJ_TRIANGLE 1
#define OBJ_PLANE 2

#include <iostream>
#include <FreeImage.h>
#include <glm.hpp>
#include <vector>
#include <algorithm>
#include <CL\opencl.h>

using namespace std;
using namespace glm;

#include "CCamera.h"
#include "CRay.h"
#include "CObject.h"
#include "CCamera.h"
#include "CLight.h"
#include "CScene.h"
#include "CImage.h"
#include "COutput.h"
#include "CRayTrace.h"