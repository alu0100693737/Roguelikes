#include "monsters.h"

CMonsters::CMonsters()
{
    monsters_ = 4;
    maxgolpes_= 3;
    
}

void CMonsters::kill(){
    maxgolpes_--;
    if(maxgolpes_<0)
        cout << "Un monstruo te ha matado!... Le quedan " << maxgolpes_ << "vidas" << endl;
    else
        cout << "Ha perdido. " << endl;
    
}
