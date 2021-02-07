#include<iostream>
#include<GL/glut.h>

#include "models.h";
#include "controls.h"
#include "textures.h"

GLfloat windowW = 100;
GLfloat windowH = 100;

void initLighting() {
	GLfloat L0_Ambient[] = { 0.7,0.7,0.7,1.0 };
	GLfloat L0_Diffuse[] = { 0.7,0.7,0.7,1.0 };
	GLfloat L0_Position[] = { 0,15,0,1 };

	glLightfv(GL_LIGHT0, GL_AMBIENT, L0_Ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, L0_Diffuse);
	glLightfv(GL_LIGHT0, GL_POSITION, L0_Position);

}

void init() {	
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glLoadIdentity();
	glEnable(GL_DEPTH_TEST);
	loadExternalTextures();

	glEnable(GL_CULL_FACE);

	
	glShadeModel(GL_SMOOTH);


	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);

	
}



void drawGrid() {
	GLfloat ext = 40.0f;
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
	glNormal3f(0.0, 0.0, 1.0);
	gluPerspective(1, 1, 10, 200);
	gluLookAt(-12.5 + camX, 5.5 + camY, 2.5 + camZ, 0, 0, 0, 0, 1.0, 0);

	cout << camX << " " << camY << " " << camZ<<"\n";
	cout << moveX << " " << moveY << " " << moveZ << "\n";
	cout << rotX << " " << rotY << " " << rotZ << "\n\n";


	glTranslatef(moveX, moveY, moveZ);
	glRotatef(rotX, 1.0f, 0.0f, 0.0f);
	glRotatef(rotY, 0.0f, 1.0f, 0.0f);
	glRotatef(rotZ, 0.0f, 0.0f, 1.0f);
	
	drawAxes();
	glColor3f(1.0, 1.0, 1.0);
	drawGrid();


	sideOne(25, 0, 0);
	
	glPushMatrix();
	glRotatef(180, 0, 1, 0);
	sideTwo(30, 0, -10);
	glPopMatrix();
	

	cardBoardHouse(-20,0,-19);
	
	tower(0, 0, 4);

	floor(0, 0, 0);

	outerWall(0, 0, 0);

	roof(0, 0, 0);
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
	glutInitWindowSize(800, 800);
	glutCreateWindow("Kill House");
	glutPositionWindow(200, 200);
	glutReshapeFunc(resize);
	glutDisplayFunc(display);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH| GLUT_SINGLE);

	glutSpecialFunc(keyboardSpecial);
	glutKeyboardFunc(keyboard);

	init();
	glutMainLoop();

	return 1;
}