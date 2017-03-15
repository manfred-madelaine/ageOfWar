CC = g++
CXXFLAGS = -std=c++11 -Wall
EXEC_NAME = aow
#SRC= $(wildcard *.cpp)
SRC = Base.cpp Archer.cpp Affichage.cpp Catapulte.cpp Console.cpp Fantassin.cpp Ia.cpp Player.cpp Joueur.cpp Unite.cpp Partie.cpp stdafx.cpp Terrain.cpp 
CLASSES = $(SRC:.cpp=)
SRC += main.cpp
OBJ_FILES = $(SRC:.cpp=.o)

all : $(EXEC_NAME)

clean :
	rm $(OBJ_FILES)

mrproper : clean
	rm $(EXEC_NAME)

$(EXEC_NAME) : $(OBJ_FILES)
	$(CC) -o $(EXEC_NAME) $(OBJ_FILES)

%.o : %.cpp %.hpp
	$(CC) $(CXXFLAGS) -o $@ -c $<
