/*Between room and room should be at least
 * two separation cells . Each room has two
 * doors from walkways which communicate
 * with the other two rooms were created.
 */

#ifndef CROOM_H
#define CROOM_H
#include "character.h"



class CRoom
{
private:
    CCharacter* ccharacter_;
    char* M_[];//room
    int m; //min 4, 2 for walls
    int n; //min 4, 2 for walls
    int level;



public:
    CRoom();
    int getlevel();
    void showRoom();
};

#endif // CROOM_H
