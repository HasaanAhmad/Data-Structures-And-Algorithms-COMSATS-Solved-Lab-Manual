#include <iostream>
using namespace std;

class Node
{
public:
    char data;
    Node *next;
    Node(char data)
    {
        this->data = data;
        next = NULL;
    }
};
class Stack
{
public:
    Node *top;
    Stack()
    {
        top = NULL;
    }
    void push(char data)
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
    bool isEmpty()
    {
        if (top == NULL)
            return true;
        else
            return false;
    }
    char peek()
    {
        if (top == NULL)
        {
            cout << "Stack is empty" << endl;
            return 0;
        }
        else
        {
            return top->data;
        }
    }
};

void PriorityBalancedCheck(string expression)
{
    Stack s;
    for (int i = 0; i < expression.length(); i++)
    {
        if (expression[i] == '(' || expression[i] == '{' || expression[i] == '[')
        {
            s.push(expression[i]);
        }
        else if (expression[i] == ')' || expression[i] == '}' || expression[i] == ']')
        {
            if (s.isEmpty())
            {
                cout << "Expression is not balanced" << endl;
                return;
            }
            else if (expression[i] == ')' && s.peek() == '(')
            {
                s.pop();
            }
            else if (expression[i] == '}' && s.peek() == '{')
            {
                s.pop();
            }
            else if (expression[i] == ']' && s.peek() == '[')
            {
                s.pop();
            }
            else
            {
                cout << "Expression is not balanced" << endl;
                return;
            }
        }
    }
    if (s.isEmpty())
    {
        cout << "Expression is balanced" << endl;
    }
    else
    {
        cout << "Expression is not balanced" << endl;
    }
}

int main()
{
    

    return 0;
}