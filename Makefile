OS = Windows
BIN = test

SRC_PRIMARY = main.cpp
SRC_SECONDARY = cross.cpp figure.cpp

STD = -std=c++14 -Os -s

LIBS = -lsfml-system -lsfml-window -lsfml-graphics -lsfml-audio
SFML_INCLUDE_PATH = D:\Programming\SFML-2.5.1\include
SFML_LIBS_PATH = D:\Programming\SFML-2.5.1\lib

LINKER_FLAGS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -static-libgcc -static-libstdc++

all:
ifeq ($(OS), Linux)
	g++ $(STD) $(LIBS) $(SRC_PRIMARY) $(SRC_SECONDARY) -o $(BIN)
else
	g++ $(STD) -I$(SFML_INCLUDE_PATH) -L$(SFML_LIBS_PATH) $(SRC_PRIMARY) $(SRC_SECONDARY) $(LINKER_FLAGS) -o $(BIN)
	strip test.exe
endif