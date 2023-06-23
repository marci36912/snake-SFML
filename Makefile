LSFML=-L../SFML-2.5.1/lib -lsfml-graphics -lsfml-window -lsfml-system
ISFML=-I../SFML-2.5.1/include
BUILD=./build
SRC=./src
COMPILE=g++ -c $< $(ISFML) -o $(BUILD)

kigyo: $(BUILD)/main.o $(BUILD)/grid.o $(BUILD)/apple.o $(BUILD)/snake.o 
	g++ $^ $(LSFML) -o ./$@

$(BUILD)/main.o: $(SRC)/main.cpp
	$(COMPILE)/main.o

$(BUILD)/grid.o: $(SRC)/grid.cpp $(SRC)/grid.hpp
	$(COMPILE)/grid.o

$(BUILD)/apple.o: $(SRC)/apple.cpp $(SRC)/apple.hpp
	$(COMPILE)/apple.o

$(BUILD)/snake.o: $(SRC)/snake.cpp $(SRC)/snake.hpp
	$(COMPILE)/snake.o

clear:
	rm -rf ./kigyo $(BUILD)/*

.PHONY: clear
