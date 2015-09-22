#include "character.h"
#include <iostream>
const int LIMITE=5;
using namespace std;
CCharacter::CCharacter()
{
    life = 5;
    amuleto = false;
    char pj = 'o';
}

int CCharacter::getlife()
{
    return life;
}

void CCharacter::setlife(int value)
{
    if (life + value <= LIMITE)
        life += value;
}

bool CCharacter::getamuleto()
{
    return amuleto;
}

void CCharacter::setamuleto(bool am)
{
    amuleto = am;
}

char CCharacter::getpj(){
    return pj;
}



