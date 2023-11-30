
#include <iostream>
#include "Animal.h"
#include "Cat.h"
#include "Dog.h"
#include "WrongAnimal.h"
#include "WrongCat.h"
#include "WrongDog.h"


int main() {
    {
        const Animal* i = new Cat();
        const Animal* j = new Dog();

        delete i;
        delete j;
    }

    std::cout << "\n===============\n" << std::endl;

    {
        Animal* animals[10];
        for (int i = 0; i < 10; i++) {
            if (i < 5) {
                animals[i] = new Dog();
            }
            else {
                animals[i] = new Cat();
            }
        }
        std::cout << "===== Construct Done =====" << std::endl;
        for (int i = 0; i < 10; i++) {
            delete animals[i];
        }
    }

    std::cout << "\n===============\n" << std::endl;

    {
        Dog dog;
        dog.setIdea(0, "Woof!");
        dog.setIdea(1, "Owww~");
        Dog dog_copy(dog);

        std::cout << "===== before modified origninal =====" << std::endl;
        std::cout << "original: ";
        dog.showIdeas();
        std::cout << "copied: ";
        dog_copy.showIdeas();

        std::cout << "===== after modified origninal =====" << std::endl;

        dog.setIdea(0, "Meow..");
        std::cout << "original: ";
        dog.showIdeas();
        std::cout << "copied: ";
        dog_copy.showIdeas();
    }

    std::cout << "\n===============\n" << std::endl;

    {
        WrongDog dog;
        dog.setIdea(0, "Woof!");
        dog.setIdea(1, "Owww~");
        WrongDog dog_copy(dog);

        std::cout << "===== before modified origninal =====" << std::endl;
        std::cout << "original: ";
        dog.showIdeas();
        std::cout << "copied: ";
        dog_copy.showIdeas();

        std::cout << "===== after modified origninal =====" << std::endl;

        dog.setIdea(0, "Meow..");
        std::cout << "original: ";
        dog.showIdeas();
        std::cout << "copied: ";
        dog_copy.showIdeas();
    }
}
