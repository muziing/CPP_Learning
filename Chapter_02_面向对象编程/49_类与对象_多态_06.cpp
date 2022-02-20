#include <iostream>
using namespace std;

// 多态 - 案例 - 电脑组装

// 抽象不同零件类
// 抽象CPU类
class CPU
{
public:
    // 抽象的计算函数
    virtual void calculate() = 0;
};

// 抽象GPU类
class GPU
{
public:
    // 抽象的显示函数
    virtual void display() = 0;
};

// 抽象内存类
class Memory
{
public:
    // 抽象的存储函数
    virtual void storage() = 0;
};

class Computer
{
public:
    Computer(CPU *cpu, GPU *gpu, Memory *mem)
    {
        m_cpu = cpu;
        m_gpu = gpu;
        m_mem = mem;
    }

    ~Computer()
    {
        if (m_cpu != NULL)
        {
            delete m_cpu;
            m_cpu = NULL;
        }
        if (m_gpu != NULL)
        {
            delete m_gpu;
            m_gpu = NULL;
        }
        if (m_mem != NULL)
        {
            delete m_mem;
            m_mem = NULL;
        }
    }

    // 提供工作函数
    void work()
    {
        // 调用接口，让零件工作起来
        m_cpu->calculate();
        m_gpu->display();
        m_mem->storage();
    }

private:
    CPU *m_cpu;    // CPU的零件指针
    GPU *m_gpu;    // 显卡零件指针
    Memory *m_mem; //内存条零件指针
};

// 具体厂商
class IntelCPU : public CPU
{
public:
    virtual void calculate()
    {
        cout << "Intel的CPU开始计算了" << endl;
    }
};

class IntelGPU : public GPU
{
public:
    virtual void display()
    {
        cout << "Intel的GPU开始显示了" << endl;
    }
};

class IntelMemory : public Memory
{
public:
    virtual void storage()
    {
        cout << "Intel的内存开始存储了" << endl;
    }
};

class AMDCPU : public CPU
{
public:
    virtual void calculate()
    {
        cout << "AMD的CPU开始计算了" << endl;
    }
};

class AMDGPU : public GPU
{
public:
    virtual void display()
    {
        cout << "AMD的GPU开始显示了" << endl;
    }
};

class AMDMemory : public Memory
{
public:
    virtual void storage()
    {
        cout << "AMD的内存开始存储了" << endl;
    }
};

void test01()
{
    // 第一台电脑零件
    CPU *intelCpu = new IntelCPU;
    GPU *intelGpu = new IntelGPU;
    Memory *intelMem = new IntelMemory;

    // 创建第一台电脑
    Computer *computer1 = new Computer(intelCpu, intelGpu, intelMem);
    computer1->work();
    delete computer1;

    // 创建第一台电脑
    Computer *computer2 = new Computer(new AMDCPU, new AMDGPU, new AMDMemory);
    computer2->work();
    delete computer2;
}

int main()
{
    test01();
    return 0;
}