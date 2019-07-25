#include "MurderMystery.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

Menu::Menu()
{
  CaseStory::CaseStory cs;
  Case::Case c1;
    
    cout<<"Welcome Detective!  Enter 1 to exit or 2 to solve murder: "<<flush;
    cin>>m1.choice;

  if(m1.choice==1)
  {
       cout<<"Goodbye!"<<endl;
       exit(1);
  }

  else
  {
       cout<<"How to Play:"<<endl;
       //call to CaseStory for getHowToPlay
       // cs.getHowToPlay();


       //call to CaseStory for getBackStory
       // cs.getBackStory();

       string clue_first = c1.clues[0];
       string clue_sec = c1.clues[1];       

       
  }
}


void Case :: setClue(string clue)
{
    clues.push_back(clue);
}
void Case :: setWeapon(string weapon)
{
    weaponList.push_back(weapon);
}

void Case :: setSolved(bool solved)
{
    this->solved = solved;
}
string Case :: getClue(int clueNum)
{
    return clues[clueNum-1];
}

string Case :: getWeapon(int weaponNum)
{
    return weaponList[weaponNum-1];
}

void Case :: printClue(/*int clueNum*/      )
{
	cout<<"1. "<<clues[0]<<endl;
	cout<<"2. "<<clues[1]<<endl;
	cout<<"3. "<<clues[2]<<endl;
	cout<<"4. "<<clues[3]<<endl;
	cout<<"5. "<<clues[4]<<endl;
}

void Case :: printWeapon()
{
	cout<<"1. "<<weaponList[0]<<endl;
	cout<<"2. "<<weaponList[1]<<endl;
	cout<<"3. "<<weaponList[2]<<endl;
	cout<<"4. "<<weaponList[3]<<endl;
	cout<<"5. "<<weaponList[4]<<endl;
}


string CaseStory :: getHowToPlay() //we should have this as a void return type and just have it print how to play when this function is called (BK)
{
    return howToPlay;
}
string CaseStory :: getBackStory() //we should also have this a void return type and just have it print the back stories (BK)
{
    return backStory;
}
Person CaseStory :: getCharacter(int characterNum)
{
    return characters[characterNum];
}


    //Not sure on constructors
Person::Person(string name, string description)
{
    this->name = name;
    alibi = description;
}
void Person :: setMurderer(bool guilty)
{
    murderer = guilty;
}
bool Person :: getMurderer()
{
    return murderer;
}
string Person :: getName()
{
    return name;
}
string Person :: getAlibi()
{
    return alibi;
}
