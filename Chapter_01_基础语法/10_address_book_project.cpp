/*
综合项目练习：通讯录管理系统

系统中需要实现的功能如下：
- 添加联系人：向通讯录中添加新人，信息包括（姓名，性别，年龄，联系电话，住址），最多记录1000人
- 显示联系人：显示通讯录中所有联系人信息
- 删除联系人：按照姓名进行删除指定联系人
- 查找联系人：按照姓名查看指定联系人信息
- 修改联系人：按照姓名重新修改指定联系人
- 清空联系人：清空通讯录中所有信息
- 退出通讯录：退出当前使用的通讯录

*/

#include <iostream>
using namespace std;

// 显示菜单界面
void showMenu()
{
    cout << "*************************" << endl;
    cout << "***** 1、添加联系人 *****" << endl;
    cout << "***** 2、显示联系人 *****" << endl;
    cout << "***** 3、删除联系人 *****" << endl;
    cout << "***** 4、查找联系人 *****" << endl;
    cout << "***** 5、修改联系人 *****" << endl;
    cout << "***** 6、清空联系人 *****" << endl;
    cout << "***** 0、退出通讯录 *****" << endl;
    cout << "*************************" << endl;
}

// 联系人结构体
struct Person
{
    string m_Name; // 姓名
    int m_Sex;     //性别：1男 2女
    int m_Age;
    string m_Phone;
    string m_Addr;
};

#define MAX 1000 // 最大人数

// 通讯录结构体
struct AddressBooks
{
    struct Person personArray[MAX]; //通讯录中保存的联系人数组
    int m_Size;                     // 通讯录中人员个数
};

void addPerson(struct AddressBooks *abs)
{
    // 判断通讯录是否已满，如果满就不再添加
    if (abs->m_Size == MAX)
    {
        cout << "通讯录已满，无法添加！" << endl;
        return;
    }
    else
    {
        // 添加具体联系人
        string name;
        cout << "请输入姓名：" << endl;
        cin >> name;
        abs->personArray[abs->m_Size].m_Name = name;

        int sex = 0;
        cout << "请输入性别：" << endl;
        cout << "1 —— 男" << endl;
        cout << "2 —— 女" << endl;
        while (true)
        {
            cin >> sex;
            if (sex == 1 || sex == 2)
            {
                abs->personArray[abs->m_Size].m_Sex = sex;
                break;
            }
            cout << "输入有误，请重新输入" << endl;
        }

        int age = 0;
        cout << "请输入年龄" << endl;
        cin >> age;
        abs->personArray[abs->m_Size].m_Age = age;

        string phone;
        cout << "请输入联系电话" << endl;
        cin >> phone;
        abs->personArray[abs->m_Size].m_Phone = phone;

        string address;
        cout << "请输入家庭住址" << endl;
        cin >> address;
        abs->personArray[abs->m_Size].m_Addr = address;

        abs->m_Size++; // 更新通讯录人数
        cout << "添加成功！" << endl;
        system("pause");
        system("clear");
    }
}

// 输出联系人信息
void outPutPerson(AddressBooks *abs, int no)
{
    cout << "姓名：" << abs->personArray[no].m_Name << "\t";
    cout << "性别：" << (abs->personArray[no].m_Sex == 1 ? "男" : "女") << "\t";
    cout << "年龄：" << abs->personArray[no].m_Age << "\t";
    cout << "电话：" << abs->personArray[no].m_Phone << "\t";
    cout << "住址：" << abs->personArray[no].m_Addr << endl;
}

void showPerson(AddressBooks *abs)
{
    if (abs->m_Size == 0)
    {
        system("clear");
        cout << "当前记录为空" << endl;
    }
    else
    {
        system("clear");
        for (int i = 0; i < abs->m_Size; i++)
        {
            outPutPerson(abs, i);
        }
    }
}

//检测联系人是否存在
int isExist(AddressBooks *abs, string name)
{
    for (int i = 0; i < abs->m_Size; i++)
    {
        if (abs->personArray[i].m_Name == name)
        {
            return i;
        }
    }
    return -1; // 如果遍历结束都没有找到，返回-1
}

// 删除联系人
void deletePerson(AddressBooks *abs)
{
    cout << "请输入要删除的联系人姓名：" << endl;
    string name;
    cin >> name;

    int ret = isExist(abs, name);

    if (ret != -1)
    {
        for (int i = ret; i < abs->m_Size; i++)
        {
            // 数据前移
            abs->personArray[i] = abs->personArray[i + 1];
        }
        // 更新人数
        abs->m_Size--;
    }
    else
    {
        cout << "查无此人" << endl;
    }
    system("clear");
}

// 查找指定联系人信息
void findPerson(AddressBooks *abs)
{
    cout << "请输入您要查找的联系人" << endl;
    string name;
    cin >> name;

    int ret = isExist(abs, name);

    if (ret != -1) // 找到联系人
    {
        outPutPerson(abs, ret);
    }
    else // 未找到联系人
    {
        cout << "查无此人" << endl;
    }
}

// 清空所有联系人
void cleanPerson(AddressBooks *abs)
{
    abs->m_Size = 0;
    system("clear");
}

int main()
{
    // 创建通讯录结构体变量
    AddressBooks abs;
    // 初始化通讯录中当前人数个数

    int select = 0; // 创建用户选择输入的变量

    while (true)
    {
        showMenu();
        cin >> select;

        switch (select)
        {
        case 1: // 添加联系人
            addPerson(&abs);
            break;
        case 2: // 显示联系人
            showPerson(&abs);
            break;
        case 3: // 删除联系人
            deletePerson(&abs);
            break;
        case 4: //查找联系人
            findPerson(&abs);
            break;
        case 5: // 修改联系人
            break;
        case 6: // 清空联系人
            cleanPerson(&abs);
            break;
        case 0: // 退出通讯录
            cout << "欢迎下次使用" << endl;
            return 0;
            break;
        default:
            break;
        }
    }

    return 0;
}