#include <iostream>
using namespace std;

class LinkedList
{
    struct Node
    {
        int data;
        Node *next;
        Node(int num, Node *ptr = nullptr)
        {
            data = num;
            next = ptr;
        }
    };
    Node *head = nullptr;
    int elements = 0;

public:
    void insertFirst(int num)
    {
        if (head == nullptr)
        {
            head = new Node(num);
        }
        else
        {
            Node *n = new Node(num, head);
            head = n;
        }
        elements++;
    }
    void insertAtNode(int num , int index){
        Node *n = new Node(num);
        Node *curr = head;
        for(int i = 1 ; i < index ; i++){
            curr = curr->next;
        }
        Node *tmp = curr->next;
        curr->next = n;
        n->next = tmp;
    }
    void display()
    {
        Node *curr = head;
        while (curr != nullptr)
        {
            cout << curr->data << " -> ";
            curr = curr->next;
        }
        cout << "NULL";
    }
    void deleteNode(int index){
        Node *curr = head;
        Node *prev = nullptr;
        for(int i = 0 ; i < index ; i++){
            prev = curr;
            curr = curr->next;
        }
        Node *tmp = curr->next;
        delete curr;
        prev->next = tmp;
    }
    ~LinkedList()
    {
        Node *curr = head;
        while (curr != nullptr)
        {
            delete curr;
            curr = curr->next;
        }
        delete head;
        head = nullptr;
        elements = 0;
    }
    void reverse(){
        Node *curr = head;
        Node *prev = nullptr;
        while (curr != nullptr){
            Node *tmp = curr;
            curr = curr->next;
            tmp->next = prev;
            prev = tmp;
        }
        head = prev;
    }
    void middleNode(){
        Node *slow = head;
        Node *fast = head;
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        cout << slow->data;
    }
};
