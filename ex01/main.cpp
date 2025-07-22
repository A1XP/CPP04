#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
	const Animal* animals[20];

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

// int main()
// {
// 	Cat original;
// 	original.setIdea(0, "hunt mice");

// 	Cat copy = original;

// 	std::cout << "Original idea: " << original.getIdea(0) << std::endl;
// 	std::cout << "Copy idea: " << copy.getIdea(0) << std::endl;

// 	original.setIdea(0, "sleep");

// 	std::cout << "Original idea after change: " << original.getIdea(0) << std::endl;
// 	std::cout << "Copy idea after change: " << copy.getIdea(0) << std::endl;
// 	return (0);
// }

