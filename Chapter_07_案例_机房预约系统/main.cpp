#include <iostream>
#include <fstream>
#include "identity.h"
#include "globalFile.h"
using namespace std;

// 登陆功能
void SignIn(string filename, int type)
{
    Identity *person = NULL;

    ifstream ifs;
    ifs.open(filename, ios::in);

    // 文件不存在情况
    if (!ifs.is_open())
    {
        cout << "文件不存在" << endl;
        ifs.close();
        return;
    }

    int id = 0;
    string name;
    string pwd;

    if (type == 1) // 学生登陆
    {
        cout << "请输入学号：" << endl;
        cin >> id;
    }
    else if (type == 2) // 教师登陆
    {
        cout << "请输入职工号：" << endl;
        cin >> id;
    }

    cout << "请输入用户名：" << endl;
    cin >> name;
    cout << "请输入密码：" << endl;
    cin >> pwd;

    if (type == 1)
    {
        // 学生登陆验证
    }
    else if (type == 2)
    {
        // 教师登陆验证
    }
    else if (type == 3)
    {
        // 管理员登陆验证
    }

    cout << "验证登陆失败！" << endl;

    system("clear");
    return;
}

int main()
{
    int select = 0; // 用于接收用户的选择

    while (true)
    {
        cout << "===================欢迎来到机房预约系统===================" << endl;
        cout << endl
             << "请输入您的身份" << endl;
        cout << "\t\t ------------------------------\n";
        cout << "\t\t|                              |\n";
        cout << "\t\t|           1.学生代表         |\n";
        cout << "\t\t|                              |\n";
        cout << "\t\t|           2.老    师         |\n";
        cout << "\t\t|                              |\n";
        cout << "\t\t|           3.管 理 员         |\n";
        cout << "\t\t|                              |\n";
        cout << "\t\t|           0.退   出          |\n";
        cout << "\t\t|                              |\n";
        cout << "\t\t -------------------------------\n";
        cout << "输入您的选择：";

        cin >> select; //接受用户选择

        switch (select)
        {
        case 1: // 学生身份
            SignIn(STUDENT_FILE, 1);
            break;
        case 2: // 老师身份
            SignIn(TEACHER_FILE, 2);
            break;
        case 3: // 管理员身份
            SignIn(ADMIN_FILE, 3);
            break;
        case 0: // 退出系统
            cout << "欢迎下一次使用" << endl;
            return 0;
            break;
        default:
            cout << "输入有误，请重新选择！" << endl;
            system("clear");
            break;
        }
    }

    return 0;
}