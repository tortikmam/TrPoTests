#include <iostream>
#include <functional>
#include <vector>
#include <string>
#include "blas_test.h"

using namespace std;

void run_test(const string& test_name, function<void()> test_func) {
    cout << "[ RUN      ] " << test_name << endl;
    try {
        test_func();
        cout << "[       OK ] " << endl;
    } catch (const exception& e) {
        cerr << "[  FAILED  ] " << " | Error: " << e.what() << endl;
    } catch (...) {
        cerr << "[  FAILED  ] " << " | Unknown error!" << endl;
    }
    cout << "------------------------------------" << endl;
}

int main(){

    cout << "Starting BLAS Laboratory Tests..." << endl;
    cout << "------------------------------------" << endl;

    run_test("SGEMM", test_sgemm);
    run_test("DGEMM", test_dgemm);
    run_test("CGEMM",  test_cgemm);
    run_test("ZGEMM",  test_zgemm);
    run_test("ZGEMM_FATAL", test_zgemm_fatal);
    
    run_test("SGEMMT", test_sgemmt);
    run_test("DGEMMT", test_dgemmt);
    run_test("CGEMMT",  test_cgemmt);
    run_test("ZGEMMT",  test_zgemmt);

    run_test("CHEMM", test_chemm);
    run_test("ZHEMM", test_zhemm);

    run_test("CHER2K", test_cher2k);
    run_test("ZHER2K", test_zher2k);

    run_test("CHERK", test_cherk);
    run_test("ZHERK", test_zherk);

    run_test("SSYR2K", test_ssyr2k);
    run_test("DSYR2K", test_dsyr2k);
    run_test("CSYR2K",  test_csyr2k);
    run_test("ZSYR2K",  test_zsyr2k);

    run_test("SSYMM", test_ssymm);
    run_test("DSYMM", test_dsymm);
    run_test("CSYMM",  test_csymm);
    run_test("ZSYMM",  test_zsymm);

    run_test("SSYRK", test_ssyrk);
    run_test("DSYRK", test_dsyrk);
    run_test("CSYRK",  test_csyrk);
    run_test("ZSYRK",  test_zsyrk);
    
    run_test("STRMM", test_strmm);
    run_test("DTRMM", test_dtrmm);
    run_test("CTRMM",  test_ctrmm);
    run_test("ZTRMM",  test_ztrmm);

    cout << "All tests completed." << endl;
    return 0;
}