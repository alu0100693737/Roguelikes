#include "croom.h"
#include <iostream>
#include <stdlib.h> //srand, rand
#include <time.h>
using namespace std;

const int NUMONSTERS = 3;
CRoom::CRoom(){
    M_=NULL;
    m=0;
    n=0;
}

CRoom::CRoom(const CRoom& copy)
{
    m = copy.getm();
    n= copy.getn();
    level = copy.getlevel();

    M_ = new char* [m];
    if(M_==NULL)
        cerr << "Error creando la habitacion\n";
    for(int i= 0; i< sizem; i++)
    {
        M_[i]= new char[n];
    }

    for(int i=0; i< m; i++)
    {
        for(int j=0; j< n; j++)
        {
            M_[i][j] = copy.pos(i,j);
        }
    }

}

CRoom::CRoom(int level)
{
    M_=NULL;
    srand(NULL);
    if(level==1){
       m = rand()%10+1,(rand()%10+1);
       n = rand()%10+1,(rand()%10+1);
    }

    if(level==2){
       m = rand()%8+1,(rand()%8+1);
       n = rand()%8+1,(rand()%8+1);
    }
    if(level==3){
       m = rand()%5+1,(rand()%5+1);
       n = rand()%5+1,(rand()%5+1);
    }
    //monsters_ = new CMonsters[NUMONSTERS];
    M_ = new char* [sizem];
    if(M_==NULL)
        cerr << "Error creando la habitacion\n";
    for(int i= 0; i< sizem; i++)
    {
        M_[i]= new char[sizen];
    }
    for(int i=0; i< sizem; i++)
    {
        for(int j=0; j < sizen; j++)
        {
            if((i==0) || (i==sizem-1))
            {
                M_[i][j] = '-';
            }else if((j==0) || (j==sizen-1)){
                M_[i][j]='|';
            }
            else{
                M_[i][j] = '*';
            }



        }
    }
}

int CRoom::pos(int i, int j)
{
    if((i<1)||(i> getm())||(j<1) || (j>getn()))
    {
        //cerr << "Error accediendo a la casilla";
        return 0;
    }
    else{
        return(i-1)*getn()+j-1; //get pos in the matrix
    }

}

int CRoom::getm(){
    return m;
}

int CRoom::getn(){
    return n;
}

int CRoom::getlevel(){
    return level;
}

void CRoom::setlevel(int l){
    level=l;
}

void CRoom::showRoom()
{
    for(int i=0; i<m; i++)
    {    for(int j=0; j<n; j++)
            cout << M_[i][j] << "  ";
        cout << endl;
    }
}

//Falta LEVEL Aun no se utiliza en ningun sitio
