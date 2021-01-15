#include<iostream>
#include<GL/glut.h>

#include "models.h";
#include "controls.h"
#include "textures.h"

GLfloat windowW = 100;
GLfloat windowH = 100;



void init() {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	
	glEnable(GL_DEPTH_TEST);
	glGenTextures(2, texture);
	loadExternalTextures();

	glEnable(GL_CULL_FACE);
	
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);

	
}

void drawGrid() {
	GLfloat ext = 20.0f;
	GLfloat step = 1.0f;
	GLfloat yGrid = -0.4f;
	GLint line;

	glBegin(GL_LINES);
	for (line = -ext; line <= ext; line += step) {
		glVertex3f(line, yGrid, ext);
		glVertex3f(line, yGrid, -ext);

		glVertex3f(ext, yGrid, line);
		glVertex3f(-ext, yGrid, line);
	}
	glEnd();

}

void drawAxes() {

	glBegin(GL_LINES);

	glLineWidth(1.5);

	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(-20, 0, 0);
	glVertex3f(20, 0, 0);

	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(0, -20, 0);
	glVertex3f(0, 20, 0);

	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0, 0, -20);
	glVertex3f(0, 0, 20);

	glEnd();
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
	
	gluPerspective(1, 1, 10, 200);
	gluLookAt(1.0 + camX, 2.0 + camY, 5.0 + camZ, 0, 0, 0, 0, 1.0, 0);

	
	glTranslatef(moveX, moveY, moveZ);
	glRotatef(rotX, 1.0f, 0.0f, 0.0f);
	glRotatef(rotY, 0.0f, 1.0f, 0.0f);
	glRotatef(rotZ, 0.0f, 0.0f, 1.0f);
	
	drawAxes();
	glColor3f(1.0, 1.0, 1.0);
	drawGrid();

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[0]);

	wall(0, 0, 0, 3, 2, 2);
	
	glBindTexture(GL_TEXTURE_2D, texture[1]);

	wall(5, 0, 0, 20, 2, 2);


	glPopMatrix();
	glutSwapBuffers();
	glFlush();
}



void resize(GLsizei w, GLsizei h) {
	glViewport(0, 0, w, h);
	GLfloat aspectRatio = h == 0 ? w / 1 : (GLfloat)w / (GLfloat)h;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	if (w < h) {
		glOrtho(-windowW, windowW, -windowH / aspectRatio, windowH / aspectRatio, 10.0f, -10.0f);
	}
	else {
		glOrtho(-windowW * aspectRatio, windowW * aspectRatio, -windowH, windowH, 10.0f, -10.0f);
	}

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Kill House");
	glutPositionWindow(200, 200);
	glutReshapeFunc(resize);
	glutDisplayFunc(display);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);

	glutSpecialFunc(keyboardSpecial);
	glutKeyboardFunc(keyboard);

	init();
	glutMainLoop();

	return 1;
}