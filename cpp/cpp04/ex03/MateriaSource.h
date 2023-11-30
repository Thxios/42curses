
#pragma once

#include "IMateriaSource.h"


class MateriaSource: public IMateriaSource {
public:
    MateriaSource();
    MateriaSource(const MateriaSource& other);
    virtual ~MateriaSource();
    MateriaSource& operator=(const MateriaSource& other);

    virtual void learnMateria(AMateria* source);
    virtual AMateria* createMateria(std::string const& type);

private:
    AMateria* sources[4];
    int n_made;
    AMateria* made[100];
};

