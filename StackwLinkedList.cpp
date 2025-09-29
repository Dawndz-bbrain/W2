#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};

class LinkedList // tạo lớp list
{
private:
    Node *head; // tạo con trỏ head
    void traverse_backward_clone(Node *head)
    {
        if (head == nullptr)
            return;
        traverse_backward_clone(head->next);
        cout << head->data << " ";
    }

public:
    LinkedList() // khởi tạo list
    {
        head = nullptr;
    }
    int get(int pos) // truy cập
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
        return temp->data;
    }
    void push_front(int value) // thêm phần tử đầu
    {
        Node *newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }
    void push_back(int value) // thêm phần tử cuối
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
    }
    void Insert(int value, int pos) // thêm vào vị trí bất kì
    {
        Node *newNode = new Node(value);
        Node *temp = head;
        for (int i = 1; i < pos; i++)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    void del_front() // xóa phần tử đầu
    {
        if (head == nullptr)
            return;
        Node *temp = head;
        head = head->next;
        delete temp;
    }
    void del_back() // xóa phần tử cuối
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
            temp = temp->next;
        delete temp->next;
        temp->next = nullptr;
    }

    // xóa phần tử bất kì
    void DelPos(int pos)
    {
        Node *temp = head;
        for (int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
    }

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
    void traverse_backward() // duyệt ngược
    {
        traverse_backward_clone(head);
        cout << endl;
    }
    bool isEmpty()
    {
        return head == nullptr;
    }
    int count()
    {
        int dem = 0;
        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
            dem++;
        }
        return dem;
    }
};

class Stack
{
private:
    LinkedList list;

public:
    bool isEmpty()
    {
        return list.isEmpty();
    }
    void push(int item)
    {
        list.push_front(item);
    }
    int pop()
    {
        int top = list.get(1);
        list.del_front();
        return top;
    }
    int peek()
    {
        return list.get(1);
    }
    int size()
    {
        return list.count();
    }
};
int main()
{
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    cout << "Pop: " << st.pop() << endl;
    cout << "Phan tu tren cung: " << st.peek() << endl;
    return 0;
}