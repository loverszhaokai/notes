#
# Makefile 
# author: zhaokai
# date: 2013-11-28
#

TESTS = main

all : $(TESTS)

clean :
	rm -f $(TESTS)
	rm -f main.o PersonUser.o Person.o PersonImpl.o

main.o: main.cc Person.h
	g++ --std=c++11 -c main.cc

PersonUser.o : PersonUser.cc Person.h
	g++ --std=c++11 -c PersonUser.cc

Person.o: Person.cc Person.h PersonImpl.h
	g++ --std=c++11 -c Person.cc

PersonImpl.o: PersonImpl.cc PersonImpl.h 
	g++ --std=c++11 -c PersonImpl.cc

$(TESTS): main.o PersonUser.o Person.o PersonImpl.o
	g++ -o main main.o PersonUser.o Person.o PersonImpl.o

