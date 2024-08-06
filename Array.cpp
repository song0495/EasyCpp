#include <iostream>
using namespace std;

class Array
{
    friend ostream& operator<<(ostream& os, Array& arr);
    friend istream& operator>>(istream& is, Array& arr);

private:
    int m_len;
    int* m_value;

public:
    Array(int len)
    {
        cout << "constructed" << endl;
        m_len = len;
        m_value = new int[m_len];
    }

    Array(const Array& another)
    {
        cout << "copied" << endl;
        m_len = another.m_len;
        m_value = new int[m_len];

        for (int i = 0; i < m_len; i++)
        {
            m_value[i] = another.m_value[i];
        }
    }

    ~Array()
    {
        cout << "destructed" << endl;
        if (m_value != nullptr)
        {
            delete[] m_value;
            m_value = nullptr;
            m_len = 0;
        }
    }

    void SetValue(int index, int value)
    {
        if ((index > m_len) && (index <= 0))
            cout << "error" << endl;
        else
            m_value[index] = value;
    }

    int GetValue(int index)
    {
        if ((index > m_len) && (index <= 0))
        {
            cout << "error" << endl;
            exit(1);
        }  
        else
        {
            return m_value[index];
        }   
    }

    int GetLen()
    {
        return m_len;
    }

    int& operator[](int index)
    {
        return m_value[index];
    }

    bool operator==(Array& another)
    {
        if (m_len != another.m_len)
        {
            return false;
        }
        
        for (int i = 0; i < m_len; i++)
        {
            if (m_value[i] != another.m_value[i])
            {
                return false;
            }
        }
        return true;
    }

    bool operator!=(Array& another)
    {
        return (!(*this == another));
    }
};

ostream& operator<<(ostream& os, Array& arr)
{
    for (int i = 0; i < arr.m_len; i++)
    {
        os << arr[i] << " ";
    }
    os << endl;

    return os;    
}

istream& operator>>(istream& is, Array& arr)
{
    for (int i = 0; i < arr.m_len; i++)
    {
        is >> arr[i];
    }

    return is;
}

int main()
{
    /*
    Array array1(10);

    cout << "set value ---------------" << endl;
    for (int i = 0; i < array1.GetLen(); i++)
    {
        array1.SetValue(i, i+1);
    }

    cout << "get value ---------------" << endl;
    for (int i = 0; i < array1.GetLen(); i++)
    {
        cout << array1.GetValue(i) << " ";
    }
    cout << endl;
    
    cout << "copy array ---------------" << endl;
    Array array2(array1);

    cout << "get value ---------------" << endl;
    for (int i = 0; i < array2.GetLen(); i++)
    {
        cout << array2.GetValue(i) << " ";
    }
    cout << endl;
    */

   Array array1(5);
   Array array2(5);

   cout << "set value ---------------" << endl;
    for (int i = 0; i < array1.GetLen(); i++)
    {
        array1[i] = i+1;
    }

    cout << array1;
    cin >> array2;

    if (array1 == array2)
    {
        cout << "相等"  << endl;
    }
    
}