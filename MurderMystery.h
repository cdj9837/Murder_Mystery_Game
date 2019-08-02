#ifndef MURDERMYSTERY_H
#define MURDERMYSTERY_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <gtkmm.h>

using namespace std;

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

class CaseStory
{
 protected:
    string howToPlay;
    string backStory;
    vector<Person> characters;
 public:
    string getHowToPlay();
    string getBackStory();
    void setCharacters();
    Person getCharacter(int characterNum);
};


class Case : public CaseStory
{
    vector<string> clues;
    bool solved;
    vector<string> weaponList;
 public:
    void setClue(string clue);
    void setWeapon(string weapon);
    void setSolved(bool solved);
    string getClue(int clueNum);
    string getWeapon(int weaponNum);
    Case main_menu_case(Case g);
};

class Menu
{
    int choice;
public:
    int getChoice();
    string guess_suspect, guess_weapon;
    Menu();
    CaseStory cs;
    Case c1;

    void gamePlay();

    friend class SuspectWindow;
    friend class ExampleWindow;

    friend class Background_Window;
    friend class Exit_Correct;
    friend class Exit_Incorrect;

};

class welcome_window : public Gtk::Window
{
public:
    welcome_window();
    virtual      ~welcome_window();

protected:
    Gtk::Window w;
    Gtk::Button play1, exit1;
    Gtk::HBox hbox, hbox2;
    Gtk::VBox vbox;
    Gtk::Box box;
    Gtk::Grid  grid;
    Gtk::Box main_box;
    Gtk::Image image,image2,image3;
    void PlaySignal();
    void ExitSignal();

};

class Rules : public Gtk::Window
{
public:
  Rules(Menu m);
  virtual ~Rules();

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

class SuspectWindow : public Gtk::Window
{
protected:

    Gtk::Box box, hello2;
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
    SuspectWindow(Menu m);
    virtual ~SuspectWindow();
};

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

class CluesWindow : public Gtk::Window
{
    public:
      CluesWindow(Menu m);
      virtual ~CluesWindow();

    protected:
      void cluesContinue();

      Gtk::Box box;

      Gtk::Button continueButton;
      Gtk::Label label, label2, label3, label4, label5;
};

class Exit_Correct: public Gtk::Window
{
    public:
      Exit_Correct(Menu m);
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
      Exit_Incorrect(Menu m);
      virtual ~Exit_Incorrect();

    protected:
      void home_page();

      Gtk::Box unsolved_box;
      Gtk::Image unsolved_image;
      Gtk::Button home_button;
      Gtk::Label unsolved_label;
      Gtk::Label label;
};

class Loop : public Gtk::Window
{
public:
    Loop(Gtk::Main app);
    virtual ~Loop();
};


#endif // MURDERMYSTERY_H_INCLUDED
