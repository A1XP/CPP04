#include "Brain.hpp"
#include <iostream>

Brain::Brain()
{
	std::cout << "Brain has been created!" << std::endl;
}

Brain::Brain(const Brain& other)
{
	std::cout << "Brain copy constructor called" << std::endl;
	for (int i = 0; i < 100; ++i)
		this->ideas[i] = other.ideas[i];
}

Brain& Brain::operator=(const Brain& other)
{
	std::cout << "Brain copy assignment operator called" << std::endl;
	if (this != &other)
		for (int i = 0; i < 100; ++i)
			this->ideas[i] = other.ideas[i];
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain has been destroyed!" << std::endl;
}

std::string Brain::getIdea(int i) const
{
	if (i >= 0 && i < 100)
		return ideas[i];
	return ""; 
}

void Brain::setIdea(int i, const std::string& idea)
{
	if (i >= 0 && i < 100)
		ideas[i] = idea;
}
