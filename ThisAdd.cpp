#include <iostream>
using namespace std;

class Test
{
private:
    int m_a;
    int m_b;

public:
    Test(int a, int b)
        :m_a(a), m_b(b){}

    void Print()
    {
        cout << m_a << " " << m_b << endl;
    }

    Test& TestAdd(Test& another)    //函数返回引⽤
    {
        this->m_a += another.m_a;
        this->m_b += another.m_b;

        return *this;   //*操作让this指针回到元素状态
    }
};

int main()
{
    Test test1(10, 20);
    Test test2(30, 40);

    Test test3 = test1.TestAdd(test2).TestAdd(test2);

    test3.Print();
}