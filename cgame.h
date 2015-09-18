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

    CRoom getidrooms(int);

    int getcontdoors(int);
    void setcontdoors(int);

};

#endif // CGAME_H
