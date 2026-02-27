#include <iostream>
#include <complex>
#include <cblas.h>
#include <cmath>
#include <cstdlib>
#include "blas_test.h"

using namespace std;

void test_ssyrk() {
    
    int n = 2, k = 3;
    float alpha = 1.0f, beta = 0.0f;

    float A[6] = {1.0f, 2.0f, 3.0f, 
                  4.0f, 5.0f, 6.0f};
    
    float C[4] = {0.0f, 0.0f, 
                  0.0f, 0.0f};

    cblas_ssyrk(CblasRowMajor, CblasUpper, CblasNoTrans, 
                n, k, alpha, A, k, beta, C, n);
    
}

void test_dsyrk() {
    
    int n = 2, k = 3;
    double alpha = 1.0, beta = 1.0;

    double A[6] = {1.0, 2.0, 3.0, 
                   4.0, 5.0, 6.0};
    
    double C[4] = {1.0, 2.0, 
                   3.0, 4.0};

    cblas_dsyrk(CblasRowMajor, CblasLower, CblasNoTrans, 
                n, k, alpha, A, k, beta, C, n);

}

void test_csyrk() {
    
    int n = 2, k = 2;
    
    complex<float> alpha(1.0f, 0.0f);
    complex<float> beta(0.0f, 0.0f);

    complex<float> A[4] = {
        complex<float>(1.0f, 1.0f), complex<float>(2.0f, 2.0f),
        complex<float>(3.0f, 3.0f), complex<float>(4.0f, 4.0f)
    };
    
    complex<float> C[4] = {
        complex<float>(0.0f, 0.0f), complex<float>(0.0f, 0.0f),
        complex<float>(0.0f, 0.0f), complex<float>(0.0f, 0.0f)
    };

    
    cblas_csyrk(CblasRowMajor, CblasUpper, CblasNoTrans, 
                n, k, &alpha, 
                reinterpret_cast<const float*>(A), k, 
                &beta, 
                reinterpret_cast<float*>(C), n);
}

void test_zsyrk() {
    
    int n = 2, k = 2;
    
    complex<double> alpha(1.0f, 0.0f);
    complex<double> beta(0.0f, 0.0f);

    complex<double> A[4] = {
        complex<double>(1.0f, 1.0f), complex<double>(2.0f, 2.0f),
        complex<double>(3.0f, 3.0f), complex<double>(4.0f, 4.0f)
    };
    
    complex<double> C[4] = {
        complex<double>(0.0f, 0.0f), complex<double>(0.0f, 0.0f),
        complex<double>(0.0f, 0.0f), complex<double>(0.0f, 0.0f)
    };

    
    cblas_zsyrk(CblasRowMajor, CblasUpper, CblasNoTrans, 
                n, k, &alpha, 
                reinterpret_cast<const float*>(A), k, 
                &beta, 
                reinterpret_cast<float*>(C), n);
}