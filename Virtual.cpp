#include <iostream>
using namespace std;

class Furniture
{
private:

public:
    string Material;

    Furniture() {}
    virtual ~Furniture() {cout << "fur desc" << endl;}  //虚析构函数

    virtual void Rest()   //虚函数, 多态
    {
        cout << "休息"  << endl;
    }
};

class Chair: virtual public Furniture   //虚继承, 菱形结构
{
private:

public:
    Chair() {}
    virtual ~Chair() {cout << "chair desc" << endl;}

    virtual void Rest()
    {
        cout << "坐在椅子上休息"  << endl;
    }
};

class Desk: virtual public Furniture
{
private:

public:
    Desk() {}
    virtual ~Desk() {cout << "desk desc" << endl;}

    virtual void Rest()
    {
        cout << "趴在桌子上休息"  << endl;
    }
};

class Bed: virtual public Furniture
{
private:

public:
    Bed() {}
    virtual ~Bed() {cout << "bed desc" << endl;}

    virtual void Rest()
    {
        cout << "躺在床上休息"  << endl;
    }
};

class Sp: public Desk, public Chair, public Bed
{
private:

public:
    Sp() {}
    virtual ~Sp() {cout << "sp desc" << endl;}

    virtual void Rest()
    {
        cout << "都可以休息"  << endl;
    }
};

void func(Furniture* fur)
{
    fur->Rest();

    delete fur;
}

int main()
{
    Furniture* fur = new Furniture;
    Chair* chair = new Chair;
    Desk* desk = new Desk;
    Bed* bed = new Bed;
    Sp* sp = new Sp;

    cout  << sp->Material << endl;  //保证sp中只有一个Material

    func(fur);
    func(chair);
    func(desk);
    func(bed);
}
