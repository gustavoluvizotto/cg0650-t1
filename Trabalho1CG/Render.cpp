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
#include <GL/glut.h>
//#include <iostream>
//#include <cstdlib>

Render::Render(const Render& orig) {
}

Render::~Render() {
}

/*
 * Construtor para definir tamanho da tela, modo de apresentacao, cor do fundo,
 * e desenho na tela
 * 
 */
Render::Render(int argc, char **argv) {

    this->sizeX = 500;
    this->sizeY = 500;

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    
    // desabilita profundidade (coordenada z)
    glDisable(GL_DEPTH_TEST);      
    // cor de fundo da janela: 1,1,1,1 = branco
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);        

    glutInitWindowSize(sizeX, sizeY);           // definindo o tamanho da tela
    glutCreateWindow("Primeiro Trabalho de Computacao Grafica");

    glutDisplayFunc(drawScene);                 // metodo que faz os desenhos
    glutKeyboardFunc(handleKeyPress);

}

/*
 * Metodo para desenhar na tela
 */
void Render::drawScene() {
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    grid();
//    glBegin(GL_LINES);
//        glColor3f(1, 0, 0);
//        glVertex2f(0, 0);
//        glVertex2f(1, 1);
//    glEnd();
        
    glutSwapBuffers();
}

/*
 * funcao que desenha uma malha na tela
 */
void Render::grid() {
    int i, j, inc = 10;
    
    glBegin(GL_LINES);
    glColor3f(1, 0, 0);
    i = -(250);         // tamanho minimo em X
    // desenhando a malha na vertical
    while (i < 250) {
        glVertex2f(i/250,-1);
        glVertex2f(i/250,1);
        i += inc;
    }
    j = -(250);         // tamanho minimo em Y
    // desenhando a malha na horizontal
    while (j < 250) {
        glVertex2f(-1,j/250);
        glVertex2f(1,j/250);
        j += inc;
    }
    glEnd();
    
    return;
}

void Render::handleKeyPress(unsigned char key, int x, int y) {
    switch (key) {
        case 27:
                exit(0);
        break;
    }
}

/*
 * Metodo para deixar o programa em loop
*/
void Render::start() {
    glutMainLoop();
}