#ifndef MURDERMYSTERY_H
#define MURDERMYSTERY_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class Menu
{
    int choice;
public:
    int getChoice();
    string guess_suspect, guess_weapon;
    Menu();

    void gamePlay();
};

class Person
{
    string name;
    string alibi;
    bool murderer;
 public:
    Person(string name, string description);
    Person(string name);
    void setMurderer(bool guilty);
    void setAlibi(string a);
    bool getMurderer();
    string getName();
    string getAlibi();
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

#endif // MURDERMYSTERY_H_INCLUDED
