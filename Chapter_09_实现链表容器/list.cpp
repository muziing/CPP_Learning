#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class list
{
public:
    // 无参构造，创建空链表
    list() : m_head(NULL), m_tail(NULL) {}

    // 拷贝构造
    list(list const &that) : m_head(NULL), m_tail(NULL)
    {
        for (node *pnode = that.m_head; pnode; pnode = pnode->m_next)
        {
            push_back(pnode->m_data);
        }
    }

    // 析构
    ~list()
    {
        clear();
    }

    // 链表判空
    bool isEmpty()
    {
        return m_head == NULL && m_tail == NULL;
    }

    // 添加头节点
    void push_front(T const &data)
    {
        m_head = new node(NULL, data, m_head);
        if (m_head->m_next)
        {
            m_head->m_next->m_prev = m_head;
        }
        else
        {
            m_tail = m_head;
        }
    }

    // 删除链表头节点
    void pop_front()
    {
        if (isEmpty())
        {
            return;
        }

        node *pnode = m_head->m_next;
        delete m_head;
        if (pnode)
            pnode->m_prev = NULL;
        else
            m_tail = NULL;

        m_head = pnode;
    }

    // 获取头节点元素
    T &front()
    {
        if (isEmpty())
            throw underflow_error("null node");
        return m_head->m_data;
    }
    T const &front() const
    {
        return const_cast<list *>(this)->front();
    }

    // 添加尾节点
    void push_back(T const &data)
    {
        m_tail = new node(m_tail, data, NULL);
        if (m_tail->m_prev)
            m_tail->m_prev->m_next = m_tail;
        else
            m_head = m_tail;
    }

    // 删除尾节点
    void pop_back()
    {
        if (isEmpty())
            return;
        node *pnode = m_tail->m_prev;
        delete m_tail;
        if (pnode)
            pnode->m_next = NULL;
        else
            m_head = NULL;
        m_tail = pnode;
    }

    // 获取尾节点数据
    T &back()
    {
        if (isEmpty())
            throw underflow_error("null node");
        return m_tail->m_data;
    }
    T const &back() const
    {
        return const_cast<list *>(this)->back();
    }

    // 清空链表
    void clear()
    {
        while (!isEmpty())
        {
            pop_front();
        }
    }

    // 获取链表大小
    size_t size()
    {
        size_t i = 0;
        for (node *pnode = m_head; pnode; pnode = pnode->m_next)
        {
            ++i;
        }
        return i;
    }

private:
    // 节点类
    class node
    {
    public:
        node(node *prev, T const &data,
             node *next) : m_prev(prev), m_data(data), m_next(next) {}
        node *m_prev; // 前指针
        T m_data;     // 节点数据
        node *m_next; // 后指针
    };
    node *m_head; // 链表头
    node *m_tail; // 链表尾

    // 在接触迭代器知识前，姑且这样用
    // friend ostream &operator<<(ostream &os, list<int> &l);

public:
    // 正向非常迭代类
    class iterator
    {
    public:
        iterator(node *start, node *cur,
                 node *end) : m_start(start), m_cur(cur), m_end(end) {}
        T &operator*()
        {
            if (m_cur == NULL)
                throw underflow_error("null node");
            return m_cur->m_data;
        }
        iterator &operator++()
        {
            if (m_cur == NULL)
                m_cur = m_start;
            else
                m_cur = m_cur->m_next;
            return *this;
        }
        iterator operator--()
        {
            if (m_cur == NULL)
                m_cur = m_end;
            else
                m_cur = m_cur->m_prev;
            return *this;
        }
        bool operator==(iterator const &that) const
        {
            return m_start == that.m_start && m_cur == that.m_cur && m_end == that.m_end;
        }
        bool operator!=(iterator const &that) const
        {
            return !(*this == that);
        }

    private:
        node *m_start; // 开始指向
        node *m_cur;   // 当前指向
        node *m_end;   // 终止指向
        friend class list;
    };

    // 获取起始迭代器（遍历链表）
    iterator begin()
    {
        return iterator(m_head, m_head, m_tail);
    }

    // 获取终止迭代器（结束标志）
    iterator end()
    {
        return iterator(m_head, NULL, m_tail);
    }

    // 迭代器指向的位置添加节点
    void insert(iterator const &loc, T const &data)
    {
        if (loc == end())
        {
            push_back(data);
        }
        else
        {
            node *pnode = new node(loc.m_cur->m_prev, data, loc.m_cur);
            if (pnode->m_prev)
                pnode->m_prev->m_next = pnode;
            else
                m_head = pnode;
            pnode->m_next->m_prev = pnode;
        }
    }

    // 删除迭代器指向的节点
    void erase(iterator const &loc)
    {
        if (loc == end())
            return;
        node *pdel = loc.m_cur;
        if (pdel->m_prev)
            pdel->m_prev->m_next = pdel->m_next;
        else
            m_head = pdel->m_next;
        if (pdel->m_next)
            pdel->m_next->m_prev = pdel->m_prev;
        else
            m_tail = pdel->m_prev;
        delete pdel;
    }

    // 正向常迭代类
    class const_iterator
    {
    public:
        const_iterator(iterator const &it) : m_it(it) {}
        T const &operator*()
        {
            return *m_it;
        }
        const_iterator &operator++()
        {
            ++m_it;
            return *this;
        }
        const_iterator &operator--()
        {
            --m_it;
            return *this;
        }
        bool operator==(const_iterator const &that) const
        {
            return m_it == that.m_it;
        }
        bool operator!=(const_iterator const &that) const
        {
            return !(*this == that);
        }

    private:
        iterator m_it;
    };

    // 获取起始常迭代器
    const_iterator begin() const
    {
        return iterator(m_head, m_head, m_tail);
    }

    // 获取终止常迭代器
    const_iterator end() const
    {
        return iterator(m_head, NULL, m_tail);
    }
};

