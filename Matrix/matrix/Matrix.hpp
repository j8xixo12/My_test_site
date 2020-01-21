#ifndef MATRIX_HPP__
#define MATRIX_HPP__

#include <iomanip>
#include <cstring>

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
        }

        Matrix(Matrix &&other) : n_rows_(other.n_rows_), n_cols_(other.n_cols_), nelement(other.nelement) {
            delete [] data;
            data = other.data;
            other.data = nullptr;
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

std::ostream & operator << (std::ostream &ostr, Matrix const &mat);
Matrix&& operator+ (Matrix &lhs, const Matrix &rhs);
Matrix&& operator+ (Matrix &&lhs, const Matrix &rhs);

#endif // MATRIX_HPP__