#include <iostream>
using namespace std;
struct date
{
    int year;
    int month;
    int date;
};
 
struct person{
    string name;
    int salary;
    struct date dob;
};

person printPerson(person any){
    cout<<"Name of person is "<< any.name << " who gets " <<any.salary <<endl;
    cout<<any.dob.date <<"-" <<any.dob.month << "-" << any.dob.year;
};


int main(){
  person Hasaan = {"Hasaan",5000,{2002,11,12}};
    printPerson(Hasaan);
    return 0;

}


