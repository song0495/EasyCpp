#include <iostream>
using namespace std;

void func(int (*arr)[3][2])
{
    cout << arr[1][1][1] << endl;
}

int main()
{
    int array[4][3][2];
    for (int i = 0; i < 4; i++)
    {
        for ( int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                array[i][j][k] = 1;
            }
        }       
    } 
    func(array);

    if (array == &array[0])
    {
        cout << "True" << endl;
    }

    if ((*(array + 1)) == array[1])
    {
        cout << "True" << endl;
    }

    if ((array[1] + 2) == &array[1][2])
    {
        cout << "True" << endl;
    }

    if (*(array[2][1] + 1) == array[2][1][1])
    {
        cout << "True" << endl;
    }

     return 0;  
}