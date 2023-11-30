
#include "MateriaSource.h"
#include "AMateria.h"


MateriaSource::MateriaSource(): n_made(0) {
    for (int i = 0; i < 4; i++) {
        sources[i] = NULL;
    }
}

MateriaSource::MateriaSource(const MateriaSource& other): n_made(0) {
    for (int i = 0; i < 4; i++) {
        if (other.sources[i]) {
            sources[i] = other.sources[i]->clone();
        }
        else {
            sources[i] = NULL;
        }
    }
}

MateriaSource::~MateriaSource() {
    for (int i = 0; i < 4; i++) {
        if (sources[i]) {
            delete sources[i];
        }
    }
    for (int i = 0; i < n_made; i++) {
        delete made[i];
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
    if (this != &other) {
        for (int i = 0; i < 4; i++) {
            if (sources[i]) {
                delete sources[i];
            }
        }
        for (int i = 0; i < n_made; i++) {
            delete made[i];
        }

        n_made = 0;
        for (int i = 0; i < 4; i++) {
            if (other.sources[i]) {
                sources[i] = other.sources[i]->clone();
            }
            else {
                sources[i] = NULL;
            }
        }
    }
    return *this;
}


void MateriaSource::learnMateria(AMateria* source) {
    for (int i = 0; i < 4; i++) {
        if (!sources[i]) {
            sources[i] = source->clone();
            break;
        }
    }
    delete source;
}

AMateria* MateriaSource::createMateria(std::string const& type) {
    if (n_made >= 100)
        return NULL;

    for (int i = 0; i < 4; i++) {
        if (type == sources[i]->getType()) {
            AMateria* ret = sources[i]->clone();
            made[n_made] = ret;
            n_made++;
            return ret;
        }
    }
    
    return NULL;
}
