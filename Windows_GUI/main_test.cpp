#include <gtkmm.h>
#include <iostream>
#include "b_header.h"

int main(int argc, char *argv[])
{
    Gtk::Main app(argc, argv);

    Background_Window w;

    Exit_Correct e1;

    Exit_Incorrect e2;

    Gtk::Main::run(w);

    Gtk::Main::run(e1);

    Gtk::Main::run(e2);

    return 0;
}
