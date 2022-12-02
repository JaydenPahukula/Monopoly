
TARGET = play
SRC_FILES = main.cpp Player.cpp Property.cpp gameFunctions.cpp

CXX = g++
CFLAGS = -Wall -g -std=c++11
OBJECTS = $(SRC_FILES:.cpp=.o)

ifeq ($(shell echo "Windows"), "Windows")
	TARGET := $(TARGET).exe
	DEL = del
else
	DEL = rm
endif

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) -o $@ $^

.cpp.o:
	$(CXX) $(CFLAGS) -o $@ -c $<

clean:
	$(DEL) $(TARGET) $(OBJECTS)

Player.o: Player.cpp Player.h Property.h
Property.o: Property.cpp Property.h Player.h
gameFunctions.o: gameFunctions.cpp gameFunctions.h Player.h Property.h
main.o: main.cpp Player.h Property.h gameFunctions.h