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
    char** gametable;
    int* idrooms; //every room, id and object
    int* contdoors; // every room shoud be two doors
    int numrooms;
    int* level; /*******CUIDADO, TENGO LEVEL EN CADA HAB TB*******/
    int* pos;//idroom, x, y
    int max_mov;
    int* doorm;//3 m doors
    int* doorn;//3 n doors
    bool* visitados; //3 direccion


public:
    CGame(int, int, int, int);
    ~CGame();
    char getdatatablegame(int, int);
    void setdatatablegame(int, int, char);
    void setdatapjrooms(char, int, int ,int);
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
    void setposroom(int);
    void setposxroom(int);
    void setposyroom(int);

    void leer();
    void movepj(int i);
    void showtableGame();
    void game();


    int getdoor0m();
    int getdoor0n();
    void setdoor0m(int);
    void setdoor0n(int);
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
    int getdoor4m();
    int getdoor4n();
    void setdoor4m(int);
    void setdoor4n(int);
    int getdoor5m();
    int getdoor5n();
    void setdoor5m(int);
    void setdoor5n(int);


    bool cambioroom; //uso para no cambiar el + cuando se cambia de habitacion

    //void operator=(CRoom(int, int));
};

#endif // CGAME_H
