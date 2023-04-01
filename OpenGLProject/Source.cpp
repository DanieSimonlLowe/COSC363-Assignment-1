/*  =================================================================
*  COSC363: Computer Graphics (2023);  University of Canterbury.
*
*  FILE NAME: Teapot.cpp
*  A very basic OpenGL program to display a teapot
*  =================================================================*/

#include <GL/freeglut.h>
#include "Camera.h"
#include <time.h>
#include "Mover.h"
#include "AmesWindow.h"
#include "Floor.h"
#include "MoirePattern.h"
#include "Sweep.h"
#include "Ball.h"

#include "Textures.h"

#define TIMER_DELAY 100



void timer(int value) {
	animateCamrea();
	animateMover();
	animateWindow();
	animatePatten();
	animateSweep();
	animateBall();
	glutPostRedisplay();
	glutTimerFunc(TIMER_DELAY, timer, 0);
}

//==================================================================
// This is the main display module containing OpenGL function calls  for
// rendering a scene.  This function is registered as a display callback
// using 'glutDisplayFunc()'   in main().

void display(void)
{
	float lpos[4] = { 60., 40., 60.0, 1.0 };  //light's position

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//gluLookAt(0, 2, 11, 0, 0, 0, 0, 1, 0);		//Camera position and orientation
	displayCamera();

	glLightfv(GL_LIGHT0, GL_POSITION, lpos);		//Set light's position

	

	drawFloor();
	drawMover();
	drawPatten();
	drawWindow();
	drawSweep();
	drawBall();


	glFlush();
	glutTimerFunc(TIMER_DELAY, timer, 0);
}

//==================================================================
//  Initialize function:
//  Used for initializing OpenGL state (lighting, color material, depth test etc.)

void initialize(void)
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);   //Background color

	initializeTexures();

	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);
	glEnable(GL_LIGHTING);					//Enable OpenGL states
	glEnable(GL_LIGHT0);


	glEnable(GL_COLOR_MATERIAL);

	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glMatrixMode(GL_PROJECTION);			//The projection matrix of the camera
	glLoadIdentity();

	

	initializeCamera(0, 5, 0);
	initializeMover();
	initializeWindow();
	initializeFloor();
	initializeSweep();
	initializeBall();
	initializePatten();
}


//==================================================================
//  The Main function: 
//  Initializes glut window and registers callbacks

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_DEPTH);	//Buffers used for display  
	glutInitWindowSize(600, 600);					//Display window size in pixels
	glutInitWindowPosition(0, 0);					//Window's position w.r.t top-left corner of screen
	glutCreateWindow("Teapot");						//Title of the window
	initialize();									//A user defined function for initialising OpenGL parameters
	glutDisplayFunc(display);						//Register 'display()'  as a callback function
	glutMainLoop();									//Enter an infinite loop, waiting for events.
	//Do not place any code here!
	return 0;
}
