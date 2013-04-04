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
    
#ifdef PL_PLOT_GRAPH
    calcLeastSquareArrow();
#endif
    
    cout << "Radius  " << "Average   " << "Standard Deviation   " << "Variance" << endl;
    cout << "------------------------------------------------" << endl;
    for (int i = 0; i < NUMBERS_OF_POINTS; i++)
        cout << i + 1 << setw(width) << average[i] << setw(width) << standardDeviantion[i] << setw(width) << variance[i] << endl;

#ifdef PL_PLOT_GRAPH
    cout << "Equation of Least Mean Square" << endl;
    cout << "y = " << aLS << " + " << bLS << "x" << endl;
    cout << "------------------------------------------------" << endl;
#endif
}

#ifdef PL_PLOT_GRAPH
void Statistic::plotStatistic(int op) {

    vector<PLFLT> X_LS; /* Vetor com os pontos do eixo x */
    vector<PLFLT> Y_LS; /* Vetor com os pontos do eixo y */
    PLINT i;

    PLFLT x[NUMBERS_OF_POINTS];
    PLFLT y[NUMBERS_OF_POINTS];

    double min = INFINITY;
    double max = 0;

    for (i = 0; i < NUMBERS_OF_POINTS; i++) {
        x[i] = (PLFLT) (i + 1);
        y[i] = (PLFLT) average[i];
        if (y[i] < min)
            min = y[i];
        if (y[i] > max)
            max = y[i];
    }

    for (PLFLT x_d = 0.0f; x_d < NUMBERS_OF_POINTS * 4; ) {
        X_LS.push_back(x_d);
        Y_LS.push_back(calcPointLeastSquareArrow(x_d));
        x_d = x_d + 0.01f;
    }

    PLINT size = X_LS.size();
    PLFLT x_LS[size];
    PLFLT y_LS[size];
    
    for(int j=0; j< size;j++){
        x_LS[j] = X_LS[j];
        y_LS[j] = Y_LS[j];
    }
    
    plsdev("png"); //para gerar files.png
    switch (op) {
        case 0:
            plsfnam("graphics/cartesian");
            break;
        case 1:
            plsfnam("graphics/polar");
            break;
        case 2:
            plsfnam("graphics/midpoint");
            break;
        default:
            plsfnam("anything");
            break;
    }
    plinit();

    plcol0(15);
    plenv(0, NUMBERS_OF_POINTS, min, max, 0, 1);

    switch (op) {
        case 0:
            pllab("Radius", "Average (us)", "Cartesian");
            plcol0(2); //yellow
            plpoin(NUMBERS_OF_POINTS, x, y, '.');
            plcol0(3); //green
            plline(size, x_LS, y_LS);
            break;
        case 1:
            pllab("Radius", "Average (us)", "Polar");
            plcol0(2); //yellow
            plpoin(NUMBERS_OF_POINTS, x, y, '.');
            plcol0(3); //green
            plline(size, x_LS, y_LS);
            break;
        case 2:
            pllab("Radius", "Average (us)", "MidPoint");
            plcol0(2); //yellow
            plpoin(NUMBERS_OF_POINTS, x, y, '.');
            plcol0(3); //green
            plline(size, x_LS, y_LS);
            break;
        default:
            pllab("Radius", "Average (us)", "Trabalho 1 - Computacao Grafica");
            plpoin(NUMBERS_OF_POINTS, x, y, '.');
            plline(size, x_LS, y_LS);
            break;
    }

    plend();
    return;
}

PLFLT Statistic::calcPointLeastSquareArrow(PLINT x) {
    return (aLS + bLS * x);
}

PLFLT Statistic::calcPointLeastSquareArrow(PLFLT x) {
    return (aLS + bLS * x);
}

void Statistic::calcLeastSquareArrow() {

    long double y_mean = 0;
    long double x_mean = 0;
    for (int i = 0; i < NUMBERS_OF_POINTS; i++) {
        y_mean += average[i];
        x_mean += (long double) i + 1;
    }

    y_mean /= NUMBERS_OF_POINTS;
    x_mean /= NUMBERS_OF_POINTS;

    long double half = x_mean;
    long double den = 0, num = 0;
    for (int i = 0; i < NUMBERS_OF_POINTS; i++) {
        long double xi_xmean;
        xi_xmean = (i + 1) - half;
        den += pow(xi_xmean, 2);
        num += (xi_xmean)*(average[i] - y_mean);
    }

    bLS = (long double) num / den;
    aLS = y_mean - bLS*half;
}

void Statistic::makeTestStatistical() {

    PLFLT x[] = {139, 126, 90, 144, 163, 136, 61, 62, 41, 120}; /* Vetor com os pontos do eixo x */
    PLFLT y[] = {122, 114, 86, 134, 146, 107, 68, 117, 71, 98}; /* Vetor com os pontos do eixo y */
    PLINT i;

    for (int i = 0; i < 10; i++) {
        cout << x << "   " << y << endl;
    }

    long double y_mean = 0;
    long double x_mean = 0;
    for (int i = 0; i < 10; i++) {
        y_mean += y[i];
        x_mean += x[i];
    }

    y_mean /= 10;
    x_mean /= 10;

    long double a = 0, b = 0;
    long double half = x_mean;
    long double den = 0, num = 0;
    for (int i = 0; i < 10; i++) {
        long double xi_xmean;
        xi_xmean = x[i] - half;
        den += pow(xi_xmean, 2);
        num += (xi_xmean)*(y[i] - y_mean);
    }

    cout << num << endl;
    cout << den << endl;
    cout << half << endl;
    b = (long double) num / den;
    a = y_mean - b*half;

    cout << y_mean << endl;
    cout << b << endl;
    cout << a << endl;

}
#endif

void Statistic::setRadius(int radius) {
    vectorPosition = radius;
    return;
}
