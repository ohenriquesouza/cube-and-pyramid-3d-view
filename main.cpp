#include <GL/glut.h>

// controle da camera
float angle = 0.0;
float distance = 5.0;
float xPosition = 0.0;

// funcoes
void display();
void drawCube();
void drawPyramid();

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0); 
    glEnable(GL_DEPTH_TEST); 
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, 800.0 / 600.0, 0.1, 100.0);
    glMatrixMode(GL_MODELVIEW); 
    glLoadIdentity();
}



void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    
    gluLookAt(0.0, 0.0, distance,  
              0.0, 0.0, 0.0,      
              0.0, 1.0, 0.0);     

   
    glTranslatef(xPosition, 0.0, 0.0);
    glRotatef(angle, 0.0, 1.0, 0.0);

    
    glPushMatrix();  
    glTranslatef(-2.0, 0.0, 0.0); 
    drawCube();
    glPopMatrix();  

    glPushMatrix();
    glTranslatef(2.0, 0.0, 0.0);  
    drawPyramid();
    glPopMatrix();

    glutSwapBuffers();
}


void specialKeys(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_LEFT:
            xPosition += 0.1;  
            break;
        case GLUT_KEY_RIGHT:
            xPosition -= 0.1;  
            break;
        case GLUT_KEY_UP:
            xPosition = 0.0;;  
            break;
    }
    glutPostRedisplay();
}


void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        angle += 5.0; 
    } else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
        distance -= 0.1; 
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH); 
    glutInitWindowSize(800, 600);
    glutCreateWindow("3D Visualization");

    init();
    glutDisplayFunc(display); 

    glutSpecialFunc(specialKeys);
    glutMouseFunc(mouse);

    glEnable(GL_DEPTH_TEST); 

    glutMainLoop();
    return 0;
}


void drawCube() {
    glColor3f(0.0f, 0.0f, 1.0f); //AZUL
    glBegin(GL_QUADS);

    // frente
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);

    // costas
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);

    // cima
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);

    // baixo
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);

    // esquerda
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);

    // direita
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, -1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);

    glEnd();
}

void drawPyramid() {
    glColor3f(1.0f, 0.0f, 0.0f); // VERMELHO
    glBegin(GL_TRIANGLES);

    // frente
    glVertex3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);

    // direita
    glVertex3f(0.0f, 1.0f, 0.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);

    //costas
    glVertex3f(0.0f, 1.0f, 0.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);

    // esquerda
    glVertex3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);

    glEnd();
}

// PQP FUNCIONOUUUUUUUUUU