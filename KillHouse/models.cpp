#include<iostream>
#include<GL/glut.h>
#include "models.h"

void wall(GLfloat x, GLfloat y, GLfloat z, GLfloat w, GLfloat l, GLfloat h) {
	glBegin(GL_QUADS);

	//TOP
	glColor3f(1.0, 1.0, 0.5);
	glVertex3f(x, y + h, z);
	glVertex3f(x, y + h, z + l);
	glVertex3f(x + w, y + h, z + l);
	glVertex3f(x + w, y + h, z);

	//BOTTOM
	glColor3f(0.5, 1.0, 1.0);
	glVertex3f(x, y, z);
	glVertex3f(x + w, y, z);
	glVertex3f(x + w, y, z + l);
	glVertex3f(x, y, z + l);

	// FRONT
	glColor3f(1.0, 0.5, 0.5);
	glVertex3f(x, y, z + l);
	glVertex3f(x + w, y, z + l);
	glVertex3f(x + w, y + h, z + l);
	glVertex3f(x, y + h, z + l);

	//// BACK
	glColor3f(1.0f, 0.5f, 1.0f);
	glVertex3f(x, y, z);
	glVertex3f(x, y + h, z);
	glVertex3f(x + w, y + h, z);
	glVertex3f(x + w, y, z);

	// LEFT
	glColor3f(0.5, 1.0, 0.5);
	glVertex3f(x, y, z);
	glVertex3f(x, y, z + l);
	glVertex3f(x, y + h, z + l);
	glVertex3f(x, y + h, z);

	//RIGHT
	glColor3f(0.5, 0.5, 1.0);
	glVertex3f(x + w, y, z);
	glVertex3f(x + w, y + h, z);
	glVertex3f(x + w, y + h, z + l);
	glVertex3f(x + w, y, z + l);
	glEnd();
}