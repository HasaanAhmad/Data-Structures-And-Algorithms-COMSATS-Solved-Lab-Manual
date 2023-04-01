#include <iostream>
using namespace std;
int main(){
	int x;
	cout << "Enter the number of elements of arrays: ";
	cin>>x;
	int arr[x];
	int option;
	while(true){
	
	int val;
	cout<<"1: Insert the value at the end of the list: " <<endl;
	cout<<"2: Insert the value at the start of the list: " << endl;
	cout<<"3: Insert the value after specific value: "<<endl;
	cout<<"4: Insert the value before specific value: "<<endl;
	cout<<"5: Display the array List: "<<endl;
	cout<<"6: Delete the value from end of the list: " <<endl;
	cout<<"7: Delete the value from the start of the list"<<endl;
	cout<<"8: Delete the specific value"<<endl;
	
	cout<< "Choose the option from 1 - 8"<<endl;
	cin>>option;
	switch(option){
		case 1:
			cin>>val;
			arr[x-1] = val;
			break;
		case 2:
			cin>>val;
			arr[0] = val;
			break;
		case 3:
			cin>>val;
			cout << "Enter a specific Value:";
			int elem;
			cin >>elem;
			arr[val]=elem;
			break;
		case 4:
			cin>>val;
			cout << "Enter a specific Value:";
			int elem2;
			cin >>elem2;
			arr[val-1]=elem2;
			break;
		case 5:
			for(int i=0;i < x;i++){
				cout <<arr[i] << endl;
			}
			break;
		case 6:
			cin>>val;
			arr[x-1] = 0;
			break;
		case 7:
			cin>>val;
			arr[0] = 0;
			break;
		case 8:
			cin>>val;
			arr[val-1] = 0;
			break;
		default:
			cout<<"Please choose a valid option: ";	
					
	}
}
}
