#include "character.h"
const int LIMITE=5;
CCharacter::CCharacter()
{
    life = 5;
    amuleto = false;
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


class CCharacter
{
private:
    int life;
    bool amuleto;

public:
    CCharacter();
    int getlife();
    void setlife(int);
    bool getamuleto();
    bool setamuleto();
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
