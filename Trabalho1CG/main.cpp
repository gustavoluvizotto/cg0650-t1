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
#include <MidPoint.h>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    Render render(argc,argv);
    MidPoint mp;
    
    mp.MidPointCircleInt(10, 3);
    render.start();
    
    return 0;
}

