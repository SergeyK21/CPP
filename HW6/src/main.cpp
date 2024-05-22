#include <src/matrix.h>
#include <iostream>

int main()
{
    math::Matrix m(3, 3);
    m(0, 0) = 1.;
    m(1, 1) = 1.;

    math::Matrix m1(3, 3);
    m1(0, 0) = 5.;
    m1(1, 1) = 5.;

    std::cout << "Matrix m is:" << std::endl;
    m.print();

    std::cout << std::endl
              << "Matrix m1 is:" << std::endl;
    m1.print();

    math::Matrix m2 = m1 + m;

    std::cout << std::endl
              << "Summ of matrices m and m1 is: " << std::endl;
    m2.print();

    math::Matrix m3 = m - m1;

    std::cout << std::endl
              << "Substract of matrices m and m1 is: " << std::endl;
    m3.print();

    std::cout << std::endl
              << "Multiplication of matrices m and m1 is:" << std::endl;

    math::Matrix m4 = m * m1;

    m4.print();

    math::Matrix m5(3, 3);

    m5 += m;

    m5 += m1;

    std::cout << std::endl
              << "Summ of matrices m5 and m and m1 is: " << std::endl;
    m5.print();

    std::cout << std::endl
              << "Multiplication of matrices m5 and 5 is:" << std::endl;

    m5 *= 5;
    m5.print();

    std::cout << "\n\n"
              << m5 << std::endl;

    std::cin >> m5;

    std::cout << "\n\n"
              << m5 << std::endl;

    return 0;
}