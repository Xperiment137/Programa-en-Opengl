
#include "stdafx.h"
#include <stdlib.h>
#include "GL/glut.h"
#include "windows.h"
#include <iostream>
#pragma comment(lib, "glut32.lib")
#define WINDOW_TITLE "Project"
using namespace std;
void Init();
void display();
void reshape(int width, int height);
void OnDraw(void);
void OnTimer(int value);
void OnKeyboardDown(unsigned char key, int x_t, int y_t);
void Calibrar(int x);
int main(int argc, char **argv) {
	int x;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE| GLUT_RGB|GLUT_DEPTH);
	glutInitWindowPosition(500, 500);
	glutInitWindowSize(300, 300);
	glutCreateWindow("Primer programa");
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glMatrixMode(GL_PROJECTION);
	gluPerspective(40.0, 800 / 600.0f, 0.1, 150);
	glutDisplayFunc(OnDraw);
	glutTimerFunc(25, OnTimer, 0);//ms
	glutKeyboardFunc(OnKeyboardDown);
	glutMainLoop();
	return 0;
}
void OnTimer(int value)
{

}
void OnKeyboardDown(unsigned char key, int x, int y)
{
	Calibrar(x);
	glutPostRedisplay();

}
void Init()
{
	glClearColor(0, 0, 0, 0);
}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	glColor3f(250, 200, 250);
	glBegin(GL_LINES);
	glVertex3f(0, 0, 0);
	glEnd();
	glFlush();
}
void reshape(int width, int height)
{
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1, 1, -1, 1, -1, 1);
	glMatrixMode(GL_MODELVIEW);
}
void OnDraw(void)
{
	int largo = 100;
	int ancho = 100;
	int i = 0;
	int j = 0;
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(7.0 ,2.0, 0,   3.0, 0, -1.0,      0.0, 1.0, 0.0);//ojo,observador,eje
	
	glFrontFace(GL_CW);
	glBegin(GL_TRIANGLES);
	for (i = 0; i < 100; i++)
	{
		for (int j = 0; j < ancho; j++) {
			for (int i = 0; i < largo; i++) {
				float x = (float(i) / (10 - 1)) * 2.0f - 1.0f;
				float z = (float(j) / (10 - 1)) * 2.0f - 1.0f;
				glColor3ub(0, 255, 0);
				glVertex3f(x, 0, z);
				glColor3ub(0,0, 250);
				glVertex3f(x, z, 0);
				glutPostRedisplay();
			}
		}
	}
	glEnd();
	glutSwapBuffers();
}
void Calibrar(int x)
{
	glutWireCube(x);
}

