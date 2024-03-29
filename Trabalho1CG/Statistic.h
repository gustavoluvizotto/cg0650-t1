/* 
 * File:   Statistic.h
 * Authors: Gilberto Volpe Neto
 *          Gustavo Luvizotto Cesar
 *
 * Created on April 1, 2013, 1:14 PM
 */

#ifndef STATISTIC_H
#define	STATISTIC_H

#include "basicInformation.h"

#include <unistd.h>
#include <sys/times.h>
#include <ctime>
#include <vector>

//#define PL_PLOT_GRAPH
#ifdef PL_PLOT_GRAPH
#include "plplot/plplot.h"
#endif

#define NUMBERS_OF_POINTS 250

class Statistic {
public:

    Statistic(char *type);
    Statistic(const Statistic& orig);
    virtual ~Statistic();

    void showStatistic();
    void plotStatistic(int op);
    void startCounter();
    void stopCounter();
    void getTime(char *state);
    void setRadius(int radius);
    //clock_t elapsedTime();
    long double elapsedTime();

#ifdef PL_PLOT_GRAPH
    void makeTestStatistical();
#endif

private:
    //struct tms oldTimer, newTimer;
    long double oldTimer, newTimer;
    vector<long double> data2Analisys[NUMBERS_OF_POINTS];

    int vectorPosition;
    long double variance[NUMBERS_OF_POINTS];
    long double standardDeviantion[NUMBERS_OF_POINTS];
    long double average[NUMBERS_OF_POINTS];

    char type[10];
#ifdef PL_PLOT_GRAPH
    //para fazer a reta dos minimos quadrados
    long double aLS, bLS;

    void calcLeastSquareArrow();
    PLFLT calcPointLeastSquareArrow(PLINT x);
    PLFLT calcPointLeastSquareArrow(PLFLT x);


#endif

    //clock_t timeSub();
    void setData(); // insere elapsedTime em vectorPosition de data2Analisys[]
    void mean();
    void stdDeviationAndVar();

};

#endif	/* STATISTIC_H */

