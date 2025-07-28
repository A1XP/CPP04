#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>
#include "ICharacter.hpp"

struct FloorList
{
	AMateria* materia;
	FloorList* next;

	FloorList(AMateria* m) : materia(m), next(NULL) {}
};

class Character : public ICharacter
{
private:
	std::string _name;
	AMateria* _inventory[4];
	FloorList* _floorList;
public:
	Character(const std::string& name);
	Character(const Character& other);
	Character& operator=(const Character& other);
	~Character();

	std::string const & getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
};

#endif