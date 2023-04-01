#include "Camera.h"
#define WATCH1_X 15
#define WATCH1_Y 2
#define WATCH1_Z 0

#define WATCH2_X 0
#define WATCH2_Y 2
#define WATCH2_Z 15

#define WATCH3_X 0
#define WATCH3_Y 2
#define WATCH3_Z -15
#define DISPLAY_DIST 1000

#define SPIN_AMOUNT 0.00001
#define WATCHING_HIGHT 10
#define WATCHING_DIST 10

#define ROAM_ANGLE_MOVE 1
#define ROAM_MOVE 0.3

#define ANGLE_CONV (2*M_PI/ 360.0)

enum State {
	ROAM,
	WATCH1,
	WATCH2,
	WATCH3
};

State state;
glm::vec3 position;
double spinAngle;
float lookAngle;

void keyInput(unsigned char key, int x, int y) {
	if (key == '0') {
		state = ROAM;
	}
	else if (key == '1') {
		state = WATCH1;
	}
	else if (key == '2') {
		state = WATCH2;
	}
	else if (key == '3') {
		state = WATCH3;
		
	}
	glutPostRedisplay();
}

void specialInput(int key, int x, int y) {
	if (key == GLUT_KEY_LEFT) {
		lookAngle -= ROAM_ANGLE_MOVE;
		if (lookAngle < 0) {
			lookAngle = 360;
		}
	}
	else if (key == GLUT_KEY_RIGHT) {
		lookAngle += ROAM_ANGLE_MOVE;
		if (lookAngle > 360) {
			lookAngle = 0;
		}
	}
	else if (key == GLUT_KEY_DOWN) {
		position.x -= cos(lookAngle * ANGLE_CONV) * ROAM_MOVE;
		position.z -= sin(lookAngle * ANGLE_CONV) * ROAM_MOVE;
	}
	else if (key == GLUT_KEY_UP) {
		position.x += cos(lookAngle* ANGLE_CONV) * ROAM_MOVE;
		position.z += sin(lookAngle* ANGLE_CONV) * ROAM_MOVE;
	}
}


void initializeCamera(double posx, double posy, double posz) {
	position.x = posx;
	position.y = posy;
	position.z = posz;
	state = ROAM;
	spinAngle = 0;
	lookAngle = 0;

	glutKeyboardFunc(keyInput);
	glutSpecialFunc(specialInput);

	gluPerspective(50.0, 1.0, 10.0, 1000.0);
	
}

void displayCamera() {
	if (state == ROAM) {
		//TODO implent looking direction from vectors
		glRotatef(lookAngle, 0, 1, 0);
		gluLookAt(position.x, position.y, position.z, position.x+10, position.y, position.z, 0, 1, 0);
		
	}
	else {
		glm::vec3 looking;
		if (state == WATCH1) {
			looking = glm::vec3(WATCH1_X, WATCH1_Y, WATCH1_Z);
		}
		else if (state == WATCH2) {
			looking = glm::vec3(WATCH2_X, WATCH2_Y, WATCH2_Z);
		}
		else {
			looking = glm::vec3(WATCH3_X, WATCH3_Y, WATCH3_Z);
		}
		float posX = looking.x + sin(spinAngle) * WATCHING_DIST;
		float posZ = looking.z + cos(spinAngle) * WATCHING_DIST;
		float posY = looking.y + WATCHING_HIGHT;
		//float posX = looking.x;
		//float posY = looking.y+10;
		//float posZ = looking.z+20;
		gluLookAt(posX, posY, posZ, looking.x, looking.y, looking.z, 0, 1, 0);
	}
	

}


void animateCamrea() {
	spinAngle += SPIN_AMOUNT;
	if (spinAngle > M_PI * 2) {
		spinAngle = 0;
	}
}

