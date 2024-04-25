#include <GL/glut.h>

float angle = 0.0f;  // Piramidin d�nme a��s�
float xpos = 0.0f;   // Piramidin x pozisyonu
float ypos = 0.0f;   // Piramidin y pozisyonu

void init() {
    glClearColor(0.0f, 1.0f, 1.0f, 1.0f);  // Arka plan rengi siyah
    glEnable(GL_DEPTH_TEST);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glTranslatef(xpos, ypos, -5.0f);  // Piramidin pozisyonunu g�ncelle

    glRotatef(angle, 0.0f, 1.0f, 0.0f);  // Piramidi y ekseninde d�nd�r

    // Her y�zeyi farkl� renkle boyama
    glBegin(GL_TRIANGLES);

    glColor3f(1.0f, 0.0f, 0.0f);  // K�rm�z�
    glVertex3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);

    glColor3f(0.0f, 1.0f, 0.0f);  // Ye�il
    glVertex3f(0.0f, 1.0f, 0.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);

    glColor3f(0.0f, 0.0f, 1.0f);  // Mavi
    glVertex3f(0.0f, 1.0f, 0.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);

    glColor3f(1.0f, 1.0f, 0.0f);  // Sar�
    glVertex3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);

    glEnd();

    glFlush();
    glutSwapBuffers();
}

void reshape(int width, int height) {
    glViewport(0, 0, (GLsizei)width, (GLsizei)height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (GLfloat)width / (GLfloat)height, 1.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char key, int x, int y) {
    if (key == 'a')
        angle += 5.0f;
    else if (key == 'd')
        angle -= 5.0f;
    else if (key == 'w')
        ypos += 0.1f;
    else if (key == 's')
        ypos -= 0.1f;
    else if (key == 'q' || key == 27) // 'q' veya ESC tu�u
        exit(0);

    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("OpenGL Piramit Hareketi");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();

    return 0;
}
