#include "Dog.hpp"
#include <iostream>

Dog::Dog()
{
	this->_type = "Dog";
	_brain = new Brain();
	std::cout << _type << " has been created!" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other)
{
	_brain = new Brain(*other._brain);
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);
		delete _brain;
		_brain = new Brain(*other._brain);
	}
	return (*this);
}

Dog::~Dog()
{
	delete _brain;
	std::cout << _type << " is destroyed." << std::endl;
}

void Dog::makeSound() const
{
	std::cout << _type << " woof!" << std::endl;
}
