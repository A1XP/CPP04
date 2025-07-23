#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{

	// const AAnimal* meta = new AAnimal();

	const AAnimal* animals[20];

	for (int i = 0; i < 10; ++i)
	{
		animals[i] = new Dog();
	}
	for (int i = 10; i < 20; ++i)
	{
		animals[i] = new Cat();
	}
	for (int i = 0; i < 20; ++i)
	{
		std::cout << "Animal " << i << " : ";
		animals[i]->makeSound();
	}
	for (int i = 0; i < 20; ++i)
	{
		delete animals[i];
	}
	return (0);
}
