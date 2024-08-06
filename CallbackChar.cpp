#include <iostream>
#include <string>
#include <string.h>
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
    char name[64];
    func* function;
};

void func_use(Test* test)
{
    cout << "id = " << test->id << " " << "name: " << test->name << endl;
    test->function();
}

Test* init_test(int id, char* str, func* function)
{
    cout << "init begin" << endl;
    Test* temp = (Test*)malloc(sizeof(Test));
    
    temp->id = id;
    strcpy(temp->name, str);
    temp->function = function;  
    cout << "init success" << endl;

    return temp;
}
void destory_test(Test* test)
{
    if (test != nullptr)
    {
        free(test);
        test = nullptr;
    } 
    cout << "destory success" << endl;
}

int main()
{
    Test* test1 = init_test(1, (char*)"ab", func1);
    Test* test2 = init_test(2, (char*)"bc", func2);
    Test* test3 = init_test(3, (char*)"cd", func3);

    func_use(test1);
    func_use(test2);
    func_use(test3);

    destory_test(test1);
    destory_test(test2);
    destory_test(test3);
}