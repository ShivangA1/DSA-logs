#include <iostream>
using namespace std;

class Stack
{
    struct Node
    {
        int num;
        Node *prev;
        Node(int n, Node *curr = nullptr)
        {
            num = n;
            prev = curr;
        }
    };
    Node *top = nullptr;
    int elements = 0;

public:
    void push(int n)
    {
        elements++;
        if (top == nullptr)
        {
            top = new Node(n);
            return;
        }
        Node *dummy = new Node(n, top);
        top = dummy;
    }
    void peek()
    {
        if (top == nullptr)
        {
            cout << "no elements";
            return;
        }
        cout << "top: " << top->num << " elements: " << elements;
    }
    void display()
    {
        Node *curr = top;
        while (curr != nullptr)
        {
            cout << curr->num << " -> ";
            curr = curr->prev;
        }
        cout << "NULL" << endl;
    }
    void pop()
    {
        if (top == nullptr)
        {
            cout << "Stack is underflowed";
            return;
        }
        Node *temp = top->prev;
        delete top;
        top = temp;
        elements--;
    }
    ~Stack(){
        Node *curr = top;
        while (curr != nullptr)
        {
            Node *temp = curr->prev;
            delete curr;
            curr= temp;
        }
        elements = 0;
        top = nullptr;
    }
};
