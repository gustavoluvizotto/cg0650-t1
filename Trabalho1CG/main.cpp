/* 
 * File:   main.cpp
 * Authors: Gilberto Volpe Neto
 *          Gustavo Luvizotto Cesar
 * 
 * Created on March 22, 2013, 5:00 PM
 */

#include <cstdlib>
#include <iostream>

#include <Render.h>
#include <CartesianCircle.h>
#include <MidPoint.h>

using namespace std;

int main(int argc, char** argv) {
    
    Render render(argc,argv);
    render.start();
    
    return 0;
}

