#include <iostream>
using namespace std;
 
class Stack{
    private:
        int top;
        int arr[5];
    public:
        Stack(){
            top = -1;
            for(int i=0; i<5; i++){
                arr[i] = 0;
            }
        }
        bool isEmpty(){
            if(top == -1)
                return true;
            else
                return false;
        }
        bool isFull(){
            if(top == 4)
                return true;
            else
                return false;
        }
        void push(int val){
            if(isFull()){
                cout << "Stack Overflow" << endl;
            }
            else{
                top++;
                arr[top] = val;
            }
        }
        int pop(){
            if(isEmpty()){
                cout << "Stack Underflow" << endl;
                return 0;
            }
            else{
                int popValue = arr[top];
                arr[top] = 0;
                top--;
                return popValue;
            }
        }
        int count(){
            return (top + 1);
        }
        int peek(int pos){
            if(isEmpty()){
                cout << "Stack Underflow" << endl;
                return 0;
            }
            else{
                return arr[pos];
            }
        }
        void display(){
            cout << "All values in the Stack are " << endl;
            for(int i=4; i>=0; i--){
                cout << arr[i] << endl;
            }
        }
};


int main(){
    Stack s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);
    s1.push(50);
    s1.display();
    cout<<"Peeking value at position 2: "<<s1.peek(2)<<endl;
    
    return 0;
}