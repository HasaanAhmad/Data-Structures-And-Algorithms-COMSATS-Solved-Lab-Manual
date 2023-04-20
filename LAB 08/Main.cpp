#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
class BST
{
public:
    Node *root;
    Node *insert(int data)
    {
        Node *newNode = new Node(data);
        if (root == NULL)
        {
            root = newNode;
            return root;
        }
        Node *temp = root;
        while (temp != NULL)
        {
            if (data < temp->data)
            {
                if (temp->left == NULL)
                {
                    temp->left = newNode;
                    return root;
                }
                temp = temp->left;
            }
            else
            {
                if (temp->right == NULL)
                {
                    temp->right = newNode;
                    return root;
                }
                temp = temp->right;
            }
        }
        return root;
    }

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
    Node* inOrder(){
        Node* temp = root;
        while(temp!=NULL){
            if(temp->left == NULL){
                cout<<temp->data<<" ";
                temp = temp->right;
            }
            else{
                Node* pre = temp->left;
                while(pre->right!=NULL && pre->right!=temp){
                    pre = pre->right;
                }
                if(pre->right == NULL){
                    pre->right = temp;
                    temp = temp->left;
                }
                else{
                    pre->right = NULL;
                    cout<<temp->data<<" ";
                    temp = temp->right;
                }
            }
        }
    }
    Node* postOrder(){
        Node* temp = root;
        while(temp!=NULL){
            if(temp->left == NULL){
                cout<<temp->data<<" ";
                temp = temp->right;
            }
            else{
                Node* pre = temp->left;
                while(pre->right!=NULL && pre->right!=temp){
                    pre = pre->right;
                }
                if(pre->right == NULL){
                    pre->right = temp;
                    temp = temp->left;
                }
                else{
                    pre->right = NULL;
                    cout<<temp->data<<" ";
                    temp = temp->right;
                }
            }
        }
    }
    Node* preOrder(){
        Node* temp = root;
        while(temp!=NULL){
            if(temp->left == NULL){
                cout<<temp->data<<" ";
                temp = temp->right;
            }
            else{
                Node* pre = temp->left;
                while(pre->right!=NULL && pre->right!=temp){
                    pre = pre->right;
                }
                if(pre->right == NULL){
                    pre->right = temp;
                    cout<<temp->data<<" ";
                    temp = temp->left;
                }
                else{
                    pre->right = NULL;
                    temp = temp->right;
                }
            }
        }
    }
};

int main()
{

    return 0;
}