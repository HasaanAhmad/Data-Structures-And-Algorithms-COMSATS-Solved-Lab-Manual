#include <iostream>
#include <string>

using namespace std;

struct Car {
    string make;
    string model;
    int year;

};

typedef struct{
    string name;
    string birthPlace;
    int age;
    bool canAffordCar;

}person;


person DoPrint(person anyVar){
   cout<<"The Name of person is " <<anyVar.name << " who is "<<anyVar.age <<"Years old. " <<"And he lives at " <<anyVar.birthPlace <<endl;
   if (anyVar.canAffordCar)
   {
    cout<<"Vrom Vrom Baby! I have the car" <<endl;
   }
   else{
    cout <<"Paisy... paisy tw nahi hennn!!!"<<endl;
   }
   return anyVar;
       
};

int main() {
    Car myCar;
    myCar.make = "Toyota";
    myCar.model = "Aqua";
    myCar.year = 2022;

    cout << "My car is a " << myCar.year << " " << myCar.make << " " << myCar.model << endl;


    person Mujtaba;
    Mujtaba.age=20;
    Mujtaba.birthPlace="Isb";
    Mujtaba.name="Mujtaba";
    Mujtaba.canAffordCar=true;

    person *Hasaan = new person();
    Hasaan->age=20;
    Hasaan->name="Hasaan Ahmad";
    Hasaan->birthPlace="Home";
    Hasaan->canAffordCar=false;

    DoPrint(*Hasaan);
    cout<<endl;
    DoPrint(Mujtaba);

    return 0;

}

