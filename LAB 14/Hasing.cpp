// Impliment hashing with linear and quadratic probing
#include <iostream>
using namespace std;
 
class Hasing{

    int hashKey(int key){
        return key % 10;
    }
    int hashKey2(int key){
        return 7 - (key % 7);
    }
    int linearProbing(int key, int i){
        return (hashKey(key) + i) % 10;
    }
    int quadraticProbing(int key, int i){
        return (hashKey(key) + i * i) % 10;
    }
};
int main(){
    
    return 0;
}