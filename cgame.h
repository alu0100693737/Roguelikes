#ifndef CGAME_H
#define CGAME_H
#include "croom.h"
#include <vector>
using namespace std;
class CGame
{
private:
    vector<CRoom*> rooms;
    int* idrooms; //every room, id and object
    int* contdoors; // every room shoud be two doors
    int numrooms;
    int* level; /*******CUIDADO, TENGO LEVEL EN CADA HAB TB*******/
    CCharacter ccharacter_;

public:
    CGame(int, int, int, int);
    ~CGame();

    void setdatapjrooms(char, int ,int);
    int getidrooms(int);
    void setidrooms(int, int);
    vector<CRoom*> getrooms();
    int getcontdoors(int);
    void setcontdoors(int, int);

    int getlevel(int i);
    void setlevel();

    void showGame();

    //void operator=(CRoom(int, int));
};

#endif // CGAME_H
