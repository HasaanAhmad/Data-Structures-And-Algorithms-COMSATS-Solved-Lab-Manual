#include <iostream>
using namespace std;
// Using the stack check that the given expression has balanced paranthesis or not.
class Node{
    public:
        char data;
        Node *next;
        Node(char data){
            this->data = data;
            next = NULL;
        }
};
class Stack{
    public:
        Node *top;
        Stack(){
            top = NULL;
        }
        void push(char data){
            Node *newNode = new Node(data);
            if(top == NULL){
                top = newNode;
            }
            else{
                newNode->next = top;
                top = newNode;
            }
        }
        void pop(){
            if(top == NULL){
                cout << "Stack is empty" << endl;
            }
            else{
                Node *temp = top;
                top = top->next;
                delete temp;
            }
        }
        void display(){
            Node *temp = top;
            while(temp != NULL){
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
        bool isEmpty(){
            if(top == NULL)
                return true;
            else
                return false;
        }
        char peek(){
            if(top == NULL){
                cout << "Stack is empty" << endl;
                return 0;
            }
            else{
                return top->data;
            }
        }

        void isBalanced(string expression){
            for(int i=0; i<expression.length(); i++){
                if(expression[i] == '(' || expression[i] == '{' || expression[i] == '['){
                    push(expression[i]);
                }
                else if(expression[i] == ')' || expression[i] == '}' || expression[i] == ']'){
                    if(isEmpty()){
                        cout << "Not Balanced" << endl;
                        return;
                    }
                    else if(expression[i] == ')' && peek() == '('){
                        pop();
                    }
                    else if(expression[i] == '}' && peek() == '{'){
                        pop();
                    }
                    else if(expression[i] == ']' && peek() == '['){
                        pop();
                    }
                    else{
                        cout << "Not Balanced" << endl;
                        return;
                    }
                }
            }
            if(isEmpty()){
                cout << "Balanced" << endl;
            }
            else{
                cout << "Not Balanced" << endl;
            }
        }
    // Checks the bracket pair in order like (){}[].
    void isPriorityBalanced(string expression){
        for(int i=0; i<expression.length(); i++){
            if(expression[i] == '(' || expression[i] == '{' || expression[i] == '['){
                push(expression[i]);
            }
            else if(expression[i] == ')' || expression[i] == '}' || expression[i] == ']'){
                if(isEmpty()){
                    cout << "Not Balanced" << endl;
                    return;
                }
                else if(expression[i] == ')' && peek() == '('){
                    pop();
                }
                else if(expression[i] == '}' && peek() == '{'){
                    pop();
                }
                else if(expression[i] == ']' && peek() == '['){
                    pop();
                }
                else{
                    cout << "Not Balanced" << endl;
                    return;
                }
            }
        }
        if(isEmpty()){
            cout << "Balanced" << endl;
        }
        else{
            cout << "Not Balanced" << endl;
        }
    }
    
};

int main(){
    Stack s;
    string expression = "((a+b)*(c-d))";
    s.isBalanced(expression);
    string expression2 = "[{}(){()}]";
    s.isBalanced(expression2);
    string expression3 = "[{( )}]";
    s.isBalanced(expression3);
    string expression4 = "[({})]";
    s.isPriorityBalanced(expression4);

    return 0;

}