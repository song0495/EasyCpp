#include <iostream>
using namespace std;

class Student
{
private:
    int m_id;
    int m_score;
    static int num;
    static int avg;

public:
    static int GetNum();
    static float GetAvg();

    Student(int id, int score)
        :m_id(id), m_score(score)
    {
        num++;
        avg += m_score;
    }

    ~Student()
    {
        num--;
        avg -= m_score;
    }
};

int Student::num  =0;
int Student::avg = 0;

int Student::GetNum()
    {
        return num;
    }

float Student::GetAvg()
    {
        return avg/num;
    }

int main()
{
    Student student1(1, 100);
    Student student2(2, 90);
    Student student3(3, 95);
    Student student4(4, 80);

    cout << "num = " << Student::GetNum() << endl;
    cout << "avg = " << Student::GetAvg() << endl;
}

