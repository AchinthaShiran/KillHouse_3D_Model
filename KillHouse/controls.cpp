#include<iostream>
#include<GL/glut.h>
#include "controls.h"

 GLfloat camY = 0.0f;
 GLfloat camX = 0.0f;
 GLfloat camZ = 0.0f;

 GLfloat rotX = 0.0f;
 GLfloat rotY = 0.0f;
 GLfloat rotZ = 0.0f;

 GLfloat moveX = 0.0f;
 GLfloat moveY = 0.0f;
 GLfloat moveZ = 0.0f;

void keyboardSpecial(int key, int x, int y) {
	if (key == GLUT_UP) {
		camY += 0.5;
	}
	if (key == GLUT_DOWN) {
		camZ--;
	}
	glutPostRedisplay();

}

void keyboard(unsigned char key, int x, int y) {
	//move
	if (key == 's') {
		moveY += 0.5;
	}
	if (key == 'w') {
		moveY-= 0.5;
	}
	if (key == 'a') {
		moveX += 0.5;
	}
	if (key == 'd') {
		moveX -= 0.5;
	}
	if (key == 'g') {
		moveZ += 0.5;
	}
	if (key == 'h') {
		moveZ -= 0.5;
	}

	//rotate
	if (key == 'k') {
		rotX += 0.5;
	}
	if (key == 'i') {
		rotX -= 0.5;
	}
	if (key == 'j') {
		rotY += 0.5;
	}
	if (key == 'l') {
		rotY -= 0.5;
	}
	if (key == '[') {
		rotZ += 0.5;
	}
	if (key == ']') {
		rotZ -= 0.5;
	}

	//camera
	if (key == '4') {
		camX += 0.5;
	}
	if (key == '6') {
		camX -= 0.5;
	}
	if (key == '8') {
		camY += 0.5;
	}
	if (key == '2') {
		camY -= 0.5;
	}
	if (key == '+') {
		camZ += 0.5;
	}
	if (key == '-') {
		camZ -= 0.5;
	}

	glutPostRedisplay();
}