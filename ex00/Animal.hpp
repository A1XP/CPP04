#ifndef ANIMAL_H
#define ANIMAL_H
#include <string>

class Animal
{
protected:
	std::string	_type;
public:
	Animal();
	Animal(const Animal& other);
	Animal& operator=(const Animal& other);
	virtual ~Animal();

	virtual const std::string& getType() const;
	virtual void makeSound() const;
};

#endif
