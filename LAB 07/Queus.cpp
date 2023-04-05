#include <iostream>
using namespace std;

class que
{
public:
    int size;
    int *q;
    int front;
    int rear;
    que()
    {
        size = 10;
        q = new int[size];
        front = rear = -1;
    }
    que(int size)
    {
        this->size = size;
        q = new int[this->size];
        front = rear = -1;
    }
    bool isEmpty()
    {
        if (front == rear)
        {
            return true;
        }
        return false;
    }
    bool isFull()
    {
        if (rear == size - 1)
        {
            return true;
        }
        return false;
    }
    void enqueue(int x)
    {
        if (isFull())
        {
            cout << "Queue is Full" << endl;
        }
        else
        {
            rear++;
            q[rear] = x;
        }
    }
    int dequeue()
    {
        int x = -1;
        if (isEmpty())
        {
            cout << "Queue is Empty" << endl;
        }
        else
        {
            front++;
            x = q[front];
        }
        return x;
    }
    void display()
    {
        for (int i = front + 1; i <= rear; i++)
        {
            cout << q[i] << " ";
        }
        cout << endl;
    }

    //  A method which also shifts the element left
    int deQue(){
        int x = -1;
        if(isEmpty()){
            cout << "Queue is Empty" << endl;
        }
        else{
            x = q[front + 1];
            for(int i = front + 1; i < rear; i++){
                q[i] = q[i + 1];
            }
            rear--;
        }
        return x;
    }
    void shiftLeft(int front,int rear){
        for(int i = front + 1; i < rear; i++){
            q[i] = q[i + 1];
        }
        rear--;
    }

};
class Deque{
    public:
    int size;
    int *q;
    int front;
    int rear;
    Deque(){
        size = 10;
        q = new int[size];
        front = rear = -1;
    }
    Deque(int size){
        this->size = size;
        q = new int[this->size];
        front = rear = -1;
    }
    bool isEmpty(){
        if(front == rear){
            return true;
        }
        return false;
    }
    bool isFull(){
        if(rear == size - 1){
            return true;
        }
        return false;
    }
    void insertFront(int x){
        if(isFull()){
            cout << "Queue is Full" << endl;
        }
        else{
            for(int i = rear; i > front; i--){
                q[i + 1] = q[i];
            }
            front++;
            q[front] = x;
            rear++;
        }
    }
    void insertRear(int x){
        if(isFull()){
            cout << "Queue is Full" << endl;
        }
        else{
            rear++;
            q[rear] = x;
        }
    }
    int deleteFront(){
        int x = -1;
        if(isEmpty()){
            cout << "Queue is Empty" << endl;
        }
        else{
            x = q[front + 1];
            for(int i = front + 1; i < rear; i++){
                q[i] = q[i + 1];
            }
            rear--;
        }
        return x;
    }
    int deleteRear(){
        int x = -1;
        if(isEmpty()){
            cout << "Queue is Empty" << endl;
        }
        else{
            x = q[rear];
            rear--;
        }
        return x;
    }
    void display(){
        for(int i = front + 1; i <= rear; i++){
            cout << q[i] << " ";
        }
        cout << endl;
    }
};


int main()
{
    que q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.display();
    q.dequeue();
    q.display();
    // Some more test cases with different values
    que q2(5);
    q2.enqueue(15);
    q2.enqueue(25);
    q2.enqueue(35);
    q2.enqueue(45);
    q2.enqueue(55);
    q2.display();
    q2.dequeue();
    q2.display();

    // testing shift Left
    que q3(5);
    q3.enqueue(15);
    q3.enqueue(25);
    q3.enqueue(35);
    q3.enqueue(45);
    q3.enqueue(55);
    q3.display();
    cout<<"Shift Left"<<endl;
    q3.shiftLeft(q3.front,q3.rear);
    q3.display();



    
    return 0;
}