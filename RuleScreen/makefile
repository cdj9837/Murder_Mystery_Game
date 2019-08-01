CXXFLAGS += -std=c++17
GTKFLAGS = `pkg-config gtkmm-3.0 --cflags --libs`

ex: main.o examplewindow.o
	$(CXX) $(CXXFLAGS) -o ksg main.o examplewindow.o $(GTKFLAGS)
	
main.o: main.cpp examplewindow.h
	$(CXX) $(CXXFLAGS) -c main.cpp $(GTKFLAGS)
	
examplewindow.o: examplewindow.h examplewindow.cpp
	$(CXX) $(CXXFLAGS) -c examplewindow.cpp $(GTKFLAGS)
	
cleanup:
	echo "Cleaning up object files and executable!"
	rm *.o
	rm ksg