#Name: Bridget Krone  Student ID: 1000698646
CXXFLAGS += -std=c++14
GTKFLAGS = `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

ex: main_test.o background.o
			$(CXX) $(CXXFLAGS) -o exfile main_test.o background.o $(GTKFLAGS)

main_test.o: main_test.cpp b_header.h
			$(CXX) $(CXXFLAGS) -c main_test.cpp $(GTKFLAGS)

background.o: b_header.h background.cpp
			$(CXX) $(CXXFLAGS) -c background.cpp $(GTKFLAGS)
