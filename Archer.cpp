#include "Archer.hpp"

Archer::Archer(): Unite(12, 0, 8, 3, 1, 3)
{
    //ctor
}

Archer::~Archer()
{
    //dtor
}

string Archer::toString() const
{
    stringstream ss;
    ss << "-- Archer:" << endl << Unite::toString();
    return ss.str();
}
