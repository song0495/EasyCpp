#include <iostream>
using namespace std;

int get1()
{
    int a = 10;
    return a;
}   //返回 值

int& get2()
{
    int a = 10;
    return a;
}   //返回 引用

int& get3()
{
    static int a = 10;
    return a;
}

int main()
{
    int a1 = 0;
    int a2 = 0;

    a1 = get1();
    //值拷⻉

    a2 = get2();
    cout << "a2" << a2 << endl;
    /*
    将⼀个引⽤赋给⼀个变量，会有拷⻉动作
	编译器类似做了如下隐藏操作，a2 = *(getA2())
    实际上无法返回一个局部变量的ref
    */
    
    int& a3 = get2();   //error 
    //返回栈变量不能成为其它引用的初始值
 
    int& a4 = get3();
    //若返回静态变量或全局变量, 可以成为其他引用的初始值

    get2() = 100;   //返回值为引用可以当左值

    cin.get();
}