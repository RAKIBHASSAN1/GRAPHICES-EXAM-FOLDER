Translation & Rotation
In this sample, we positioned each of the shapes by defining their vertices with respective to the same origin (called world space). 
It took me quite a while to figure out the absolute coordinates of these vertices.

Instead, we could position each of the shapes by defining their vertices with respective to their own center (called model space or local space). 
We can then use translation and/or rotation to position the shapes at the desired locations in the world space, as shown in the following revised display() function.

glMatrixMode(GL_MODELVIEW); // To operate on model-view matrix
glLoadIdentity();           // Reset

Translation and rotation are parts of so-called model transform, which transform from the objects from the local space (or model space) to the common world space. 
To carry out model transform, we set the matrix mode to mode-view matrix (GL_MODELVIEW) and reset the matrix. 

OpenGL is operating as a state machine. That is, once a state is set, the value of the state persists until it is changed. 
In other words, once the coordinates are translated or rotated, all the subsequent operations will be based on this coordinates.

Translation is done via glTranslate function:

void gltranslatef (GLfloat x, GLfloat y, GLfloat z)
   // where (x, y, z) is the translational vector

Take note that glTranslatef function must be placed outside the glBegin/glEnd, where as glColor can be placed inside glBegin/glEnd.

Rotation is done via glRotatef function:

void glRotatef (GLfloat angle, GLfloat x, GLfloat y, GLfloat z)
   // where angle specifies the rotation in degree, (x, y, z) forms the axis of rotation.
Take note that the rotational angle is measured in degrees (instead of radians) in OpenGL.

In this example, we translate within the x-y plane (z=0) and rotate about the z-axis (which is normal to the x-y plane).