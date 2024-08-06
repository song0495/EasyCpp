#include <iostream>
using namespace std;

class A 
{
    friend int Sum(A& a);   //  友元函数
    friend class B; //  友元类
private:
    int m_x;
    int m_y;

public:
    A(int x, int y):m_x(x), m_y(y){}

    void PrintA()
    {
        cout << "a = " << m_x << endl;
    }
};

class B
{
private:
    int m_x;

public:
    B(int x):m_x(x){}

    void PrintA(const A& another)
    {
        cout << "a = " << another.m_x << endl;
    }
};

int Sum(A& a)
{
    return a.m_x + a.m_y;
}

int main()
{
    A a(10, 20);
    B b(20);

    b.PrintA(a);
    cout << Sum(a) << endl;
}