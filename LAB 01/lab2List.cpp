// HASAAN AHMAD 
// SP22-BSE-017

#include<iostream>  
#include<list>  
using namespace std; 
// METHOD TO PRINT LIST
void showlist(list<int> g)
{
    list<int>::iterator it;
    for (it = g.begin(); it != g.end(); ++it)
        cout << '\t' << *it;
    cout << '\n';
}

// MAIN METHODS
int main()
{
    list<int> myList = {23,4,35,65};
    // TO ACCESS THE LAST ELEMENT
    cout<<myList.back();
    // To Insert in the end
    myList.emplace_back(30);
    showlist(myList);
    // To insert in the start
    myList.emplace_front(20);
    showlist(myList);
    // Insert at specific position
    // Takes pointer
    auto it = myList.begin();
    // ADVANCING THE ITERATOR
    advance(it,2);
    myList.emplace(it,15);
    showlist(myList);
    

    // To remove first element
    myList.pop_front();
    showlist(myList);
    // To remove last element
    myList.pop_back();
    showlist(myList);

// TO REMOVE AT SPECIFIC PLACE
    it = myList.begin();
    advance(it,2);
    myList.erase(it);
    showlist(myList);

// NICELY DONE SEE YA LATER
    return 0;
}
