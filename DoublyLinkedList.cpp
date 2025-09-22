#include <iostream>
using namespace std;
class Node
{
    int data;
    Node *next;
    Node *prev;
    Node(int value)
    {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};
class DoublyLL
{
private:
    Node *head;

public:
    List()
    {
        head = nullptr;
    }

    // truy cập
    int get(int pos)
    {
        Node *temp = head;
        int index = 1;
        while (temp != nullptr)
        {
            if (index == pos)
                return temp->data;
            temp = temp->next;
            index++;
        }
    }

    // chèn phần tử đầu
    void push_front(int value)
    {
        Node *newNode = new Node(value);
        newNode->prev = nullptr;
        newNode->next = head;
        head = newNode;
    }

    // chèn phần tử cuối
    void push_back(int value)
    {
        Node *newNode = new Node(value);
        if (head == nullptr)
        {
            head = newNode;
            return;
        }
        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
        newNode->next = nullptr;
    }

    // chèn vào vị trí bất kì
    void InsertPos(int value, int pos)
    {
        Node *newNode = new Node(value);
        Node *temp = head;
        for (int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
    }

    // xóa phần tử đầu
    void del_front()
    {
        if (head == nullptr)
            return;
        Node *temp = head;
        head = head->next;
        head->next->prev = nullptr;
        delete temp;
    }

    // xóa phần tử cuối
    void del_back()
    {
        if (head == nullptr)
            return;
        if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
            return;
        }
        Node *temp = head;
        while (temp->next->next != nullptr)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }

    // xóa vị trí bất kì
    // void delPos(int pos)
    // {
    //     Node *temp = head;
    //     for (int i = 1; i < pos; i++)
    //     {
    //         temp = temp->next;
    //     }
    //     temp->next = temp->next->next;
    //     temp->next->next->prev = temp;
    // }

    // duyệt xuôi
    void traverse_forward() // duyệt xuôi
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
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
    myList.del_back();
    cout << "phan tu sau khi xoa phan tu cuoi la: ";
    myList.traverse_forward();
    return 0;
}