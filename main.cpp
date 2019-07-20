#include "MurderMystery.h"

void main_menu_case()
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
	string clue5 = "small traces of black carbon found on bridgette gotti hands";
	
	g.setClue(clue1);
	g.setClue(clue2);
	g.setClue(clue3);
	g.setClue(clue4);
	g.setClue(clue5);
	
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


int main ()
{
	main_menu_case();
}

