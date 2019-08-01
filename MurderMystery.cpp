#include "MurderMystery.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

Menu::Menu() //Welcome window in this function
{
    cout<<"Welcome Detective!  Enter 1 to exit or 2 to solve murder: "<<flush;
    cin>>choice;

    if(choice==1)
    {
        cout<<"Goodbye!"<<endl;
        exit(1);
    }

    else
    {
        gamePlay();
    }
}

void Menu :: gamePlay() //Rules window in this function
{
    cs.setCharacters();
    int life=0, suspectNum, weaponNum;
    bool solved;

    cs.getHowToPlay();
    //Rules window here

    cs.getBackStory();
    //Backstory();

    c1=c1.main_menu_case(c1);
}

Case Case::main_menu_case(Case g)
{
	//Case g;
	string weapon1 = "Dagger";
	string weapon2 = "Lead Pipe";
	string weapon3 = "Rope";
	string weapon4 = "Candle Stick";
	string weapon5 = "Wrench";

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

void CaseStory :: getHowToPlay()
{
    ifstream instructions("instructions.txt");
    string line;

    cout<<"\n\n"<<endl;

    if(!instructions.is_open())
    {
        cout<<"Can't open file"<<endl;
        exit(1);
    }
}

void CaseStory :: getBackStory()
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
    Person Bridgette("Bridgette Gotti");
    Person Dan("Dan Gillick");
	Person Johnny("Johnny Tightlips");
	Person Frank("Frankie Squealer");
	Person Joey("Joey Calabrese");

	Dan.setMurderer(false);
	Johnny.setMurderer(false);
	Joey.setMurderer(false);
	Frank.setMurderer(true);
	Bridgette.setMurderer(false);

	characters.push_back(Bridgette);
    characters.push_back(Dan);
    characters.push_back(Johnny);
    characters.push_back(Frank);
    characters.push_back(Joey);
}

