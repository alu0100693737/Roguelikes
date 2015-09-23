//#include <QCoreApplication>
#include <time.h>
#include <sys/time.h>
#include <iostream>
#include <string>
#include "croom.h"
#include "cgame.h"
#include <ostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{
    /*string a;

        //delay(2);
    //for(int i=0; i < 30; i++){
        a =  "\n\t\t██╗    ██╗███████╗██╗      ██████╗ ██████╗ ███╗   ███╗███████╗    ████████╗ ██████╗ ";
        a += "\n\t\t██║    ██║██╔════╝██║     ██╔════╝██╔═══██╗████╗ ████║██╔════╝    ╚══██╔══╝██╔═══██╗";
        a += "\n\t\t██║ █╗ ██║█████╗  ██║     ██║     ██║   ██║██╔████╔██║█████╗         ██║   ██║   ██║";
        a += "\n\t\t██║███╗██║██╔══╝  ██║     ██║     ██║   ██║██║╚██╔╝██║██╔══╝         ██║   ██║   ██║";
        a += "\n\t\t╚███╔███╔╝███████╗███████╗╚██████╗╚██████╔╝██║ ╚═╝ ██║███████╗       ██║   ╚██████╔╝";
        a += "\n\t\t ╚══╝╚══╝ ╚══════╝╚══════╝ ╚═════╝ ╚═════╝ ╚═╝     ╚═╝╚══════╝       ╚═╝    ╚═════╝ ";

        cout << "\033[2J\033[1;1H"; //clear linux regexp
         cout << a;
         a = ""; cout << a; cout << endl << endl;

         cout << "\033[2J\033[1;1H";

         a =  "\n\t\t██████╗  ██████╗  ██████╗ ██╗   ██╗███████╗██╗     ██╗██╗  ██╗███████╗███████╗";
         a += "\n\t\t██╔══██╗██╔═══██╗██╔════╝ ██║   ██║██╔════╝██║     ██║██║ ██╔╝██╔════╝██╔════╝";
         a += "\n\t\t██████╔╝██║   ██║██║  ███╗██║   ██║█████╗  ██║     ██║█████╔╝ █████╗  ███████╗";
         a += "\n\t\t██╔══██╗██║   ██║██║   ██║██║   ██║██╔══╝  ██║     ██║██╔═██╗ ██╔══╝  ╚════██║";
         a += "\n\t\t██║  ██║╚██████╔╝╚██████╔╝╚██████╔╝███████╗███████╗██║██║  ██╗███████╗███████║";
         a += "\n\t\t╚═╝  ╚═╝ ╚═════╝  ╚═════╝  ╚═════╝ ╚══════╝╚══════╝╚═╝╚═╝  ╚═╝╚══════╝╚══════╝";

         cout << a;
         a = ""; cout << a; cout << endl << endl;
         cout << "\t\t\t\t\t\t\t Desarrollado por Ivan Garcia Campos\n" << endl;
*/      string a = "";
         CGame E(3, 1,3, 2);
          CGame F(3,1,2,1 );


         E.showGame();
         for(int i=0; i<20; i++)
            E.leer();
         //cout << "\033[2J\033[1;1H"; //clear linux regexp
         //cout << endl << endl;
         F.showGame();
         cout << endl << endl;
       /*  for(int i=0; i< E.getrooms().at(0)->getm(); i++){
             for(int j=0; j< E.getrooms().at(0)->getn(); j++){
                cout <<  E.getrooms().at(0)->getdata(i,j) << " ";

                //flush();
             }cout << endl;


        }
*/

    //cout << E.getrooms().at(0)->getm() << " " << E.getrooms().at(0)->getn();
//Funcionan las habitaciones
       /*  CRoom A(1);
        for(int i=0; i< A.getm(); i++){
            for(int j=0; j<A.getn(); j++)
                cout << A.getdata(i,j);
            cout << endl;


        }/*
         A.showRoom();
         CRoom B(2);
         B.showRoom();
         CRoom C(3);
         C.showRoom();*/

    //QCoreApplication a(argc, argv);
    //return a.exec();
}
