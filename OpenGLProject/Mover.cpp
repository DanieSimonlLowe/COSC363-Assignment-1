#include "Mover.h"
#define LEG_CYCLE_SIZE 20000
#define ARM_CYCLE_SIZE 500000
#define POS_X 1
#define POS_Y 0
#define POS_Z 0

#define LEG_LENGTH 2
#define LEG_WIDTH 0.4
#define MAX_LEG_ANGLE 50

#define ARM_WIDTH 0.2
#define MAX_ARM_LENGTH 5

#define ANGLE_CONV (2*M_PI/ 360.0)

#define BODY_RAD 0.8

unsigned int legStep;
unsigned int armStep;

void initializeMover() {
	legStep = 0;
	armStep = 0;

	
	glEnable(GL_LIGHT1);
	float white[] = { 1.0,1.0,1.0,1.0 };
	glLightfv(GL_LIGHT1, GL_DIFFUSE, white);
	
}



void animateMover() {
	legStep += 1;
	if (legStep > LEG_CYCLE_SIZE) {
		legStep = 0;
	}
	armStep += 1;
	if (armStep > ARM_CYCLE_SIZE) {
		armStep = 0;
	}
}

double getLegAngle() {
	double angle = 0;
	if (legStep < LEG_CYCLE_SIZE / 2) {
		angle = legStep / (LEG_CYCLE_SIZE / 2.0) * MAX_LEG_ANGLE;
	}
	else {
		angle = (LEG_CYCLE_SIZE - legStep) / (LEG_CYCLE_SIZE / 2.0) * MAX_LEG_ANGLE;
	}
	return angle;
}

void drawTopLeg() {
	double angel = getLegAngle();
	glTranslated(-sin(ANGLE_CONV*angel)*LEG_LENGTH, cos(ANGLE_CONV * angel) * LEG_LENGTH,0);
	glRotated(-angel, 0, 0, 1);
	glTranslated(LEG_WIDTH / 2, LEG_LENGTH / 2, 0);
	glScaled(LEG_WIDTH, LEG_LENGTH, LEG_WIDTH);
	glutSolidCube(1.0);
}

void drawBottomLeg() {
	glRotated(getLegAngle(), 0, 0, 1);
	glTranslated(LEG_WIDTH / 2, LEG_LENGTH / 2, 0);
	glScaled(LEG_WIDTH, LEG_LENGTH, LEG_WIDTH);
	glutSolidCube(1.0);
}

void drawLeg() {
	glPushMatrix();
	drawTopLeg();
	glPopMatrix();
	glPushMatrix();
	drawBottomLeg();
	glPopMatrix();
}

float getArmLength() {
	float len = 0;
	if (armStep < ARM_CYCLE_SIZE / 2) {
		len = armStep / (ARM_CYCLE_SIZE / 2.0) * MAX_ARM_LENGTH;
	}
	else {
		len = (ARM_CYCLE_SIZE - armStep) / (ARM_CYCLE_SIZE / 2.0) * MAX_ARM_LENGTH;
	}
	return len;
}

void arm() {
	float len = getArmLength();
	
	glPushMatrix();
	glTranslatef(len/2-0.5, 0, 0);
	glScalef(len, ARM_WIDTH, ARM_WIDTH);
	glutSolidCube(1.0);
	glPopMatrix();

	float spotdir[] = { 0.0, -2.0, 0.0 };
	float lpos[] = { len, 0.0, 0, 1.0 };
	glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 60.0);
	glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 15.0);
	glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, spotdir);
	glLightfv(GL_LIGHT1, GL_POSITION, lpos);
}

void drawBody() {
	glPushMatrix();
	

	double angel = getLegAngle();
	glTranslated(0.5, 2*cos(ANGLE_CONV * angel) * LEG_LENGTH, 0);
	glutSolidSphere(BODY_RAD, 10, 10);
	glColor3f(2.0, 0.2, 0.2);
	glTranslated(BODY_RAD, 0, 0);
	arm();
	glPopMatrix();
}



void drawMover() {
	glPushMatrix();
	glTranslatef(15, 0, 0);
	glRotatef(90, 0, 1, 0);

	glPushMatrix();
	glColor3f(1.0, 0.2, 0.2);
	drawLeg();
	
	glRotated(180, 0, 1, 0);
	glTranslated(-1, 0, 0);
	drawLeg();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.2, 0.7, 1.0);
	drawBody();
	glPopMatrix();
	glPopMatrix();
}
