#ifndef ARCHER_H
#define ARCHER_H

#include <iostream>
#include <string>
#include <sstream>

#include "Unite.hpp"

using namespace std;

class Archer : public Unite
{
    public:
        Archer();
        virtual ~Archer();

        string toString() const;

    protected:

    private:
};

#endif // ARCHER_H
