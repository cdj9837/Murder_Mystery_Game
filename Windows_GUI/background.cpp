#include <gtkmm.h>
#include <string>
#include <iostream>
#include "MurderMystery.h"
#include "b_header.h"

//Below is the GUI for the Background GUI, Solved Exit GUI, and Not Solved GUI

//First: Background GUI

Background_Window::Background_Window(): box(Gtk::ORIENTATION_VERTICAL)
{
    set_size_request(100,100);
    this->set_border_width(60);
    set_title("Background Information");

    add(box);

    //we can uncomment these when we add it to the main file so it can call the functions normally
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





//Second: Solved Exit GUI

Exit_Correct::Exit_Correct(): solved_box(Gtk::ORIENTATION_VERTICAL)
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





//Third: Unsolved Exit GUI

Exit_Incorrect::Exit_Incorrect(): unsolved_box(Gtk::ORIENTATION_VERTICAL)
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

}

void Exit_Incorrect::home_page()
{
    //call to signal_clicked to welcome menu
}
