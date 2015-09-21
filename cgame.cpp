#include "cgame.h"
#include <stdlib.h> //srand, rand
#include <time.h>
#include "croom.h"
CGame::CGame(int nrooms)
{
    contdoors = new int[2];
    idrooms = new int[nrooms];
    numrooms = nrooms;
    level = 1;

    for(int i=0; i< numrooms; i++)
    {
        rooms.push_back(new CRoom(level));
        idrooms[i]=i;
    }

    /*srand(time(NULL));
    for(int i=0; i< numrooms; i++)
    {
        rooms[i] = new CRoom(1);
*/
        /*numrooms++;
        CRoom aux = new CRoom(rand()%10+1,(rand()%10+1));
        rooms[i] = CRoom(aux);

        idrooms[i] = numrooms;
    }*/
}

/*void CGame::operator=(CRoom a)
{
    this->idrooms
}*/

/*CRoom CGame::getrooms(int i){
    return rooms[i];
}*/

int CGame::getidrooms(int a)
{
    return idrooms[a];
}

void CGame::setidrooms(int data, int id){
    idrooms[id] = data;
}

int CGame::getcontdoors(int id)
{
    return contdoors[id];
}

void CGame::setcontdoors(int data, int id)
{
    contdoors[id] = data;
}

int CGame::getlevel(){
    return level;
}

void CGame::setlevel(){
    level+=1; //up the level
}

void CGame::showGame(){


}