Person CaseStory :: getCharacter(int characterNum)
{
    return characters[characterNum-1];
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

SuspectWindow::SuspectWindow(Menu m) : box(Gtk::ORIENTATION_VERTICAL), hello(Gtk::ORIENTATION_VERTICAL)
{
    //resize(1000,1000);
    set_border_width(10);
    add(box);

    suspect.set("Suspect.png");
    box.pack_start(suspect);
    //box.pack_start(hello);

    s1.add_label(m.cs.getCharacter(1).getName());
    s1.set_size_request(80,32);
    sGrid.attach(s1,0,0,1,5);
    s1.signal_clicked().connect(sigc::mem_fun(*this, &SuspectWindow::onButtonClickedNotMurder));

    s2.add_label(m.cs.getCharacter(2).getName());
    s2.set_size_request(80,32);
    sGrid.attach(s2,1,0,1,5);
    s2.signal_clicked().connect(sigc::mem_fun(*this, &SuspectWindow::onButtonClickedNotMurder));

    s3.add_label(m.cs.getCharacter(3).getName());
    s3.set_size_request(80,32);
    sGrid.attach(s3,2,0,1,5);
    s3.signal_clicked().connect(sigc::mem_fun(*this, &SuspectWindow::onButtonClickedNotMurder));

    s4.add_label(m.cs.getCharacter(4).getName());
    s4.set_size_request(80,32);
    sGrid.attach(s4,3,0,1,5);
    s4.signal_clicked().connect(sigc::mem_fun(*this, &SuspectWindow::onButtonClickedMurder));

    s5.add_label(m.cs.getCharacter(5).getName());
    s5.set_size_request(80,32);
    sGrid.attach(s5,4,0,1,5);
    s5.signal_clicked().connect(sigc::mem_fun(*this, &SuspectWindow::onButtonClickedNotMurder));

    //nter.set_halign(ALIGN_CENTER);
    box.pack_start(sGrid);
    show_all_children();

};

SuspectWindow::~SuspectWindow(){}

void SuspectWindow::onButtonClickedMurder()
{
    weapons.set("Weapon.jpg");
    hello2.pack_start(weapons);
    box.pack_start(hello2);

    w1.add_label("Dagger");
    wGrid.attach(w1,0,0,1,5);
    w1.signal_clicked().connect(sigc::mem_fun(*this, &SuspectWindow::onButtonClickedWeapon));

    w2.add_label("Lead Pipe");
    wGrid.attach(w2,1,0,1,5);
    w2.signal_clicked().connect(sigc::mem_fun(*this, &SuspectWindow::onButtonClickedMurderNotWeapon));

    w3.add_label("Rope");
    wGrid.attach(w3,2,0,1,5);
    w3.signal_clicked().connect(sigc::mem_fun(*this, &SuspectWindow::onButtonClickedMurderNotWeapon));

    w4.add_label("Candle Stick");
    wGrid.attach(w4,3,0,1,5);
    w4.signal_clicked().connect(sigc::mem_fun(*this, &SuspectWindow::onButtonClickedMurderNotWeapon));

    w5.add_label("Wrench");
    wGrid.attach(w5,4,0,1,5);
    w5.signal_clicked().connect(sigc::mem_fun(*this, &SuspectWindow::onButtonClickedMurderNotWeapon));

    box.pack_start(wGrid);
    show_all_children();
}

void SuspectWindow::onButtonClickedNotMurder()
{
    weapons.set("Weapon.jpg");
    hello2.pack_start(weapons);
    box.pack_start(hello2);

    w1.add_label("Drill");
    wGrid.attach(w1,0,0,1,5);
    w1.signal_clicked().connect(sigc::mem_fun(*this, &SuspectWindow::onButtonClickedNotMurderWeapon));

    w2.add_label("Knife");
    wGrid.attach(w2,1,0,1,5);
    w2.signal_clicked().connect(sigc::mem_fun(*this, &SuspectWindow::onButtonClickedNotWeapon));

    w3.add_label("Plastic Bag");
    wGrid.attach(w3,2,0,1,5);
    w3.signal_clicked().connect(sigc::mem_fun(*this, &SuspectWindow::onButtonClickedNotWeapon));

    w4.add_label("Gun");
    wGrid.attach(w4,3,0,1,5);
    w4.signal_clicked().connect(sigc::mem_fun(*this, &SuspectWindow::onButtonClickedNotWeapon));

    w5.add_label("Katana");
    wGrid.attach(w5,4,0,1,5);
    w5.signal_clicked().connect(sigc::mem_fun(*this, &SuspectWindow::onButtonClickedNotWeapon));

    box.pack_start(wGrid);
    show_all_children();

}

void SuspectWindow::onButtonClickedWeapon()
{
    Gtk::MessageDialog dialog(*this, "SOLVED!", false, Gtk::MESSAGE_INFO);
    dialog.run();

    solved=true;

    close();
}
void SuspectWindow::onButtonClickedNotWeapon()
{
    Gtk::MessageDialog dialog(*this, "NOT SOLVED!", false, Gtk::MESSAGE_INFO);
    dialog.run();

    close();
}

void SuspectWindow::onButtonClickedMurderNotWeapon()
{
    Gtk::MessageDialog dialog(*this, "NOT SOLVED!", false, Gtk::MESSAGE_INFO);
    dialog.set_secondary_text("Right Murderer, Wrong Weapon");
    dialog.run();

    close();
}
void SuspectWindow::onButtonClickedNotMurderWeapon()
{
    Gtk::MessageDialog dialog(*this, "NOT SOLVED!", false, Gtk::MESSAGE_INFO);
    dialog.set_secondary_text("Wrong Murderer, Right Weapon");
    dialog.run();

    close();
}

<<<<<<< HEAD
//welcome window functions
welcome_window::welcome_window()
{
    //set images
    image.set("image.jpg");
    image2.set("play1.png");
    image3.set("cancel.png");

    resize(900,700);     //size of window
    set_border_width(10); //window border
    set_position(Gtk::WIN_POS_CENTER); //WINDOW POSITION IN THE CENTER OF SCREEN


    set_title("Murder Mystery"); //window title

    //play button
    play1.set_size_request(80, 32);
    play1.set_image(image2);
    play1.signal_clicked().connect(sigc::mem_fun(*this,&welcome_window::PlaySignal));


    //exit button
    exit1.set_size_request(80,32);
    exit1.set_image(image3);
    exit1.signal_clicked().connect(sigc::mem_fun(*this,&welcome_window::ExitSignal));

    hbox.pack_start(play1,1,0);
    hbox2.pack_start(exit1,1,0);

    vbox.pack_start(image);
    vbox.pack_start(grid);
    vbox.pack_start(hbox);
    vbox.pack_start(hbox2);
    box.pack_start(vbox);

    add(box);

    show_all_children();
}
welcome_window::~welcome_window(){}
void welcome_window::PlaySignal()
{

    play1.remove();
    //exit1.remove();
    vbox.remove(hbox2);


    add(main_box);
    resize(100,600);
    set_border_width(10);
    set_position(Gtk::WIN_POS_CENTER); //WINDOW POSITION IN THE CENTER OF SCREEN


    Gtk::HBox box;

    image.set("clue.png");

    play1.add_label("Continue");



    box.pack_start(image);
    box.pack_start(play1);

    main_box.pack_start(box);

    grid.show_all();

}
void welcome_window::ExitSignal()
{
    exit(0);
}
=======
Background_Window::Background_Window(Menu m): box(Gtk::ORIENTATION_VERTICAL)
{
    set_size_request(100,100);
    this->set_border_width(60);
    set_title("Background Information");

    add(box);

    //CaseStory cs();
    //cs.getBackStory();

    label.set_text("\nScene Incident Report: You, as a Crime Investigator, arrived at the crime scene (1400 hours) on 123 Bourbon Street. At 1200 hours...(continue printing out the rest)\n");
    box.pack_start(label);

    back_image.set("location.png");
    box.pack_start(back_image);

    label1.set_text("\n");
    box.pack_start(label1);

    continue_button.add_label("Continue");
    continue_button.signal_clicked().connect(sigc::mem_fun(*this,&Background_Window::background_continue));
    box.pack_start(continue_button);

    show_all_children();
}

Background_Window::~Background_Window()
{

}

void Background_Window::background_continue()
{
    //call to signal_clicked to start Suspects / Weapons window
}


Exit_Correct::Exit_Correct(Menu m): solved_box(Gtk::ORIENTATION_VERTICAL)
{
    set_size_request(100,100);
    this->set_border_width(60);
    set_title("Exit Page");

    add(solved_box);

    solved_label.set_text("\nCongratulations! You caught the murderer!\n");
    solved_box.pack_start(solved_label);

    solved_image.set("solved.jpg");
    solved_box.pack_start(solved_image);

    label.set_text("\n");
    solved_box.pack_start(label);

    home_button.add_label("Continue to Home Menu");
    home_button.signal_clicked().connect(sigc::mem_fun(*this,&Exit_Correct::home_page));
    solved_box.pack_start(home_button);

    show_all_children();
}

Exit_Correct::~Exit_Correct()
{

}

void Exit_Correct::home_page()
{
    //call to signal_clicked to welcome menu
}


Exit_Incorrect::Exit_Incorrect(Menu m): unsolved_box(Gtk::ORIENTATION_VERTICAL)
{
    set_size_request(100,100);
    this->set_border_width(60);
    set_title("Exit Page");

    add(unsolved_box);

    unsolved_label.set_text("\nSorry! You didn't choose the correct murderer and weapon. This case remains unsolved.\n");
    unsolved_box.pack_start(unsolved_label);

    unsolved_image.set("unsolved.jpg");
    unsolved_box.pack_start(unsolved_image);

    label.set_text("\n");
    unsolved_box.pack_start(label);

    home_button.add_label("Continue to Home Menu");
    home_button.signal_clicked().connect(sigc::mem_fun(*this,&Exit_Incorrect::home_page));
    unsolved_box.pack_start(home_button);

    show_all_children();
}

Exit_Incorrect::~Exit_Incorrect()
{
>>>>>>> master

}

void Exit_Incorrect::home_page()
{
    //call to signal_clicked to welcome menu
}
