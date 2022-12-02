
TARGET = play
SRC_FILES = main.cpp Player.cpp Property.cpp gameFunctions.cpp OtherProperty.cpp RailroadProperty.cpp UtilityProperty.cpp OwnableProperty.cpp

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
OtherProperty.o: OtherProperty.cpp OtherProperty.h Property.h Player.h
RailroadProperty.o: RailroadProperty.cpp RailroadProperty.h Property.h Player.h
UtilityProperty.o: UtilityProperty.cpp UtilityProperty.h Property.h Player.h
OwnableProperty.o: OwnableProperty.cpp OwnableProperty.h Property.h Player.h
gameFunctions.o: gameFunctions.cpp gameFunctions.h Player.h Property.h OtherProperty.h RailroadProperty.h UtilityProperty.h OwnableProperty.h
main.o: main.cpp Player.h Property.h gameFunctions.h