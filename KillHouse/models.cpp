#include<iostream>
#include<GL/glut.h>
#include "models.h"

void wall(GLfloat x, GLfloat y, GLfloat z, GLfloat w, GLfloat l, GLfloat h) {
	glBegin(GL_QUADS);

	//TOP
	glTexCoord2f(0.0,0.0); glVertex3f(x, y + h, z);
	glTexCoord2f(1.0, 0.0); glVertex3f(x, y + h, z + l);
	glTexCoord2f(1.0, 1.0); glVertex3f(x + w, y + h, z + l);
	glTexCoord2f(0.0, 1.0); glVertex3f(x + w, y + h, z);
	glEnd();

	//BOTTOM
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); glVertex3f(x, y, z);
	glTexCoord2f(1.0, 0.0); glVertex3f(x + w, y, z);
	glTexCoord2f(1.0, 1.0); glVertex3f(x + w, y, z + l);
	glTexCoord2f(0.0, 1.0); glVertex3f(x, y, z + l);
	glEnd();
	// FRONT
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); glVertex3f(x, y, z + l);
	glTexCoord2f(2.0, 0.0); glVertex3f(x + w, y, z + l);
	glTexCoord2f(2.0, 2.0); glVertex3f(x + w, y + h, z + l);
	glTexCoord2f(0.0, 2.0); glVertex3f(x, y + h, z + l);
	glEnd();
	//// BACK
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); glVertex3f(x, y, z);
	glTexCoord2f(1.0, 0.0); glVertex3f(x, y + h, z);
	glTexCoord2f(1.0, 1.0); glVertex3f(x + w, y + h, z);
	glTexCoord2f(0.0, 1.0); glVertex3f(x + w, y, z);
	glEnd();
	// LEFT
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); glVertex3f(x, y, z);
	glTexCoord2f(1.0, 0.0); glVertex3f(x, y, z + l);
	glTexCoord2f(1.0, 1.0); glVertex3f(x, y + h, z + l);
	glTexCoord2f(0.0, 1.0); glVertex3f(x, y + h, z);
	glEnd();
	//RIGHT
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); glVertex3f(x + w, y, z);
	glTexCoord2f(1.0, 0.0); glVertex3f(x + w, y + h, z);
	glTexCoord2f(1.0, 1.0); glVertex3f(x + w, y + h, z + l);
	glTexCoord2f(0.0, 1.0); glVertex3f(x + w, y, z + l);
	glEnd();
}