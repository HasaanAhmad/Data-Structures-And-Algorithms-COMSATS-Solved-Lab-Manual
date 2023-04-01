
#include <iostream>
using namespace std;

int main() {
   int arr[] = { 3, 5, 2, 8, 1, 9 };
   int n = sizeof(arr) / sizeof(arr[0]); // Calculate the size of the array
   int key = 8; // Element to search
   int i = 0;
   
   while (i < n && arr[i] != key) { 
      i++;
   }
   
   if (i < n) {
      cout << "Element found at index " << i << endl;
   }
   else {
      cout << "Element not found" << endl;
   }
   
   return 0;
}
