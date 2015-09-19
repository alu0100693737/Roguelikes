#include "croom.h"
#include <iostream>

using namespace std;

const int NUMONSTERS = 3;
CRoom::CRoom(int sizem, int sizen)
{
    M_=NULL;
    m =sizem;
    n=sizen;

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

/*class CRoom
{
private:

    CMonsters* monsters_; //number of monsters for every room
    char* M_[];//room
    int m; //min 4, 2 for walls
    int n; //min 4, 2 for walls
    int level;



public:
    CRoom();
    int getlevel();
    int setlevel();

    int getm();
    int setn();



    void showRoom();
};


*/
