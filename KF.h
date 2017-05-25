//
// Created by szymon on 25.05.17.
//
#include <iostream>
#include <eigen3/Eigen/Dense>   // biblkioteka pozwalajaca na operacje na macierzach
#include <fstream>

using namespace std;
using namespace Eigen;

#ifndef KALMAN_KF_H
#define KALMAN_KF_H



class Kalman{
private:
    float dt;  // podstawa czasu
    float u;      // jednoelementowy wektor u
    /** MODEL UKLADU W PRZESTRZENI STANOW **/
    Matrix<float, 2, 2> A;  // macierz stanu dla wektora X
    Vector2f B;             // macierz stanu dla wektora u
    RowVector2f C;
    /** SZUMY I MACIERZE KOWARIANCJI **/
    float dv = 1;           // szum procesowy
    float dw = 2;           // szum pomiarowy
    Matrix<float, 2, 2> V;  // macierze kowariancji szumow
    Matrix<float, 1, 1> W;
    Matrix<float,2,2> P;   // macierz kowariancji wyznaczonej estymacji x
    float x[2000];               // tablica z pomiarami x i v
    float v[2000];
public:
    void init();
    void KF();
    void open(float* dat, string name);
};


#endif //KALMAN_KF_H
