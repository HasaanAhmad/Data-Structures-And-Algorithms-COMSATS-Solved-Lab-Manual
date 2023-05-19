
#include <iostream>
using namespace std;
 
// Make BST Using Recursive Approach
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
class BST{
    public:
    Node* root;
    // Insertion method for BST using Recursion and Base Cases
    Node* insert(int data){
        Node* newNode = new Node(data);
        if(root == NULL){
            root = newNode;
            return root;
        }
        Node* temp = root;
        while(temp!=NULL){
            if(data < temp->data){
                if(temp->left == NULL){
                    temp->left = newNode;
                    return root;
                }
                temp = temp->left;
            }
            else{
                if(temp->right == NULL){
                    temp->right = newNode;
                    return root;
                }
                temp = temp->right;
            }
        }
        return root;
    }
    // Search method for BST using Recursion and Base Cases
    Node* search(int key){
        Node* temp = root;
        while(temp!=NULL){
            if(temp->data == key){
                return temp;
            }
            else if(key < temp->data){
                temp = temp->left;
            }
            else{
                temp = temp->right;
            }
        }
        return NULL;
    }
    // Delete method for BST using Recursion and Base Cases
    Node* deleteNode(int key){
        Node* temp = root;
        Node* parent = NULL;
        while(temp!=NULL){
            if(temp->data == key){
                break;
            }
            else if(key < temp->data){
                parent = temp;
                temp = temp->left;
            }
            else{
                parent = temp;
                temp = temp->right;
            }
        }
        if(temp == NULL){
            return root;
        }
        // Case 1: Node to be deleted is a leaf node
        if(temp->left == NULL && temp->right == NULL){
            if(parent == NULL){
                root = NULL;
                return root;
            }
            if(parent->left == temp){
                parent->left = NULL;
            }
            else{
                parent->right = NULL;
            }
            delete temp;
            return root;
        }
        // Case 2: Node to be deleted has only one child
        if(temp->left == NULL && temp->right != NULL){
            if(parent == NULL){
                root = temp->right;
                delete temp;
                return root;
            }
            if(parent->left == temp){
                parent->left = temp->right;
            }
            else{
                parent->right = temp->right;
            }
            delete temp;
            return root;
        }
        if(temp->left != NULL && temp->right == NULL){
            if(parent == NULL){
                root = temp->left;
                delete temp;
                return root;
            }
            if(parent->left == temp){
                parent->left = temp->left;
            }
            else{
                parent->right = temp->left;
            }
            delete temp;
            return root;
        }
        // Case 3: Node to be deleted has two children
        Node* minNode = temp->right;
        Node* minParent = temp;
        while(minNode->left!=NULL){
            minParent = minNode;
            minNode = minNode->left;
        }
        temp->data = minNode->data;
        if(minParent->left == minNode){
            minParent->left = minNode->right;
        }
        else{
            minParent->right = minNode->right;
        }
        delete minNode;
        return root;
    }
    
};

int main(){
    
    return 0;
}