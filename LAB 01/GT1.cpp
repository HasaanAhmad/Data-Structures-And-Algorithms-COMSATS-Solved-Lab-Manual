#include <iostream>
using namespace std;
int main(){
	int terms;
	int x,y;
	cout <<"Enter the starting value: ";
	cin>>y;
	cout<<"Enter the stopping value: ";
	cin>>terms;
	int sum;
	for(int i = y; i <= terms; i++){
		sum += (i*i);
	}
	cout << "The sum is " << sum << endl;
	}
