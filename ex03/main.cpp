#include "AMateria.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
    IMateriaSource* src = new MateriaSource();

    AMateria* tmpIce = new Ice();
    src->learnMateria(tmpIce);
    delete tmpIce;

    AMateria* tmpCure = new Cure();
    src->learnMateria(tmpCure);
    delete tmpCure;

    ICharacter* me = new Character("me");

    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);

    me->unequip(0);
    me->unequip(1);
    me->unequip(2);
    me->unequip(3);
    
    delete bob;
    delete me;
    delete src;
    return 0;
}
