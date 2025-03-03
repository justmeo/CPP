#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    const int size = 4;
    Animal* animals[size];
    
    // Create an array of Animal pointers (half Dogs, half Cats)
    for (int i = 0; i < size; i++) {
        if (i % 2 == 0)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }
    
    // Test polymorphic behavior
    for (int i = 0; i < size; i++) {
        std::cout << animals[i]->getType() << std::endl;
        animals[i]->makeSound();
    }
    
    // Test deep copy for Dog
    Dog* dog1 = new Dog();
    Dog* dog2 = new Dog(*dog1); // copy constructor
    *dog2 = *dog1;            // copy assignment
    dog1->makeSound();
    dog2->makeSound();
    delete dog1;
    delete dog2;
    
    // Clean up array
    for (int i = 0; i < size; i++)
        delete animals[i];
    
    return 0;
}
