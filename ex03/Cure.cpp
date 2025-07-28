#include "Cure.hpp"
#include <iostream>

Cure::Cure() : AMateria("cure")
{
	std::cout << "Cure constructor called." << std::endl;
}
Cure::Cure(const Cure& other) : AMateria("cure")
{
	(void)other;
	std::cout << "Cure copy constructor called." << std::endl;
}
Cure& Cure::operator=(const Cure& other)
{
	(void)other;
	std::cout << "Cure copy assignment operator called." << std::endl;
	return (*this);
}

Cure::~Cure()
{
	std::cout << "Cure destructor called." << std::endl;
}

AMateria* Cure::clone() const
{
	return new Cure(*this);
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}