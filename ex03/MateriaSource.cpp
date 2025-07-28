#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource constructor called." << std::endl;
	for (int i = 0; i < 4; ++i)
		_materia[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	std::cout << "MateriaSource copy constructor called." << std::endl;
	for (int i = 0; i < 4; ++i)
	{
		if (other._materia[i])
			_materia[i] = other._materia[i]->clone();
		else
			_materia[i] = NULL;
	}
}
MateriaSource& MateriaSource::operator=(const MateriaSource& temp)
{
	std::cout << "MateriaSource copy assignment operator called." << std::endl;
	if (this != &temp)
	{
		for (int i = 0; i < 4; ++i)
		{
			if (_materia[i])
			{
				delete _materia[i];
				_materia[i] = NULL;
			}
			if (temp._materia[i])
				_materia[i] = temp._materia[i]->clone();
			else
				_materia[i] = NULL;
		}
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource destructor called." << std::endl;
	for (int i = 0; i < 4; i++)
		if (_materia[i])
			delete _materia[i];
}

void MateriaSource::learnMateria(AMateria* m)
{
	if (!m)
		return;

	for (int i = 0; i < 4; ++i)
	{
		if (!_materia[i])
		{
			_materia[i] = m->clone();
			std::cout << _materia[i]->getType() << " materia was learned by index " << i << std::endl;
			return;
		}
	}
	std::cout << m->getType() << " can not be learned - MateriaSource is full" << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const& type)
{
	for (int i = 0; i < 4; ++i)
	{
		if (_materia[i] && type == _materia[i]->getType())
		{
			AMateria* created = _materia[i]->clone();
			if (created)
			{
				std::cout << type << " materia was created" << std::endl;
				return (created);
			}
			else
			{
				std::cout << "Failed to clone materia of type: " << type << std::endl;
				return NULL;
			}
		}
	}
	std::cout << "Unknown materia type: " << type << std::endl;
	return (NULL);
}
