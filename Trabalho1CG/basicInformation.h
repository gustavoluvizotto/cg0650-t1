/* 
 * File:   basicInformation.h
 * Author: gilvolpe
 *
 * Created on March 25, 2013, 2:36 PM
 */

#ifndef BASICINFORMATION_H
#define	BASICINFORMATION_H

#include <GL/glut.h>
#include <unistd.h>
#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

GLfloat scale(GLint number);

struct Point2D {
    GLfloat _x, _y;

    Point2D(GLint x = 0, GLint y = 0) {
        _x = scale(x);
        _y = scale(y);
    }
};

typedef struct Point2D Point2D;

struct SizeRadiusDraw {
    GLint sizeCartesian[250], sizePolar[250], sizeMidPoint[250];

    SizeRadiusDraw() {
        GLint random;
        for (GLint i = 0; i < 250; i++) {
            this->sizeCartesian[i] = i + 1;
            this->sizePolar[250 - (i + 1)] = i + 1;

            do {
                bool flag = true;
                random = (GLint) (rand() % 250 + 1);
                for (GLint j = 0; j < i && flag; j++) {
                    if (random == this->sizeMidPoint[j])
                        flag = false;
                }
            } while (!true);

            this->sizeMidPoint[i] = random;
        }
    }
};

typedef struct SizeRadiusDraw SizeRadiusDraw;


#endif	/* BASICINFORMATION_H */

