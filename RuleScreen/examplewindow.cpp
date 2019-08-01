#include "examplewindow.h"
#include <iostream>

ExampleWindow::ExampleWindow()
: m_HBox(Gtk::ORIENTATION_VERTICAL, 5), m_VBox2(Gtk::ORIENTATION_VERTICAL, 5), m_Frame_LineWrapped("***GAME RULES***")
, button_send("Continue")
{
  set_size_request(700, 200);	
  set_title("Mystery Murder Game");
  set_border_width(5);

  add(m_HBox);

  m_HBox.pack_start(m_VBox2, Gtk::PACK_SHRINK);

  m_Label_LineWrapped.set_text(

	"1. YOU HAVE TO FIND THE KILLER WITHIN THREE TURNS OTHERWISE THE KILLER" 
	"\nWILL FIND YOU!\n\n"

	"2. CHOOSE A CASE TO WORK ON, LOOK FOR CLUES AT THE SCENE...\n\n"

	"3. READ THE BACKGROUND STORY AND DESCRIPTION/ALIBI OF THE SUSPECT(S)"
	"\nFOUND AT THE CRIME SCENE.\n\n"

	"4. FROM YOUR INVESTIGATION, CHOOSE THE WEAPON THAT WAS USED AT" 
	"\nSCENE AND ENTER THE NAME OF THE SUSPECTED KILLER.\n\n"

	"5. IF YOUR SUSPECT WAS DETERMINED THAT HE/SHE IS NOT THE KILLER, THEN" 
	"\nMOVE ONTO THE NEXT CASE. BUT BEWARE YOU MUST FIND THE KILLER WITHIN 3 TURNS...\n\n"

	"6. IF YOU FOUND THE KILLER, GREAT!! JUSTICE HAVE BEEN SERVED!!"

	"\nGOOD LUCK, MCGRUFF IS COUNTING ON YOU TO SOLVE!!");
  m_Label_LineWrapped.set_line_wrap();
  m_Frame_LineWrapped.add(m_Label_LineWrapped);
  m_VBox2.pack_start(m_Frame_LineWrapped, Gtk::PACK_SHRINK);
  
  button_send.signal_clicked().connect(sigc::mem_fun(*this,		
	&ExampleWindow::send_value));		
	m_HBox.pack_start(button_send);

  show_all_children();
}

ExampleWindow::~ExampleWindow()
{
}

void	ExampleWindow::send_value()	
{			
	std::string	input=entry.get_text();
	Gtk::MessageDialog dialog (*this, "VOID NO NEW WINDOW ",false,Gtk::MESSAGE_ERROR);
	dialog.set_secondary_text("NEED TO LINK NEW WINDOW");
	dialog.run();
	
}	



