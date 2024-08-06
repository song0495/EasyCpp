#include <iostream>
using namespace std;

class Parent1
{
private:
    int a;

public:
    Parent1(int a)
    {
        this->a = a;
    }

    void Print()
    {
        cout << a << endl;
    }
};

class Parent2
{
private:
    int a;

public:
    Parent2(int a)
    {
        this->a = a;
    }

    virtual void Print()
    {
        cout << a << endl;
    }
};

class Parent
{
private:
    int a;

public:
    Parent(int a)
    {
        this->a = a;
        cout << "Parent construct" << endl;
        Print();    //在多态时, 触发父类Print()
    }

    virtual void Print()
    {
        cout << "Parent a = " << a << endl;
    }
};

class Child: public Parent
{
private:
    int b;

public:
    Child(int a, int b) :Parent(a)
    {
        Print();    //在多态时, 触发子类Print()
        this->b = b;
        cout << "Child construct" << endl;
    }

    virtual void Print()
    {
        cout << "Child b = " << b << endl;
    }
};

int main()
{
    /*
    Parent1 p1(10);
    Parent2 p2(10);

    cout << "Parent1 size:" << sizeof(p1) << endl;
    cout << "Parent2 size:" << sizeof(p2) << endl;
    */

   Parent* child = new Child(10, 20);

   delete child;
}