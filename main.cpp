//#include <QCoreApplication>
#include <time.h>
#include <sys/time.h>
#include <iostream>
#include <string>
using namespace std;
void delay(int secs) {
      for(int i = (time(NULL) + secs); time(NULL) != i; time(NULL));
      }

int main(int argc, char *argv[])
{





    string a;

        //delay(2);
    for(int i=0; i < 30; i++){
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
         cout << "\t\t\t\t\t Desarrollado por Ivan Garcia Campos\n" << endl;


}

    //QCoreApplication a(argc, argv);

    //return a.exec();
}
