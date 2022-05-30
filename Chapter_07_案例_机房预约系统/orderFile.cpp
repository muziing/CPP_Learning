#include "orderFile.h"

// 拆分字符串并插入到map容器中
void cutString(string str, map<string, string> &m)
{
    string key;
    string value;
    int pos = str.find(":");
    if (pos != -1)
    {
        key = str.substr(0, pos);
        value = str.substr(pos + 1, str.size() - pos);
        m.insert(make_pair(key, value));
    }
}

OrderFile::OrderFile()
{
    ifstream ifs;
    ifs.open(ORDER_FILE, ios::in);

    string date;     // 日期
    string interval; // 时间段
    string stuId;    // 学生编号
    string stuName;  // 学生姓名
    string roomId;   // 机房编号
    string status;   // 预约状态

    this->m_Size = 0; // 预约登记个数

    while (ifs >> date && ifs >> interval && ifs >> stuId &&
           ifs >> stuName && ifs >> roomId && ifs >> status)
    {
        // 测试代码
        // cout << date << endl;
        // cout << interval << endl;
        // cout << stuId << endl;
        // cout << stuName << endl;
        // cout << roomId << endl;
        // cout << status << endl;

        string key;
        string value;
        map<string, string> m;

        cutString(date, m);
        cutString(interval, m);
        cutString(stuId, m);
        cutString(stuName, m);
        cutString(roomId, m);
        cutString(status, m);

        this->m_orderData.insert(make_pair(this->m_Size, m));
        this->m_Size++;
    }
    ifs.close();

    // 测试代码
    // for (map<int, map<string, string>>::iterator it = m_orderData.begin(); it != m_orderData.end(); it++)
    // {
    //     cout << "条数=" << it->first << " 值=" << endl;
    //     for (map<string, string>::iterator mit = (*it).second.begin(); mit != (*it).second.end(); mit++)
    //     {
    //         cout << "\t"
    //              << "key=" << mit->first << " value=" << mit->second << endl;
    //     }
    //     cout << endl;
    // }
}

void OrderFile::updateOrder()
{
    if (this->m_Size == 0)
    {
        return; // 预约记录0条，直接return
    }

    ofstream ofs(ORDER_FILE, ios::out | ios::trunc);
    for (int i = 0; i < m_Size; i++)
    {
        ofs << "date:" << this->m_orderData[i]["date"] << " ";
        ofs << "interval:" << this->m_orderData[i]["interval"] << " ";
        ofs << "stuId:" << this->m_orderData[i]["stuId"] << " ";
        ofs << "stuName:" << this->m_orderData[i]["stuName"] << " ";
        ofs << "roomId:" << this->m_orderData[i]["roomId"] << " ";
        ofs << "status:" << this->m_orderData[i]["statis"] << " ";
    }
    ofs.close();
}
