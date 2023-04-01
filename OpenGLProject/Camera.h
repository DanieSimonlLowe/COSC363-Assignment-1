#ifndef CAMERA_H

#define CAMERA_H
#include <GL/freeglut.h>

#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif // !_USE_MATH_DEFINES
#include <math.h>
#include <glm/glm.hpp>
#include <time.h>


void initializeCamera(double posx, double posy, double posz);

void displayCamera();

void animateCamrea();

#endif
