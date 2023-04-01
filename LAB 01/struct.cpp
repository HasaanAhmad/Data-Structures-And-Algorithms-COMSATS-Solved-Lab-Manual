// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;


struct student{
    int roll,marks;
    string name;
    char grade;
};
// METHOD TO PRINT STRUCT USING POINTER
void printStruct(struct student *student){
    cout<<"The roll number of student is "<<student ->roll <<endl;
    cout<<"Marks of student are "<<student ->marks <<endl;
    cout<<"Name is "<<student ->name <<endl;
    cout<<"His grade is "<<student ->grade <<endl;
}

int main() {

    // INITIALIZING A STRUCT
    student Hasaan;
    // ADDING VALUES TO STRUCT

    Hasaan.roll=017;
    Hasaan.name="Hasaan";
    Hasaan.marks=49;
    Hasaan.grade='A';

    student Usman;
    cout<<"Enter your Roll no";
    cin>>Usman.roll;
    cout<<"Enter your Marks";
    cin>>Usman.marks;
    cout<<"Enter your grade";
    cin>>Usman.grade;
    cout<<"Enter your Name";
    cin>>Usman.name;
    // Printing strut using method

    printStruct(&Hasaan);
    printStruct(&Usman);

    return 0;
}

