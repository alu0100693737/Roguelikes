#ifndef CHARACTER_H
#define CHARACTER_H

//in the game represented as @
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

#endif // CCHARACTER_H
