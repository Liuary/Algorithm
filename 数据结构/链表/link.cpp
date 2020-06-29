#include <iostream>

// #define print(args) std::cout << args
// #define println(args) std::cout << args << std::endl;

// 这个是链表节点的结构体，由两个变量组成：数据、下一个链表节点的地址
template<typename T>
struct LinkNode
{
T data;
LinkNode *next = nullptr;
};

// 这个是链表的管理类
template<typename T>
class Link
{
private:
    LinkNode<T> *data;
    size_t length = 0;
protected:
    // 返回第一个匹配的元素的上一个节点的地址
    virtual LinkNode<T>* SearchElement(T data);
public:
    // 无参构造函数
    Link();
    // 带参构造函数
    Link(T data);
    // 析构函数
    virtual ~Link();
    // 插入新元素
    virtual void InsertElement(T data);
    // 打印链表
    virtual void PrintLink();
    // 删除找到的第一个元素
    virtual void DeleteElement(T data);
    // 更新找到的第一个元素
    virtual void UpdateElement(T data, T newData);
    // 获取链表长度
    virtual size_t GetLinkLength();
    // 交换链表中两个元素的值（如果有）
    virtual void Swap(T first, T second);
};

template<typename T>
Link<T>::Link()
{
    this->data = new LinkNode<T>();
}

template<typename T>
Link<T>::Link(T data)
{
    Link();
    InsertElement(data);
}

template<typename T>
Link<T>::~Link()
{
    if (this->data == nullptr)
    {
        return;
    }
    LinkNode<T> *front = this->data;
    LinkNode<T> *behind = nullptr;
    while (front->next != nullptr)
    {
        behind = front;
        front = front->next;
        delete behind;
    }
    delete front;
}

template<typename T>
void Link<T>::InsertElement(T data)
{
    LinkNode<T> *position = this->data;
    if (position->next == nullptr)
    {
        position->next = new LinkNode<T>();
        position->next->data = data;
        length++;
        return;
    }
    while (position->next != nullptr)
    {
        position = position->next;
    }
    position->next = new LinkNode<T>();
    position->next->data = data;
    length++;
}

template<typename T>
void Link<T>::DeleteElement(T data)
{
    LinkNode<T> *position = SearchElement(data);
    if (position == nullptr)
    {
        return;
    }
    LinkNode<T> *discard = position->next;
    position->next = discard->next;
    delete discard;
    length--;
}

template<typename T>
void Link<T>::UpdateElement(T data, T newData)
{
    LinkNode<T> *position = SearchElement(data);
    if (position == nullptr)
    {
        return;
    }
    position->next->data = newData;
}

template<typename T>
size_t Link<T>::GetLinkLength()
{
    return length;
}

template<typename T>
LinkNode<T>* Link<T>::SearchElement(T data)
{
    LinkNode<T> *position = this->data->next;
    if (position == nullptr)
    {
        return nullptr;
    }
    
    LinkNode<T> *last = this->data;
    while (position != nullptr)
    {
        if (position->data == data)
        {
            return last;
        }
        last = position;
        position = position->next;
    }
    return nullptr;
}

template<typename T>
void Link<T>::Swap(T first, T second)
{
    LinkNode<T> *firstP = SearchElement(first);
    LinkNode<T> *secondP = SearchElement(second);
    if (firstP != nullptr and secondP != nullptr)
    {
        if (firstP->next != nullptr and secondP->next != nullptr)
        {
            firstP->next->data = second;
            secondP->next->data = first;
        }
    }
}

template<typename T>
void Link<T>::PrintLink()
{
    LinkNode<T> *position = this->data->next;
    if (position == nullptr)
    {
        return;
    }
    
    while(position != nullptr)
    {
        std::cout << position->data << " ";
        position = position->next;
    }
    std::cout << std::endl;

}

int main(int argc, char const *argv[])
{
    Link<int> l;
    l.InsertElement(233);
    l.InsertElement(666);
    l.InsertElement(999);

    std::cout << l.GetLinkLength() << std::endl;

    l.DeleteElement(666);
    l.UpdateElement(233, 520);

    std::cout << l.GetLinkLength() << std::endl;
    l.Swap(520, 999);
    l.Swap(233, 520);

    l.PrintLink();

    ::system("pause");
    return 0;
}
