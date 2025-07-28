#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>
#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
private:
	AMateria(const AMateria& other);
	AMateria& operator=(const AMateria& other);
protected:
	std::string _type;
public:
	AMateria(const std::string& type);
	virtual ~AMateria();

	const std::string& getType() const;
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};

#endif