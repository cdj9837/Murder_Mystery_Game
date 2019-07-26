#include <gtkmm.h>
#include <string>
#include <iostream>
#include "MurderMystery.h"
#include "b_header.h"

Background_Window::Background_Window()
{
    set_size_request(400,300);
    set_title("Background Information");

    add(box);

    back_image.set("location.png");
    box.pack_start(back_image);

    CaseStory cs;

    cs.getBackStory();

    continue_button.add_label("Continue");
    continue_button.signal_clicked().connect(sigc::mem_fun(*this,&Background_Window::background_continue));
    box.pack_start(continue_button);

    show_all_children();
}

Background_Window::~Background_Window()
{

}

void Background_Window::background_continue()
{
    //call to signal_clicked to start Suspects / Weapons window
}

int main()
{
    Gtk::Main app();

    Background_Window w;

    Gtk::Main::run(w);

    return 0;
}
