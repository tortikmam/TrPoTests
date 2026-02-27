#include <iostream>
#include <complex>
#include <cblas.h>
#include <cmath>
#include <cstdlib>
#include "blas_test.h"

using namespace std;

// Умножение матрицы на треугольную матрицу

void test_strmm() {
    int m = 2, n = 2;
    float alpha = 1.0f;
    
    float A[4] = {2.0f, 1.0f,
                  0.0f, 3.0f};
    
    float B[4] = {1.0f, 2.0f,
                  3.0f, 4.0f};
    
    cblas_strmm(CblasRowMajor, CblasLeft, CblasUpper, CblasNoTrans, CblasNonUnit,
                m, n, alpha, A, m, B, n);
    
}

void test_dtrmm() {
    int m = 2, n = 2;
    double alpha = 1.0;
    
    double A[4] = {2.0, 1.0,
                   0.0, 3.0};
    
    double B[4] = {1.0, 2.0,
                   3.0, 4.0};
    
    cblas_dtrmm(CblasRowMajor, CblasLeft, CblasUpper, CblasNoTrans, CblasNonUnit,
                m, n, alpha, A, m, B, n);

}

void test_ctrmm() {
    int m = 2, n = 2;
    
    complex<float> alpha(1.0f, 0.0f);
    
    complex<float> A[4] = {
        complex<float>(2.0f, 0.0f), complex<float>(1.0f, 1.0f),
        complex<float>(0.0f, 0.0f), complex<float>(3.0f, 0.0f)
    };
    
    complex<float> B[4] = {
        complex<float>(1.0f, 1.0f), complex<float>(2.0f, 2.0f),
        complex<float>(3.0f, 3.0f), complex<float>(4.0f, 4.0f)
    };
    
    cblas_ctrmm(CblasRowMajor, CblasLeft, CblasUpper, CblasNoTrans, CblasNonUnit,
                m, n, &alpha, 
                reinterpret_cast<const float*>(A), m, 
                reinterpret_cast<float*>(B), n);

}

void test_ztrmm() {
    int m = 2, n = 2;
    
    complex<double> alpha(1.0, 0.0);
    
    complex<double> A[4] = {
        complex<double>(2.0, 0.0), complex<double>(1.0, 1.0),
        complex<double>(0.0, 0.0), complex<double>(3.0, 0.0)
    };
    
    complex<double> B[4] = {
        complex<double>(1.0, 1.0), complex<double>(2.0, 2.0),
        complex<double>(3.0, 3.0), complex<double>(4.0, 4.0)
    };
    
    cblas_ztrmm(CblasRowMajor, CblasLeft, CblasUpper, CblasNoTrans, CblasNonUnit,
                m, n, &alpha, 
                reinterpret_cast<const double*>(A), m, 
                reinterpret_cast<double*>(B), n);

}