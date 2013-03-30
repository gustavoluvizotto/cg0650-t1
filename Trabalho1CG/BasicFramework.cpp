/* 
 * File:   BasicFramework.cpp
 * Author: gilvolpe
 * 
 * Created on March 29, 2013, 6:28 PM
 */

#include "BasicFramework.h"
#include "BasicCircle.h"

BasicFramework *BasicFramework::instance = 0;

void BasicFramework::setInstance(BasicFramework* basicFramework) {
    instance = basicFramework;
}

void BasicFramework::handleKeyPressWrapper(unsigned char key, int x, int y) {
    instance->handleKeyPress(key, x, y);
}

void BasicFramework::displayWrapper() {
    instance->display();
}

void BasicFramework::timerWrapper(GLint unused) {
    instance->timer(unused);
}

void BasicFramework::handleMouseWrapper(GLint state, GLint button, GLint x, GLint y) {
    instance->handleMouse(state, button, x, y);
}

void BasicFramework::handleMouseMotionWrapper(GLint x, GLint y) {
    instance->handleMouseMotion(x, y);
}

void BasicFramework::timer(GLint unused) {
    glutPostRedisplay();
    glutTimerFunc(TIME_UPDATE_MS, timerWrapper, unused);
}

void BasicFramework::setColor(GLint color) {

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
}

void BasicFramework::printstring(char *string, Point3D point, GLint color) {

    this->setColor(color);

    glRasterPos3f(point._x, point._y, point._z);
    for (char *p = string; *p; p++)
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, *p);
}

/*
 * Metodo para deixar o programa em loop
 */
void BasicFramework::start(int argc, char *argv[]) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

    // desabilita profundidade (coordenada z)
    glEnable(GL_DEPTH_TEST);

    // cor de fundo da janela: 1,1,1,1 = branco
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); //comando nao está funcionando ???

    glutInitWindowSize(sizeX, sizeY); // definindo o tamanho da tela
    glutCreateWindow("Primeiro Trabalho de Computacao Grafica");

    //Inicializa as funções necessárias ao openGL
    glutDisplayFunc(displayWrapper); // metodo que faz os desenhos
    glutKeyboardFunc(handleKeyPressWrapper);
    glutMouseFunc(handleMouseWrapper);
    glutMotionFunc(handleMouseMotionWrapper);
    glutTimerFunc(TIME_UPDATE_MS, timerWrapper, 0);

    glutMainLoop();
}

BasicFramework::BasicFramework() {

    this->sizeX = SIDE_SIZE;
    this->sizeY = SIDE_SIZE;

}

BasicFramework::~BasicFramework() {

}
