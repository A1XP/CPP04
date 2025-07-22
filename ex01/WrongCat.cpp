#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat()
{
	this->_type = "WrongCat";
	std::cout << _type << " has been created!" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
	std::cout << "WrongCat copy assignment operator called" << std::endl;
	if (this != &other)
		WrongAnimal::operator=(other);
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << _type << " is destroyed." << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << _type << " meow!" << std::endl;
}
