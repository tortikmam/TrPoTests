#include <iostream>
#include <complex>
#include <cblas.h>
#include <cmath>
#include <cstdlib>
#include "blas_test.h"

using namespace std;

void test_cherk() {
    
    int n = 2, k = 2;
    float alpha = 1.0f;
    float beta = 0.0f;

    complex<float> A[4] = {
        complex<float>(1.0f, 1.0f), complex<float>(2.0f, 2.0f),
        complex<float>(3.0f, 3.0f), complex<float>(4.0f, 4.0f)
    };
    
    complex<float> C[4] = {
        complex<float>(0.0f, 0.0f), complex<float>(0.0f, 0.0f),
        complex<float>(0.0f, 0.0f), complex<float>(0.0f, 0.0f)
    };

    cblas_cherk(CblasRowMajor, CblasUpper, CblasNoTrans, 
                n, k, alpha, 
                reinterpret_cast<const float*>(A), k, 
                beta, 
                reinterpret_cast<float*>(C), n);
}

void test_zherk() {
    
    int n = 2, k = 2;
    double alpha = 1.0f;
    double beta = 0.0f;

    complex<double> A[4] = {
        complex<double>(1.0f, 1.0f), complex<double>(2.0f, 2.0f),
        complex<double>(3.0f, 3.0f), complex<double>(4.0f, 4.0f)
    };
    
    complex<double> C[4] = {
        complex<double>(0.0f, 0.0f), complex<double>(0.0f, 0.0f),
        complex<double>(0.0f, 0.0f), complex<double>(0.0f, 0.0f)
    };

    cblas_cherk(CblasRowMajor, CblasUpper, CblasNoTrans, 
                n, k, alpha, 
                reinterpret_cast<const float*>(A), k, 
                beta, 
                reinterpret_cast<float*>(C), n);
}
