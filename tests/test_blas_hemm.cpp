#include <iostream>
#include <cblas.h>
#include <complex>
#include "blas_test.h"

using namespace std;

void test_chemm() {
    int m = 2, n = 2;
    complex<float> alpha(1.0f, 0.0f);
    complex<float> beta(0.0f, 0.0f);

    complex<float> A[4] = {
        {2.0f, 0.0f}, {1.0f, 2.0f},
        {1.0f, -2.0f}, {3.0f, 0.0f}
    };
    
    complex<float> B[4] = {
        {1.0f, 1.0f}, {2.0f, 2.0f},
        {3.0f, 3.0f}, {4.0f, 4.0f}
    };
    
    complex<float> C[4] = {{0,0}, {0,0}, {0,0}, {0,0}};

    cblas_chemm(CblasRowMajor, CblasLeft, CblasUpper,
                m, n, &alpha, reinterpret_cast<float*>(A), m,
                reinterpret_cast<float*>(B), n, &beta,
                reinterpret_cast<float*>(C), n);
    
}

void test_zhemm() {
    int m = 2, n = 2;
    complex<double> alpha(1.0, 0.0);
    complex<double> beta(0.0, 0.0);

    complex<double> A[4] = {
        {5.0, 0.0}, {0.0, 1.0},
        {0.0, -1.0}, {2.0, 0.0}
    };
    
    complex<double> B[4] = {
        {1.0, 0.0}, {0.0, 1.0},
        {1.0, 0.0}, {0.0, 1.0}
    };
    
    complex<double> C[4] = {{0,0}, {0,0}, {0,0}, {0,0}};

    cblas_zhemm(CblasRowMajor, CblasLeft, CblasUpper,
                m, n, &alpha, reinterpret_cast<double*>(A), m,
                reinterpret_cast<double*>(B), n, &beta,
                reinterpret_cast<double*>(C), n);

}