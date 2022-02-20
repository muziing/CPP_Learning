#include <iostream>
#include <fstream>
using namespace std;

/*
写文件步骤如下：
1.包含头文件
#include <fstream>
2.创建流对象
ofstream ofs
3.打开文件
ofs.open("文件路径", 打开方式);
4.写数据
ofs << "写入的数据";
5.关闭文件
ofs.close();
*/

/*
打开方式详解
ios::in     为读文件而打开文件
ios::out    为写文件而打开文件
ios::ate    初始位置：文件尾
ios::app    追加方式写文件
ios::trunc  如果文件存在，先删除再创建
ios::binary 二进制方式
*/

// 文本文件 写文件

void test01()
{
    ofstream ofs;
    ofs.open("test.txt", ios::out);
    ofs << "测试文本" << endl;
    ofs.close();
}

int main()
{
    test01();
    return 0;
}
