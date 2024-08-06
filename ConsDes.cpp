#include <iostream>
using namespace std;

class Test
{
private:
    int m_x;
    int m_y;

public:
    Test(int x, int y)
    {
        cout << "constructed" << endl;
        m_x = x;
        m_y = y;
    }

    ~Test()
    {
        cout << "destructed" << endl;
    }

    Test(const Test& another)
    {
        cout << "copied" << endl;
        m_x = another.m_x;
        m_y = another.m_y;
    }
};

void func1(Test test)    //Test test = t1 调用了拷贝构造函数
{
    cout << "func1 begin" << endl;
    Test t2 = test;
    cout << "func1 end" << endl;
}

Test func2()
{
    cout << "func2 begin" << endl;
    Test temp(10, 20);
    cout << "func2 end" << endl;
    
    return temp;
}   //返回一个匿名变量, 匿名变量 = temp, 触发拷贝构造

int main()
{
    cout << "main begin" << endl;

    //Test t1(10, 20);
    //func1(t1);

    //func2();  //无接收, 匿名变量析构
    //Test t2 = func2();  //有接收, 且不触发拷贝构造 

    Test t1(10, 20);
    t1 = func2();
    cout << "main end" << endl;
}