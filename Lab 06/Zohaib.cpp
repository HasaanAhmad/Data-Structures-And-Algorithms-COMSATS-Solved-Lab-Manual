#include <iostream>
#include <string>
using namespace std;

struct Node
{
    char data;
    Node *link;
};

class LinkedStack
{
private:
    Node *head;

public:
    LinkedStack()
    {
        head = NULL;
    }
    void push(char e)
    {
        Node *temp = new Node;
        temp->data = e;
        temp->link = head;
        head = temp;
    }
    void pop()
    {
        if (head == NULL)
        {
            cout << "\nStack is empty...Underflow condition\n";
        }
        else
        {
            Node *temp = head;
            char t = temp->data;
            head = temp->link;
            delete temp;
        }
    }
    char top()
    {
        return head->data;
    }
    bool isBalanced(string expression)
    {
        char ch;
        char ch1;
        char ch2;
        bool condi;
        int count = 0;
        for (int i = 0; i < expression.length(); i++)
        {
            if (expression[i] == '(' || expression[i] == '{' || expression[i] == '[')
            {
                push(expression[i]);
                continue;
            }
            if (head == NULL)
            {
                condi = true;
            }
            if (count == 0)
            {
                ch2 = top();
            }
            ch1 = top();
            if (count == 1)
            {
                if (ch2 == '[' && (ch1 == '(' || ch1 == '{'))
                {
                    condi = false;
                    break;
                }
                else if (ch2 == '{' && ch1 == '(')
                {
                    condi = false;
                    break;
                }
                else
                {
                    condi = true;
                }
                count = 0;
            }
            switch (expression[i])
            {
            case ')':
                ch = top();
                if (ch == '{' || ch == '[')
                {
                    condi = false;
                }
                pop();
                break;
            case '}':
                ch = top();
                if (ch == '(' || ch == '[')
                {
                    condi = false;
                }
                pop();
                break;
            case ']':
                ch = top();
                if (ch == '{' || ch == '(')
                {
                    condi = false;
                }
                pop();
                break;
            }
            count++;
            ch2 = ch1;
        }
        return condi;
    }
};

int main()
{
    // Testing isBalanced
    LinkedStack stack;
    string expression;
    cout << "Enter an expression: ";
    cin >> expression;
    if (stack.isBalanced(expression))
    {
        cout << "Balanced" << endl;
    }
    else
    {
        cout << "Not Balanced" << endl;
    }
    return 0;
}