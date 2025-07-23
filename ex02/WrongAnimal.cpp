#include "WrongAnimal.hpp"
#include <string>
#include <iostream>

WrongAnimal::WrongAnimal() : _type("WrongAnimal")
{
	std::cout << _type << " has been created!" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : _type(other._type)
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
	std::cout << "WrongAnimal copy assignment operator called" << std::endl;
	if (this != &other)
		_type = other._type;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << _type << " is destroyed." << std::endl;
}

void WrongAnimal::makeSound() const
{
	std::cout << _type << " trtrtrtr!" << std::endl;
}

const std::string& WrongAnimal::getType() const
{
	return (this->_type);
}
