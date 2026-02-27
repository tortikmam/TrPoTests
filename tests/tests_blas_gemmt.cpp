#include <iostream>
#include <complex>
#include <cblas.h>
#include <cmath>
#include <cstdlib>
#include "blas_test.h"

using namespace std;

// Умножение матриц с сохранением только верхней/нижней треугольной части

void test_sgemmt() {
    int n = 2, k = 2;
    float alpha = 1.0f, beta = 0.0f;

    float A[4] = {1.0f, 2.0f, 
                  3.0f, 4.0f};
    float B[4] = {5.0f, 6.0f, 
                  7.0f, 8.0f};
    float C[4] = {0.0f, 0.0f, 
                  0.0f, 0.0f};

    cblas_sgemmt(CblasRowMajor, CblasUpper, CblasNoTrans, CblasNoTrans, 
                 n, k, alpha, A, k, B, n, beta, C, n);

}

void test_dgemmt() {

    int n = 2, k = 2;
    double alpha = 1.0, beta = 0.0;

    double A[4] = {1.0, 2.0, 
                   3.0, 4.0};
    double B[4] = {5.0, 6.0, 
                   7.0, 8.0};
    double C[4] = {0.0, 0.0, 
                   0.0, 0.0};

    cblas_dgemmt(CblasRowMajor, CblasUpper, CblasNoTrans, CblasNoTrans, 
                 n, k, alpha, A, k, B, n, beta, C, n);

}

// Умножение матриц с комплексными числами (одинарная точность)
void test_cgemmt() {
    int n = 2, k = 2;
    
    complex<float> alpha(1.0f, 0.0f);
    complex<float> beta(0.0f, 0.0f);

    complex<float> A[4] = {
        complex<float>(1.0f, 1.0f), complex<float>(2.0f, 2.0f),
        complex<float>(3.0f, 3.0f), complex<float>(4.0f, 4.0f)
    };
    
    complex<float> B[4] = {
        complex<float>(5.0f, 5.0f), complex<float>(6.0f, 6.0f),
        complex<float>(7.0f, 7.0f), complex<float>(8.0f, 8.0f)
    };
    
    complex<float> C[4] = {
        complex<float>(0.0f, 0.0f), complex<float>(0.0f, 0.0f),
        complex<float>(0.0f, 0.0f), complex<float>(0.0f, 0.0f)
    };

    cblas_cgemmt(CblasRowMajor, CblasUpper, CblasNoTrans, CblasNoTrans, 
                 n, k, &alpha, 
                 reinterpret_cast<const float*>(A), k, 
                 reinterpret_cast<const float*>(B), n, 
                 &beta, 
                 reinterpret_cast<float*>(C), n);

}

void test_zgemmt() {
    
    int n = 2, k = 2;
    
    complex<double> alpha(1.0, 0.0);
    complex<double> beta(0.0, 0.0);

    complex<double> A[4] = {
        complex<double>(1.0, 1.0), complex<double>(2.0, 2.0),
        complex<double>(3.0, 3.0), complex<double>(4.0, 4.0)
    };
    
    complex<double> B[4] = {
        complex<double>(5.0, 5.0), complex<double>(6.0, 6.0),
        complex<double>(7.0, 7.0), complex<double>(8.0, 8.0)
    };
    
    complex<double> C[4] = {
        complex<double>(0.0, 0.0), complex<double>(0.0, 0.0),
        complex<double>(0.0, 0.0), complex<double>(0.0, 0.0)
    };

    cblas_zgemmt(CblasRowMajor, CblasUpper, CblasNoTrans, CblasNoTrans, 
                 n, k, &alpha, 
                 reinterpret_cast<const double*>(A), k, 
                 reinterpret_cast<const double*>(B), n, 
                 &beta, 
                 reinterpret_cast<double*>(C), n);

}
