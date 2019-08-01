CXXFLAGS += -std=c++17
GTKFLAGS = `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

ex: Suspect_main.o Suspect.o
	$(CXX) $(CXXFLAGS) -o murder Suspect_main.o Suspect.o $(GTKFLAGS)
Suspect_main.o: Suspect_main.cpp Suspect.h
	$(CXX) $(CXXFLAGS) -c Suspect_main.cpp $(GTKFLAGS)
Suspect.o: Suspect.cpp Suspect.h
	$(CXX) $(CXXFLAGS) -c Suspect.cpp $(GTKFLAGS)
