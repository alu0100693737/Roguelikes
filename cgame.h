#ifndef CGAME_H
#define CGAME_H
#include "croom.h"
#include <vector>
using namespace std;
class CGame
{
private:
    vector<CRoom*> rooms;
    CCharacter* ccharacter_;
    int* idrooms; //every room, id and object
    int* contdoors; // every room shoud be two doors
    int numrooms;
    int* level; /*******CUIDADO, TENGO LEVEL EN CADA HAB TB*******/
    int* pos;//idroom, x, y
    int max_mov;
    int* doorm;//3 m doors
    int* doorn;//3 n doors


public:
    CGame(int, int, int, int);
    ~CGame();

    void setdatapjrooms(char, int ,int);
    int getidrooms(int);
    void setidrooms(int, int);
    vector<CRoom*> getrooms();
    int getcontdoors(int);
    void setcontdoors(int, int);
    CCharacter* getcharacter();
    int getlevel(int i);
    void setlevel();
    int getmax_mov();
    void setmax_mov();
    void setmax_mov(int);

    int getposroom();
    int getposxroom();
    int getposyroom();
    void setposromm(int);
    void setposxroom(int);
    void setposyroom(int);

    void leer();
    void movepj(int i);
    void showGame();
    void game();

    int getdoor1m();
    int getdoor1n();
    void setdoor1m(int);
    void setdoor1n(int);
    int getdoor2m();
    int getdoor2n();
    void setdoor2m(int);
    void setdoor2n(int);
    int getdoor3m();
    int getdoor3n();
    void setdoor3m(int);
    void setdoor3n(int);




    //void operator=(CRoom(int, int));
};

#endif // CGAME_H
