#include "MurderMystery.h"
#include <gtkmm.h>
#include <iostream>

int main (int argc, char **argv)
{
    Gtk::Main app(argc, argv);
    Menu m1;

    int life=0;
    bool s=false;

    SuspectWindow window(m1);
    Gtk::Main::run(window);

    s=window.solved;
    life++;

    if(life<3 && !s)
    {
        SuspectWindow win(m1);
        Gtk::Main::run(win);

        s=win.solved;
        life++;
    }

    if(life<3 && !s)
    {
        SuspectWindow w(m1);
        Gtk::Main::run(w);

        s=w.solved;
        life++;
    }
    return 0;
}

