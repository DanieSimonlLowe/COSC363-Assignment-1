#include "MoirePattern.h"

#include "Textures.h"


float angle;

void initializePatten() {
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	angle = 0;
}

void animatePatten() {
	angle += 0.001;
}

void drawFace() {
	glEnable(GL_BLEND);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, TEX_PATTEN);

	glBegin(GL_QUADS);
		glColor3d(0, 0, 0);
		glNormal3d(0, 0, 1);

		glTexCoord2f(0, 0);
		glVertex3f(-0.5, -0.5, 0);

		glTexCoord2f(1, 0);
		glVertex3f(0.5, -0.5, 0);

		glTexCoord2f(1, 3);
		glVertex3f(0.5, 0.5, 0);

		glTexCoord2f(0, 3);
		glVertex3f(-0.5, 0.5, 0);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);
}

void drawPatten() {
	glPushMatrix();
	glTranslatef(0, 5, -15);

	glScalef(4, 4, 4);
	drawFace();

	glTranslatef(0, 0, 0.1);
	glRotatef(angle, 0, 0, 1);
	drawFace();

	glPopMatrix();
}