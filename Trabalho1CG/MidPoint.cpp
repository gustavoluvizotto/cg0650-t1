/* 
 * File:   MidPoint.cpp
 * Authors: Gustavo Luvizotto Cesar
 *          Gilberto Volpe Neto
 * Created on March 23, 2013, 3:44 PM
 */

#include "MidPoint.h"
#include <GL/glut.h>

enum color { 
    preto = 0,
    azul,
    verde,
    turquesa,
    vermelho,
    magenta,
    amarelo,
    branco,
};

void MidPoint::MidPointCircleInt(int r, int color) {   
    int x, y, d;

    /* Valores iniciais */
    x = 0;
    y = r;
    d = 1 - r;
    this->CirclePoints(x, y, color);
    while (y > x) {
        if (d < 0) {
                /* Selecione E */
                d = d + 2 * x + 3;
                x++;
        }else {
                /* Selecione SE */
                d = d + 2 * (x - y) + 5;
                x++;
                y--;
        } 
        this->CirclePoints(x, y, color);
    } 
}

void MidPoint::CirclePoints(int x, int y, int color) {
    switch (color) {
        case preto:
            glColor3f(0,0,0);
            break;
        case azul:
            glColor3f(0,0,1);
            break;
        case verde:
            glColor3f(0,1,0);
            break;
        case turquesa:
            glColor3f(0,1,1);
            break;
        case vermelho:
            glColor3f(1,0,0);
            break;
        case magenta:
            glColor3f(1,0,1);
            break;
        case amarelo:
            glColor3f(1,1,0);
            break;
        case branco:
            glColor3f(1,1,1);
            break;
        default:
            glColor3f(0,0,0);
            break;
    }
    glBegin(GL_DOT3_RGB);
    glVertex2f(x/250,y/250);
    glEnd();
}