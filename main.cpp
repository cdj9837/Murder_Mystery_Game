#include "MurderMystery.h"
#include <gtkmm.h>
#include <iostream>

int main (int argc, char **argv)
{
    while(true){
    Gtk::Main app(argc, argv);
    Loop l(app);
    /*Menu m1;

    int life=0;
    bool s=false;

    welcome_window wind;

    Gtk::Main::run(wind);

    Rules rules(m1);
    Gtk::Main::run(rules);

    Background_Window story(m1);
    Gtk::Main::run(story);

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

        Exit_Incorrect e(m1);
        Gtk::Main::run(e);
    }
    else
    {
        Exit_Correct e1(m1);
        Gtk::Main::run(e1);
    }*/}
    //return 0;}
}

