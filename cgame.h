#ifndef CGAME_H
#define CGAME_H
#include "croom.h"
class CGame
{
private:
    CRoom* idrooms; //every room
    int* contdoors; // every room shoud be two doors
    CCharacter ccharacter_;

public:
    CGame();

    CRoom getidrooms(int);

    int getcontdoors(int);
    void setcontdoors(int);

    int getlevel();
    int setlevel();


};

#endif // CGAME_H
