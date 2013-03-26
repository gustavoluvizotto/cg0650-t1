/* 
 * File:   Render.cpp
 * Authors: Gilberto Volpe Neto
 *          Gustavo Luvizotto Cesar
 * Created on March 22, 2013, 5:10 PM
 */

/*
 *      R G B Valor Binario     Cor
 *      0 0 0 0                 preto
 *      0 0 1 1                 azul
 *      0 1 0 2                 verde
 *      0 1 1 3                 turquesa
 *      1 0 0 4                 vermelho
 *      1 0 1 5                 magenta
 *      1 1 0 6                 amarelo
 *      1 1 1 7                 branco
 */

#include "Render.h"
#include "basicInformation.h"

/*
 * Construtor para definir tamanho da tela, modo de apresentacao, cor do fundo,
 * e desenho na tela
 * 
 */
Render::Render(int argc, char **argv) {

    this->sizeX = SIDE_SIZE;
    this->sizeY = SIDE_SIZE;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

    // desabilita profundidade (coordenada z)
    glEnable(GL_DEPTH_TEST);

    // cor de fundo da janela: 1,1,1,1 = branco
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); //comando nao está funcionando ???

    glutInitWindowSize(sizeX, sizeY); // definindo o tamanho da tela
    glutCreateWindow("Primeiro Trabalho de Computacao Grafica");

    glutDisplayFunc(drawScene); // metodo que faz os desenhos
    glutKeyboardFunc(handleKeyPress);
}

/*
 * Metodo para desenhar na tela
 */
void Render::drawScene() {

    static int value = 0;
    static bool end = false;

    static Point3D point[6];
    point[0]._x = scale(270);
    point[1]._y = scale(270);
    point[2]._z = scale(270);

    point[3]._x = scale(-120);
    point[3]._z = scale(0);
    point[3]._y = scale(-340);
    point[4] = point[3];
    point[4]._y = scale(-360);
    point[5] = point[3];
    point[5]._y = scale(-380);

    static char strings[6][100];
    strcpy(strings[0], "X");
    strcpy(strings[1], "Y");
    strcpy(strings[2], "Z");
    strcpy(strings[3], "CARTESIAN");
    strcpy(strings[4], "POLAR");
    strcpy(strings[5], "INTEGER");

    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

#ifdef _3D_
    glRotatef(-45.0f, 0.0f, 1.0f, 0.0f);
    glRotatef(-45.0f, 0.0f, 0.0f, 1.0f);
    glTranslatef(scale(10),scale(10),scale(10));
    vertex();
#else    
    grid();
#endif

    if (value < 250 && !end) {
        drawCircle(value);
        value++;

        if (value == 250) {
            value--;
            end = true;
        }
    } else {
        if (value >= 0 && end) {
            drawCircle(value);
            value--;
            if (value == -1) {
                value++;
                end = false;
            }
        }
    }

    for (GLint i = 0; i < 6; i++) {
        printstring(strings[i], point[i], i);
    }

    glutSwapBuffers();
}

void Render::vertex() {

    glBegin(GL_LINES);

    //x
    glColor3f(0, 0, 1);
    glVertex3f(-1, 0, 0);
    glVertex3f(1, 0, 0);
    //y
    glColor3f(0, 1, 0);
    glVertex3f(0, -1, 0);
    glVertex3f(0, 1, 0);
    //z
    glColor3f(1, 0, 0);
    glVertex3f(0, 0, -1);
    glVertex3f(0, 0, 1);

    glEnd();

    return;
}

/*
 * funcao que desenha uma malha na tela
 */
void Render::grid() {

    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);

    /*
     * Desenha uma grade para melhor visualização dos
     * pontos na tela
     */
    for (GLint i = -250; i <= 250; i += 5) {
        GLfloat point = scale(i);
        glVertex2f(point, -1);
        glVertex2f(point, 1);
        glVertex2f(-1, point);
        glVertex2f(1, point);
    }

    glEnd();


    return;
}

void Render::drawCircle(GLint value) {

    static SizeRadiusDraw radius2Draw;

    CartesianCircle cartesian(radius2Draw.sizeCartesian[value]);
    PolarCircle polar(radius2Draw.sizePolar[value]);
    MidPoint mid(radius2Draw.sizeMidPoint[value]);

    cartesian.work();
    polar.work();
    mid.work();
}

void Render::timer(GLint unused) {
    glutPostRedisplay();
    glutTimerFunc(30, timer, 0);
}

void Render::handleKeyPress(unsigned char key, int x, int y) {
    switch (key) {
        case 27:
            exit(0);
            break;
    }
}

void Render::printstring(char *string, Point3D point, GLint color) {

    switch (color) {
        case 0:
            glColor3f(0.0f, 0.0, 1.0f);
            break;
        case 1:
            glColor3f(0.0f, 1.0, 0.0f);
            break;
        case 2:
            glColor3f(1.0f, 0.0, 0.0f);
            break;
        case 3:
            glColor3f(0.0f, 1.0, 1.0f);
            break;
        case 4:
            glColor3f(1.0f, 1.0, 0.0f);
            break;
        case 5:
            glColor3f(1.0f, 0.0, 1.0f);
            break;
        default:
            glColor3f(1.0f, 1.0f, 1.0f);
            break;
    }

    glRasterPos3f(point._x, point._y, point._z);
    for (char *p = string; *p; p++)
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, *p);
}

/*
 * Metodo para deixar o programa em loop
 */
void Render::start() {
    glutTimerFunc(30, timer, 0);
    glutMainLoop();
}

Render::Render(const Render& orig) {
}

Render::~Render() {
}
