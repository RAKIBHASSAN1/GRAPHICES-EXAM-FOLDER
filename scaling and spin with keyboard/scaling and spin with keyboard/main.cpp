/*
 * GL04ModelTransform.cpp: Model Transform - Translation and Rotation
 * Transform primitives from their model spaces to world space.
 */
#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include <stdlib.h>

static GLfloat spin = 0;

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
	glRotatef(spin, 0.0, 0.0, 1.0);
	glColor3f(1.0, 1.0, 1.0);

	glBegin(GL_TRIANGLES);
      glVertex3f (10 , 10, 0.0);
      glVertex3f (0.0, 10, 0.0);
      glVertex3f (0.0,0, 0.0);
	glEnd();
	glFlush();
}


void init(void)
{
	glClearColor (0.0, 0.0, 0.0, 0.0);
	glOrtho(-80.0, 80.0, -80.0, 80.0, -1.0, 1.0);
}


void spe_key(int key, int x, int y)
{

	switch (key) {

		case GLUT_KEY_LEFT:
		    spin = 0;
			glScalef(2.0,2.0,2.0);
			glutPostRedisplay();
			break;

		case GLUT_KEY_RIGHT:
			spin = -5;
			glutPostRedisplay();
			break;

	  default:
			break;
	}
}


int main()
{
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (250, 250);
	glutInitWindowPosition (100, 100);
	glutCreateWindow ("Scaling");
	init();
	glutDisplayFunc(display);

	glutSpecialFunc(spe_key);

	glutMainLoop();
	return 0;   /* ANSI C requires main to return int. */
}

