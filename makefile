CC = gcc
CXX = g++
CFLAG = -g -std=c++11
LIBS  = -lm -lstdc++
EXCUTABLE_FILE = main

SCENE_SUB=./scene/
GAME_SUB=./scene/game/
UI_SUB=./scene/ui/
SOURCE=$(wildcard ./*cpp $(SCENE_SUB)*.cpp $(GAME_SUB)*.cpp $(UI_SUB)*.cpp)
INCLUDE = -I ./scene/ -I ./ -I ./scene/game/ -I ./scene/ui/

OBJECTS=$(patsubst %.cpp,%.o,$(SOURCE))
$(EXCUTABLE_FILE) : $(OBJECTS)
	$(CXX) $(CFLAG) $^ -o $@
$(OBJECTS):%.o : %.cpp
	$(CXX) -c $(CFLAG) $< -o $@

.PHONY:clean
clean:
	rm -rf *.o $(SCENE_SUB)*.o $(GAME_SUB)*.o $(UI_SUB)*.o
