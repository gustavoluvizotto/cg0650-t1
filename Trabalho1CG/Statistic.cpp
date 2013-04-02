/* 
 * File:   Statistic.cpp
 * Authors: Gilberto Volpe Neto
 *          Gustavo Luvizotto Cesar
 * 
 * Created on April 1, 2013, 1:14 PM
 */

#include "Statistic.h"

Statistic::Statistic(char *type) {
    for (int i = 0; i < NUMBERS_OF_POINTS; i++)
        variance[i] = standardDeviantion[i] = average[i] = 0;
    strcpy(this->type, type);
}

Statistic::Statistic(const Statistic& orig) {
}

Statistic::~Statistic() {
}

void Statistic::getTime(char *state) {
    struct timeval time;
    gettimeofday(&time, NULL);
    if (!strcmp(state, "new")) {
        newTimer = time.tv_sec * 1000000 + time.tv_usec;
        setData();
    } else
        oldTimer = time.tv_sec * 1000000 + time.tv_usec;
}

void Statistic::startCounter() {
    //    times(&oldTimer);
    return;
}

void Statistic::stopCounter() {
    //    times(&newTimer);
    //    setData();
    return;
}

/*
clock_t Statistic::timeSub() {
    clock_t sub;
    sub = (newTimer.tms_stime + newTimer.tms_utime) - (oldTimer.tms_stime - oldTimer.tms_utime);
    //    cout << sub << endl;
    return sub;
}
 */

//clock_t Statistic::elapsedTime() {

long double Statistic::elapsedTime() {
    //return timeSub();
    return (newTimer - oldTimer);
}

void Statistic::setData() {
    //data2Analisys[vectorPosition - 1].push_back((long double) elapsedTime() / CLOCKS_PER_SEC);
    data2Analisys[vectorPosition - 1].push_back((long double) elapsedTime());
    return;
}

void Statistic::mean() {
    int i;

    vector<long double>::iterator it;
    for (i = 0; i < 250; i++) {
        for (it = data2Analisys[i].begin(); it != data2Analisys[i].end(); it++)
            average[i] += *it;
        average[i] = (long double) average[i] / (data2Analisys[i].size());
    }
    return;
}

void Statistic::stdDeviationAndVar() {
    int i;

    vector<long double>::iterator it;
    for (i = 0; i < 250; i++) {
        for (it = data2Analisys[i].begin(); it != data2Analisys[i].end(); it++)
            standardDeviantion[i] = pow(*it - average[i], 2);
        standardDeviantion[i] = (long double) standardDeviantion[i] / data2Analisys[i].size();
        variance[i] = standardDeviantion[i];
        standardDeviantion[i] = sqrt(standardDeviantion[i]);
    }
    return;
}

void Statistic::showStatistic() {
    int width = 15;
    mean();
    stdDeviationAndVar();
    cout << "Radius  " << "Average   " << "Standard Deviation   " << "Variance" << endl;
    cout << "----------------------------------------------------" << endl;
    for (int i = 0; i < NUMBERS_OF_POINTS; i++)
        cout << i + 1 << setw(width) << average[i] << setw(width)
        << standardDeviantion[i] << setw(width) << variance[i] << endl;
}

#define NUMPONTOS 200
#define XMIN  -10
#define XMAX   10
#define YMIN  -1.0
#define YMAX   1.0

void Statistic::plotStatistic() {
    PLFLT x[NUMPONTOS + 1]; /* Vetor com os pontos do eixo x */
    PLFLT y[NUMPONTOS + 1]; /* Vetor com os pontos do eixo y */
    PLFLT z[NUMPONTOS + 1], w[NUMPONTOS + 1];
    PLINT i;

    double min = 999999999999999;
    double max = 0;

    for (i = 0; i < NUMPONTOS; i++) {
        x[i] = (PLFLT) (i + 1);
        y[i] = (PLFLT) average[i];
        z[i] = (PLFLT) standardDeviantion[i];
        w[i] = (PLFLT) variance[i];
        if (y[i] < min)
            min = y[i];
        if (y[i] > max)
            max = y[i];
    }
    plinit();


    plenv(0, NUMPONTOS, min, max, 0, -1);
    plpoin(NUMPONTOS, x, y, '.');
    pllab("Radius", "Average", "Trabalho 1 - Computacao Grafica");

    plenv(0, NUMPONTOS, min, max, 0, -1);
    plpoin(NUMPONTOS, x, z, '.');
    pllab("Radius", "Std. Dev.", "Trabalho 1 - Computacao Grafica");

    plenv(0, NUMPONTOS, min, max, 0, -1);
    plpoin(NUMPONTOS, x, w, '.');
    pllab("Radius", "Var.", "Trabalho 1 - Computacao Grafica");

    plend();
    return;
}

void Statistic::setRadius(int radius) {
    vectorPosition = radius;
    return;
}