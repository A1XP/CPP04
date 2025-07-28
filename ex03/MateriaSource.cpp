#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource constructor called." << std::endl;
	for (int i = 0; i < 4; ++i)
		_materias[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	std::cout << "MateriaSource copy constructor called." << std::endl;
	for (int i = 0; i < 4; ++i)
	{
		if (other._materias[i])
			_materias[i] = other._materias[i]->clone();
		else
			_materias[i] = NULL;
	}
}
MateriaSource& MateriaSource::operator=(const MateriaSource& temp)
{
	std::cout << "MateriaSource copy assignment operator called." << std::endl;
	if (this != &temp)
	{
		for (int i = 0; i < 4; ++i)
		{
			if (_materias[i])
			{
				delete _materias[i];
				_materias[i] = NULL;
			}
			if (temp._materias[i])
				_materias[i] = temp._materias[i]->clone();
			else
				_materias[i] = NULL;
		}
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource destructor called." << std::endl;
	for (int i = 0; i < 4; i++)
		if (_materias[i])
			delete _materias[i];
}

void MateriaSource::learnMateria(AMateria* m)
{
	if (!m)
		return;

	for (int i = 0; i < 4; ++i)
	{
		if (!_materias[i])
		{
			_materias[i] = m->clone();
			std::cout << _materias[i]->getType() << " materia was learned by index " << i << std::endl;
			return;
		}
	}
	std::cout << m->getType() << " can not be learned - MateriaSource is full" << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const& type)
{
	for (int i = 0; i < 4; ++i)
	{
		if (_materias[i] && type == _materias[i]->getType())
		{
			AMateria* created = _materias[i]->clone();
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
