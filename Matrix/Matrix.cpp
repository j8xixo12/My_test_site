#include <iostream>
#include <cstring>
#include <iomanip>

class Matrix {
    public:
        Matrix(size_t _n_rows, size_t _n_cols) : n_rows_(_n_rows), n_cols_(_n_cols) {
            nelement = n_rows_ * n_cols_;
            data = new double[nelement];
        }

        ~Matrix() { delete[] data; }

        Matrix(Matrix &other) : n_rows_(other.n_rows_), n_cols_(other.n_cols_), nelement(other.nelement) {
            if(this == &other) return;

            data = new double[nelement];
            memcpy(data, other.data, nelement * sizeof(double));

            std::cout << "Copy data from: " << other.data << "to " << this << std::endl;
        }

        Matrix(Matrix &&other) : n_rows_(other.n_rows_), n_cols_(other.n_cols_), nelement(other.nelement) {
            delete [] data;
            data = other.data;
            other.data = nullptr;

            std::cout << "Move data from: " << other.data << "to " << this << std::endl;
        }

        double operator() (size_t _rows, size_t _cols) const { return data[_rows * n_rows_ + _cols]; }
        double& operator() (size_t _rows, size_t _cols) { return data[_rows * n_rows_ + _cols]; }
        
        Matrix& operator+= (const Matrix& rhs) {
            for (auto i = 0; i < this->n_rows(); ++i) {
                for (auto j = 0; j < this->n_cols(); ++j) {
                    this->data[i * n_rows_ + j] += rhs.data[i * n_rows_ + j];
                }
            }
            return *this;
        }

        Matrix& operator= (Matrix&& rhs) {
            if(this == &rhs) return *this;

            this->n_rows_ = rhs.n_rows_;
            this->n_cols_ = rhs.n_cols_;
            this->nelement = rhs.nelement;
            memcpy(this->data, rhs.data, this->nelement * sizeof(double));
            rhs.data = nullptr;

            return *this;
        }
        Matrix& operator= (const Matrix& rhs) {
            if(this == &rhs) return *this;
            
            this->n_rows_ = rhs.n_rows_;
            this->n_cols_ = rhs.n_cols_;
            this->nelement = rhs.nelement;
            memcpy(this->data, rhs.data, this->nelement * sizeof(double));
            
            return *this;
        }
        size_t n_rows() const { return n_rows_; }
        size_t n_cols() const { return n_cols_; }

    private:
        size_t n_rows_;
        size_t n_cols_;
        size_t nelement;
        double *data;
};

Matrix&& operator+ (Matrix &lhs, const Matrix &rhs) {
            lhs += rhs;
            return std::move(lhs);
}
Matrix&& operator+ (Matrix &&lhs, const Matrix &rhs) {
            lhs += rhs;
            return std::move(lhs);
}
        
std::ostream & operator << (std::ostream &ostr, Matrix const &mat) {
    for (size_t i = 0; i < mat.n_rows(); ++i)
    {
        for (size_t j = 0; j < mat.n_cols(); ++j)
        {
            ostr << std::setw(3) << mat(i, j) << '\t';
        }
        ostr << std::endl;
    }

    return ostr;
}

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