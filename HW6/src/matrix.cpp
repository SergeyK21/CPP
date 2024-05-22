#include <src/matrix.h>
#include <cmath>
using namespace math;

real &Matrix::operator()(int row, int col)
{
    if (row >= this->rows_)
    {
        std::cerr << "Matrix: row number out of bounds" << std::endl;
        // return 0;
    }

    if (col >= this->cols_)
    {
        std::cerr << "Matrix: col number out of bounds" << std::endl;
        // return 0;
    }

    int pos(0);
    pos = cols_ * row + col;

    return this->mvec_.at(pos);
}

real Matrix::operator()(int row, int col) const
{
    if (row >= this->rows_)
    {
        std::cerr << "Matrix: row number out of bounds" << std::endl;
        // return 0;
    }

    if (col >= this->cols_)
    {
        std::cerr << "Matrix: col number out of bounds" << std::endl;
        // return 0;
    }

    int pos(0);
    pos = cols_ * row + col;

    return this->mvec_.at(pos);
}

void Matrix::print()
{
    for (int i = 0; i < this->rows_; i++)
    {
        for (int j = 0; j < this->rows_; j++)
        {
            std::cout << this->mvec_[this->cols_ * i + j] << "\t";
        }
        std::cout << std::endl;
    }
}
namespace math
{
    Matrix operator+(const Matrix &A, const Matrix &B)
    {
        if ((A.cols_ != B.cols_) || (A.rows_ != B.rows_))
        {
            std::cerr << "Matrix: Matrix can't be added" << std::endl;
            return Matrix(0, 0);
        }

        Matrix M(A.cols_, A.rows_);

        for (int i = 0; i < M.mvec_.size(); i++)
        {
            M.mvec_.at(i) = A.mvec_.at(i) + B.mvec_.at(i);
        }

        return M;
    }

    Matrix operator-(const Matrix &A, const Matrix &B)
    {
        if ((A.cols_ != B.cols_) || (A.rows_ != B.rows_))
        {
            std::cerr << "Matrix: Matrix can't be subtracted" << std::endl;
            return Matrix(0, 0);
        }

        Matrix M(A.cols_, A.rows_);

        for (int i = 0; i < M.mvec_.size(); i++)
        {
            M.mvec_.at(i) = A.mvec_.at(i) - B.mvec_.at(i);
        }

        return M;
    }

    Matrix operator*(const Matrix &A, const Matrix &B)
    {
        if (A.cols_ != B.rows_)
        {
            std::cerr << "Matrix: Matrices can't be multiplied" << std::endl;
            return Matrix(0, 0);
        }

        Matrix M(A.rows_, B.cols_);

        for (int pos = 0; pos < M.mvec_.size(); pos++)
        {
            int row = (int)std::floor(pos / M.cols_);
            int col = pos - row * M.cols_;

            for (int k = 0; k < A.cols_; k++)
            {
                M.mvec_.at(pos) += A(row, k) * B(k, col);
            }
        }

        return M;
    }

    void Matrix::operator+=(const Matrix &B)
    {
        if ((this->cols_ != B.cols_) || (this->rows_ != B.rows_))
        {
            std::cerr << "Matrix: Matrix can't be added" << std::endl;
        }

        for (int i = 0; i < this->mvec_.size(); i++)
        {
            this->mvec_.at(i) = this->mvec_.at(i) + B.mvec_.at(i);
        }
    }

    void Matrix::operator-=(const Matrix &B)
    {
        if ((this->cols_ != B.cols_) || (this->rows_ != B.rows_))
        {
            std::cerr << "Matrix: Matrix can't be added" << std::endl;
        }

        for (int i = 0; i < this->mvec_.size(); i++)
        {
            this->mvec_.at(i) = this->mvec_.at(i) - B.mvec_.at(i);
        }
    }

    void Matrix::operator*=(const real &r)
    {

        for (int pos = 0; pos < this->mvec_.size(); pos++)
        {
            this->mvec_.at(pos) *= r;
        }
    }

    std::ostream &operator<<(std::ostream &os, const Matrix &A)
    {
        for (int i = 0; i < A.rows_; i++)
        {
            for (int j = 0; j < A.cols_; j++)
            {
                os << A(i, j) << "  ";
            }
            os << "\n";
        }

        return os;
    }

    std::istream &operator>>(std::istream &is, Matrix &A)
    {
        for (int i = 0; i < A.rows_; i++)
        {
            std::cout << "¬ведите " << (i + 1) << " строку:" << std::endl;
            for (int j = 0; j < A.cols_; j++)
            {
                real &temp = A(i, j);
                is >> temp;
            }
        }

        return is;
    }
}
