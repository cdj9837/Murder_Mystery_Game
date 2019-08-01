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
    void getHowToPlay();
    void getBackStory();
<<<<<<< HEAD
=======
    void setCharacters();
>>>>>>> master
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
};

class SuspectWindow : public Gtk::Window
{
protected:

    Gtk::Box box, hello, hello2, center;
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


#endif // MURDERMYSTERY_H_INCLUDED
