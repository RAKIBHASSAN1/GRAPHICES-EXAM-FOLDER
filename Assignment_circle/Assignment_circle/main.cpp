#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include <stdlib.h>
#include<math.h>

#define RED 1
#define GREEN 2
#define BLUE 3
#define ORANGE 4
#define QUIT 5

static int obj = GREEN;

static GLfloat spin = 0.0;
static float	tx	=  0.0;
static float	ty	=  0.0;

void my_menu(int item) {
	if (item == QUIT)
    exit(0);
  obj = item;
  glutPostRedisplay();
}

void display(void)
{
    float ss;
    glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.0);
	glRotatef(spin, 0.0, 0.0, 1.0);
	glPushMatrix();
	glTranslatef(tx,ty,0);
	glBegin(GL_POLYGON);



    for(int i=0;i<360;i++)
    {
        if(i<180)
            {
                switch (obj) {
                    case RED :
                        glColor3f(1.0, 0.0, 0.0);
                         break;

                    case GREEN :
                        glColor3f(0.0, 1.0, 0.0);
                        break;

                    case BLUE :
                        glColor3f(0.0, 0.0, 1.0);
                        break;

                    case ORANGE :
                        glColor3f(1.0, 0.5, 0.5);
                         break;

                    case QUIT :
                         exit(0);
                         break;
                    }
            }
        else
           {
                glColor3f(1.0, 0.0, 0.0);
           }
        ss=i*3.1416/180;
        glVertex2f(20*cos(ss),20*sin(ss));
    }
    glEnd();
    glPopMatrix();
	glFlush();
}

void spinDisplay_left(void)
{
  spin = 1;
			glutPostRedisplay();
			glRotatef(spin, 0.0, 0.0, 1.0);
}

void spinDisplay_right(void)
{
   spin = -1;
			glutPostRedisplay();
			glRotatef(spin, 0.0, 0.0, 1.0);
}

void init(void)
{
	glClearColor (1.0, 1.0, 1.0, 1.0);
	glOrtho(-80.0, 80.0, -80.0, 80.0, -1.0, 1.0);
}

void my_keyboard(unsigned char key, int x, int y)
{

	switch (key) {

        case 'l':
            tx -=5;
            glutPostRedisplay();
            break;

		case 'r':
            tx +=5;
            glutPostRedisplay();
            break;

        case 'u':
            ty +=5;
            glutPostRedisplay();
            break;

		case 'd':
            ty -=5;
            glutPostRedisplay();
            break;

		case 's':
			 glutIdleFunc(NULL);
			 break;

        case 'm':
            glutIdleFunc(spinDisplay_left);
         break;
      case 'n':
			glutIdleFunc(spinDisplay_right);
         break;

	  default:
			break;
	}
}

void spe_key(int key, int x, int y)
{

	switch (key) {
        case GLUT_KEY_UP:
		    spin = 0;
			glScalef(2.0,2.0,2.0);
			glutPostRedisplay();
			break;

        case GLUT_KEY_DOWN:
		    spin = 0;
			glScalef(0.5,0.5,0.5);
			glutPostRedisplay();
			break;

        case GLUT_KEY_LEFT:
			spin = +5;
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
	glutInitWindowSize (550, 350);
	glutInitWindowPosition (100, 100);
	glutCreateWindow ("Translation and Mouse Functions");
	init();
	glutCreateMenu(my_menu);
	glutAddMenuEntry("Red",RED);
	glutAddMenuEntry("Blue",BLUE);
	glutAddMenuEntry("Green",GREEN);
	glutAddMenuEntry("Orange",ORANGE);
	glutAddMenuEntry("Quit", QUIT);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutDisplayFunc(display);
	glutKeyboardFunc(my_keyboard);
	glutSpecialFunc(spe_key);
	glutMainLoop();
	return 0;   /* ANSI C requires main to return int. */
}


