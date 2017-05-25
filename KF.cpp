//
// Created by szymon on 25.05.17.
//

#include "KF.h"

using namespace std;
using namespace Eigen;

void Kalman::KF() {
    init();
    fstream out( "wynik.txt", ios::out );   // plik do zapisu przefiltrowanych danych
    Matrix<float,1,1> eps,Y,S;  // macierze pomocnicze
    VectorXf K;                 // wzmocnienie Kalmana
    Vector2f xnext, xlast;
    Matrix<float,2,2> Pnext, Plast;
    xnext << 0,0;                    // wartość początkowa filtru
    Pnext = P;
    Plast = P;
    for(int i = 0; i < sizeof(v)/sizeof(float); i++) {
        B << dt,((1-v[i-1]/v[i])/dt);   // aktualna wartosc macierzy B
        Y << x[i];
        u = v[i];
        /** aktualizacja czasu */
        xnext = A*xlast + B*u;
        Pnext = A*Plast*A.transpose() + V;
        /** aktualizacja pomiarow */
        eps = Y - C*xnext;                   // róznica miedzy wartoscia zadana a oszacowana
        S = C*Pnext*C.transpose() + W;
        K = Pnext*C.transpose()*S.inverse(); // obliczenie wzmocnienia kalmana
        xlast = xnext + K*eps;                // estymata stanu (wartosc wynikowa filtru)
        Plast = Pnext * K*S*K.transpose();
        out << xlast[0] << endl;
    }
}

void Kalman::init(){    // inicjalizacja macierzy i wektorow wejsciowych
    dt = 0.01;
    dv = 1;
    dw = 2;
    u = 0;
    A << 1, dt*dt/2, 0, 0;
    B << dt,((1-v[0]/v[1])/dt);
    C << 1,0;
    V << 5*dv*dv*dt,0,0,5*dv*dv*dt;
    W << dw*dw;
    P << 0.01,0,0,0.01;
    open(x,"polozenie.csv");
    open(v,"predkosc.csv");
}



void Kalman::open(float* dat, string name) {
    int i = 0;
    float j;
    fstream in(name, ios::in );
    if(in)
    {
        while(in){
            in >> j;
            dat[i] = j;
            i++;
        }
    }
    else
    {
        cout << "nie można otworzyć pliku" << endl;
    }
    in.close();
}
