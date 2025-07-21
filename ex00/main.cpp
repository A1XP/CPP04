#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
const Animal* meta = new Animal();
const Animal* j = new Dog();
const Animal* i = new Cat();
std::cout << j->getType() << " " << std::endl;
std::cout << i->getType() << " " << std::endl;
i->makeSound(); //will output the cat sound!
j->makeSound();
meta->makeSound();

delete meta;
delete j;
delete i;

const WrongAnimal* animal = new WrongAnimal();
const WrongAnimal* cat = new WrongCat();

std::cout << animal->getType() << " says: ";
animal->makeSound();

std::cout << cat->getType() << " says: ";
cat->makeSound();

delete animal;
delete cat;
return 0;
}
