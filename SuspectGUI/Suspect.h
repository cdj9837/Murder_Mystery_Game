#ifndef SUSPECT_H_INCLUDED
#define SUSPECT_H_INCLUDED

#include <gtkmm.h>
#include <string>
using namespace std;
class SuspectWindow : public Gtk::Window
{
protected:

    Gtk::Box box, hello, hello2;
    Gtk::Image suspect, weapons;

    Gtk::Button s1, s2, s3, s4, s5, w1, w2, w3, w4, w5;

    Gtk::Grid sGrid, wGrid;


    void onButtonClicked();
    void onButtonClickedMurder();
    void onButtonClickedNotMurder();

    void onButtonClickedMurderNotWeapon();
    void onButtonClickedNotMurderWeapon();

    void onButtonClickedWeapon();
    void onButtonClickedNotWeapon();
public:
    bool solved=false;
    SuspectWindow();
    virtual ~SuspectWindow();
};

class Person
{
    string name;
    bool murderer;
 public:
    Person(string name);
    void setMurderer(bool guilty);
    bool getMurderer();
    string getName();
};

#endif // SUSPECT_H_INCLUDED
