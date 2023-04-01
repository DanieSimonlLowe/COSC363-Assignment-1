#include "Sweep.h"
#define SWEEP_N_SLICES 8
#define SWEEP_N_POINTS 10
#define SWEEP_HEIGHT_MULT 6
#define SWEEP_MIN_WIDTH 0.1

float diff;
float bx[SWEEP_N_POINTS];
float bnx[SWEEP_N_POINTS];
float bny[SWEEP_N_POINTS];


float getDistCenter(float height) {
	return SWEEP_MIN_WIDTH + 0.5 + sin(diff + SWEEP_HEIGHT_MULT * height) / 2.0;
}


float getHeight(int point) {
	return point / (float)SWEEP_N_POINTS;
}

void initNormal() {
	for (int i = 0; i < SWEEP_N_POINTS; i++) {
		float height = getHeight(i);
		bny[i] = -SWEEP_HEIGHT_MULT * cos(diff + SWEEP_HEIGHT_MULT * height);
		bnx[i] = 2.0;
	}
}

void initCurve() {
	for (int i = 0; i < SWEEP_N_POINTS; i++) {
		float height = getHeight(i);
		bx[i] = getDistCenter(height);;
	}
}

void initializeSweep() {
	diff = 0;

}

void animateSweep() {
	diff += 0.00005;
	if (diff > 2 * M_PI) {
		diff = 0;
	}
	initNormal();
	initCurve();
}

bool sign(float a) {
	if (a <= 0) {
		return false;
	}
	else {
		return true;
	}
}

void drawSweepMain() {
	
	float vx[SWEEP_N_POINTS];
	float vy[SWEEP_N_POINTS];
	float vz[SWEEP_N_POINTS];

	float wx[SWEEP_N_POINTS];
	float wy[SWEEP_N_POINTS];
	float wz[SWEEP_N_POINTS];

	float nx[SWEEP_N_POINTS];
	float ny[SWEEP_N_POINTS];
	float nz[SWEEP_N_POINTS];

	float mx[SWEEP_N_POINTS];
	float my[SWEEP_N_POINTS];
	float mz[SWEEP_N_POINTS];
	


	for (int i = 0; i < SWEEP_N_POINTS; i++) {
		float height = getHeight(i);
		vx[i] = bx[i];
		vy[i] = height;
		vz[i] = 0;

		nx[i] = bnx[i];
		ny[i] = bny[i];
		nz[i] = 0;
	}
	glColor3f(1, 1, 1);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, TEX_ROCK);
	float angStep = (2 * M_PI) / (float)SWEEP_N_SLICES;
	for (int slice = 1; slice < (SWEEP_N_SLICES+1); slice++) {
		for (int i = 0; i < SWEEP_N_POINTS; i++) {
			wx[i] = cos(angStep) * vx[i] + sin(angStep) * vz[i];
			wy[i] = vy[i];
			wz[i] = -sin(angStep) * vx[i] + cos(angStep) * vz[i];

			
			mx[i] = cos(angStep) * nx[i] + sin(angStep) * nz[i];
			my[i] = 1;
			mz[i] = -sin(angStep) * nx[i] + cos(angStep) * nz[i];

		}
		glBegin(GL_QUAD_STRIP);
		for (int i = 0; i < SWEEP_N_POINTS; i++) {
			glNormal3f(nx[i], ny[i], nz[i]);
			glTexCoord2f((slice-1) / (float)SWEEP_N_SLICES, i / (float)SWEEP_N_POINTS);
			glVertex3f(vx[i], vy[i], vz[i]);

			glNormal3f(mx[i], my[i], mz[i]);
			glTexCoord2f(slice / (float)SWEEP_N_SLICES, i / (float)SWEEP_N_POINTS);
			glVertex3f(wx[i], wy[i], wz[i]);
		}
		glEnd();
		for (int i = 0; i < SWEEP_N_POINTS; i++) {
			vx[i] = wx[i];
			vy[i] = wy[i];
			vz[i] = wz[i];
			nx[i] = mx[i];
			ny[i] = my[i];
			nz[i] = mz[i];
		}
	}

	glDisable(GL_TEXTURE_2D);
}

void drawSweep() {
	glPushMatrix();
	glTranslatef(-15.0, 0, 0.0);
	glScalef(2, 20, 2);
	drawSweepMain();
	glPopMatrix();
}