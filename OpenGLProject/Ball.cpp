#include "Ball.h"
#define BALL_LIFESPAN 60000
#define BALL_GRAV_ACLE 0.0000004
#define BALL_FACTOR 0.3

float ballY;
float ballX;
float ballZ;
float ballVelY;
float ballVelX;
float ballVelZ;
int ballLife;

float randFloat(float range, float min) {
	return (float)rand() / (float)(RAND_MAX / range) + min;
}

void genBall() {
	ballLife = BALL_LIFESPAN;
	ballY = 1;
	ballX = 0;
	ballZ = 0;
	ballVelY = randFloat(0.002, 0.001);
	ballVelX = randFloat(0.002, -0.001);
	ballVelZ = randFloat(0.002, -0.001);
}


void initializeBall() {
	srand(time(NULL));
	genBall();
}


void animateBall() {
	ballVelY -= BALL_FACTOR*BALL_GRAV_ACLE;
	ballLife -= 1;
	if (ballLife < 0 || ballY <= 0.5) {
		genBall();
	}
	ballX += BALL_FACTOR*ballVelX;
	ballY += BALL_FACTOR*ballVelY;
	ballZ += BALL_FACTOR*ballVelZ;
}


void drawBall() {
	glPushMatrix();
	glTranslatef(15, 0, 15);
	glColor3f(0.1, 1, 0.5);
	glTranslatef(ballX, ballY, ballZ);
	glutSolidSphere(1, 10, 10);
	glPopMatrix();
}