#include <iostream>
using namespace std;
 
class Node{
    public:
        int data;
        Node *next;
      Node(int x){
          data = x;
          next = NULL;
      }
};
class queue{
    public:
        Node *front;
        Node *rear;
        queue(){
            front = rear = NULL;
        }
        void enqueue(int x){
            Node *t = new Node(x);
            if(front == NULL){
                front = rear = t;
            }
            else{
                rear->next = t;
                rear = t;
            }
        }
        int dequeue(){
            int x = -1;
            if(front == NULL){
                cout << "Queue is Empty" << endl;
            }
            else{
                Node *t = front;
                front = front->next;
                x = t->data;
                delete t;
            }
            return x;
        }
        void display(){
            Node *p = front;
            while(p){
                cout << p->data << " ";
                p = p->next;
            }
            cout << endl;
        }
        
};


int main(){
    
    return 0;
}