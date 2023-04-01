#include <iostream>

using namespace std;

// Node class
class Node {
public:
    int data;
    Node* next;
};

// Linked list class
class LinkedList {
public:
    Node* head;

    // Constructor
    LinkedList() {
        head = nullptr;
    }

    // Insert a new node at the beginning of the list
    void insert(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = head;
        head = newNode;
    }

    // Append a new node at the end of the list
    void append(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* curr = head;
            while (curr->next != nullptr) {
                curr = curr->next;
            }
            curr->next = newNode;
        }
    }

    // Delete a node with a given data value
    void remove(int data) {
        if (head == nullptr) {
            return;
        }

        if (head->data == data) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* curr = head;
        while (curr->next != nullptr && curr->next->data != data) {
            curr = curr->next;
        }
        if (curr->next != nullptr) {
            Node* temp = curr->next;
            curr->next = temp->next;
            delete temp;
        }
    }

    // Traverse the list and print the data values of each node
    void traverse() {
        Node* curr = head;
        while (curr != nullptr) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }
};

int main() {
    // Create a new linked list
    LinkedList list;

    // Insert some nodes at the beginning of the list
    list.insert(1);
    list.insert(2);
    list.insert(3);

    // Append some nodes at the end of the list
    list.append(4);
    list.append(5);
    list.append(6);

    // Traverse the list and print the data values of each node
    cout << "List contents: ";
    list.traverse();

    // Remove some nodes from the list
    list.remove(3); 
    list.remove(6);

    // Traverse the list and print the data values of each node
    cout << "List contents after removal: ";
    list.traverse();

    return 0;
}
