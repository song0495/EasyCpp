#include <iostream>
using namespace std;

class A
{
private:
    int m_a;

public:
    A(int a): m_a(a) {
        cout << "A constructed" << endl;
    }

    void Print()
    {cout << "a = " << m_a << endl;}

    ~A()
    {cout << "A deconstructed" << endl;}
};

class AutoPtr
{
private:
    A* ptr;

public:
    AutoPtr(A* ptr)
    {
        cout << "ptr constructed" << endl;
        this->ptr = ptr;
    }

    ~AutoPtr()
    {
        if (ptr != nullptr)
        {
            cout << "ptr destructed" << endl;
            delete ptr;
            ptr = nullptr;
        }
    }

    A* operator->()
    {
        return ptr;
    }

    A& operator*()
    {
        return *ptr;
    }
};

int main()
{
    AutoPtr autoptr(new A(10)); 
    autoptr->Print();
    (*autoptr).Print();
}