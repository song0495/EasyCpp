#include <iostream>
using namespace std;

class CPU
{
public:
    virtual void Calculate() = 0;
};

class Graphics
{
public:
    virtual void Display() = 0;
};

class Memory
{
public:
    virtual void Storage() = 0;
};

class IntelCPU: public CPU
{
public:
    virtual void Calculate()
    {
        cout << "IntelCPU calculate" << endl;
    }
};

class AMDCPU: public CPU
{
public:
    virtual void Calculate()
    {
        cout << "AMDCPU calculate" << endl;
    }
};

class NVIDIAGraphics: public Graphics
{
public:
    virtual void Display()
    {
        cout << "NVIDIAGraphics diaplay" << endl;
    }
};

class AMDGraphics: public Graphics
{
public:
    virtual void Display()
    {
        cout << "AMDGraphics diaplay" << endl;
    }
};

class IntelMemory: public Memory
{
public:
    virtual void Storage()
    {
        cout << "IntelMemory storage" << endl;
    }
};

class KinstonMemory: public Memory
{
public:
    virtual void Storage()
    {
        cout << "KinstonMemory storage" << endl;
    }
};

class Computer
{
private:
    CPU* cpu;
    Graphics* graphics;
    Memory* memory;

public:
    Computer(CPU* cpu, Graphics* graphics, Memory* memory)
    {
        this->cpu = cpu;
        this->graphics = graphics;
        this->memory = memory;
    }

    ~Computer()
    {
        if (this->cpu != nullptr)
        {
            delete this->cpu;
            cout << "delete cpu" << endl;
        }
        if (this->graphics != nullptr)
        {
            delete this->graphics;
            cout << "delete graphics" << endl;
        }
        if (this->memory != nullptr)
        {
            delete this->memory;
            cout << "delete memory" << endl;
        }
        cout << "delete all" << endl;
    }

    void Work()
    {
        this->cpu->Calculate();
        this->graphics->Display();
        this->memory->Storage();
        cout << "Done!" << endl;
    }
};

void func()
{
    Computer* computer1 = new Computer(new IntelCPU, 
        new NVIDIAGraphics, new KinstonMemory);

    computer1->Work();

    delete computer1;
    cout << "end func" << endl;
}

int main()
{
    func();
    cin.get();
}