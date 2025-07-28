#include "Character.hpp"
#include <iostream>

Character::Character(const std::string& name) : _name(name), _floorList(NULL)
{
	std::cout << "Character " << _name << " constructor called." << std::endl;
	for (int i = 0; i < 4; ++i)
		_inventory[i] = NULL;
	
}

Character::Character(const Character& other) : _name(other._name), _floorList(NULL)
{
	std::cout << "Character copy constructor called." << std::endl;
	for (int i = 0; i < 4; ++i)
	{
		if (other._inventory[i])
			_inventory[i] = other._inventory[i]->clone();
		else
			_inventory[i] = NULL;
	}

	FloorList* otherCurrent = other._floorList;
    FloorList** thisCurrent = &_floorList;

    while (otherCurrent)
    {
        *thisCurrent = new FloorList(otherCurrent->materia->clone());
        thisCurrent = &((*thisCurrent)->next);
		otherCurrent = otherCurrent->next;
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
	while (_floorList)
	{
		FloorList* tmp = _floorList->next;
		delete _floorList->materia;
		delete _floorList;
		_floorList = tmp;
	}
	FloorList* otherCurrent = other._floorList;
	FloorList** thisCurrent = &_floorList;

	while (otherCurrent)
	{
		*thisCurrent = new FloorList(otherCurrent->materia->clone());
		thisCurrent = &((*thisCurrent)->next);
		otherCurrent = otherCurrent->next;
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
	FloorList* current = _floorList;
	while (current)
	{
		FloorList* next = current->next;
		std::cout << "Dropped materia " << current->materia->getType() << " was deleted." << std::endl;
		delete current->materia;
		delete current;
		current = next;
	}
	_floorList = NULL;
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
	FloorList* newNode = new FloorList(_inventory[idx]);
    newNode->next = _floorList;
    _floorList = newNode;
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
