#include <iostream>
#include <string.h>
using namespace std;

class Teacher
{
private:
    int m_id;
    char* m_name;

public:
    Teacher(int id, char* name)
    {
        cout << "constructed" << endl;
        m_id = id;
        m_name = (char*)malloc(strlen(name) + 1);
        strcpy(m_name, name);
    }

    Teacher(const Teacher &another)
    {
        cout << "copied" << endl;

        m_id = another.m_id;
        m_name = (char*)malloc(strlen(another.m_name) + 1);
        strcpy(m_name, another.m_name);
    }

    ~Teacher()
    {
        cout << "destructed" << endl;
        if (m_name != NULL)
        {
            free(m_name);
            m_name = NULL;
            cout << "free" << endl;
        }
        
    }

    void Print_name()
    {
        cout << "name is:" << m_name << endl;
    }
};

int main()
{
    Teacher teacher1(22, (char*)"zhangsan");
    teacher1.Print_name();

    Teacher teacher2(teacher1);
    teacher2.Print_name();
}