#include <iostream>
using namespace std;

class Test
{
private:
    int m_a;

public:
    Test(int a)
    {
        this->m_a = a;  //  this指针指向当前对象的地址
        cout  << this->GetA() << endl;
    }

    int GetA() const    //const 修饰this指针
    {
        //this->m_a = 100;
        return this->m_a;
    }
};

int main()
{
    Test test(10);
    cout << test.GetA() << endl;
}