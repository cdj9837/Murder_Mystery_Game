#ifndef MURDERMYSTERY_H
#define MURDERMYSTERY_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

//testing repository

class Menu
{
protected:
    int choice;
public:
    int getChoice();
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
    void setSolved(bool solved);
    string getClue(int clueNum);
};

class Game
{
    vector<Case> start;
public:
    void setCase(Case c);
    Case getCase(int caseNum);
};

#endif // MURDERMYSTERY_H_INCLUDED
