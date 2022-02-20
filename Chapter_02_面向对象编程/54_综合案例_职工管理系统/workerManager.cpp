#include "workerManager.h"

WorkerManager::WorkerManager()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    // 1.文件不存在
    if (!ifs.is_open())
    {
        // cout << "文件不存在" << endl; //测试输出
        this->m_EmpNum = 0; //初始化人数
        this->m_FileIsEmpty = true;
        this->m_EmpArray = NULL; // 初始化数组指针
        ifs.close();
        return;
    }
    // 2.文件为空
    char ch;
    ifs >> ch;
    if (ifs.eof())
    {
        // cout << "文件为空!" << endl;
        this->m_EmpNum = 0;
        this->m_FileIsEmpty = true;
        this->m_EmpArray = NULL;
        ifs.close();
        return;
    }

    // 3.文件存在，并且记录有数据
    int num = this->get_EmpNum();
    // cout << "职工个数为: " << num << endl;
    this->m_EmpNum = num; // 更新成员属性

    // 开辟空间
    this->m_EmpArray = new Worker *[this->m_EmpNum];
    // 将文件中的数据存到数组中
    this->init_Emp();
}

WorkerManager::~WorkerManager()
{
    if (this->m_EmpArray != NULL)
    {
        for (int i = 0; i < this->m_EmpNum; i++)
        {
            if (this->m_EmpArray[i] != NULL)
            {
                delete this->m_EmpArray[i];
            }
        }
        delete[] this->m_EmpArray;
        this->m_EmpArray = NULL;
    }
}

void WorkerManager::Show_Menu()
{
    cout << "******************************" << endl;
    cout << "**** 欢迎使用职工管理系统 ****" << endl;
    cout << "******* 0.退出管理程序 *******" << endl;
    cout << "******* 1.添加职工信息 *******" << endl;
    cout << "******* 2.显示职工信息 *******" << endl;
    cout << "******* 3.删除离职职工 *******" << endl;
    cout << "******* 4.修改职工信息 *******" << endl;
    cout << "******* 5.查找职工信息 *******" << endl;
    cout << "******* 6.按照编号排序 *******" << endl;
    cout << "******* 7.清空所有文档 *******" << endl;
    cout << "******************************" << endl;
    cout << endl;
}

void WorkerManager::exitSystem()
{
    cout << "欢迎下次使用" << endl;
    exit(0);
}

void WorkerManager::Add_Emp()
{
    cout << "请输入增加职工数量: " << endl;

    int addNum = 0;
    cin >> addNum;

    if (addNum > 0)
    {
        // 计算新空间大小
        int newSize = this->m_EmpNum + addNum;

        // 开辟新空间
        Worker **newSpace = new Worker *[newSize];

        // 将原空间下内容存放到新空间下
        if (this->m_EmpArray != NULL)
        {
            for (int i = 0; i < this->m_EmpNum; i++)
            {
                newSpace[i] = this->m_EmpArray[i];
            }
        }
        // 输入新数据
        for (int i = 0; i < addNum; i++)
        {
            int id;
            string name;
            int dSelect;

            cout << "请输入第" << i + 1 << " 个新职工编号: " << endl;
            cin >> id;
            cout << "请输入第 " << i + 1 << " 个新职工姓名: " << endl;
            cin >> name;
            cout << "请选择该职工岗位:  " << endl;
            cout << "1、普通职工\n2、经理\n3、老板" << endl;
            cin >> dSelect;

            Worker *worker = NULL;
            switch (dSelect)
            {
            case 1:
                worker = new Employee(id, name, 1);
                break;
            case 2:
                worker = new Manager(id, name, 2);
                break;
            case 3:
                worker = new Boss(id, name, 3);
                break;

            default:
                break;
            }
            newSpace[this->m_EmpNum + i] = worker;
        }

        // 释放原有空间
        delete[] this->m_EmpArray;

        // 更改新空间的指向
        this->m_EmpArray = newSpace;

        // 更新新的职工人数
        this->m_EmpNum = newSize;

        // 更新职工不为空标志
        this->m_FileIsEmpty = false;

        // 提示信息
        cout << "成功添加" << addNum << "名新职工" << endl;

        // 保存到文件中
        this->save();
    }
    else
    {
        cout << "输入有误" << endl;
    }
    system("clear");
}

void WorkerManager::save()
{
    ofstream ofs;
    ofs.open(FILENAME, ios::out);

    for (int i = 0; i < this->m_EmpNum; i++)
    {
        ofs << this->m_EmpArray[i]->m_Id << " "
            << this->m_EmpArray[i]->m_Name << " "
            << this->m_EmpArray[i]->m_DeptId << endl;
    }
    ofs.close();
}

int WorkerManager::get_EmpNum()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    int id;
    string name;
    int dId;
    int num = 0;

    while (ifs >> id && ifs >> name && ifs >> dId)
    {
        num++;
    }
    ifs.close();

    return num;
}

