#include <iostream>
#include <string>
using namespace std;

typedef void(func)(void);

void func1(void)
{
    cout << "func1" << endl;
}

void func2(void)
{
    cout << "func2" << endl;
}

void func3(void)
{
    cout << "func3" << endl;
}

struct Test
{
public:
    int id;
    string name;
    func* function;
};

void func_use(Test* test)
{
    cout << "id = " << test->id << " " << "name: " << test->name << endl;
    test->function();
}

Test* init_test(int id, string str, func* function)
{
    cout << "init begin" << endl;
    Test* temp = new Test;
    
    /*
    Test* temp = (Test*)malloc(sizeof(Test));
    malloc无法给string类型开辟空间, 只能使用new
    */

    temp->id = id;
    temp->name = str;
    temp->function = function;  
    cout << "init success" << endl;

    return temp;
}
void destory_test(Test* test)
{
    if (test != nullptr)
    {
        delete test;
        test = nullptr;
    } 
    cout << "destory success" << endl;
}

int main()
{
    Test* test1 = init_test(1, "ab", func1);
    Test* test2 = init_test(2, "bc", func2);
    Test* test3 = init_test(3, "cd", func3);

    func_use(test1);
    func_use(test2);
    func_use(test3);

    destory_test(test1);
    destory_test(test2);
    destory_test(test3);
}