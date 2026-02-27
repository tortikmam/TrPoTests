#include <iostream>
#include <complex>
#include <cblas.h>
#include <cmath>
#include <cstdlib>
#include "blas_test.h"

using namespace std;

// Умножение где одна матрица симметрична, а другая нет (одинарная точность)
void test_ssymm() {
    
    int m = 3, n = 2;
    float alpha = 1.0f, beta = 0.0f;
    

    float A[9] = {1.0f, 2.0f, 3.0f,
                  2.0f, 4.0f, 5.0f,
                  3.0f, 5.0f, 6.0f};
    
    float B[6] = {1.0f, 2.0f,
                  3.0f, 4.0f,
                  5.0f, 6.0f};
    
    float C[6] = {0};

    cblas_ssymm(CblasRowMajor, CblasLeft, CblasUpper,
                m, n, alpha, A, 3, B, 2, beta, C, 2);

}

void test_dsymm() {
    
    int m = 3, n = 2;
    double alpha = 1.0, beta = 0.0;
    
    double A[9] = {1.0, 2.0, 3.0,
                   2.0, 4.0, 5.0,
                   3.0, 5.0, 6.0};

    double B[6] = {1.0, 2.0,
                   3.0, 4.0,
                   5.0, 6.0};
    
    double C[6] = {0};

    cblas_dsymm(CblasRowMajor, CblasLeft, CblasUpper,
                m, n, alpha, A, 3, B, 2, beta, C, 2);

}

void test_csymm() {
    
    int m = 2, n = 2;
    
    complex<float> alpha(1.0f, 0.0f);
    complex<float> beta(0.0f, 0.0f);

    complex<float> A[4] = {
        complex<float>(1.0f, 1.0f), complex<float>(2.0f, 2.0f),
        complex<float>(2.0f, 2.0f), complex<float>(3.0f, 3.0f)
    };
    
    complex<float> B[4] = {
        complex<float>(1.0f, 0.0f), complex<float>(2.0f, 0.0f),
        complex<float>(3.0f, 0.0f), complex<float>(4.0f, 0.0f)
    };
    
    complex<float> C[4] = {
        complex<float>(0.0f, 0.0f), complex<float>(0.0f, 0.0f),
        complex<float>(0.0f, 0.0f), complex<float>(0.0f, 0.0f)
    };

    cblas_csymm(CblasRowMajor, CblasLeft, CblasUpper,
                m, n, &alpha, 
                reinterpret_cast<const float*>(A), m, 
                reinterpret_cast<const float*>(B), n, 
                &beta, 
                reinterpret_cast<float*>(C), n);

}


void test_zsymm() {
    
    int m = 2, n = 2;
    
    complex<double> alpha(1.0, 0.0);
    complex<double> beta(0.0, 0.0);

    complex<double> A[4] = {
        complex<double>(1.0, 1.0), complex<double>(2.0, 2.0),
        complex<double>(2.0, 2.0), complex<double>(3.0, 3.0)
    };
    
    complex<double> B[4] = {
        complex<double>(1.0, 0.0), complex<double>(2.0, 0.0),
        complex<double>(3.0, 0.0), complex<double>(4.0, 0.0)
    };
    
    complex<double> C[4] = {
        complex<double>(0.0, 0.0), complex<double>(0.0, 0.0),
        complex<double>(0.0, 0.0), complex<double>(0.0, 0.0)
    };

    cblas_zsymm(CblasRowMajor, CblasLeft, CblasUpper,
                m, n, &alpha, 
                reinterpret_cast<const double*>(A), m, 
                reinterpret_cast<const double*>(B), n, 
                &beta, 
                reinterpret_cast<double*>(C), n);

}
