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
    string guess_suspect, guess_weapon;
 public:
    Menu();
};

class Person
{
    string name;
    string alibi;
    bool murderer;
 public:
    Person(string name, string description);
    void setMurderer(bool guilty);
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
    string getHowToPlay();
    string getBackStory();
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
    void printClue(/*int clueNum*/ );
    void printWeapon();
    string getClue(int clueNum);
    string getWeapon(int weaponNum);
};

#endif // MURDERMYSTERY_H_INCLUDED
