# makefile for Time class with three files:
# Time.h, Time.cpp, Driver.cpp
# Try "-std=gnu++0x" or "-std=c++11"

a.out: PasswordDriver.o PasswordManager.o
	g++ PasswordDriver.o PasswordManager.o

Driver.o: Driver.cpp PasswordManager.h
	g++ -c -std=gnu++0x PasswordDriver.cpp

Time.o: PasswordManager.cpp PasswordManager.h
	g++ -c -std=gnu++0x Time.cpp



