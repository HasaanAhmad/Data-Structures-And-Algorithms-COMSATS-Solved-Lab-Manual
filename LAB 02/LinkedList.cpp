#include <iostream>
using namespace std;


// Node class implementation
class Node{
    public:
    int data;
    Node* next;

    // Constructor
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

// node class Head insertion method
void insertAtHead(Node* &head, int data) {
    // Creating a new node
    Node* temp = new Node(data);
    temp ->next= head;
    head = temp;
};

// Node printing method
void print(Node* &head){
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data <<"  ";
        temp = temp->next;
};
    cout << endl;

};
// Main Method
int main(){
    cout<<"Welcome"<<endl;
// Creating a new node
    Node* node1 = new Node(10);

    // Printing the data
    // cout<< node1->data << endl;
    // cout << node1->next << endl;
    
    // Head pointer to node1
    Node* head = node1;
    print(head);
    insertAtHead(head,12);
    print(head);

    insertAtHead(head,15);

    print(head);



    return 0;
}