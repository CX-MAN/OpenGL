// OpenGLTest.cpp: 主项目文件。

#include "stdafx.h"
#include<stdlib.h>
#include"glut.h"
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,1.0,1.0);
	glLoadIdentity();
	gluLookAt(0, 0,2, 0, 0, 0, 0, 1, 0);
	glScalef(1,1,1);
	glutWireCube(1.0);
	glFlush();


}
void init()
{
	glClearColor(0.0, 0.0, 0.0,0.0);
	glShadeModel(GL_FLAT);
}
void reshape(int w,int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei) h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-1,1,-1,1,1.5,20);
	glMatrixMode(GL_MODELVIEW);
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Hello");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}