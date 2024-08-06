#include <iostream>
using namespace std;

class Test
{
private:
    int a;

public:
    Test(int a): a(a) {
        cout << "construct" << endl;
    }
    ~Test(){
        cout << "destruct" << endl;
    }
};

void func1()
{
    Test test1(10);
}

int main()
{
    func1();
    cin.get();
}