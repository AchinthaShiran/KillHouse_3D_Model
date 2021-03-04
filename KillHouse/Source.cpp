#include<iostream>
#include<GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include "models.h";
#include "controls.h"
#include "textures.h"

GLfloat windowW = 100;
GLfloat windowH = 100;

void initLighting() {

	//Decalring the Ambient, Diffuse components of the LIght_0 and the position in the eye coordinate system
	GLfloat L0_Ambient[] = { 0.4, 0.4, 0.4, 1.0 };
	GLfloat L0_Diffuse[] = { 0.7, 0.7, 0.7, 1.0 };
	GLfloat L0_postion[] = { 0, 30, 4, 1.0 };

	/*glPushMatrix();
	glTranslatef(0, 30, 4);
	glutSolidSphere(1, 100, 100);
	glPopMatrix();*/

	glLightfv(GL_LIGHT0, GL_AMBIENT, L0_Ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, L0_Diffuse);
	glLightfv(GL_LIGHT0, GL_POSITION, L0_postion);


	//1
	GLfloat L1_Ambient[] = { 0.5, 0.5, 0.5, 1.0 };
	GLfloat L1_Diffuse[] = { 0.7, 0.7, 0.7, 1.0 };
	GLfloat L1_Specular[] = { 1.0, 1.0, 1.0, 1.0 }; 
	GLfloat L1_postion[] = { 0,40,4 , 1.0 };

	glLightfv(GL_LIGHT1, GL_AMBIENT, L1_Ambient);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, L1_Diffuse);
	glLightfv(GL_LIGHT1, GL_SPECULAR, L1_Specular);
	glLightfv(GL_LIGHT1, GL_POSITION, L1_postion);

	/*glPushMatrix();
	glTranslatef(0, 40, 4);
	glutSolidSphere(0.4, 100, 100);
	glPopMatrix();*/

	//Declaration of the ligt reflecting properties for the materials
	GLfloat specularReflectance[] = { 1.0, 1.0, 1.0, 1.0 };
	glMaterialfv(GL_FRONT, GL_SPECULAR, specularReflectance);
	glMateriali(GL_FRONT, GL_SHININESS, 100);


	GLfloat L_Ambient[] = { 0.9, 0.9, 0.9, 1.0 };
	GLfloat L_Diffuse[] = { 0.9, 0.9, 0.9, 1.0 };
	GLfloat L_Specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat L_SpotDirection[] = { 0.0, -1.0, 0.0 };
	

	//2
	GLfloat L2_postion[] = { 40, 22, -6, 1.0 };

	/*glPushMatrix();
	glTranslatef(40, 20, -6);
	glutSolidSphere(0.4, 100, 100);
	glPopMatrix();*/

	glLightfv(GL_LIGHT2, GL_AMBIENT, L_Ambient);
	glLightfv(GL_LIGHT2, GL_DIFFUSE, L_Diffuse);
	glLightfv(GL_LIGHT2, GL_SPECULAR, L_Specular);
	glLightfv(GL_LIGHT2, GL_POSITION, L2_postion);

	glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, L_SpotDirection);
	glLightf(GL_LIGHT2, GL_SPOT_CUTOFF, 30.0);


	//3
	GLfloat L3_postion[] = { -10, 22, 4, 1.0 };

	/*glPushMatrix();
	glTranslatef(-10, 20, 4);
	glutSolidSphere(0.4, 100, 100);
	glPopMatrix();*/

	glLightfv(GL_LIGHT3, GL_AMBIENT, L_Ambient);
	glLightfv(GL_LIGHT3, GL_DIFFUSE, L_Diffuse);
	glLightfv(GL_LIGHT3, GL_SPECULAR, L_Specular);
	glLightfv(GL_LIGHT3, GL_POSITION, L3_postion);

	glLightfv(GL_LIGHT3, GL_SPOT_DIRECTION, L_SpotDirection);
	glLightf(GL_LIGHT3, GL_SPOT_CUTOFF, 30.0);


	//4
	GLfloat L4_postion[] = {10, 22, 4, 1.0 };
	
	/*glPushMatrix();
	glTranslatef(10, 20, 4);
	glutSolidSphere(0.4, 100, 100);
	glPopMatrix();*/

	glLightfv(GL_LIGHT4, GL_AMBIENT, L_Ambient);
	glLightfv(GL_LIGHT4, GL_DIFFUSE, L_Diffuse);
	glLightfv(GL_LIGHT4, GL_SPECULAR, L_Specular);
	glLightfv(GL_LIGHT4, GL_POSITION, L4_postion);

	glLightfv(GL_LIGHT4, GL_SPOT_DIRECTION, L_SpotDirection);
	glLightf(GL_LIGHT4, GL_SPOT_CUTOFF, 30.0);

	//5
	GLfloat L5_postion[] = { -40, 22, -6, 1.0 };

	/*glPushMatrix();
	glTranslatef(-40, 20, -6);
	glutSolidSphere(0.4, 100, 100);
	glPopMatrix();*/

	glLightfv(GL_LIGHT5, GL_AMBIENT, L_Ambient);
	glLightfv(GL_LIGHT5, GL_DIFFUSE, L_Diffuse);
	glLightfv(GL_LIGHT5, GL_SPECULAR, L_Specular);
	glLightfv(GL_LIGHT5, GL_POSITION, L5_postion);

	glLightfv(GL_LIGHT5, GL_SPOT_DIRECTION, L_SpotDirection);
	glLightf(GL_LIGHT5, GL_SPOT_CUTOFF, 30.0);

	//6
	GLfloat L6_postion[] = {-40,22,16, 1.0 };

	/*glPushMatrix();
	glTranslatef(-40, 20, 16);
	glutSolidSphere(0.4, 100, 100);
	glPopMatrix();*/

	glLightfv(GL_LIGHT6, GL_AMBIENT, L_Ambient);
	glLightfv(GL_LIGHT6, GL_DIFFUSE, L_Diffuse);
	glLightfv(GL_LIGHT6, GL_SPECULAR, L_Specular);
	glLightfv(GL_LIGHT6, GL_POSITION, L6_postion);

	glLightfv(GL_LIGHT6, GL_SPOT_DIRECTION, L_SpotDirection);
	glLightf(GL_LIGHT6, GL_SPOT_CUTOFF, 30.0);

	//7
	GLfloat L7_postion[] = { 40,22,16, 1.0 };

	//glPushMatrix();
	//glTranslatef(40, 20, 16);
	//glutSolidSphere(0.4, 100, 100);
	//glPopMatrix();

	glLightfv(GL_LIGHT7, GL_AMBIENT, L_Ambient);
	glLightfv(GL_LIGHT7, GL_DIFFUSE, L_Diffuse);
	glLightfv(GL_LIGHT7, GL_SPECULAR, L_Specular);
	glLightfv(GL_LIGHT7, GL_POSITION, L7_postion);

	glLightfv(GL_LIGHT7, GL_SPOT_DIRECTION, L_SpotDirection);
	glLightf(GL_LIGHT7, GL_SPOT_CUTOFF, 30.0);

	
}


