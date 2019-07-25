#include "MurderMystery.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

Menu::Menu()
{
    cout<<"Welcome Detective!  Enter 1 to exit or 2 to solve murder: "<<flush;
    cin>>choice;

    if(choice==1)
    {
        cout<<"Goodbye!"<<endl;
        exit(1);
    }

    else
        gamePlay();
}

void Menu :: gamePlay()
{
    CaseStory cs;
    cs.setCharacters();
    Case c1;
    int life=0, suspectNum, weaponNum;
    bool solved;
    //call to CaseStory for getHowToPlay
    cs.getHowToPlay();

    //call to CaseStory for getBackStory
    cs.getBackStory();

    c1=c1.main_menu_case(c1);

    string clue_first = c1.getClue(0);
    string clue_sec = c1.getClue(1);

    //cout<<clue_first<<endl;

    while(life<3 && !solved)
    {
        cout<<c1.getClue(0)<<endl;
        cout<<c1.getClue(1)<<endl;
        cout<<c1.getClue(2)<<endl;
        cout<<c1.getClue(3)<<endl;
        cout<<c1.getClue(4)<<endl;

        cout<<"\nCharacter list:"<<endl;
        for(int i = 0 ; i<5;i++)
            cout<<i+1<<". "<<cs.getCharacter(i).getName()<<endl;

        cout<<"\n\n"<<endl;
        cout<<"Here are the following weapons that are found at the scene..."<<endl;
        cout<<"1. "<<c1.getWeapon(0)<<endl;
        cout<<"2. "<<c1.getWeapon(1)<<endl;
        cout<<"3. "<<c1.getWeapon(2)<<endl;
        cout<<"4. "<<c1.getWeapon(3)<<endl;
        cout<<"5. "<<c1.getWeapon(4)<<endl;

        cout<<"\nwhich suspect do you think is best link to the scene of the crime?"<<endl;
        cin>>suspectNum;
        suspectNum=suspectNum-1;

        cout<<"\nWhich weapon do you think is best link to the scene of the crime?"<<endl;
        cin>>weaponNum;

        string selected_weapon = c1.getWeapon(weaponNum);
        Person p = cs.getCharacter(suspectNum);
        bool yes = p.getMurderer();

        if(yes && weaponNum==1)
        {
            cout<<"\nYay you Solved it!!!\n"<<endl;
            solved=true;
        }

        else if(yes && selected_weapon!="Drill")
        {
            cout<<"\nCorrect person wrong weapon\n"<<endl;
            life++;
        }

        else if(!yes && selected_weapon=="Drill")
        {
            cout<<"\nCorrect weapon wrong person\n"<<endl;
            life++;
        }

        else
        {
            cout<<"\nKiller still at LARGE!\n"<<endl;
            life++;
        }
    }
}

Case Case::main_menu_case(Case g)
{
	//Case g;
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

	return g;
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
    return clues[clueNum];
}

string Case :: getWeapon(int weaponNum)
{
    return weaponList[weaponNum];
}

void CaseStory :: getHowToPlay() //we should have this as a void return type and just have it print how to play when this function is called (BK)
{
    ifstream instructions("instructions.txt");
    string line;

    cout<<"\n\n"<<endl;

    if(!instructions.is_open())
    {
        cout<<"Can't open file"<<endl;
        exit(1);
    }

    while(!instructions.eof())
    {
        getline(instructions, line);
        cout<<line<<endl;
    }
    cout<<"\n\n"<<endl;

}
void CaseStory :: getBackStory() //we should also have this a void return type and just have it print the back stories (BK)
{
    //print casestory
    ifstream File("backstory.txt");
    string line;

    if(!File.is_open())
    {
        cout<<"Could not open file"<<endl;
        exit(1);
    }

    while(!File.eof())
    {
        getline(File, line);
        cout<<line<<endl;
    }
}

void CaseStory :: setCharacters()
{
    Person Dan("Dan Gillick");
	Person Johnny("Johnny Tightlips");
	Person Joey("Joey Calabrese");
	Person Frank("Frankie Squealer");
	Person Bridgette("Bridgette Gotti");

	Dan.setMurderer(false);
	Johnny.setMurderer(false);
	Joey.setMurderer(false);
	Frank.setMurderer(true);
	Bridgette.setMurderer(false);

    characters.push_back(Dan);
    characters.push_back(Johnny);
    characters.push_back(Joey);
    characters.push_back(Frank);
    characters.push_back(Bridgette);
}

Person CaseStory :: getCharacter(int characterNum)
{
    return characters[characterNum];
}

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

void Person :: setAlibi(string a)
{
    alibi = a;
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
