#include <iostream>
using namespace std;

struct Teacher
{
    char name[64];
    int age;
};

int getTeacher1(Teacher **ptr)
{
    Teacher* tmp = NULL;
    if(ptr == NULL)
        return -1;
    
    tmp = (Teacher*)malloc(sizeof(Teacher));
    if (tmp == NULL)
        return -1;
    
    tmp->age = 33;
    *ptr = tmp;

    return 0;
}

int getTeacher2(Teacher* &ptr)
{
    ptr = (Teacher*)malloc(sizeof(Teacher));
    if (ptr == NULL)
        return -1;
    
    ptr->age = 33;

    return 0;
}

void FreeTeacher(Teacher* ptr)
{
    if (ptr == NULL)
        return;
    
    free(ptr);
}

int main()
{
    Teacher* teacher = NULL;

    getTeacher1(&teacher);	
	cout << "age:" << teacher->age << endl;	
	FreeTeacher(teacher);

    getTeacher2(teacher);	
	cout << "age:" << teacher->age << endl;	
	FreeTeacher(teacher);

    return 0;
}