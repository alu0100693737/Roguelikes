#ifndef MONSTERS_H
#define MONSTERS_H

class CMonsters
{
private:
    int idmonster; //monster identity
public:
    CMonsters();

    void movemonster(); //distancia Manhattan m, n
    void kill();

};

#endif // MONSTERS_H
