#include <iostream>
using namespace std;

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
};

class Infix{
    private:
        string exp;
    public:
        Infix(string exp){
            this->exp = exp;
        }
        bool isOperator(char c){
            if(c == '+' || c == '-' || c == '*' || c == '/')
                return true;
            else
                return false;
        }
        int precedence(char c){
            if(c == '*' || c == '/')
                return 3;
            else if(c == '+' || c == '-')
                return 2;
            else
                return 0;
        }
        string convert(){
            string postfix = "";
            Stack s;
            for(int i=0; i<exp.length(); i++){
                if((exp[i] >= 'a' && exp[i] <= 'z') || (exp[i] >= 'A' && exp[i] <= 'Z')){
                    postfix += exp[i];
                }
                else if(exp[i] == '('){
                    s.push(exp[i]);
                }
                else if(exp[i] == ')'){
                    while((s.top->data != '(') && (!s.isEmpty())){
                        char temp = s.top->data;
                        s.pop();
                        postfix += temp;
                    }
                    if(s.top->data == '('){
                        s.pop();
                    }
                }
                else if(isOperator(exp[i])){
                    if(s.isEmpty()){
                        s.push(exp[i]);
                    }
                    else{
                        if(precedence(exp[i]) > precedence(s.top->data)){
                            s.push(exp[i]);
                        }
                        else if((precedence(exp[i]) == precedence(s.top->data)) && (exp[i] == '^')){
                            while((precedence(exp[i]) == precedence(s.top->data)) && (exp[i] == '^')){
                                char temp = s.top->data;
                                s.pop();
                                postfix += temp;
                            }
                            s.push(exp[i]);
                        }
                        else if(precedence(exp[i]) == precedence(s.top->data)){
                            s.push(exp[i]);
                        }
                        else{
                            while((!s.isEmpty()) && (precedence(exp[i]) < precedence(s.top->data))){
                                char temp = s.top->data;
                                s.pop();
                                postfix += temp;
                            }
                            s.push(exp[i]);
                        }
                    }
                }
            }
            while(!s.isEmpty()){
                char temp = s.top->data;
                s.pop();
                postfix += temp;
            }
            return postfix;
        }
};

class Postfix{
    private:
        string exp;
    public:
        Postfix(string exp){
            this->exp = exp;
        }
        bool isOperator(char c){
            if(c == '+' || c == '-' || c == '*' || c == '/')
                return true;
            else
                return false;
        }
        int performOperation(char operation, int operand1, int operand2){
            if(operation == '+')
                return operand1 + operand2;
            else if(operation == '-')
                return operand1 - operand2;
            else if(operation == '*')
                return operand1 * operand2;
            else if(operation == '/')
                return operand1 / operand2;
            else
                return -1;
        }
        int evaluatePostfix(string exp){
            Stack s;
            for(int i=0; i<exp.length(); i++){
                if(exp[i] >= '0' && exp[i] <= '9'){
                    s.push(exp[i] - '0');
                }
                else if(isOperator(exp[i])){
                    int operand2 = s.top->data;
                    s.pop();
                    int operand1 = s.top->data;
                    s.pop();
                    int result = performOperation(exp[i], operand1, operand2);
                    s.push(result);
                }
            }
            return s.top->data;
        }
};

int main(){
    
    // testing infix to postfix conversion
     string exp = "a+b*(c^d-e)^(f+g*h)-i";
    Infix i(exp);
    string postfix = i.convert();
    cout << "Postfix expression: " << postfix << endl;
    // Testing numbers infix Expression
    string exp1 = "2+3*4+(4-6/2)*5";
    Infix i1(exp1);
    string postfix1 = i1.convert();
    cout << "Postfix expression: " << postfix1 << endl;
    // Testing numbers postfix Expression
    return 0;
}