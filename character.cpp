#include "character.h"
const int LIMITE=5;
CCharacter::CCharacter()
{
    life = 5;
    amuleto = false;
    char pj = '$';
    int* pos = [0,0,0];//idroom, x, y por defecto
}

int CCharacter::getlife()
{
    return life;
}

void CCharacter::setlife(int value)
{
    if (life + value <= LIMITE))
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

int CCharacter::getposroom(){
    return pos[0];
}

int CCharacter::getposxroom(){
    return pos[1];
}

int CCharacter::getposyroom(){
    return pos[2];
}

class CCharacter
{
private:
    int life;
    bool amuleto;
    char pj = '$';
    int* pos = [0,0,0];//idroom, x, y

public:
    CCharacter();
    int getlife();
    void setlife(int);
    bool getamuleto();
    bool setamuleto();
    char getpj();

/*
 * el personaje se asociara a una posicion
 * fija de la primera habitacion y el amuleto se
 * pondra en una posicion rand() de la tercera
 * habitacion. Tener en cuenta m y n.
 */

    void moveright();
    void moveleft();
    void moveup();
    void movedown();
};
