#include <iostream>
using namespace std;
 
int main(){
    int a = 100;
    int arr[] = {23,3,4,34};
    string sArr[3]= {"Hasaan", "Ahmad", "Well Ykm right?"};

    string* sPoint = &sArr[0];

    int* pointer = &a;
    int* point = &arr[0];
    cout<<a <<endl;
    cout<<pointer <<endl;
    cout<< *pointer <<endl;
    cout<< point <<endl;
    cout << *point <<endl;
    cout << sPoint<<endl;
    cout << *(sPoint++)<<endl;
    cout << *(sPoint++)<<endl;
    cout << *(sPoint++)<<endl;
    

    return 0;
}