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

    // truy cập
    int get(int pos) 
    {
        if (pos < 0 || pos >= size)
        {
            cout << "vi tri truy cap ngoai pham vi" << endl;
            return -1;
        }
        return data[pos];
    }

    // chèn phần tử đầu
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

    // chèn phần tử cuối
    void push_back(int value)
    {
        if (size == MAX)
            return;
        data[size] = value;
        size++;
    }

    //chèn vị trí bất kì
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

    // xóa phần tử đầu
    void del_front()
    {
        for (int i = 0; i < size - 1; i++)
        {
            data[i] = data[i + 1];
        }
        size--;
    }

    // xóa phần tử cuối
    void del_back()
    {
        size--;
    }

    // duyệt xuôi
    void traverse_forward()
    {
        for (int i = 0; i < size; i++)
        {
            cout << data[i] << " ";
        }
    }

    //duyệt ngược
    void traverse_backward()
    {
        for (int i = size - 1; i >= 0; i--)
        {
            cout << data[i] << " ";
        }
    }
};
int main()
{
    List myList;
    myList.push_front(10);
    myList.push_back(20);
    myList.push_back(30);
    myList.push_front(5);
    cout << "phan tu o vi tri thu 2 la: " << myList.get(2) << endl;
    myList.del_front();
    cout << "phan tu sau khi xoa phan tu dau la: ";
    myList.traverse_forward();
    cout << endl;
    myList.del_back();
    cout << "phan tu sau khi xoa phan tu cuoi la: ";
    myList.traverse_forward();
    return 0;
}

