#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
    const Animal* meta = new Animal();
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();
    
    std::cout << dog->getType() << std::endl;
    std::cout << cat->getType() << std::endl;
    
    dog->makeSound(); // Dog sound
    cat->makeSound(); // Cat sound
    meta->makeSound(); // Animal sound
    
    std::cout << std::endl;
    
    const WrongAnimal* wrong = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();
    
    wrong->makeSound();     // WrongAnimal sound
    wrongCat->makeSound();  // Still WrongAnimal sound because function is not virtual
    
    delete meta;
    delete dog;
    delete cat;
    delete wrong;
    delete wrongCat;
    
    return 0;
}
