#include <iostream>
#include <string>

class Animal {
public:
  // Constructor function
  Animal(std::string name, int age, std::string species) 
      : name_(name), age_(age), species_(species) {}

  // Public methods
  void speak() {
    std::cout << "Hello, my name is " << name_ << " and I am a " << species_
              << " who is " << age_ << " years old.\n";
  }

private:
  std::string name_;
  int age_;
  std::string species_;
};

int main() {
  Animal dog("Fido", 5, "dog");
  dog.speak();

  Animal cat("Fluffy", 3, "cat");
  cat.speak();

  return 0;
}
