#include "MurderMystery.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

Menu::Menu()
{
  CaseStory cs;
  Case c1;

    cout<<"Welcome Detective!  Enter 1 to exit or 2 to solve murder: "<<flush;
    cin>>choice;

  if(choice==1)
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

       //string clue_first = c1.clues[0];
       //string clue_sec = c1.clues[1];

        c1.main_menu_case();
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

Person::Person(string name)
{
    this->name=name;
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

void Case::main_menu_case()
{
	Case g;
	string weapon1 = "Drill";
	string weapon2 = "knife";
	string weapon3 = "Plastic Bag";
	string weapon4 = "Gun";
	string weapon5 = "Katana";

	g.setWeapon(weapon1);
	g.setWeapon(weapon2);
	g.setWeapon(weapon3);
	g.setWeapon(weapon4);
	g.setWeapon(weapon5);

	string clue1 = "Dan Gillick is very thin, and physically weak, his hands are not rough...";
	string clue2 = "Johnny Tightlips is physically build, his hands are pretty rough as a farmer...";
	string clue3 = "small traces of blood found on Joey Calabrese shirt cuffs...";
	string clue4 = "various drill bits found in Frankie Squealer toolbox, when checking his car";
	string clue5 = "small traces of black carbon found on Bridgette Gotti hands";

	g.setClue(clue1);
	g.setClue(clue2);
	g.setClue(clue3);
	g.setClue(clue4);
	g.setClue(clue5);

	Person Dan("Dan Gillick");
	Person Johnny("Johnny Tightlips");
	Person Joey("Joey Calabrese");
	Person Frank("Frankie Squealer");
	Person Bridgette("Bridgette Gotti");

	Frank.setMurderer(true);

	int clueNum;
	int weaponNum;

	cout<<"Here are the following clues that are obtained at the scene..."<<endl<<endl;
	g.printClue();
	cout<<endl;
	cout<<"Here are the following weapons that are found at the scene..."<<endl;
	g.printWeapon();

	cout<<"\nwhich clue do you think is best link to the scene of the crime?"<<endl;
	cin>>clueNum;

	cout<<"\nWhich weapon do you think is best link to the scene of the crime?"<<endl;
	cin>>weaponNum;

	string selected_clue = g.getClue(clueNum);

	string selected_weapon = g.getWeapon(weaponNum);

	if(selected_clue.compare("various drill bits found in Frankie Squealer toolbox, when checking his car") == 0 && selected_weapon.compare("Drill") == 0)
	{
		cout<<"YOU SOLVED THE CASE!!"<<"Frankie Squealer is the killer!!"<<"CASE CLOSED"<<endl;
		//use vector container, characters to fill in name...

		bool solved = true;
		g.setSolved(solved);
	}

	else
	{
		cout<<"NOPE, those are not the right clue and weapon!! Killer is still at large.. CASE still open"<<endl;
		bool solved = false;
		g.setSolved(solved);
	}
}

