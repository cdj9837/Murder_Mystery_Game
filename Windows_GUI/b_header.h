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
      Gtk::Label label;
      Gtk::Label label1;

};

class Exit_Correct: public Gtk::Window
{
    public:
      Exit_Correct();
      virtual ~Exit_Correct();

    protected:
      void home_page();

      Gtk::Box solved_box;
      Gtk::Image solved_image;
      Gtk::Button home_button;
      Gtk::Label solved_label;
      Gtk::Label label;

};

class Exit_Incorrect: public Gtk::Window
{
    public:
      Exit_Incorrect();
      virtual ~Exit_Incorrect();

    protected:
      void home_page();

      Gtk::Box unsolved_box;
      Gtk::Image unsolved_image;
      Gtk::Button home_button;
      Gtk::Label unsolved_label;
      Gtk::Label label;

};

#endif
