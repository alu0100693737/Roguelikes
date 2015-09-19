/*Between room and room should be at least
 * two separation cells . Each room has two
 * doors from walkways which communicate
 * with the other two rooms were created.
 */

#ifndef CROOM_H
#define CROOM_H
#include "character.h"
#include "monsters.h"



class CRoom
{
private:

    //CMonsters* monsters_; //number of monsters for every room
    char** M_;//room
    int m; //min 4, 2 for walls
    int n; //min 4, 2 for walls
    int level;



public:
    CRoom(int, int);
    int pos(int, int);
    int getlevel();
    int setlevel();

    int getm();
    int getn();




    void showRoom();
};

#endif // CROOM_H
