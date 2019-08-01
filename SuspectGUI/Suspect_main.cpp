#include "Suspect.h"
#include <gtkmm.h>
#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    Gtk::Main app(argc, argv);
    int life=0;
    bool s=false;
    //std::vector<std::string> info={"Bridgette","Dan","Johnny","Frankie","Joey"};

    SuspectWindow window;
    Gtk::Main::run(window);

    s=window.solved;
    life++;

    if(life<3 && !s)
    {
        SuspectWindow win;
        Gtk::Main::run(win);

        s=win.solved;
        life++;
    }

    if(life<3 && !s)
    {
        SuspectWindow w;
        Gtk::Main::run(w);

        s=w.solved;
        life++;
    }

    if(!s)
        cout<<"Murderer got away"<<endl;
    else
        cout<<"SOLVED"<<endl;

    return 0;
}


