#ifndef CGAME_H
#define CGAME_H
#include "croom.h"
class CGame
{
private:
    CRoom* idrooms; //every room
    int* contdoors; // every room shoud be two doors

public:
    CGame();

};

#endif // CGAME_H
