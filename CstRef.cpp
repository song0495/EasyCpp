#include <iostream>
using namespace std;

int main()
{
    double val = 3.14;	
    const int &ref	= val;	
    /*
    实际上的引用操作：
    int temp = val;	
    const int& ref = temp;
    */
    double& ref2 = val;	

    cout << ref <<" "<< ref2 <<endl;	

    val	= 4.14;	
    cout << ref <<" "<< ref2 <<endl;	

    return 0;
}