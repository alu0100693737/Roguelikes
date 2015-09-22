#include "cgame.h"
#include <stdlib.h> //srand, rand
#include <time.h>
#include "croom.h"
#include <iostream>
#include <ostream>
#include <fstream>
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


    for(int i=0; i< numrooms; i++)
    {
        rooms.push_back(new CRoom(level[i]));
        //catch que el nivel del segundo tenga que ser menor que el primeroo para no desmarcar
        idrooms[i]=i;
    }
    setdatapjrooms(ccharacter_.getpj(), ccharacter_.getposxroom(), ccharacter_.getposyroom());

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
    delete [] level;
    numrooms =0;

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


vector<CRoom*> CGame::getrooms(){
    return rooms;
}

void CGame::setidrooms(int data, int id){
    idrooms[id] = data;
}

void CGame::setdatapjrooms(char car, int x, int y){
    getrooms().at(0)->setpjdata(car, x,y);
}

int CGame::getcontdoors(int id)
{
    return contdoors[id];
}

void CGame::setcontdoors(int data, int id)
{
    contdoors[id] = data;
}

int CGame::getlevel(int id){
    return level[id];
}

void CGame::setlevel(){
    level+=1; //up the level
}




void CGame::showGame(){


    cout << "\033[2J\033[1;1H"; //clear linux regexp
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
            contador+=13;
            while (auxn2<n2 && auxm2<m2)
            {
                //cout << auxm2 << auxn2 << " ";
                cout << " " << getrooms().at(1)->getdata(auxm2, auxn2);
                contador+=2;
                auxn2++;

            }
            auxm2++;
            auxn2 = 0;
            if (contador<80)
                for(;contador<80; contador++)
                    cout <<" ";
            cout << "*" << endl;


        }//first and second room showing
        for(int i=0; i< 2; i++){
        cout << "*                                                                               *" << endl;
        }
        contador = 0;
        for(int j=0; j < getrooms().at(2)->getm(); j++){

            cout << "*                                ";
            contador =10;
            for(int k = 0; k < getrooms().at(2)->getn(); k++)
            {
                /*for(int n=0; n < rooms.at(1)->getm(); n++){
                    for(int p=0; p < rooms.at(0)->getn(); p++)
                    {*/
                        cout << " " << getrooms().at(2)->getdata(j,k);
                        contador+=2;
            }
            if (contador<57)
                for(;contador<57; contador++)
                    cout <<" ";
            cout << "*" << endl;
        }



    for(int i=0; i< 1; i++){
    cout << "*                                                                               *" << endl;
    }
    string a;
    cout << "*                      %   %   %   *   *   #   #   =   =   =                    *\n";
    cout << "*                      R   O   G   U   E   L   I   K   E   S                    *\n";
    cout << "*                      =   =   =   #   #   *   *   %   %   %                    *\n";
    cout << "*                                                                               *\n";
    cout << " *******************************************************************************" << endl;

}
