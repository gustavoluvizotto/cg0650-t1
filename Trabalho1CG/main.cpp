/* 
 * File:   main.cpp
 * Authors: Gilberto Volpe Neto
 *          Gustavo Luvizotto Cesar
 * 
 * Created on March 22, 2013, 5:00 PM
 */

#include <cstdlib>
#include <iostream>

#include "BasicFramework.h"
#include "Render.h"

using namespace std;

int main(int argc, char** argv) {
    
    BasicFramework *basic = new RenderCircles();
    basic->setInstance(basic);
    
    basic->start(argc,argv);
    
    return 0;
}

