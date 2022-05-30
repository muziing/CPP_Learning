#pragma once
#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include "globalFile.h"
using namespace std;

class OrderFile
{
public:
    OrderFile();

    // 更新预约记录
    void updateOrder();

    // 记录容器 key--记录的条数 value--记录具体信息的键值对
    map<int, map<string, string>> m_orderData;

    // 预约记录条数
    int m_Size;
};
