#include "student.h"
#include "teacher.h"
#include "manager.h"

// 管理员菜单
void managerMenu(Manager *&manager)
{
    while (true)
    {
        // 管理员菜单
        manager->operMenu();

        int select = 0;
        cin >> select;

        if (select == 1) // 添加帐号
        {
            cout << "添加帐号" << endl;
            manager->addPerson();
        }
        else if (select == 2) // 查看帐号
        {
            cout << "查看帐号" << endl;
            manager->showPerson();
        }
        else if (select == 3) // 查看机房
        {
            cout << "查看机房" << endl;
            manager->showComputer();
        }
        else if (select == 4) // 清空预约
        {
            cout << "清空预约" << endl;
            manager->cleanFile();
        }
        else
        {
            delete manager;
            system("clear");
            cout << "注销成功" << endl;
            return;
        }
    }
}

// 学生菜单
void studentMenu(Student *&student)
{
    while (true)
    {
        // 学生菜单
        student->operMenu();

        int select = 0;
        cin >> select;

        if (select == 1) // 申请预约
        {
            student->applyOrder();
        }
        else if (select == 2) // 查看自身预约
        {
            student->showMyOrder();
        }
        else if (select == 3) // 查看所有预约
        {
            student->showAllOrder();
        }
        else if (select == 4)
        {
            student->cancelOrder();
        }
        else
        {
            delete student;
            system("clear");
            cout << "注销成功" << endl;
            return;
        }
    }
}

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
        int fId;
        string fName;
        string fPwd;
        while (ifs >> fId && ifs >> fName && ifs >> fPwd)
        {
            if (id == fId && name == fName && pwd == fPwd)
            {
                system("clear");
                cout << "学生验证登陆成功" << endl;
                person = new Student(id, name, pwd);
                Student *student = (Student *)person; // 转换数据类型
                studentMenu(student);
                return;
            }
        }
    }
    else if (type == 2)
    {
        // 教师登陆验证
        int fId;
        string fName;
        string fPwd;
        while (ifs >> fId && ifs >> fName && ifs >> fPwd)
        {
            if (id == fId && name == fName && pwd == fPwd)
            {
                system("clear");
                cout << "教师登陆验证成功" << endl;
                person = new Teacher(id, name, pwd);
                return;
            }
        }
    }
    else if (type == 3)
    {
        // 管理员登陆验证
        string fName;
        string fPwd;
        while (ifs >> fName && ifs >> fPwd)
        {
            if (name == fName && pwd == fPwd)
            {
                system("clear");
                cout << "验证登陆成功！" << endl;
                person = new Manager(name, pwd);
                Manager *manager = (Manager *)person; // 转换数据类型
                managerMenu(manager);
                return;
            }
        }
    }

    system("clear");
    cout << "验证登陆失败！" << endl;

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
        cout << "\t\t ------------------------------\n";
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
        default:
            system("clear");
            cout << "输入有误，请重新选择！" << endl;
            break;
        }
    }

    return 0;
}