.PHONY: all, clean

CPP = g++
CC = gcc 
INC = inc/
SRC = src/
INC1 = C:/wxWidgets-3.0.5/include/msvc/wx/
INC2 = "C:/wxWidgets-3.0.5/lib/gcc_lib/"
CPPFLAGS = -g -Wall -c

all: main.exe
main.exe: modbus-rtu.o modbus-data.o modbus.o dialog.o mainframe.o main.o
	$(CPP) modbus-rtu.o modbus-data.o modbus.o dialog.o mainframe.o main.o -o main `wx-config --libs` -I$(INC) -I$(SRC) 
main.o: main.cpp 
	$(CPP)  main.cpp `wx-config --cxxflags` -I$(INC) -I$(SRC) $(CPPFLAGS)  
mainframe.o: $(SRC)mainframe.cpp
	$(CPP) $(SRC)mainframe.cpp `wx-config --cxxflags` -I$(INC) -I$(SRC) $(CPPFLAGS)
dialog.o: $(SRC)dialog.cpp
	$(CPP) $(SRC)dialog.cpp `wx-config --cxxflags` -I$(INC) -I$(SRC) $(CPPFLAGS)
modbus.o: $(SRC)/modbus.c
	$(CC) $(SRC)/modbus.c -c -I$(INC) -g -Wall
modbus-data.o: $(SRC)/modbus-data.c
	$(CC) $(SRC)/modbus-data.c -c -I$(INC) -g -Wall
modbus-rtu.o: $(SRC)/modbus-rtu.c
	$(CC) $(SRC)/modbus-rtu.c -c -I$(INC) -g -Wall
clean:
	rm -rf *.exe *.o *.map *.lst