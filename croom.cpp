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

CRoom::CRoom(int level)
{
    M_=NULL;
    srand(time(NULL));
    if(level==1){ //we need to stop 1 second to change de rand()
       delay(1);
       m = rand()%10+8,(rand()%10+8);
       delay(1);
       n = rand()%10+8,(rand()%10+8);
    }

    if(level==2){
       delay(1);
       m = rand()%8+5,(rand()%8+5);
       delay(1);
       n = rand()%8+5,(rand()%8+5);
    }
    if(level==3){
       delay(1);
       m = rand()%5+3,(rand()%5+3);
       delay(1);
       n = rand()%5+3,(rand()%5+3);
    }
    //monsters_ = new CMonsters[NUMONSTERS];
    M_ = new char* [m];
    if(M_==NULL)
        cerr << "Error creando la habitacion\n";
    for(int i= 0; i< m; i++)
    {
        M_[i]= new char[n];
    }

    cout << "m vale: " << m << endl;
    cout << "n vale: " << n << endl;
    for(int i=0; i< m; i++)
    {
        for(int j=0; j < n; j++)
        {
            if((i==0) || (i==m-1))
            {
                M_[i][j] = '-';
            }else if((j==0) || (j==n-1)){
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

char CRoom::getdata(int i, int j){
        //cout << M_[i][j]<< endl;
        return M_[i][j];
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

void CRoom::setpjdata(char car, int x, int y)
{
    //cout << x << y << endl;
    //cout << "Hola"<< endl;
    M_[x][y]=car;
    //cout << x << y << endl;
    //cout << M_[0][0] << endl;
}

void CRoom::moveright(int i, int j){
    M[i][j]='*';
    M[i][j+1] ='o';

}

void CRoom::moveleft(int i, int j){
    M[i][j]='*';
    M[i][j-1] ='o';

}

void CRoom::moveup(){
    M[i][j]='*';
    M[i-1][j] ='o';

}

void CRoom::movedown(){
    M[i][j]='*';
    M[i+1][j] ='o';

}

void CRoom::showRoom()
{
    for(int i=0; i<m; i++)
    {    for(int j=0; j<n; j++)
            cout << M_[i][j] << "  ";
        cout << endl;
    }
}

void CRoom::delay(int secs) {
      for(int i = (time(NULL) + secs); time(NULL) != i; time(NULL));
}

//Falta LEVEL Aun no se utiliza en ningun sitio
