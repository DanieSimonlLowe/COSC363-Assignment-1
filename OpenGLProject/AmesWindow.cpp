#include "AmesWindow.h"

#define ROT_AMOUNT 0.01

float rot;

void initializeWindow() {
	rot = 0;
}


void animateWindow() {
	rot += ROT_AMOUNT;
	if (rot > 360) {
		rot = 0;
	}
}

void drawWindow() {
	glPushMatrix();
	
	glTranslatef(0, 5, 15);

	glRotatef(rot, 0, 1, 0);

	glScalef(0.2, 0.2, 0.2);
	glTranslatef(-9, 0, 0);
	glBegin(GL_QUADS);
	glColor3f(1, 0, 0);
	glVertex3d(0, 7, 0);  // right most thing
	glVertex3d(1.5, 7.5, 0);
	glVertex3d(1.5, -7.5, 0);
	glVertex3d(0, -7.5, 0);

	glVertex3d(3, 6, 0);  //TOPBIT of window.
	glVertex3d(10, 5, 0);
	glVertex3d(8.75, 4.5, 0);
	glVertex3d(3, 5.25, 0);

	glVertex3d(10, 5, 0);  //side of window.
	glVertex3d(10, 0.75, 0);
	glVertex3d(8.75, 0.75, 0);
	glVertex3d(8.75, 4.5, 0);

	glVertex3d(11, 4.8, 0);  //TOPBIT of window.
	glVertex3d(16.5, 4.1, 0);
	glVertex3d(15.5, 3.5, 0);
	glVertex3d(11, 4.1, 0);

	glVertex3d(16.5, 4, 0);  //side of window.
	glVertex3d(16.5, 0.75, 0);
	glVertex3d(15.5, 0.75, 0);
	glVertex3d(15.5, 3.5, 0);

	// bottom
	glVertex3d(3, -6, 0);  //TOPBIT of window.
	glVertex3d(10, -5, 0);
	glVertex3d(8.75, -4.5, 0);
	glVertex3d(3, -5.25, 0);

	glVertex3d(10, -5, 0);  //side of window.
	glVertex3d(10, -0.75, 0);
	glVertex3d(8.75, -0.75, 0);
	glVertex3d(8.75, -4.5, 0);

	glVertex3d(11, -4.8, 0);  //TOPBIT of window.
	glVertex3d(16.5, -4.1, 0);
	glVertex3d(15.5, -3.5, 0);
	glVertex3d(11, -4.1, 0);

	glVertex3d(16.5, -4, 0);  //side of window.
	glVertex3d(16.5, -0.75, 0);
	glVertex3d(15.5, -0.75, 0);
	glVertex3d(15.5, -3.5, 0);

	//main part.
	glColor3f(0.5, 1, 1);

	glVertex3d(1.5, 7.5, 0); // left
	glVertex3d(1.5, -7.5, 0);
	glVertex3d(3, -7, 0);
	glVertex3d(3, 7, 0);

	glVertex3d(3, 0.75, 0); // middle
	glVertex3d(18, 0.75, 0);
	glVertex3d(18, -0.75, 0);
	glVertex3d(3, -0.75, 0);
	

	glVertex3d(3, 7, 0);
	glVertex3d(3, 6, 0);
	glVertex3d(16.5, 4, 0);
	glVertex3d(18, 4, 0);

	glVertex3d(16.5, 4, 0);
	glVertex3d(18, 4, 0);
	glVertex3d(18, -4, 0);
	glVertex3d(16.5, -4, 0);

	glVertex3d(3, -7, 0);
	glVertex3d(3, -6, 0);
	glVertex3d(16.5, -4, 0);
	glVertex3d(18, -4, 0);

	
	glVertex3d(10, 5, 0);
	glVertex3d(11, 4.75, 0);
	glVertex3d(11, -4.75, 0);
	glVertex3d(10, -5, 0);
	

	glEnd();
	glPopMatrix();
}