#include "AAnimal.hpp"
#include <iostream>

AAnimal::AAnimal() : _type("AAnimal")
{
	std::cout << _type << " has been created!" << std::endl;
}

AAnimal::AAnimal(const std::string& type) : _type(type)
{
	std::cout << _type << " has been created!" << std::endl;
}

AAnimal::AAnimal(const AAnimal& other) : _type(other._type)
{
	std::cout << "Animal copy constructor called" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& other)
{
	std::cout << "Animal copy assignment operator called" << std::endl;
	if (this != &other)
		_type = other._type;
	return (*this);
}

AAnimal::~AAnimal()
{
	std::cout << "Animal " << _type << " is destroyed." << std::endl;
}

void AAnimal::makeSound() const
{
	std::cout << _type << " trtrtrtr!" << std::endl;
}

const std::string& AAnimal::getType() const
{
	return (this->_type);
}
