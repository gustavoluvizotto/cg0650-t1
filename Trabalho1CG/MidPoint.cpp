/* 
 * File:   MidPoint.cpp
 * Authors: Gustavo Luvizotto Cesar
 *          Gilberto Volpe Neto
 * Created on March 23, 2013, 3:44 PM
 */

#include "MidPoint.h"

MidPoint::MidPoint() {
}

MidPoint::MidPoint(const MidPoint& orig) {
}

MidPoint::~MidPoint() {
}

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
    
}