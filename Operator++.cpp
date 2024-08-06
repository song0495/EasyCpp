#include <iostream>
using namespace std;

class Complex
{
    friend Complex operator+(Complex& temp1, Complex& temp2);
    friend Complex& operator++(Complex& complex);
    friend const Complex operator++(Complex& complex, int);
    
private:
    int m_x;
    int m_y;

public:
    Complex(int x, int y): m_x(x), m_y(y) {}
    void Print()
    {
        cout << "<" << m_x << ", " << m_y << ">" << endl;
    }
};

Complex operator+(Complex& temp1, Complex& temp2)
{
    Complex temp(temp1.m_x + temp2.m_x, 
        temp1.m_y + temp2.m_y);

    return temp;
}

Complex& operator++(Complex& complex)
{
    complex.m_x++;
    complex.m_y++;
    
    return complex;
}

const Complex operator++(Complex& complex, int)
{
    Complex temp(complex.m_x, complex.m_y);
    complex.m_x++;
    complex.m_y++;
    //注意i++和++i都区别
    
    return temp;
}

int main()
{
    Complex complex1(1, 2);
    Complex complex2(3, 4);

    Complex complex3 = complex1 + complex2;
    complex3.Print();

    ++complex3;
    complex3.Print();

    complex3++;
    complex3.Print();
}