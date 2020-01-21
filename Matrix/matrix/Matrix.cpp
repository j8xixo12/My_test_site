#include "Matrix.hpp"

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