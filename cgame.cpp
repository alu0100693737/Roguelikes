#include "cgame.h"
#include <stdlib.h> //srand, rand
#include <time.h>
#include "croom.h"
#include <iostream>
using namespace std;
CGame::CGame(int nrooms, int id1, int id2, int id3)
{
    contdoors = new int[2];
    idrooms = new int[nrooms];
    numrooms = nrooms;
    level = new int [3];
    level[0] =id1;
    level[1]= id2;
    level[2]= id3;

})

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

CGame::~CGame(){
    delete [] contdoors;
    delete [] idrooms;
    numrooms =0;
    level=1;
    for ( int i = 0; i < rooms.size(); i++)
    {
        delete rooms[i];
    }
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

vector<CRoom*> CGame::getrooms(){
    return rooms;
}


void CGame::showGame(){
    try {



    int contador = 2;
    int m2 = getrooms().at(1)->getm();
    int n2= getrooms().at(1)->getn();
    int auxm2=0;
    int auxn2=0;

    cout << " ******************************************************************************* " << endl;
    cout << "*                                                                               *" << endl;
    cout << "*                                                                               *" << endl;

   /* for(int i=0; i< E.getrooms().at(0)->getm(); i++){
        for(int j=0; j< E.getrooms().at(0)->getn(); j++){
           cout <<  E.getrooms().at(0)->getdata(i,j) << " ";
*/
           //flush();

        for(int j=0; j < getrooms().at(0)->getm(); j++){

            cout << "*         ";
            contador =10;
            for(int k = 0; k < getrooms().at(0)->getn(); k++)
            {
                /*for(int n=0; n < rooms.at(1)->getm(); n++){
                    for(int p=0; p < rooms.at(0)->getn(); p++)
                    {*/
                        cout << " " << getrooms().at(0)->getdata(j,k);
                        contador+=2;
            }
            cout << "             ";
            contador+=14;
            while (auxn2<n2 && auxm2<m2)
            {
                //cout << auxm2 << auxn2 << " ";
                cout << " " << getrooms().at(1)->getdata(auxm2, auxn2);
                contador+=3;
                auxn2++;

            }
            auxm2++;
            auxn2 = 0;
            if (contador<96)
                for(;contador<96; contador++)
                    cout <<" ";
            cout << "*" << endl;


    }

    for(int i=0; i< 8; i++){
    cout << "*                                                                               *" << endl;
    }
    cout << "*                                                                               *" << endl;
    cout << " *******************************************************************************" << endl;
    } catch (...) {
        /*terminate called after throwing an instance of 'std::out_of_range'
        what():  vector::_M_range_check: __n (which is 1) >= this->size() (which is 1)
      Abortado (`core' generado)*/
    }
}
