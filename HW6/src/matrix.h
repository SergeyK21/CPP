#pragma once
#include <vector>
#include <iostream>

namespace math
{
    typedef double real;

    class Matrix
    {
    private:
        int cols_;
        int rows_;
        std::vector<real> mvec_;

    public:
        Matrix(){};

        Matrix(int rows, int cols) : cols_(cols), rows_(rows), mvec_(std::vector<real>(rows * cols)){};

        real &operator()(int row, int col);

        real operator()(int row, int col) const;

        void print();

        friend Matrix operator+(const Matrix &A, const Matrix &B);

        friend Matrix operator-(const Matrix &A, const Matrix &B);

        friend Matrix operator*(const Matrix &A, const Matrix &B);

        void operator+=(const Matrix &B);

        void operator-=(const Matrix &B);

        void operator*=(const real &r);

        friend std::ostream &operator<<(std::ostream &os, const Matrix &A);

        friend std::istream &operator>>(std::istream &is, Matrix &A);
    };

}