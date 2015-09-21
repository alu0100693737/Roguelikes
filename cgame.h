#ifndef CGAME_H
#define CGAME_H
#include "croom.h"
#include <vector>
class CGame
{
private:
    vector<CRoom> rooms;
    int* idrooms; //every room, id and object
    int* contdoors; // every room shoud be two doors
    int numrooms;
    int level; /*******CUIDADO, TENGO LEVEL EN CADA HAB TB*******/
    //CCharacter ccharacter_;

public:
    CGame(int);
    CRoom getrooms(int i);
    void setrooms(int i, CRoom a);
    int getidrooms(int);
    void setidrooms(int, int);

    int getcontdoors(int);
    void setcontdoors(int, int);

    int getlevel();
    void setlevel();

    void showGame();

    //void operator=(CRoom(int, int));
};

#endif // CGAME_H
