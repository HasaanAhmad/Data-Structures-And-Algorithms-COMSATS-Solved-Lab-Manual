
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
    
};

int main(){
    
    return 0;
}