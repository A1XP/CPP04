#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria(const std::string& type) : _type(type)
{
	std::cout << "AMateria " << _type << " constructor called." << std::endl;
}

AMateria::~AMateria()
{
	std::cout << "AMateria destructor called." << std::endl;
}

const std::string& AMateria::getType() const
{
	return (this->_type);
}

void AMateria::use(ICharacter& target)
{
	std::cout << "Character used " << getType() << " on target " << target.getName() << std::endl;
}
