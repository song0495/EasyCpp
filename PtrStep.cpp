#include <iostream>
using namespace std;

class Parent
{
public:
    int a;

    Parent(int a)
    {
        this->a = a;
    }

    virtual void Print()
    {
        cout << "Parent: a = " << a << endl;
    }
};

class Child: public Parent
{
public:
    int b;

    Child(int a) :Parent(a) {}

    virtual void Print()
    {
        cout << "Child: a = " << a << endl;
    }
};

int main()
{
    Child arr[] = {Child(0), Child(1), Child(2)};

    Child* cp = &arr[0];
    Parent* pp = &arr[0];

    cp->Print();
    pp->Print();

    cp++;   //cp + sizeof(Child)
    pp++;   //pp + sizeof(Parent)
    //sizeof(Child) != sizeof(Parent)

    cp->Print();
    pp->Print();

    int i = 0;
    for (cp = &arr[0], i = 0; i < 3; i++, cp++)
    {
        cp->Print();
    }

    for (pp = &arr[0], i = 0; i < 3; i++, cp++)
    {
        pp->Print();
    }
}
