#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j + 1] < arr[j])
            {
                swap(arr[j + 1], arr[j]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}
void selectionSort( int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i+1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        swap(arr[minIndex], arr[i]);
    }
}
void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int j = i - 1;
        int key = arr[i];
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[++j] = key;
    }
}
void mergeSort(int arr[], int l, int r)
// l = left, r = right
{
    if (l >= r)
        return;
    int mid = (l + r) / 2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);
    int i = l, j = mid + 1, k = 0;
    int temp[r - l + 1];
    while (i <= mid && j <= r)
    {
        if (arr[i] < arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }
    while (i <= mid)
        temp[k++] = arr[i++];
    while (j <= r)
        temp[k++] = arr[j++];
    for (int i = l; i <= r; i++)
        arr[i] = temp[i - l];
}
// Recursive bubbleSort
void bubbleSortRecursive(int arr[], int n)
{
    if (n == 1)
        return;
    bool swapped = false;
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i + 1] < arr[i])
        {
            swap(arr[i + 1], arr[i]);
            swapped = true;
        }
    }
    if (swapped)
        bubbleSortRecursive(arr, n - 1);
}
// bubble sort for Linked List
struct Node
{
    int data;
    Node *next;
};
void bubbleSortLinkedList(Node *head)
{
    Node *curr = head;
    while (curr)
    {
        Node *temp = curr->next;
        while (temp)
        {
            if (curr->data > temp->data)
                swap(curr->data, temp->data);
            temp = temp->next;
        }
        curr = curr->next;
    }
}
// Selection sort for Linked List
void selectionSortLinkedList(Node *head)
{
    Node *curr = head;
    while (curr)
    {
        Node *minNode = curr;
        Node *temp = curr->next;
        while (temp)
        {
            if (temp->data < minNode->data)
                minNode = temp;
            temp = temp->next;
        }
        swap(curr->data, minNode->data);
        curr = curr->next;
    }
}
// Insertion sort for Linked List
void insertionSortLinkedList(Node *head)
{
    Node *curr = head;
    while (curr)
    {
        Node *temp = curr->next;
        while (temp)
        {
            if (curr->data > temp->data)
                swap(curr->data, temp->data);
            temp = temp->next;
        }
        curr = curr->next;
    }
}


int main(){
    int arr[] = {5, 4, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    int arr2[] = {5, 4, 3, 2, 1};
    selectionSort(arr2, n);
    for (int i = 0; i < n; i++)
        cout << arr2[i] << " ";
    cout << endl;
    int arr3[] = {5, 4, 3, 2, 1};
    insertionSort(arr3, n);
    for (int i = 0; i < n; i++)
        cout << arr3[i] << " ";
    cout << endl;
    int arr4[] = {5, 4, 3, 2, 1};
    mergeSort(arr4, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << arr4[i] << " ";
    cout << endl;
    int arr5[] = {5, 4, 3, 2, 1};
    bubbleSortRecursive(arr5, n);
    for (int i = 0; i < n; i++)
        cout << arr5[i] << " ";
    cout << endl;
    // Linked List
    Node *head = new Node();
    head->data = 5;
    head->next = new Node();
    head->next->data = 4;
    head->next->next = new Node();
    head->next->next->data = 3;
    head->next->next->next = new Node();
    head->next->next->next->data = 2;
    head->next->next->next->next = new Node();
    head->next->next->next->next->data = 1;
    head->next->next->next->next->next = NULL;
    bubbleSortLinkedList(head);
    Node *curr = head;
    while (curr)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
    Node *head2 = new Node();
    head2->data = 5;
    head2->next = new Node();
    head2->next->data = 4;
    head2->next->next = new Node();
    head2->next->next->data = 3;
    head2->next->next->next = new Node();
    head2->next->next->next->data = 2;
    head2->next->next->next->next = new Node();
    head2->next->next->next->next->data = 1;
    head2->next->next->next->next->next = NULL;
    selectionSortLinkedList(head2);
    Node *curr2 = head2;
    while (curr2)
    {
        cout << curr2->data << " ";
        curr2 = curr2->next;
    }
    cout << endl;
    Node *head3 = new Node();
    head3->data = 5;
    head3->next = new Node();
    head3->next->data = 4;
    head3->next->next = new Node();
    head3->next->next->data = 3;
    head3->next->next->next = new Node();
    head3->next->next->next->data = 2;
    head3->next->next->next->next = new Node();
    head3->next->next->next->next->data = 1;
    head3->next->next->next->next->next = NULL;
    insertionSortLinkedList(head3);
    Node *curr3 = head3;
    while (curr3)
    {
        cout << curr3->data << " ";
        curr3 = curr3->next;
    }
    cout << endl;
    
    
    return 0;
}