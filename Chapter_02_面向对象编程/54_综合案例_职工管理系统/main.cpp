#include "workerManager.h"

int main()
{
    // 实例化管理者对象
    WorkerManager wm;
    int choice = 0; // 存储用户输入的选项
    while (true)
    {
        wm.Show_Menu();
        cout << "输入您的选择:" << endl;
        cin >> choice;

        switch (choice)
        {
        case 0: // 退出系统
            wm.exitSystem();
            break;
        case 1: // 添加职工
            wm.Add_Emp();
            break;
        case 2: // 显示职工
            wm.Show_Emp();
            break;
        case 3: // 删除职工
            wm.Del_Emp();
            break;
        case 4: //修改职工
            wm.Mod_Emp();
            break;
        case 5: //查找职工
            wm.Find_Emp();
            break;
        case 6: //排序职工
            break;
        case 7: //清空文档
            wm.Clean_File();
            break;
        default:
            // system("clear");
            break;
        }
    }

    return 0;
}