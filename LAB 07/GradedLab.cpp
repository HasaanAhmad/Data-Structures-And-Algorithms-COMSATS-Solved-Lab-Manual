#include <iostream>
using namespace std;
// Graded Lab 1

/*
Implement the methods developed in Activity 1 for Dynmaic Queue i.e. Linked Implementation of the Queue.
*/

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
class Queue
{
public:
    Node *front;
    Node *rear;
    int size;
    Queue()
    {
        front = NULL;
        rear = NULL;
        size = 0;
    }
    void enqueue(int data)
    {
        Node *newNode = new Node(data);
        if (front == NULL)
        {
            front = newNode;
            rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
        size++;
    }
    void dequeue()
    {
        if (front == NULL)
        {
            cout << "Queue is empty" << endl;
        }
        else
        {
            Node *temp = front;
            front = front->next;
            delete temp;
            size--;
        }
    }
    int getSize()
    {
        return size;
    }
    bool isEmpty()
    {
        return size == 0;
    }
    int getFront()
    {
        if (front == NULL)
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return front->data;
    }
    int getRear()
    {
        if (rear == NULL)
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return rear->data;
    }
    void print()
    {
        Node *temp = front;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void shiftLeft(Node *front, Node *rear)
    {
        Node *temp = front;
        while (temp != NULL)
        {
            temp->data = temp->next->data;
            temp = temp->next;
        }
        rear->data = 0;
    }
};

class Deque{
    public:
    Node *front;
    Node *rear;
    int size;
    Deque(){
        front = NULL;
        rear = NULL;
        size = 0;
    }
    void enqueueFront(int data){
        Node *newNode = new Node(data);
        if(front == NULL){
            front = newNode;
            rear = newNode;
        }
        else{
            newNode->next = front;
            front = newNode;
        }
        size++;
    }
    void enqueueRear(int data){
        Node *newNode = new Node(data);
        if(front == NULL){
            front = newNode;
            rear = newNode;
        }
        else{
            rear->next = newNode;
            rear = newNode;
        }
        size++;
    }
    void dequeueFront(){
        if(front == NULL){
            cout << "Queue is empty" << endl;
        }
        else{
            Node *temp = front;
            front = front->next;
            delete temp;
            size--;
        }
    }
    void dequeueRear(){
        if(front == NULL){
            cout << "Queue is empty" << endl;
        }
        else{
            Node *temp = front;
            while(temp->next != rear){
                temp = temp->next;
            }
            delete rear;
            rear = temp;
            rear->next = NULL;
            size--;
        }
    }
    int getSize(){
        return size;
    }
    bool isEmpty(){
        return size == 0;
    }
    int getFront(){
        if(front == NULL){
            cout << "Queue is empty" << endl;
            return -1;
        }
        return front->data;
    }
    int getRear(){
        if(rear == NULL){
            cout << "Queue is empty" << endl;
            return -1;
        }
        return rear->data;
    }
    void print(){
        Node *temp = front;
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    // Implimenting Queue
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.print();
    cout << q.getSize() << endl;
    q.dequeue();
    q.print();
    cout << q.getSize() << endl;
    cout << q.isEmpty() << endl;
    cout << q.getFront() << endl;
    cout << q.getRear() << endl;
    q.print();

    // Implimenting Deque

    cout<<"Deque" << endl;

    Deque d;
    d.enqueueFront(1);
    d.enqueueFront(2);
    d.enqueueFront(3);
    d.enqueueFront(4);
    d.enqueueFront(5);
    d.print();
    
    return 0;
}