#include <iostream>
using namespace std;

const int MAX = 100;

class List
{
public:
    int data[MAX];
    int size;
    List()
    {
        size = 0;
    }
    int get(int pos) //
    {
        if (pos < 0 || pos >= size)
        {
            cout << "vi tri truy cap ngoai pham vi" << endl;
            return -1;
        }
        return data[pos];
    }
    void push_front(int value)
    {
        if (size == MAX)
            return;
        for (int i = size; i > 0; i--)
        {
            data[i] = data[i - 1];
        }
        data[0] = value;
        size++;
    }
    void push_back(int value)
    {
        if (size == MAX)
            return;
        data[size] = value;
        size++;
    }
    void InsertPos(int value, int pos)
    {
        if (size == MAX)
            return;
        for (int i = size; i >= pos; i--)
        {
            data[i] = data[i - 1];
        }
        data[pos - 1] = value;
        size++;
    }
    void del_front()
    {
        for (int i = 0; i < size - 1; i++)
        {
            data[i] = data[i + 1];
        }
        size--;
    }
    void del_back()
    {
        size--;
    }
    void delPos(int pos)
    {
        for (int i = pos - 1; i < size - 1; i++)
        {
            data[i] = data[i + 1];
        }
        size--;
    }
    void traverse_forward()
    {
        for (int i = 0; i < size; i++)
        {
            cout << data[i] << " ";
        }
    }
    void traverse_backward()
    {
        for (int i = size - 1; i >= 0; i--)
        {
            cout << data[i] << " ";
        }
    }
};

class Queue
{
private:
    List list;

public:
    bool isEmpty()
    {
        return list.size == 0;
    }
    void enqueue(int item)
    {
        list.push_front(item);
    }
    int peek()
    {
        return list.get(list.size - 1);
    }
    int dequeue()
    {
        int front = list.get(list.size - 1);
        list.del_back();
        return front;
    }
    int size()
    {
        return list.size;
    }
};
int main()
{
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Phan tu dau tien: " << q.peek() << endl; // 10
    cout << "Dequeue: " << q.dequeue() << endl;       // 10
    cout << "Dequeue: " << q.dequeue() << endl;       // 20
    cout << "Phan tu dau tien: " << q.peek() << endl; // 30

    return 0;
}