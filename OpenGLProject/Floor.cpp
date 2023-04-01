#include "Floor.h"

#include "Textures.h"

#define FLOOR_SIZE 40
#define FLOOR_SUBDIV 80
#define FLOOR_SUBDIV_TILES 1
#define FLOOR_TILE_SIZE (2 * FLOOR_SIZE / FLOOR_SUBDIV)



void initializeFloor() {
	
}

void drawFloor() {
	
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, TEX_TILE);

	glBegin(GL_QUADS);
	glColor3d(1, 1, 1);
	glNormal3d(0, 1, 0);
	//TODO make tiles have texture.
	for (int i = 0; i < FLOOR_SUBDIV; i += 1) {
		for (int j = 0; j < FLOOR_SUBDIV; j += 1) {
			float x = i * FLOOR_TILE_SIZE - FLOOR_SIZE;
			float z = j * FLOOR_TILE_SIZE - FLOOR_SIZE;
			glTexCoord2f(0, 0);
			glVertex3f(x, 0, z);

			glTexCoord2f(FLOOR_SUBDIV_TILES, 0);
			glVertex3f(x + FLOOR_TILE_SIZE, 0, z);

			glTexCoord2f(FLOOR_SUBDIV_TILES, FLOOR_SUBDIV_TILES);
			glVertex3f(x + FLOOR_TILE_SIZE, 0, z + FLOOR_TILE_SIZE);

			glTexCoord2f(0, FLOOR_SUBDIV_TILES);
			glVertex3f(x, 0, z + FLOOR_TILE_SIZE);
		}
	}
	
	glEnd();
	glDisable(GL_TEXTURE_2D);
}