#include <iostream>
#include <string.h>
using namespace std;

class MyString
{
    friend ostream& operator<<(ostream& os, MyString& str);
    friend istream& operator>>(istream& is, MyString& str);

private:
    int m_len;
    char* m_str;

public:
    MyString()
    {
        m_len = 0;
        m_str = nullptr;
    }

    MyString(int len)
    {
        cout << "MyString(int len)" << endl;
        m_len = len;
        m_str = new char(m_len + 1);
    }

    MyString(char* str)
    {
        cout << "MyString(char* str)" << endl;
        int len = strlen(str);
        m_len = len;
        m_str = new char(m_len + 1);
        strcpy(m_str , str);
    }

    ~MyString()
    {
        if (m_str != nullptr)
        {
            cout << "~MyString()" << endl;
            delete[] m_str;
            m_str = nullptr;
            m_len = 0;
        }      
    }

    char&  operator[](int index)
    {
        return m_str[index];
    }

    MyString& operator=( const MyString& another)
    {
        if (m_str != nullptr)
        {
            delete[] m_str;
            m_str = nullptr;
            m_len = 0;
        }
        
        m_len = another.m_len;
        m_str = new char(m_len + 1);
        strcpy(m_str , another.m_str);

        return *this;
    }

    bool operator==(MyString& another)
    {
        if (m_len != another.m_len)
        {
            return false;
        }
        
        for (int i = 0; i < m_len; i++)
        {
            if (m_str[i] != another.m_str[i])
            {
                return false;
            }
        }
        
        return true;
    }

    bool operator!=(MyString& another)
    {
        return (!(*this == another));
    }
};

ostream& operator<<(ostream& os, MyString& str)
{
    for (int i = 0; i < str.m_len; i++)
    {
        os << str.m_str[i];
    }
    os << endl;
    
    return os;
}

istream& operator>>(istream& is, MyString& str)
{
    if (str.m_str != nullptr)
    {
        delete[] str.m_str;
        str.m_str = nullptr;
        str.m_len = 0;
    }

    char temp[1024] = {0};
    cin >> temp;
    int len = strlen(temp);
    str.m_len = len;
    str.m_str = new char(str.m_len + 1);
    strcpy(str.m_str, temp);
    
    return is;
}

int main()
{
    MyString str1((char*)"zhangsan");
    MyString str2((char*)"lisi");

    cout << str1;
    cout << str2;

}