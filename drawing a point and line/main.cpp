#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, includes glu.h and gl.h

//<<<<<<<<<<<<<<<<<<<<<<< myInit >>>>>>>>>>>>>>>>>>>>
void myInit(void)
{
glClearColor(1.0,1.0,1.0,0.0); // set white background color
glColor3f(0.0f, 0.0f, 0.0f); // set the drawing color
glPointSize(3.0); // a �dot� is 4 by 4 pixels
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}
//<<<<<<<<<<<<<<<<<<<<<<<< myDisplay >>>>>>>>>>>>>>>>>
void myDisplay(void)
{
glClear(GL_COLOR_BUFFER_BIT); // clear the screen

glBegin(GL_POINTS);
glVertex2i(150, 130); // draw three points

glEnd();
//glFlush(); // send all output to display

glBegin(GL_LINES);        //drwaing line
		glVertex2i(10,10);
		glVertex2i(100,100);
	glEnd();

	glFlush();
}
//<<<<<<<<<<<<<<<<<<<<<<<< main >>>>>>>>>>>>>>>>>>>>>>
int main(int argc, char** argv)
{
glutInit(&argc, argv); // initialize the toolkit
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // set display mode
glutInitWindowSize(640,480); // set window size
glutInitWindowPosition(100, 150); // set window position on screen
glutCreateWindow("Drawing Points"); // open the screen window
glutDisplayFunc(myDisplay); // register redraw function
myInit();
glutMainLoop(); // go into a perpetual loop
return 0;
}
