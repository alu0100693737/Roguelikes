        #include "cgame.h"
        #include <stdlib.h> //srand, rand
        #include <time.h>
        #include "croom.h"
        #include <iostream>
        #include <ostream>
        #include <fstream>
        #include <cmath>
        #include <string>     // std::string, std::to_string
        using namespace std;
        CGame::CGame(int nrooms, int id1, int id2, int id3)
        {   
            nummonsters_= 4;
            maxgolpes_ = 5;
            cambioroom=false;
            primermovimiento=false;
            
            gametable = new char* [35];
            for(int i=0; i< 35; i++)
                gametable[i] = new char[40];
            for(int i=0; i< 35; i++)
            {        for(int j = 0; j< 40; j++)
                    {   if ( i==0 || i== 34 || j==0 || j==39)
                            gametable[i][j] = '*';
                        else
                            gametable[i][j] =' ';
                    }
            }
            contdoors = new int[2];
            idrooms = new int[nrooms];
            numrooms = nrooms;
            level = new int [3];
            level[0] =id1;
            level[1]= id2;
            level[2]= id3;
            pos = new int [3];//pos game por defecto 0, 0, 0 (room, x, y)
            pos[0]=0; //first room
            for(int i=1; i<3; i++)
                pos[i]=1;
            
            //max movimientos
            max_mov=60; 
            
            doorm = new int[6];
            doorn = new int [6];
            visitados = new bool [3];
            for(int i=0; i< 3; i++)
                visitados[i] = false;


            ccharacter_ = new CCharacter();
            monsters_ = new int[nummonsters_];
            
            posmonstersx_ = new int[nummonsters_];
            posmonstersy_ = new int[nummonsters_];
            
            for(int i = 0; i< nummonsters_; i++)
                monsters_[i] = i;
            
            cout << "Num de monstruos: " << nummonsters_ << endl;
            
            for(int i=0; i< numrooms; i++)
            {
                rooms.push_back(new CRoom(level[i]));
                //catch que el nivel del segundo tenga que ser menor que el primeroo para no desmarcar
                idrooms[i]=i;
            }
            srand(time(NULL));

            doorm[0] = (getrooms().at(0)->getm()-1)/2;
            doorn[0] = getrooms().at(0)->getn()-1;

            doorm[1] = (getrooms().at(1)->getm()-1)/2;
            doorn[1] = 0;


            doorm[2] = (getrooms().at(1)->getm()-1);
            doorn[2] = (getrooms().at(1)->getn()-1)/2;

            doorm[3] = (getrooms().at(2)->getm()-1)/2;
            doorn[3] = getrooms().at(2)->getn()-1;


            doorm[4] = 0;
            doorn[4] = (getrooms().at(2)->getn()-1)/2;

            doorm[5] = (getrooms().at(0)->getm()-1);//la ultima puerta de la ultima habitacion a la primera se pondra cuando recojas el amuleto
            doorn[5] = (getrooms().at(0)->getn()-1)/2;


            setdatapjrooms('o', 0, 1, 1);
            getrooms().at(0)->setpjdata('+', doorm[0], doorn[0]);
            getrooms().at(1)->setpjdata('+', doorm[1], doorn[1]);
            getrooms().at(1)->setpjdata('+', doorm[2], doorn[2]);
            getrooms().at(2)->setpjdata('+', doorm[3], doorn[3]);
            getrooms().at(2)->setpjdata('+', doorm[4], doorn[4]);
            //enseñar ultima puerta
            getrooms().at(0)->setpjdata('=', doorm[5], doorn[5]);
            srand(time(NULL));
            delay(1);
            int num1 = (rand()% getrooms().at(2)->getm())+1;
            delay(1);
            int num2= (rand()%getrooms().at(2)->getn())+1;
            getrooms().at(2)->setpjdata('$', num1, num2);

            
            //asignacion de monstruos
            posmonstersx_[0] = ((getrooms().at(0)->getm()-1)/2)+2;
            posmonstersx_[1] = ((getrooms().at(0)->getm()-1)/2)-1;
            
            posmonstersx_[2] = ((getrooms().at(1)->getm()-1)/2)-1;
            posmonstersx_[3] = ((getrooms().at(1)->getm()-1)/2)+1;
            
            posmonstersy_[0] = ((getrooms().at(0)->getn()-1)/2);
            posmonstersy_[1] = ((getrooms().at(0)->getn()-1)/2)-1;

            posmonstersy_[2] = ((getrooms().at(1)->getn()-1)/2)-1;
            posmonstersy_[3] = ((getrooms().at(1)->getn()-1)/2);
            
            //cada dos movimientos del pj se moveran los monstruos
            getrooms().at(0)->setpjdata('W', posmonstersx_[0], posmonstersy_[0]);
            getrooms().at(0)->setpjdata('W', posmonstersx_[1], posmonstersy_[1]);
            getrooms().at(1)->setpjdata('W', posmonstersx_[2], posmonstersy_[2]);
            getrooms().at(1)->setpjdata('W', posmonstersx_[3], posmonstersy_[3]);

            //asignacion de rooms a game

            for(int i=0; i< getrooms().at(0)->getm(); i++)
                for(int j=0; j< getrooms().at(0)->getn(); j++)
                {
                    setdatatablegame(i+4, j+5, getrooms().at(0)->getdata(i,j));
                }
            for(int i=0; i< getrooms().at(1)->getm(); i++)
                for(int j=0; j< getrooms().at(1)->getn(); j++)
                {
                    gametable[i+4][j+23] = getrooms().at(1)->getdata(i,j);
                }
            for(int i=0; i< getrooms().at(2)->getm(); i++)
                for(int j=0; j< getrooms().at(2)->getn(); j++)
                {
                    gametable[i+20][j+15] = getrooms().at(2)->getdata(i,j);
                }
            //decoration
            string a;
            string b;
            string c;
            string d;
            a = "%%%**##===";
            for(int i=0; i< a.size(); i++)
                gametable[28][i+25] = a.at(i);
            
            a= "VIDA:" ;
            cout << "size de VIDA: " << a.size() << endl;
            //<< maxgolpes_.to_string();
            
            
            for(int l=0; l< a.size(); l++)
                gametable[29][l+7] =a.at(l);
            setdatatablegame(29, 13,53);//marcamos la vida actual
        // b = "*  Movement:" + getmax_mov();
        // c= "  Lives: " + getcharacter()->getlife();


            a = "ROGUELIKES ";
            for(int i=0; i< a.size(); i++)
                gametable[29][i+25] =a.at(i);

            a = "===##**%%%";
            for(int i=0; i< a.size(); i++)
                gametable[30][i+25] = a.at(i);


            /*if(getmax_mov()>9)
                a << "*  Movement:"<< getmax_mov() << "  Lives: " << getcharacter()->getlife() << "\t        ROGUELIK   E   S   *\n";
            else
                a << "*  Movement:"<< getmax_mov() << "  Lives: " << getcharacter()->getlife() << "\t                R   O   G   U   E   L   I   K   E   S   *\n";
            a << "*\t                                =   =   =   #   #   *   *   %   %   %   *\n";*/
            //Cuando se coja el amuleto
            //getrooms().at(2)->setpjdata('+', doorm[4], doorn[4]);
            //getrooms().at(0)->setpjdata('+', doorm[5], doorn[5]);


            /*srand(time(NULL));
            for(int i=0; i< numrooms; i++)
            {
                rooms[i] = new CRoom(1);
        */
                /*numrooms++;
                CRoom aux = new CRoom(rand()%10+1,(rand()%10+1));
                rooms[i] = CRoom(aux);

                idrooms[i] = numrooms;
            }*/
        }

        CGame::~CGame(){
            delete [] contdoors;
            delete [] idrooms;
            delete [] level;
            numrooms =0;

            for ( int i = 0; i < rooms.size(); i++)
            {
                delete rooms[i];
            }
        }

        /*void CGame::operator=(CRoom a)
        {
            this->idrooms
        }*/

        /*CRoom CGame::getrooms(int i){
            return rooms[i];
        }*/

        char CGame::getdatatablegame(int i, int j){
            return gametable[i][j];
        }

        void CGame::setdatatablegame(int i, int j, char a){
            gametable[i][j]=a;
        }

        int CGame::getidrooms(int a)
        {
            return idrooms[a];
        }


        vector<CRoom*> CGame::getrooms(){
            return rooms;
        }

        CCharacter* CGame::getcharacter(){
            return ccharacter_;
        }

        void CGame::setidrooms(int data, int id){
            idrooms[id] = data;
        }

        void CGame::setdatapjrooms(char car, int level, int x, int y){

            getrooms().at(level)->setpjdata(car, x,y);
        }

        int CGame::getcontdoors(int id)
        {
            return contdoors[id];
        }

        void CGame::setcontdoors(int data, int id)
        {
            contdoors[id] = data;
        }

        int CGame::getposroom(){
            return pos[0];
        }

        void CGame::setposroom(int p){
            pos[0] = p;
        }

        int CGame::getposxroom(){
            return pos[1];
        }

        void CGame::setposxroom(int x){
            pos[1] += x;
        }

        int CGame::getposyroom(){
            return pos[2];
        }

        void CGame::setposyroom(int y){
            pos[2] += y;
        }

        int CGame::getlevel(int id){
            return level[id];
        }
        int CGame::getmax_mov(){
            return max_mov;
        }
        void CGame::setmax_mov(){
            max_mov--;
        }

        void CGame::setmax_mov(int num)//aumentar movimientos, posibles objetos
        {
            max_mov+=num;
        }

        void CGame::setlevel(){
            level+=1; //up the level
        }


        int CGame::getdoor0m(){
            return doorm[0];
        }

        int CGame::getdoor0n(){
            return doorn[0];
        }

        void CGame::setdoor0m(int m){
            doorm[0] = m;
        }

        void CGame::setdoor0n(int n){
            doorn[0] = n;
        }

        int CGame::getdoor1m(){
            return doorm[1];
        }

        int CGame::getdoor1n(){
            return doorn[1];
        }

        void CGame::setdoor1m(int m){
            doorm[1] = m;
        }

        void CGame::setdoor1n(int n){
            doorn[1] = n;
        }

        int CGame::getdoor2m(){
            return doorm[2];
        }

        int CGame::getdoor2n(){
            return doorn[2];
        }

        void CGame::setdoor2m(int m){
            doorm[2] = m;
        }

        void CGame::setdoor2n(int n){
            doorn[2] = n;
        }

        int CGame::getdoor3m(){
            return doorm[3];
        }

        int CGame::getdoor3n(){
            return doorn[3];
        }

        void CGame::setdoor3m(int m){
            doorm[3] = m;
        }

        void CGame::setdoor3n(int n){
            doorn[3] = n;
        }
        int CGame::getdoor4m(){
            return doorm[4];
        }

        int CGame::getdoor4n(){
            return doorn[4];
        }

        void CGame::setdoor4m(int m){
            doorm[4] = m;
        }

        void CGame::setdoor4n(int n){
            doorn[4] = n;
        }
        int CGame::getdoor5m(){
            return doorm[5];
        }

        int CGame::getdoor5n(){
            return doorn[5];
        }

        void CGame::setdoor5m(int m){
            doorm[5] = m;
        }

        void CGame::setdoor5n(int n){
            doorn[5] = n;
        }

        void CGame::leer(){
            //si el monstruo ha matado al personaje principal, return
            int valormuerte = 0; // si vale 1, fin del programa
            char aux;
            while(getmax_mov()>0){
                
                cout << "Le quedan: " << getmax_mov() << " ";
                if(ccharacter_->getamuleto()==true){
                    cout << "Tiene el amuleto." << endl;
                    cout << "Debes volver a la posicion de salida para finalizar el juego" << endl;
                }
                else 
                    cout << endl;
                
                if((getposroom()==0) && (getposxroom() ==1) && (getposyroom() ==1) && (ccharacter_->getamuleto()==true)){
                    cout << "Juego terminado!!!!!!\n Felicidades!" << endl;
                    return;
                    
                }

                cout << "\t\tEnter a movement: right(d), left(a), up(w), down(x): " << endl;
                cin >> aux;
                cout << getrooms().at((getposroom()))->getm() << " " << getrooms().at((getposroom()))->getn() << endl;
                //if((getrooms().at(getposroom())->getdata(getposxroom(), getposyroom())=='*')||(getrooms().at(getposroom())->getdata(getposxroom(), getposyroom()) =='+')){
                    
                if (aux=='d' && ((getrooms().at((getposroom()))->getdata(getposxroom(),getposyroom()+1)==('$')))){//nos encontramos un amuleto
                ccharacter_->setamuleto(true);
                cout << "Debes volver a la posicion de salida para finalizar el juego" << endl;
                setdatatablegame(getposxroom()+20, getposyroom()+16, 'X');
                showtableGame();
                //getrooms().at((getposroom()))->setpjdata('X', getposxroom(),getposyroom()+1);
                //movepj(1);
                    
                }
                else if((aux=='d' && getposyroom()<getrooms().at((getposroom()))->getn()-2)){//|| aux==ARROW_UP)
                        cout << "Derecha y me encuentro dentro de una habitacion" << endl;
                        valormuerte= movepj(1);//right
                        if(valormuerte==1)
                            break;
                        }
                    
                else if (aux=='d' && ((getrooms().at((getposroom()))->getdata(getposxroom(),getposyroom()+1)==('+')))){
                        valormuerte= movepj(1);
                        if(valormuerte==1)
                            break;
                        cout << "Derecha y me encuentro una +" << endl;
                        cout << "Pulse enter para cambiar a la siguiente habitacion" << endl;
                        char text;
                        cin >> text;
                        if(text == 'd'){
                            cout << text << endl;
                            
                            getrooms().at((getposroom()))->setpjdata('+', getposxroom(),getposyroom()-1);
                            setposroom(1);
                            pos[1] = ((getrooms().at(1)->getm()-1)/2);
                            pos[2] =0; //reset posyroom porque la puerta en la segunda habitacion en y vale cero
                            //cout << "pos x: " << getposxroom() << " pos y: " << getposyroom() << endl;
                            //setdatatablegame(((getrooms().at(1)->getm()-1)/2), 0, '|');
                            //setdatapjrooms('o', 1, 1, 1);
                            //setposyroom(1);
                            setdatatablegame(getdoor0m()+4,getdoor0n()+5, '+');
                            cambioroom= true;
                            setdatatablegame(getdoor1m()+4,getdoor1n()+23, 'o');
                            ///cout << "HOLAAA" << endl;
                            setmax_mov();//-1
                            
                            showtableGame();
                        }
                }
                /*else if(aux=='d' && ((getrooms().at((getposroom()))->getdata(getposxroom(),getposyroom()+1)==('*')))){
                    cout << "Derecha y me encuentro una *" << endl;
                    movepj(1);//right
                    
                }*/
            else if (aux=='a' && ((getrooms().at((getposroom()))->getdata(getposxroom(),getposyroom()-1)==('$')))){//nos encontramos un amuleto
                    ccharacter_->setamuleto(true);
                    cout << "Debes volver a la posicion de salida para finalizar el juego" << endl;
                    setdatatablegame(getposxroom()+20, getposyroom()+14, 'X');
                    showtableGame();
                    //getrooms().at((getposroom()))->setpjdata('X', getposxroom(),getposyroom()-1);
                    //movepj(2);//left
                    
                }
                else if(aux=='a'&& getposyroom()>1)
                        valormuerte= movepj(2);//left
                        if(valormuerte==1)
                            break;

                /*else if (aux=='a' && ((getrooms().at((getposroom()))->getdata(getposxroom(),getposyroom()-1)=='+')||(getrooms().at((getposroom()))->getdata(getposxroom(),getposyroom()-1)=='#'))){
                        movepj(2);//right
                }*/
                else if (aux=='w' && ((getrooms().at((getposroom()))->getdata(getposxroom()-1,getposyroom())==('$')))){//nos encontramos un amuleto
                        ccharacter_->setamuleto(true);
                        cout << "Debes volver a la posicion de salida para finalizar el juego" << endl;
                        setdatatablegame(getposxroom()+19, getposyroom()+15, 'X');
                        showtableGame();
                        //getrooms().at((getposroom()))->setpjdata('X', getposxroom()-1,getposyroom());
                        //movepj(3);//up
                }
                else if(aux=='w'&& getposxroom()>1)
                        valormuerte= movepj(3);//up
                        if(valormuerte==1)
                            break;
                        
                else if (aux=='w' && (getrooms().at((getposroom()))->getdata(getposxroom()-1,getposyroom())=='+')){
                        
                    
                        valormuerte= movepj(3);//up
                        if(valormuerte==1)
                            break;
                        cout << "Arriba y me encuentro una +" << endl;
                        cout << "Pulse 'w' para cambiar a la siguiente habitacion" << endl;
                        char text;
                        cin >> text;
                        if(text == 'w'){
                            cout << text << endl;
                            
                        /* doorm[1] = (getrooms().at(1)->getm()-1)/2;
            doorn[1] = 0;*/
                            /*setposxroom((getrooms().at(1)->getm()-1)/2);
                            setposyroom(0);*/
                            
                            getrooms().at((getposroom()))->setpjdata('+', getposxroom(),getposyroom()-1);
                            setposroom(0); //room
                            
                            pos[1] = (getrooms().at(0)->getm()-1);//la ultima puerta de la ultima habitacion a la primera se pondra cuando recojas el amuleto
                            pos[2] = (getrooms().at(0)->getn()-1)/2;
                            
                        
                            //cout << "pos x: " << getposxroom() << " pos y: " << getposyroom() << endl;
                            //setdatatablegame(((getrooms().at(1)->getm()-1)/2), 0, '|');
                            //setdatapjrooms('o', 1, 1, 1);
                            //setposyroom(1);
                            setdatatablegame(getdoor4m()+20,getdoor4n()+15, '+');
                            cambioroom= true;
                            setdatatablegame(getdoor5m()+4,getdoor5n()+5, 'o');
                            //cout << "HOLAAA" << endl;
                            setmax_mov();//-1
                            showtableGame();
                        }
                            
                }
                else if (aux=='x' && ((getrooms().at((getposroom()))->getdata(getposxroom()+1,getposyroom())==('$')))){//nos encontramos un amuleto
                            ccharacter_->setamuleto(true);
                            cout << "Debes volver a la posicion de salida para finalizar el juego" << endl;
                            setdatatablegame(getposxroom()+21, getposyroom()+15, 'X');
                            showtableGame();
                            //getrooms().at((getposroom()))->setpjdata('X', getposxroom()+1,getposyroom());
                            //movepj(4);
                }
                else if(aux=='x'&& getposxroom()<getrooms().at((getposroom()))->getm()-2)
                        movepj(4);//down
                
                else if (aux=='x' && ((getrooms().at((getposroom()))->getdata(getposxroom()+1,getposyroom())=='+'))){
                        movepj(4);//down
                        
                        cout << "Abajo y me encuentro una +" << endl;
                        cout << "Pulse 'x' para cambiar a la siguiente habitacion" << endl;
                        char text;
                        cin >> text;
                        if(text == 'x'){
                            cout << text << endl;
                            
                        /* doorm[1] = (getrooms().at(1)->getm()-1)/2;
            doorn[1] = 0;*/
                            /*setposxroom((getrooms().at(1)->getm()-1)/2);
                            setposyroom(0);*/
                            
                            getrooms().at((getposroom()))->setpjdata('+', getposxroom(),getposyroom()-1);
                            setposroom(2); //room
                            pos[1] = (getrooms().at(2)->getm()-1)/2; //x
                            pos[2] = getrooms().at(2)->getn()-1;//y
                            
                        
                            //cout << "pos x: " << getposxroom() << " pos y: " << getposyroom() << endl;
                            //setdatatablegame(((getrooms().at(1)->getm()-1)/2), 0, '|');
                            //setdatapjrooms('o', 1, 1, 1);
                            //setposyroom(1);
                            setdatatablegame(getdoor2m()+4,getdoor2n()+23, '+');
                            cambioroom= true;
                            setdatatablegame(getdoor3m()+20,getdoor3n()+15, 'o');
                            //cout << "HOLAAA" << endl;
                            setmax_mov();//-1
                            showtableGame();
                        }
                }
                
                else if (((aux=='a') || (aux=='d') || (aux=='w') || (aux=='x'))) //in a wall
                {
                    cout << "Siguiente casilla: " << getrooms().at((getposroom()))->getdata(getposxroom(),getposyroom()+1) << endl;
                    cout << "\t\tThere is a wall in that box, try another move" << endl << endl;
                    
                    leer();
                }else
                {
                    cout << "\t\tError in the character entered by keyboard. Try another."<< endl << endl;
                    leer();
                }
                //movepj(aux);//1 right, 2 left, 3 up, 4 down
            }
            if(getmax_mov()==0)
                    cout << "Game over, try again"<< endl;
        }


        int CGame::movepj(int i){ //rooms (4,5), (4,23), (20, 15)
            if(i==1)//right
            {
                    //pos[2] += 1;
                    getrooms().at((getposroom()))->moveright(getposxroom(), getposyroom());
                    if((getposroom()==0) && getdatatablegame(getposxroom()+4, getposyroom()+6) != 'W'){
                        //pos[2] += 1;
                        getrooms().at((getposroom()))->moveright(getposxroom(), getposyroom());
                        if(cambioroom==false)
                            setdatatablegame(getposxroom()+4, getposyroom()+5, '*');
                        else{
                            setdatatablegame(getposxroom()+4, getposyroom()+5, '+');
                        }
                        setposyroom(1);
                        setdatatablegame(getposxroom()+4, getposyroom()+5, 'o');
                    }
                    else if((getposroom()==1) && getdatatablegame(getposxroom()+4, getposyroom()+24) != 'W')
                    {
                        //pos[2] += 1;
                        getrooms().at((getposroom()))->moveright(getposxroom(), getposyroom());
                        cout << "No puedes volver a la primera habitacion" << endl;
                        if(cambioroom==false)
                            setdatatablegame(getposxroom()+4, getposyroom()+23, '*');
                        else
                            setdatatablegame(getposxroom()+4, getposyroom()+23, '+');
                        setposyroom(1);
                        setdatatablegame(getposxroom()+4, getposyroom()+23, 'o');
                    }
                    else if(getposroom()==2)
                    {   
                        //pos[2] += 1;
                        getrooms().at((getposroom()))->moveright(getposxroom(), getposyroom());
                        cout << "No puedes volver a la segunda habitacion" << endl;
                        if(cambioroom==false)
                            setdatatablegame(getposxroom()+20, getposyroom()+15, '*');
                        else
                            setdatatablegame(getposxroom()+20, getposyroom()+15, '+');
                        
                        setposyroom(1);
                        setdatatablegame(getposxroom()+20, getposyroom()+15, 'o');
                    }else{
                        cout << "ALEJATEE DEL MONSTRUO ANTES DE MORIRR!" << endl;
                        maxgolpes_--;
                        pintarvida();
                    }
                    cambioroom=false;

            }
            if(i==2)//left
            {

                    if((getposroom()==0) && getdatatablegame(getposxroom()+4, getposyroom()+4) != 'W'){
                        getrooms().at(getposroom())->moveleft(getposxroom(), getposyroom());
                        if(cambioroom==false)
                            setdatatablegame(getposxroom()+4, getposyroom()+5, '*');
                        else
                            setdatatablegame(getposxroom()+4, getposyroom()+5, '+');
                        setposyroom(-1);
                        setdatatablegame(getposxroom()+4, getposyroom()+5, 'o');
                    }
                    else if((getposroom()==1) && getdatatablegame(getposxroom()+4, getposyroom()+22) != 'W')
                    {
                        getrooms().at(getposroom())->moveleft(getposxroom(), getposyroom());
                        cout << "No puedes volver a la primera habitacion" << endl;
                        if(cambioroom==false)
                            setdatatablegame(getposxroom()+4, getposyroom()+23, '*');
                        else
                            setdatatablegame(getposxroom()+4, getposyroom()+23, '+');
                        setposyroom(-1);
                        setdatatablegame(getposxroom()+4, getposyroom()+23, 'o');
                    }
                    else if(getposroom()==2)
                    {
                        getrooms().at(getposroom())->moveleft(getposxroom(), getposyroom());
                        cout << "No puedes volver a la segunda habitacion" << endl;
                        if(cambioroom==false)
                            setdatatablegame(getposxroom()+20, getposyroom()+15, '*');
                        else
                            setdatatablegame(getposxroom()+20, getposyroom()+15, '+');
                        setposyroom(-1);
                        setdatatablegame(getposxroom()+20, getposyroom()+15, 'o');
                    }else{
                        cout << "ALEJATEE DEL MONSTRUO ANTES DE MORIRR!" << endl;
                        maxgolpes_--;
                        pintarvida();
                    }
                    cambioroom=false;
            }
            if(i==3)//up
            {
                    if((getposroom()==0) && getdatatablegame(getposxroom()+3, getposyroom()+5) != 'W'){
                        getrooms().at(getposroom())->moveup(getposxroom(), getposyroom());
                        if(cambioroom==false)
                            setdatatablegame(getposxroom()+4, getposyroom()+5, '*');
                        else
                            setdatatablegame(getposxroom()+4, getposyroom()+5, '+');
                        setposxroom(-1);
                        setdatatablegame(getposxroom()+4, getposyroom()+5, 'o');
                    }
                    else if((getposroom()==1) && getdatatablegame(getposxroom()+3, getposyroom()+23) != 'W')
                    {
                        getrooms().at(getposroom())->moveup(getposxroom(), getposyroom());
                        cout << "No puedes volver a la primera habitacion" << endl;
                        if(cambioroom==false)
                            setdatatablegame(getposxroom()+4, getposyroom()+23, '*');
                        else
                            setdatatablegame(getposxroom()+4, getposyroom()+23, '+');
                        setposxroom(-1);
                        setdatatablegame(getposxroom()+4, getposyroom()+23, 'o');
                    }
                    else if(getposroom()==2)
                    {
                        getrooms().at(getposroom())->moveup(getposxroom(), getposyroom());
                        cout << "No puedes volver a la segunda habitacion" << endl;
                        if(cambioroom==false)
                            setdatatablegame(getposxroom()+20, getposyroom()+15, '*');
                        else
                            setdatatablegame(getposxroom()+20, getposyroom()+15, '+');
                        setposxroom(-1);
                        setdatatablegame(getposxroom()+20, getposyroom()+15, 'o');
                    }else {
                        cout << "ALEJATEE DEL MONSTRUO ANTES DE MORIRR!" << endl;
                        maxgolpes_--;
                        pintarvida();
                    }
                    cambioroom=false;
            }
            if(i==4)//down
            {
                    if((getposroom()==0) && getdatatablegame(getposxroom()+5, getposyroom()+5) != 'W'){
                        getrooms().at(getposroom())->movedown(getposxroom(), getposyroom());
                        if(cambioroom==false)
                            setdatatablegame(getposxroom()+4, getposyroom()+5, '*');
                        else
                            setdatatablegame(getposxroom()+4, getposyroom()+5, '+');
                        setposxroom(1);
                        setdatatablegame(getposxroom()+4, getposyroom()+5, 'o');
                    }
                    else if((getposroom()==1) && getdatatablegame(getposxroom()+5, getposyroom()+23) != 'W')
                    {
                        getrooms().at(getposroom())->movedown(getposxroom(), getposyroom());
                        cout << "No puedes volver a la primera habitacion" << endl;
                        if(cambioroom==false)
                            setdatatablegame(getposxroom()+4, getposyroom()+23, '*');
                        else
                            setdatatablegame(getposxroom()+4, getposyroom()+23, '+');
                        setposxroom(1);
                        setdatatablegame(getposxroom()+4, getposyroom()+23, 'o');
                    }
                    else if(getposroom()==2)
                    {
                        getrooms().at(getposroom())->movedown(getposxroom(), getposyroom());
                        cout << "No puedes volver a la segunda habitacion" << endl;
                        if(cambioroom==false)
                            setdatatablegame(getposxroom()+20, getposyroom()+15, '*');
                        else
                            setdatatablegame(getposxroom()+20, getposyroom()+15, '+');
                        setposxroom(1);
                        setdatatablegame(getposxroom()+20, getposyroom()+15, 'o');
                    }else{
                        cout << "ALEJATEE DEL MONSTRUO ANTES DE MORIRR!" << endl;
                        maxgolpes_--;
                    }
                    cambioroom=false;
            }
            bool valido = false;//movimiento del monstruo valido
            setmax_mov();//-1
            int* difx = new int [2];
            int* dify = new int[2];

            if(getmax_mov()%2==0)//movemos los monstruos
            {   cout << "HOLA" << posmonstersx_[0] << posmonstersy_[0] << endl;
                        if(getposroom()==0)
                        {   for (int i= 0; i< 2; i++)
                            {
                                difx[i] = fabs(posmonstersx_[i]-getposxroom());
                                dify[i] = fabs(posmonstersy_[i]-getposyroom());
                            
                                cout << "La distancia actual del monstruo con el pj es: " << difx[i] << ", " << dify[i] << endl; 
                            }
                            for(int k=0; k<2; k++){//num de monstruos en movimiento{
                                
                                //monstruos golpeando al pj
                                if((difx[k]==0 && dify[k]==2) || (difx[k]==2 && dify[k]==0)){
                                    maxgolpes_--;
                                    pintarvida();
                                    cout << "Le han golpeado, le quedan: " << maxgolpes_ << "vidas." << endl;
                                }
                                //Monstruos misma habitacion //Si entran en conflicto, uno de ellos no se mueve
                                    //down
                                    if(fabs((posmonstersx_[k]+1)-getposxroom())< difx[k] && (getdatatablegame(posmonstersx_[k]+5, posmonstersy_[k]+5) !='W')) //si el pj esta a la derecha del monstruo
                                    {
                                        if(getdatatablegame(posmonstersx_[k]+5, posmonstersy_[k]+5)!= 'o'){
                                            setdatatablegame(posmonstersx_[k]+4, posmonstersy_[k]+5, '*');
                                            posmonstersx_[k]++;
                                            setdatatablegame(posmonstersx_[k]+4, posmonstersy_[k]+5, 'W');
                                            valido = true;
                                            cout << "quedan x:" << posmonstersx_<< endl;
                                            //break;
                                        }else{
                                            maxgolpes_--;
                                            pintarvida();
                                        }
                                    }
                            //up
                                    else if(fabs((posmonstersx_[k]-1)-getposxroom())< difx[k]&& (getdatatablegame(posmonstersx_[k]+3, posmonstersy_[k]+5) !='W')) //si el pj esta a la derecha del monstruo
                                    {
                                        if(getdatatablegame(posmonstersx_[k]+3, posmonstersy_[k]+5)!= 'o'){
                                            setdatatablegame(posmonstersx_[k]+4, posmonstersy_[k]+5, '*');
                                            posmonstersx_[k]--;
                                            setdatatablegame(posmonstersx_[k]+4, posmonstersy_[k]+5, 'W');
                                            valido = true;
                                            cout << "quedan x:" << posmonstersx_ << endl;
                                            //break;
                                        }else{
                                            maxgolpes_--;
                                            pintarvida();
                                        }
                                    }
                            //right
                                    else if(fabs((posmonstersy_[k]+1)-getposyroom())< dify[k] && (getdatatablegame(posmonstersx_[k]+4, posmonstersy_[k]+6) !='W')) //si el pj esta a la derecha del monstruo
                                    {
                                        if(getdatatablegame(posmonstersx_[k]+4, posmonstersy_[k]+6)!= 'o'){
                                            setdatatablegame(posmonstersx_[k]+4, posmonstersy_[k]+5, '*');
                                            posmonstersy_[k]++;
                                            setdatatablegame(posmonstersx_[k]+4, posmonstersy_[k]+5, 'W');
                                            valido = true;
                                            cout << "quedan y:" << posmonstersy_ << endl;
                                            //break;
                                        }else{
                                            maxgolpes_--;
                                            pintarvida();
                                        }
                                        
                                    }//left
                                    else if(fabs((posmonstersy_[k]-1)-getposyroom())< dify[k] && (getdatatablegame(posmonstersx_[k]+4, posmonstersy_[k]+4) !='W')) //si el pj esta a la derecha del monstruo
                                    {
                                        if(getdatatablegame(posmonstersx_[k]+5, posmonstersy_[k]+4)!= 'o'){
                                            setdatatablegame(posmonstersx_[k]+4, posmonstersy_[k]+5, '*');
                                            posmonstersy_[k]--;
                                            setdatatablegame(posmonstersx_[k]+4, posmonstersy_[k]+5, 'W');
                                            valido = true;
                                            cout << "quedan y:" << posmonstersy_ << endl;
                                            //break;
                                        }else{
                                            maxgolpes_--;
                                            pintarvida();
                                        }
                                    }else{
                                        cout << "ALEJATEE DEL MONSTRUO ANTES DE MORIRR!" << endl;
                                        maxgolpes_--;
                                        pintarvida();

                                        
                                        cout << "Vida: " << maxgolpes_ << endl;
                                    }
                                    
                                }
                                for(int k=2; k< 4; k++){//resto de monstruos
                                    if(posmonstersx_[k]+2< getrooms().at(1)->getm()){//down
                                        setdatatablegame(posmonstersx_[k]+4, posmonstersy_[k]+23, '*');
                                        posmonstersx_[k]++;
                                        setdatatablegame(posmonstersx_[k]+4, posmonstersy_[k]+23, 'W');
                                        valido = true;
                                    }else if(posmonstersx_[k]-2 > 0){
                                        setdatatablegame(posmonstersx_[k]+4, posmonstersy_[k]+23, '*');//up
                                        posmonstersx_[k]--;
                                        setdatatablegame(posmonstersx_[k]+4, posmonstersy_[k]+23, 'W');
                                        valido = true;
                                    }else if(posmonstersy_[k]+2< getrooms().at(1)->getn()){//right
                                        setdatatablegame(posmonstersx_[k]+4, posmonstersy_[k]+23, '*');
                                        posmonstersx_[k]++;
                                        setdatatablegame(posmonstersx_[k]+4, posmonstersy_[k]+23, 'W');
                                        valido = true;
                                    }else if(posmonstersx_[k]-2 > 0){
                                        setdatatablegame(posmonstersy_[k]+4, posmonstersy_[k]+23, '*');//left
                                        posmonstersy_[k]--;
                                        setdatatablegame(posmonstersy_[k]+4, posmonstersy_[k]+23, 'W');
                                        valido = true;
                                    }
                                }
                        }else{ //pj en la segunda habitacion, comportamiento contrario. Hecho copy paste de anterior condicion. Hacer funcion especifica 
                            cout << "CACA" << endl;
                            for (int i= 0; i< 2; i++)
                            {
                                difx[i] = fabs(posmonstersx_[i+2]-getposxroom());
                                dify[i] = fabs(posmonstersy_[i+2]-getposyroom());
                            
                                cout << "La distancia actual del monstruo con el pj es: " << difx[i] << ", " << dify[i] << endl; 
                                cout <<"HEYSSS" << endl;
                                
                            }
                            for(int k=2; k<4; k++){//num de monstruos en movimiento{
                                    
                                    //monstruos golpeando
                                    if((difx[k-2]==0 && dify[k-2]==2) || (difx[k-2]==2 && dify[k-2]==0)){
                                        maxgolpes_--;
                                        pintarvida();
                                        cout << "Le han golpeado, le quedan: " << maxgolpes_ << "vidas." << endl;
                                    }
                                cout << "HEYSSSS " << difx[0] << fabs((posmonstersx_[k]+1)-getposxroom())<< endl;
                
                                    //down
                                    if(fabs((posmonstersx_[k]+1)-getposxroom())<= difx[k-2] && (getdatatablegame(posmonstersx_[k]+5, posmonstersy_[k]+23) !='W')) //si el pj esta a la derecha del monstruo
                                    {   cout << "Pos monstruo: " << posmonstersx_[k]+1 << "," << posmonstersy_[k] << "Pos pj: " << getposxroom() << "," << getposyroom() << endl;
                                        cout << "VALOR DIFERENCIA: " << fabs((posmonstersx_[k]+1)-getposxroom()) << endl;
                                        
                                        if(getdatatablegame(posmonstersx_[k]+5, posmonstersy_[k]+23)!= 'o'){
                                            setdatatablegame(posmonstersx_[k]+4, posmonstersy_[k]+23, '*');
                                            posmonstersx_[k]++;
                                            setdatatablegame(posmonstersx_[k]+4, posmonstersy_[k]+23, 'W');
                                            valido = true;
                                            cout << "quedan x:" << posmonstersx_<< endl;
                                            showtableGame();
                                            //break;
                                        }else{
                                            maxgolpes_--;
                                            pintarvida();
                                        }
                                    }
                                    //up
                                    else if(fabs((posmonstersx_[k]-1)-getposxroom())<= difx[k-2]&& (getdatatablegame(posmonstersx_[k]+3, posmonstersy_[k]+23) !='W')) //si el pj esta a la derecha del monstruo
                                    {
                                        if(getdatatablegame(posmonstersx_[k]+3, posmonstersy_[k]+23)!= 'o'){
                                            setdatatablegame(posmonstersx_[k]+4, posmonstersy_[k]+23, '*');
                                            posmonstersx_[k]--;
                                            setdatatablegame(posmonstersx_[k]+4, posmonstersy_[k]+23, 'W');
                                            valido = true;
                                            cout << "quedan x:" << posmonstersx_ << endl;
                                            showtableGame();
                                            //break;
                                        }else{
                                            maxgolpes_--;
                                            pintarvida();
                                        }
                                    }
                                    //right
                                    else if(fabs((posmonstersy_[k]+1)-getposyroom())<= dify[k-2] && (getdatatablegame(posmonstersx_[k]+4, posmonstersy_[k]+24) !='W')) //si el pj esta a la derecha del monstruo
                                    {
                                        if(getdatatablegame(posmonstersx_[k]+4, posmonstersy_[k]+24)!= 'o'){
                                            setdatatablegame(posmonstersx_[k]+4, posmonstersy_[k]+23, '*');
                                            posmonstersy_[k]++;
                                            setdatatablegame(posmonstersx_[k]+4, posmonstersy_[k]+23, 'W');
                                            valido = true;
                                            cout << "quedan y:" << posmonstersy_ << endl;
                                            showtableGame();
                                            //break;
                                        }else{
                                            maxgolpes_--;
                                            pintarvida();
                                        }
                                    }//left
                                    else if(fabs((posmonstersy_[k]-1)-getposyroom())<= dify[k-2] && (getdatatablegame(posmonstersx_[k]+4, posmonstersy_[k]+22) !='W')) //si el pj esta a la derecha del monstruo
                                    {
                                        if(getdatatablegame(posmonstersx_[k]+4, posmonstersy_[k]+22)!= 'o'){
                                            setdatatablegame(posmonstersx_[k]+4, posmonstersy_[k]+23, '*');
                                            posmonstersy_[k]--;
                                            setdatatablegame(posmonstersx_[k]+4, posmonstersy_[k]+23, 'W');
                                            valido = true;
                                            cout << "quedan y:" << posmonstersy_ << endl;
                                            showtableGame();
                                            //break;
                                        }else{
                                            maxgolpes_--;
                                            pintarvida();
                                        }
                                    }else{
                                        cout << "ALEJATEE DEL MONSTRUO ANTES DE MORIRR!" << endl;
                                        maxgolpes_--;
                                        pintarvida();
                                    }
                                }
                                for(int k=0; k< 2; k++){//resto de monstruos
                                    if(posmonstersx_[k]+2< getrooms().at(0)->getm()){//down
                                        setdatatablegame(posmonstersx_[k]+4, posmonstersy_[k]+5, '*');
                                        posmonstersx_[k]++;
                                        setdatatablegame(posmonstersx_[k]+4, posmonstersy_[k]+5, 'W');
                                        valido = true;
                                    }else if(posmonstersx_[k]-2 > 0){
                                        setdatatablegame(posmonstersx_[k]+4, posmonstersy_[k]+5, '*');//up
                                        posmonstersx_[k]--;
                                        setdatatablegame(posmonstersx_[k]+4, posmonstersy_[k]+5, 'W');
                                        valido = true;
                                    }else if(posmonstersy_[k]+2< getrooms().at(0)->getn()){//right
                                        setdatatablegame(posmonstersx_[k]+4, posmonstersy_[k]+5, '*');
                                        posmonstersx_[k]++;
                                        setdatatablegame(posmonstersx_[k]+4, posmonstersy_[k]+5, 'W');
                                        valido = true;
                                    }else if(posmonstersx_[k]-2 > 0){
                                        setdatatablegame(posmonstersy_[k]+4, posmonstersy_[k]+5, '*');//left
                                        posmonstersy_[k]--;
                                        setdatatablegame(posmonstersy_[k]+4, posmonstersy_[k]+5, 'W');
                                        valido = true;
                                    }
                                }
                        }
                        /*for(int k=0; k< 2; k++){
                            //Muerte pj por monstruo
                            if((difx[k]==0 && dify[k]==1) || (difx[k]==1 && dify[k]==0)){
                                    maxgolpes_--;
                                    cout << "Le han golpeado, le quedan: " << maxgolpes_ << "vidas." << endl;
                                    if(maxgolpes_==0)
                                        exit(0);
                            }
                        }*/

                
            }//si el movimiento es par movemos monstruos
        //  delay(1);
        // m = rand()%10+9,(rand()%10+8);
                        
                        /*if(dif0x>0){
                            if(fabs((posmonstersx_[0]+1)-getposxroom())< dif0x) //si el pj esta a la derecha del monstruos
                            {
                                getrooms().at(0)->setpjdata('*', posmonstersx_[0], posmonstersy_[0]);
                                posmonstersx_[0]++;
                                getrooms().at(0)->setpjdata('W', posmonstersx_[0], posmonstersy_[0]);
                                
                            }
                            else{//monstruo a la izquierda
                                getrooms().at(0)->setpjdata('*', posmonstersx_[0], posmonstersy_[0]);
                                posmonstersx_[0]--;
                                getrooms().at(0)->setpjdata('W', posmonstersx_[0], posmonstersy_[0]);
                            }
                        }else if(dif0y>1){
                            if(fabs((posmonstersx_[0]+1)-getposxroom())< dif0y) //si el pj esta a la derecha del monstruos
                            {
                                getrooms().at(0)->setpjdata('*', posmonstersx_[0], posmonstersy_[0]);
                                posmonstersx_[0]++;
                                getrooms().at(0)->setpjdata('W', posmonstersx_[0], posmonstersy_[0]);
                                
                            }
                            else{//monstruo a la izquierda
                                getrooms().at(0)->setpjdata('*', posmonstersx_[0], posmonstersy_[0]);
                                posmonstersx_[0]--;
                                getrooms().at(0)->setpjdata('W', posmonstersx_[0], posmonstersy_[0]);
                            }
                        }else if(dif0y== 1)
                            maxgolpes_--;
                        else
                            cout << "Error " << endl;
                    }//for*/

            
            
            if(primermovimiento==false){
                primermovimiento= true;
                setdatatablegame(5, 6,'U');//marcamos la casilla de salida
            }
            
            
            showtableGame();
        }


        void CGame::showtableGame(){
            for(int i=0; i<35; i++){
                for(int j=0; j< 40; j++)
                    cout << getdatatablegame(i,j) << " ";
                cout << endl;
            }
        }

        void CGame::game(){


        }

        void CGame::delay(int secs) {
            for(int i = (time(NULL) + secs); time(NULL) != i; time(NULL));
        };
        
        void CGame::pintarvida(){
            if(maxgolpes_==5)
                gametable[29][13]='5';//2
            else if(maxgolpes_==4)
                gametable[29][13]='4';//2
            else if(maxgolpes_==3)
                gametable[29][13]='3';//2
                                            //setdatatablegame(29, 7+5,51);//3 5 corresponde a 'VIDA: ' a.size()
            else if(maxgolpes_==2)
                gametable[29][13]='2';//2
            else if(maxgolpes_==1)
                gametable[29][13]='1';    //setdatatablegame(29, 7+5,49);//1
            else if(maxgolpes_==0)
                gametable[29][13]='0';//setdatatablegame(29, 7+5,48);//0
           else
                  maxgolpes_=0;
                                 
           if(maxgolpes_==0){
                showtableGame();
                cout << "Ha muerto." << endl;
                exit(0);
            }
            showtableGame();
        }
