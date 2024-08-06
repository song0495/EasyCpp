#include <iostream>
using namespace std;

class Parent
{
private:
    int p;

public:
    Parent(int p)
    {
        cout << "parent construct" << endl;
        this->p = p;
    }

    ~Parent()
    {
        cout << "parent destruct" << endl;
    }
};

class Child: public Parent
{
private:
    int c;

public:
    Child(int p, int c): Parent(p)
    {
        cout << "child construct" << endl;
        this->c = c;
    }

    ~Child()
    {
        cout << "child destruct" << endl;
    }
};

int main()
{
    Parent p(10);
    Child c(20, 30);
}