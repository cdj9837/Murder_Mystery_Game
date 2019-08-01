#include "Suspect.h"
#include <gtkmm.h>
#include <iostream>

using namespace std;

SuspectWindow::SuspectWindow() : box(Gtk::ORIENTATION_VERTICAL), hello(Gtk::ORIENTATION_VERTICAL)
{
    //set_size_request(300,200);
    set_border_width(10);
    add(box);

    suspect.set("Suspect.png");
    hello.pack_start(suspect);
    box.pack_start(hello);

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

    /*characters.push_back(Dan);
    characters.push_back(Johnny);
    characters.push_back(Joey);
    characters.push_back(Frank);
    characters.push_back(Bridgette);*/

    s1.add_label(Bridgette.getName());
    sGrid.attach(s1,0,0,1,5);
    s1.signal_clicked().connect(sigc::mem_fun(*this, &SuspectWindow::onButtonClickedNotMurder));

    s2.add_label("Dan Gillick");
    sGrid.attach(s2,1,0,1,5);
    s2.signal_clicked().connect(sigc::mem_fun(*this, &SuspectWindow::onButtonClickedNotMurder));

    s3.add_label("Johnny Tightlips");
    sGrid.attach(s3,2,0,1,5);
    s3.signal_clicked().connect(sigc::mem_fun(*this, &SuspectWindow::onButtonClickedNotMurder));

    s4.add_label("Frankie Squealer");
    sGrid.attach(s4,3,0,1,5);
    s4.signal_clicked().connect(sigc::mem_fun(*this, &SuspectWindow::onButtonClickedMurder));

    s5.add_label("Joey Calabrese");
    sGrid.attach(s5,4,0,1,5);
    s5.signal_clicked().connect(sigc::mem_fun(*this, &SuspectWindow::onButtonClickedNotMurder));

    box.pack_start(sGrid);
    show_all_children();

};

SuspectWindow::~SuspectWindow(){}

void SuspectWindow::onButtonClickedMurder()
{
    //Gtk::MessageDialog dialog(*this, "MURDERER!", false, Gtk::MESSAGE_INFO);
    //dialog.run();

    //weapons.set("Suspect.png");
    //hello2.pack_start(weapons);
    box.pack_start(hello2);

    w1.add_label("Drill");
    wGrid.attach(w1,0,0,1,5);
    w1.signal_clicked().connect(sigc::mem_fun(*this, &SuspectWindow::onButtonClickedWeapon));

    w2.add_label("Knife");
    wGrid.attach(w2,1,0,1,5);
    w2.signal_clicked().connect(sigc::mem_fun(*this, &SuspectWindow::onButtonClickedMurderNotWeapon));

    w3.add_label("Plastic Bag");
    wGrid.attach(w3,2,0,1,5);
    w3.signal_clicked().connect(sigc::mem_fun(*this, &SuspectWindow::onButtonClickedMurderNotWeapon));

    w4.add_label("Gun");
    wGrid.attach(w4,3,0,1,5);
    w4.signal_clicked().connect(sigc::mem_fun(*this, &SuspectWindow::onButtonClickedMurderNotWeapon));

    w5.add_label("Katana");
    wGrid.attach(w5,4,0,1,5);
    w5.signal_clicked().connect(sigc::mem_fun(*this, &SuspectWindow::onButtonClickedMurderNotWeapon));

    box.pack_start(wGrid);
    show_all_children();


}

void SuspectWindow::onButtonClickedNotMurder()
{
    //weapons.set("Suspect.png");
    //hello2.pack_start(weapons);
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

//PERSON

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
