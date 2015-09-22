#ifndef CHARACTER_H
#define CHARACTER_H

//in the game represented as @
class CCharacter
{
private:
    int life;
    bool amuleto;
    char pj;
    int* pos;//idroom, x, y

public:
    CCharacter();
    int getlife();
    void setlife(int);
    bool getamuleto();
    void setamuleto(bool a);
    char getpj();

/*
 * el personaje se asociara a una posicion
 * fija de la primera habitacion y el amuleto se
 * pondra en una posicion rand() de la tercera
 * habitacion. Tener en cuenta m y n.
 */

};

#endif // CCHARACTER_H
