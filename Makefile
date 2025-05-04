CXX = g++
TARGET = main.exe

SRC = main.cpp ant.cpp pheromone.cpp

OBJ = $(SRC:.cpp=.o)

SFML_PATH = "C:/Program Files/SFML-3.0.0"
INCLUDES = -I$(SFML_PATH)/include
LIBS = -L$(SFML_PATH)/lib -lsfml-graphics -lsfml-window -lsfml-system

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET) $(LIBS)

%.o: %.cpp
	$(CXX) -c $< -o $@ $(INCLUDES)

clean:
	-rm *.exe
	-rm  *.o 


run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run

all: $(TARGET)