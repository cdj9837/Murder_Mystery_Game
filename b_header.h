#ifndef B_HEADER_H
#define B_HEADER_H

#include <gtkmm.h>

class Background_Window: public Gtk::Window
{
    public:
      Background_Window();
      virtual ~Background_Window();

    protected:
      void background_continue();

      Gtk::Box box;
      Gtk::Image back_image;
      Gtk::Button continue_button;

};

#endif
