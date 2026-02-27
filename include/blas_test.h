#ifndef BLAS_TESTS_H
#define BLAS_TESTS_H

void test_sgemm(void);
void test_dgemm(void);
void test_cgemm(void);
void test_zgemm(void);

void test_sgemmt(void);
void test_dgemmt(void);
void test_cgemmt(void);
void test_zgemmt(void);

void test_ssymm(void);
void test_dsymm(void);
void test_csymm(void);
void test_zsymm(void);

void test_chemm(void);
void test_zhemm(void);
void test_zgemm_fatal(void);

void test_cher2k(void);
void test_zher2k(void);

void test_cherk(void);
void test_zherk(void);

void test_ssyr2k(void);
void test_dsyr2k(void);
void test_csyr2k(void);
void test_zsyr2k(void);

void test_ssyrk(void);
void test_dsyrk(void);
void test_csyrk(void);
void test_zsyrk(void);

void test_strmm(void);
void test_dtrmm(void);
void test_ctrmm(void);
void test_ztrmm(void);

void test_ssymm(void);
void test_dsymm(void);
void test_csymm(void);
void test_zsymm(void);

#endif