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
    pos = new int [3];//pos game por defecto 0, 0, 0 (room, x, y)
    pos[0]=0; //first room
    for(int i=1; i<3; i++)
        pos[i]=1;
    max_mov=10; //max movements
    doorm = new int[6];
    doorn = new int [6];


    ccharacter_ = new CCharacter();
    for(int i=0; i< numrooms; i++)
    {
        rooms.push_back(new CRoom(level[i]));
        //catch que el nivel del segundo tenga que ser menor que el primeroo para no desmarcar
        idrooms[i]=i;
    }
    srand(time(NULL));

    doorm[0] = (getrooms().at(0)->getm()-1)/2;
    doorn[0] = getrooms().at(0)->getn()-1;

    doorm[1] = (getrooms().at(1)->getm()-1)/2;
    doorn[1] = 0;


    doorm[2] = (getrooms().at(1)->getm()-1);
    doorn[2] = (getrooms().at(1)->getn()-1)/2;

    doorm[3] = (getrooms().at(2)->getm()-1)/2;
    doorn[3] = getrooms().at(2)->getn()-1;


    doorm[4] = 0;
    doorn[4] = (getrooms().at(2)->getn()-1)/2;

    doorm[5] = (getrooms().at(0)->getm()-1);//la ultima puerta de la ultima habitacion a la primera se pondra cuando recojas el amuleto
    doorn[5] = (getrooms().at(0)->getn()-1)/2;


    setdatapjrooms('o', 1, 1);
    getrooms().at(0)->setpjdata('+', doorm[0], doorn[0]);
    getrooms().at(1)->setpjdata('+', doorm[1], doorn[1]);
    getrooms().at(1)->setpjdata('+', doorm[2], doorn[2]);
    getrooms().at(2)->setpjdata('+', doorm[3], doorn[3]);
    //Cuando se coja el amuleto
    //getrooms().at(2)->setpjdata('+', doorm[4], doorn[4]);
    //getrooms().at(0)->setpjdata('+', doorm[5], doorn[5]);


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

CCharacter* CGame::getcharacter(){
    return ccharacter_;
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

int CGame::getposroom(){
    return pos[0];
}

void CGame::setposromm(int p){
    pos[0] = p;
}

int CGame::getposxroom(){
    return pos[1];
}

void CGame::setposxroom(int x){
    pos[1] += x;
}

int CGame::getposyroom(){
    return pos[2];
}

void CGame::setposyroom(int y){
    pos[2] += y;
}

int CGame::getlevel(int id){
    return level[id];
}
int CGame::getmax_mov(){
    return max_mov;
}
void CGame::setmax_mov(){
    max_mov--;
}

void CGame::setmax_mov(int num)//aumentar movimientos, posibles objetos
{
    max_mov+=num;
}

void CGame::setlevel(){
    level+=1; //up the level
}


int CGame::getdoor1m(){
    return doorm[0];
}

int CGame::getdoor1n(){
    return doorn[0];
}

void CGame::setdoor1m(int m){
    doorm[0] = m;
}

void CGame::setdoor1n(int n){
    doorn[0] = n;
}

int CGame::getdoor2m(){
    return doorm[1];
}

int CGame::getdoor2n(){
    return doorn[1];
}

void CGame::setdoor2m(int m){
    doorm[1] = m;
}

void CGame::setdoor2n(int n){
    doorn[1] = n;
}

int CGame::getdoor3m(){
    return doorm[2];
}

int CGame::getdoor3n(){
    return doorn[2];
}

void CGame::setdoor3m(int m){
    doorm[2] = m;
}

void CGame::setdoor3n(int n){
    doorn[2] = n;
}

void CGame::leer(){

    char aux;
    while(getmax_mov()>0){
        cout << "\t\tEnter a movement: right(d), left(a), up(w), down(x): " << endl;
        cin >> aux;
        cout << getrooms().at((getposroom()))->getm() << " " << getrooms().at((getposroom()))->getn() << endl;
        if(aux=='d' && getposyroom()<getrooms().at((getposroom()))->getn()-2)//|| aux==ARROW_UP)
            movepj(1);//right
        else if(aux=='a'&& getposyroom()>1)
            movepj(2);//left
        else if(aux=='w'&& getposxroom()>1)
            movepj(3);//up
        else if(aux=='x'&& getposxroom()<getrooms().at((getposroom()))->getm()-2)
            movepj(4);//down
        else if ((aux=='a') || (aux=='d') || (aux=='w') || (aux=='x')) //in a wall
        {
            cout << "\t\tThere is a wall in that box, try another move" << endl << endl;
            leer();
        }
        else
        {
            cout << "\t\tError in the character entered by keyboard. Try another."<< endl << endl;
            leer();
        }
        //movepj(aux);//1 right, 2 left, 3 up, 4 down
    }
    if(getmax_mov()==0)
            cout << "Game over, try again"<< endl;
}

void CGame::movepj(int i){
    if(i==1)//right
    {
            //pos[2] += 1;
             getrooms().at((getposroom()))->moveright(getposxroom(), getposyroom());
             setposyroom(1);
    }
    if(i==2)//left
    {
            getrooms().at(getposroom())->moveleft(getposxroom(), getposyroom());
            setposyroom(-1);
    }
    if(i==3)//up
    {
            getrooms().at(getposroom())->moveup(getposxroom(), getposyroom());
            setposxroom(-1);
    }
    if(i==4)//down
    {
            getrooms().at(getposroom())->movedown(getposxroom(), getposyroom());
            setposxroom(1);
    }
    setmax_mov();//-1
    showGame();


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
    cout << "*\t                                %   %   %   *   *   #   #   =   =   =   *\n";
    if(getmax_mov()>9)
        cout << "*  Movement:"<< getmax_mov() << "  Lives: " << getcharacter()->getlife() << "\t        R   O   G   U   E   L   I   K   E   S   *\n";
    else
        cout << "*  Movement:"<< getmax_mov() << "  Lives: " << getcharacter()->getlife() << "\t                R   O   G   U   E   L   I   K   E   S   *\n";
    cout << "*\t                                =   =   =   #   #   *   *   %   %   %   *\n";
    cout << "*                                                                               *\n";
    cout << " *******************************************************************************" << endl;

}


void CGame::game(){


}