void init() {	
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glLoadIdentity();
	GLfloat globalAmbient[] = { 0.4, 0.4, 0.4, 1.0 };
	glEnable(GL_DEPTH_TEST);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glHint(GL_LINE_SMOOTH_HINT, GL_DONT_CARE);
	glEnable(GL_LINE_SMOOTH);
	glEnable(GL_BLEND);
	glEnable(GL_CULL_FACE);
	glShadeModel(GL_SMOOTH);

	//Enable the adding of lights
	glEnable(GL_LIGHTING);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

	glShadeModel(GL_SMOOTH);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, globalAmbient);

	//glEnable(GL_COLOR_MATERIAL);


	// enable the normalization of the normal vectors (converting the vector values to the range 0-1)
	glEnable(GL_NORMALIZE);
	
	loadExternalTextures();
	


/*
	glEnable(GL_DEPTH_TEST);

	
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glHint(GL_LINE_SMOOTH_HINT, GL_DONT_CARE);
	glLineWidth(2.5);
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	loadExternalTextures();

	glEnable(GL_CULL_FACE);

	
	glShadeModel(GL_SMOOTH);
	glEnable(GL_COLOR_MATERIAL);

	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);

	initLighting();
	*/
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

	//glNormal3f(0.0, 1.0, 0.0);
	
	gluPerspective(1, 1, 10, 200);

	gluLookAt(-12.5 + camX, 5.5 + camY, 2.5 + camZ, 0, 0, 0, 0, 1.0, 0);

	

	//glNormal3f(0.0, 0.0, 1.0);
	//displayx();

	

	cout <<lightX << " " << lightY << " " << lightZ<<"\n";
	//cout << moveX << " " << moveY << " " << moveZ << "\n";
	//cout << rotX << " " << rotY << " " << rotZ << "\n\n";
	

	glTranslatef(moveX, moveY, moveZ);
	glRotatef(rotX, 1.0f, 0.0f, 0.0f);
	glRotatef(rotY, 0.0f, 1.0f, 0.0f);
	glRotatef(rotZ, 0.0f, 0.0f, 1.0f);

	initLighting();

	//glPushMatrix();
	///glTranslatef(0, 0, 0);
	//displayx();
	//glPopMatrix();

	//drawAxes();
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