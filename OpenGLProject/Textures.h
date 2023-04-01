#pragma once

#include <GL/freeglut.h>

#include "loadTGA.h"

#define TEX_COUNT 3


#define TEX_TILE (getTex(0))
#define TEX_PATTEN (getTex(1))
#define TEX_ROCK (getTex(2))

void initializeTexures();

GLuint getTex(unsigned int num);