void WorkerManager::init_Emp()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    int id;
    string name;
    int dId;
    int index = 0;

    while (ifs >> id && ifs >> name && ifs >> dId)
    {
        Worker *worker = NULL;
        if (dId == 1)
        {
            worker = new Employee(id, name, dId);
        }
        else if (dId == 2)
        {
            worker = new Manager(id, name, dId);
        }
        else
        {
            worker = new Boss(id, name, dId);
        }
        this->m_EmpArray[index] = worker;
        index++;
    }
    ifs.close();
}

void OutEmpty()
{
    cout << "文件不存在或记录为空!" << endl;
}

void WorkerManager::Show_Emp()
{
    if (this->m_FileIsEmpty)
    {
        OutEmpty();
    }
    else
    {
        system("clear");
        for (int i = 0; i < m_EmpNum; i++)
        {
            this->m_EmpArray[i]->showInfo();
        }
    }
}

int WorkerManager::IsExist(int id)
{
    int index = -1;
    for (int i = 0; i < this->m_EmpNum; i++)
    {
        if (this->m_EmpArray[i]->m_Id == id)
        {
            index = i;
            break;
        }
    }
    return index;
}

void WorkerManager::Del_Emp()
{
    if (this->m_FileIsEmpty)
    {
        OutEmpty();
    }
    else
    {
        system("clear");
        // 按照职工编号删除
        cout << "请输入想要删除的职工编号: " << endl;
        int id = 0;
        cin >> id;

        int index = this->IsExist(id);

        if (index != -1)
        {
            // 数据前移
            for (int i = index; i < this->m_EmpNum; i++)
            {
                this->m_EmpArray[i] = this->m_EmpArray[i + 1];
            }
            this->m_EmpNum--;
            // 同步更新到文件中
            this->save();

            cout << "删除成功!" << endl;
        }
        else
        {
            cout << "删除失败,未找到该职工" << endl;
        }
    }
}

void WorkerManager::Mod_Emp()
{
    if (this->m_FileIsEmpty)
    {
        OutEmpty();
    }
    else
    {
        cout << "请输入修改职工的编号: " << endl;
        int id;
        cin >> id;

        int ret = this->IsExist(id);
        if (ret != -1)
        {
            // 查找到编号的职工
            delete this->m_EmpArray[ret];

            int newId = 0;
            string newName = "";
            int dSelect = 0;

            cout << "查到" << id << "号职工,请输入新职工号: " << endl;
            cin >> newId;
            cout << "请输入姓名: " << endl;
            cin >> newName;
            cout << "请输入岗位: \n1.普通职工\n2.经理\n3.老板" << endl;
            cin >> dSelect;

            Worker *worker = NULL;
            switch (dSelect)
            {
            case 1:
                worker = new Employee(newId, newName, dSelect);
                break;
            case 2:
                worker = new Manager(newId, newName, dSelect);
                break;
            case 3:
                worker = new Boss(newId, newName, dSelect);
                break;
            default:
                break;
            }

            this->m_EmpArray[ret] = worker;
            cout << "修改成功" << endl;
            this->save();
        }
        else
        {
            cout << "修改失败,查无此人!" << endl;
        }
    }
}

void WorkerManager::Find_Emp()
{
    if (this->m_FileIsEmpty)
    {
        OutEmpty();
    }
    else
    {
        system("clear");
        cout << "请输入查找方式: \n1.按职工编号查找\n2.按职工姓名查找" << endl;
        int select = 0;
        cin >> select;

        if (select == 1)
        {
            // 按编号查
            int id;
            cout << "请输入查找的职工编号: " << endl;
            cin >> id;
            int ret = IsExist(id);
            if (ret != -1)
            {
                cout << "查找成功,该职工信息如下: " << endl;
                this->m_EmpArray[ret]->showInfo();
            }
            else
            {
                cout << "查找失败,查无此人" << endl;
            }
        }
        else if (select == 2)
        {
            // 按姓名查
            string name;
            cout << "请输入查找的姓名: " << endl;
            cin >> name;

            // 加入判断是否查到的标志
            bool flag = false;

            for (int i = 0; i < m_EmpNum; i++)
            {
                if (this->m_EmpArray[i]->m_Name == name)
                {
                    system("clear");
                    cout << "查找成功,该职工信息如下: " << endl;
                    flag = true;
                    this->m_EmpArray[i]->showInfo();
                }
            }
            if (flag == false)
            {
                cout << "查找失败,查无此人" << endl;
            }
        }
        else
        {
            cout << "输入选项有误" << endl;
        }
    }
}

void WorkerManager::Clean_File()
{
    system("clear");
    cout << "确认清空?" << endl;
    cout << "1.确认\n2.返回" << endl;
    int select = 0;
    cin >> select;

    if (select == 1)
    {
        ofstream ofs(FILENAME, ios::trunc); // 如果存在则删除文件并重新创建
        ofs.close();

        if (this->m_EmpArray != NULL)
        {
            for (int i = 0; i < this->m_EmpNum; i++)
            {
                if (this->m_EmpArray[i] != NULL)
                {
                    delete this->m_EmpArray[i];
                }
            }
            this->m_EmpNum = 0;
            delete[] this->m_EmpArray;
            this->m_EmpArray = NULL;
            this->m_FileIsEmpty = true;
        }
        cout << "清空成功!" << endl;
    }
}