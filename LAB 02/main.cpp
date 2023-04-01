#include <iostream>
using namespace std;
 
int main(){
    cout<<"Hello world!"<<endl;
    int a=5;
    int b=7;
    cout <<"Before Swaping";
    cout<<a <<"  " <<b<<endl;
    cout <<"After swapping";
    swap(a,b);
    cout<<a <<"  " <<b <<endl;

    return 0;
}

int swap(int &x , int &y){
    int temp = x;
    x = y;
    y = temp;   
}
