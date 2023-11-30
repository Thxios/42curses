
#include <iostream>
#include "Animal.h"
#include "Cat.h"
#include "Dog.h"
#include "WrongAnimal.h"
#include "WrongCat.h"
#include "WrongDog.h"


int main() {
    const Animal* meta = new Animal();
    const Animal* i = new Cat();
    const Animal* j = new Dog();

    std::cout << i->getType() << " " << std::endl;
    std::cout << j->getType() << " " << std::endl;

    i->makeSound();
    j->makeSound();
    meta->makeSound();

    delete i;
    delete j;
    delete meta;

    std::cout << "\n=====\n" << std::endl;

    
    const WrongAnimal* meta2 = new WrongAnimal();
    const WrongAnimal* i2 = new WrongCat();
    const WrongAnimal* j2 = new WrongDog();

    i2->makeSound();
    j2->makeSound();
    meta2->makeSound();

    delete meta2;
    // delete i2;  // Error
    // delete j2;

    std::cout << "\n=====\n" << std::endl;

    std::cout << "sizeof Cat: " << sizeof(*i) << std::endl;
    std::cout << "sizeof WrongCat: " << sizeof(*i2) << std::endl;
}
