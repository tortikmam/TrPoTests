#include <iostream>
#include <complex>
#include <cblas.h>

using namespace std;

void test_cher2k() {
    int n = 2, k = 2;
    float alpha = 1.0f;  // комплексный! но в BLAS передается как два float
    float beta = 0.0f;

    // Для комплексного alpha нужно передавать {real, imag}
    float alpha_array[2] = {1.0f, 0.0f};
    float beta_array[2] = {0.0f, 0.0f};

    complex<float> A[4] = {
        {1.0f, 1.0f}, {2.0f, 2.0f},
        {3.0f, 3.0f}, {4.0f, 4.0f}
    };
    
    complex<float> B[4] = {
        {5.0f, 5.0f}, {6.0f, 6.0f},
        {7.0f, 7.0f}, {8.0f, 8.0f}
    };
    
    complex<float> C[4] = {0};

    cblas_cher2k(CblasRowMajor, CblasUpper, CblasNoTrans, 
                 n, k, alpha_array, 
                 reinterpret_cast<const float*>(A), k, 
                 reinterpret_cast<const float*>(B), k, 
                 beta,
                 reinterpret_cast<float*>(C), n);
}

void test_zher2k() {
    int n = 2, k = 2;
    double alpha[2] = {1.0, 0.0};
    double beta = 0.0;

    complex<double> A[4] = {
        {1.0, 1.0}, {2.0, 2.0},
        {3.0, 3.0}, {4.0, 4.0}
    };
    
    complex<double> B[4] = {
        {5.0, 5.0}, {6.0, 6.0},
        {7.0, 7.0}, {8.0, 8.0}
    };
    
    complex<double> C[4] = {0};

    cblas_zher2k(CblasRowMajor, CblasUpper, CblasNoTrans, 
                 n, k, alpha, 
                 reinterpret_cast<const double*>(A), k, 
                 reinterpret_cast<const double*>(B), k, 
                 beta, 
                 reinterpret_cast<double*>(C), n);
}