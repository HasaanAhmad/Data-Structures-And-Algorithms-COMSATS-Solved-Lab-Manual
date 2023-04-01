#include <iostream>
#include <cstring>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

class Stack
{
public:
    Node* top;
    Stack()
    {
        top = NULL;
    }
    void push(int data)
    {
        Node *newNode = new Node(data);
        if (top == NULL)
        {
            top = newNode;
        }
        else
        {
            newNode->next = top;
            top = newNode;
        }
    }
    void pop()
    {
        if (top == NULL)
        {
            cout << "Stack is empty" << endl;
        }
        else
        {
            Node *temp = top;
            top = top->next;
            delete temp;
        }
    }
    void display()
    {
        Node *temp = top;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    Stack *s1 = new Stack();
    s1->push(10);
    s1->push(20);
    s1->push(30);
    s1->push(40);
    s1->push(50);
    s1->display();
    s1->pop();
    s1->display();

    Stack s2;
    char str[]="Hello I am Hasaan";
    int len = strlen(str);
    for(int i=0; i<len; i++)
    {
        s2.push(str[i]);
    }
    s2.display();

    return 0;
}