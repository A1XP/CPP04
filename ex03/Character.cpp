#include "Character.hpp"
#include <iostream>

Character::Character(const std::string& name) : _name(name), _floorCount(0)
{
	std::cout << "Character " << _name << " constructor called." << std::endl;
	for (int i = 0; i < 4; ++i)
		_inventory[i] = NULL;
	for (int i = 0; i < 100; ++i)
		_floorMaterias[i] = NULL;
}

Character::Character(const Character& other) : _name(other._name)
{
	std::cout << "Character copy constructor called." << std::endl;
	for (int i = 0; i < 4; ++i)
	{
		if (other._inventory[i])
			_inventory[i] = other._inventory[i]->clone();
		else
			_inventory[i] = NULL;
	}
	_floorCount = other._floorCount;
	for (int i = 0; i < _floorCount; ++i)
	{
		if (other._floorMaterias[i])
			_floorMaterias[i] = other._floorMaterias[i]->clone();
		else
			_floorMaterias[i] = NULL;
	}
}

Character& Character::operator=(const Character& other)
{
	std::cout << "Character copy assignment operator called." << std::endl;
	if (this != &other)
	{
		_name = other._name;
		for (int i = 0; i < 4; ++i)
		{
			if (_inventory[i])
			{
				delete _inventory[i];
				_inventory[i] = NULL;
			}
			if (other._inventory[i])
				_inventory[i] = other._inventory[i]->clone();
			else
				_inventory[i] = NULL;
		}
	}
	for (int i = 0; i < _floorCount; ++i)
	{
		if (_floorMaterias[i])
		{
			delete _floorMaterias[i];
			_floorMaterias[i] = NULL;
		}
	}
	_floorCount = other._floorCount;
	for (int i = 0; i < _floorCount; ++i)
	{
		if (other._floorMaterias[i])
			_floorMaterias[i] = other._floorMaterias[i]->clone();
		else
			_floorMaterias[i] = NULL;
	}
	return (*this);
}

Character::~Character()
{
	std::cout << "Character destructor called." << std::endl;
	for (int i = 0; i < 4; ++i)
	{
		if (_inventory[i])
		{
			std::cout << "Slot " << i << " of " << _inventory[i]->getType() << " was deleted." << std::endl;
			delete _inventory[i];
		}
	}
	for (int i = 0; i < _floorCount; ++i)
	{
		if (_floorMaterias[i])
		{
			std::cout << "Floor slot " << i << " of " << _floorMaterias[i]->getType() << " was deleted." << std::endl;
			delete _floorMaterias[i];
		}
	}
}

std::string const & Character::getName() const
{
	return (this->_name);
}

void Character::equip(AMateria* m)
{
	if (!m)
		return;

	for (int i = 0; i < 4; ++i)
	{
		if (!_inventory[i])
		{
			_inventory[i] = m;
			std::cout << "Equipped materia in slot " << i << std::endl;
			return;
		}
	}
	std::cout << "Inventory is full, cannot equip materia." << std::endl;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
	{
		std::cout << "Invalid slot index : " << idx << std::endl;
		return;
	}
	if (!_inventory[idx])
	{
		std::cout << "Can't unequip empty slot : " << idx << std::endl;
		return;
	}
	if (_floorCount >= 100)
	{
		std::cout << "Floor is full, cannot drop materia." << std::endl;
		return;
	}

	_floorMaterias[_floorCount++] = _inventory[idx];
	std::cout << _inventory[idx]->getType() << " was dropped on the floor from slot " << idx << std::endl;
	_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 ||idx > 3)
	{
		std::cout << "Can't use invalid slot index : " << idx << std::endl;
		return;
	}
	if (!_inventory[idx])
	{
		std::cout << "Can't use empty slot : " << idx << std::endl;
		return;
	}
	_inventory[idx]->use(target);
}