#ifndef GTKMM_EXAMPLEWINDOW_H
#define GTKMM_EXAMPLEWINDOW_H

#include <gtkmm.h>

class ExampleWindow : public Gtk::Window
{
public:
  ExampleWindow();
  virtual ~ExampleWindow();

protected:

void send_value();

  //Child widgets:
  Gtk::Box m_HBox;
  Gtk::Box m_VBox2;
  Gtk::Entry entry;
  Gtk::Frame m_Frame_LineWrapped;
  Gtk::Label m_Label_LineWrapped;
  Gtk::Button	button_send; 
  
};

#endif //GTKMM_EXAMPLEWINDOW_H

