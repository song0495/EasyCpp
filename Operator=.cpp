#include <iostream>
#include <cstring>
using namespace std;

class Student
{
private:
    int m_id;
    char* m_name;

public:
    Student(int id, char* name)
    {
        m_id = id;
        int len = strlen(name);
        m_name = new char[len + 1];
        strcpy(m_name, name);
    }

    void PrintName()
    {
        cout << "name: " << m_name << endl;
    }

    ~Student()
    {
        if (m_name != nullptr)
        {
            delete[] m_name;
            m_name = nullptr;
            m_id = 0;
        } 
    }

    Student& operator=(Student& student)
    {
        if (this == &student)
        {
            return *this;
        }
        else
        {
            delete[] m_name;
            m_name = nullptr;
            m_id = 0;
        }
        m_id = student.m_id;
        int len = strlen(student.m_name);
        m_name = new char[len + 1];
        strcpy(m_name, student.m_name);

        return *this;
    }
};

int main()
{
    Student student1(1, (char*)"zhangsan");
    student1.PrintName();

    Student student2(2, (char*)"lisi");
    student2.PrintName();

    student1 = student2;
    student1.PrintName();
}