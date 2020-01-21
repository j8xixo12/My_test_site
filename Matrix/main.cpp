#include "Matrix.hpp"
#include <iostream>

int main(int argc, char *argv[]) {
    Matrix A(3, 3);
    Matrix B(3, 3);
    Matrix C(3, 3);

    for (auto i = 0; i < A.n_rows(); ++i) {
        for (auto j = 0; j < A.n_cols(); ++j) {
            A(i, j) = i * 10.0 + j;
        }
    }

    for (auto i = 0; i < B.n_rows(); ++i) {
        for (auto j = 0; j < B.n_cols(); ++j) {
            B(i, j) = i * 20.0 + j;
        }
    }

    for (auto i = 0; i < C.n_rows(); ++i) {
        for (auto j = 0; j < C.n_cols(); ++j) {
            C(i, j) = i * 30.0 + j;
        }
    }

    std::cout << "A = B + C + A + A + A:" << std::endl;
    A = B + C + A + A + A;
    for (auto i = 0; i < A.n_rows(); ++i) {
        for (auto j = 0; j < A.n_cols(); ++j) {
        }
    }
    std::cout << A;
    return 0;
}