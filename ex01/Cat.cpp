#include "Cat.hpp"
#include <iostream>

Cat::Cat()
{
	this->_type = "Cat";
	_brain = new Brain();
	std::cout << _type << " has been created!" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other)
{
	_brain = new Brain(*other._brain);
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
	std::cout << "Cat copy assignment operator called" << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);
		delete _brain;
		_brain = new Brain(*other._brain);
	}
	return (*this);
}

Cat::~Cat()
{
	delete _brain;
	std::cout << _type << " is destroyed." << std::endl;
}

void Cat::makeSound() const
{
	std::cout << _type << " meow!" << std::endl;
}

void Cat::setIdea(int index, const std::string& idea)
{
	if (_brain && index >= 0 && index < 100)
		_brain->setIdea(index, idea);
}

std::string Cat::getIdea(int index) const
{
	if (_brain && index >= 0 && index < 100)
		return _brain->getIdea(index);
	return "";
}