// 比较查找（利用==）
template <typename IT, typename T>
IT find(IT const &a, IT const &b, T const &data)
{
    for (IT it = a; it != b; ++it)
    {
        if (*it == data)
        {
            return it;
        }
    }
    return b;
}

// 以上代码模拟容器
// -----------------------
// 以下代码模拟普通用户使用

// ostream &operator<<(ostream &os, list<int> &l)
// {
//     for (list<int>::node *pnode = l.m_head; pnode; pnode = pnode->m_next)
//     {
//         os << pnode->m_data << ' ';
//     }
//     return os;
// }

void print(string const &str, list<int> &l)
{
    cout << str << endl;
    typedef list<int>::iterator IT;
    for (IT it = l.begin(); it != l.end(); ++it)
    {
        cout << *it << ' ';
    }
    cout << endl
         << "--------------------" << endl;
}

// 快速排序（"<"）
template <typename IT>
void sort(IT const &begin, IT const &end)
{
    IT p = begin;
    IT last = end;
    --last;
    for (IT i = begin, j = last; i != j;)
    {
        while (i != p && *i < *p)
        {
            ++i;
        }
        if (i != p)
        {
            swap(*i, *p);
            p = i;
        }
        while (j != p && *p < *j)
        {
            --j;
        }
        if (j != p)
        {
            swap(*p, *j);
            p = j;
        }
    }
    IT it = begin;
    ++it;
    if (p != begin && p != it)
        sort(begin, p);
    it = p;
    ++it;
    if (it != end && it != last)
        sort(it, end);
}

// 快速排序（比较器）
template <typename IT, typename CMP>
void sort(IT const &begin, IT const &end, CMP cmp)
{
    IT p = begin;
    IT last = end;
    --last;
    for (IT i = begin, j = last; i != j;)
    {
        while (i != p && cmp(*i, *p))
        {
            ++i;
        }
        if (i != p)
        {
            swap(*i, *p);
            p = i;
        }
        while (j != p && cmp(*p, *j))
        {
            --j;
        }
        if (j != p)
        {
            swap(*p, *j);
            p = j;
        }
    }
    IT it = begin;
    ++it;
    if (p != begin && p != it)
        sort(begin, p, cmp);
    it = p;
    ++it;
    if (it != end && it != last)
        sort(it, end, cmp);
}

// 比较类
class CMP
{
public:
    bool operator()(int const &a, int const &b)
    {
        return a > b;
    }
};

int main()
{
    list<int> ls;
    for (size_t i = 0; i < 5; i++)
    {
        ls.push_front(10 + i);
    }
    for (size_t i = 0; i < 5; i++)
    {
        ls.push_back(100 + i);
    }
    // cout << ls << endl;
    print("添加节点后：", ls);
    ls.pop_front();
    ls.pop_back();
    // cout << ls << endl;
    print("删除头尾节点后：", ls);

    ls.insert(++ls.begin(), 1000);
    print("在迭代器指向的位置添加节点后：", ls);
    ls.erase(ls.begin());
    print("删除迭代器指向的节点后：", ls);

    typedef list<int>::iterator IT;
    IT it = ls.begin();
    *it = 800;
    print("更改迭代器指向的节点后：", ls);

    IT fit = find(ls.begin(), ls.end(), 100);
    if (fit != ls.end())
        ls.erase(fit);
    print("找到100并删除后：", ls);

    /*
    const list<int> cls(ls);
    typedef list<int>::const_iterator CIT;
    for (CIT cit = cls.begin(); cit != cls.end(); ++cit)
    {
        cout << *cit << ' ';
    }
    cout << endl
         << "--------------------" << endl;

    CIT cit = cls.begin();
    // *cit = 900; // 不可修改，会报错
    */

    // sort(ls.begin(), ls.end());
    CMP cmp; // 比较器
    sort(ls.begin(), ls.end(), cmp);
    print("排序后：", ls);

    return 0;
}