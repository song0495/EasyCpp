#include <iostream>
using namespace std;

class Complex
{
    friend istream& operator>>(istream& is, Complex& temp);
    friend ostream& operator<<(ostream& os, Complex& temp);
    
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

istream& operator>>(istream& is, Complex& temp)
{
    cout << "x: ";
    is >> temp.m_x;
    cout << "y: ";
    is >> temp.m_y;

    return is;
}

ostream& operator<<(ostream& os, Complex& temp)
{
    os << "<" << temp.m_x << ", " << temp.m_y << ">";

    return os;
}

int main()
{
    Complex complex(1, 2);
    cin >> complex;
    cout << complex << endl;
}