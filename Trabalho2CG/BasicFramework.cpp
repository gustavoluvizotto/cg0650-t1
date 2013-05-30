/* 
 * File:   BasicFramework.cpp
 * Author: gilvolpe
 * 
 * Created on March 29, 2013, 6:28 PM
 */

#include "BasicFramework.h"

BasicFramework *BasicFramework::instance = 0;

void BasicFramework::setInstance(BasicFramework* basicFramework) {
    instance = basicFramework;
}

void BasicFramework::handleKeyPressWrapper(unsigned char key, int x, int y) {
    instance->handleKeyPress(key, x, y);
}

void BasicFramework::handleKeyPressWrapperNumber(int key, int x, int y) {
    instance->handleKeyPressNumber(key, x, y);
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

void BasicFramework::doSomethingInTimerWrapper() {
    instance->doSomethingInTime();
}

void BasicFramework::timer(GLint unused) {
    doSomethingInTimerWrapper();
    glutPostRedisplay();
    glutTimerFunc(TIME_UPDATE_MS, timerWrapper, unused);
}

/*
 * Metodo para deixar o programa em loop
 */
void BasicFramework::start(int argc, char *argv[]) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

    glutInitWindowSize(sizeX, sizeY); // definindo o tamanho da tela
    glutCreateWindow("Segundo Trabalho de Computacao Grafica");
    glutInitWindowPosition(0,0);
    
    //Inicializa as funções necessárias ao openGL
    glutDisplayFunc(displayWrapper); // metodo que faz os desenhos
    glutIdleFunc(displayWrapper);
    glutKeyboardFunc(handleKeyPressWrapper);
    glutSpecialFunc(handleKeyPressWrapperNumber);
    glutMouseFunc(handleMouseWrapper);
    glutMotionFunc(handleMouseMotionWrapper);
    glutTimerFunc(TIME_UPDATE_MS, timerWrapper, 0);

    int screen_width=SIDE_SIZE; // We obtain the new screen width values and store it
    int screen_height=SIDE_SIZE; // Height value
    
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_SMOOTH);
    
    glViewport(0,0,screen_width,screen_height); 
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f,(GLfloat)screen_width/(GLfloat)screen_height,10.0f,10000.0f);
    
    glEnable(GL_DEPTH_TEST);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glEnable(GL_TEXTURE_2D);
      
    glutMainLoop();
}

BasicFramework::BasicFramework() {
    this->sizeX = SIDE_SIZE;
    this->sizeY = SIDE_SIZE;
}

BasicFramework::~BasicFramework() {

}
