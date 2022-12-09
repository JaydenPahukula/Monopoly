
TARGET = FP
SRC_FILES = main.cpp gameFunctions.cpp Player.cpp Property.cpp OtherProperty.cpp OwnableProperty.cpp RailroadProperty.cpp UtilityProperty.cpp
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

main.o: main.cpp Player.h Property.h gameFunctions.h
gameFunctions.o: gameFunctions.cpp gameFunctions.h Player.h Property.h OtherProperty.h OwnableProperty.h RailroadProperty.h UtilityProperty.h
Player.o: Player.cpp Player.h Property.h
Property.o: Property.cpp Property.h Player.h
OtherProperty.o: OtherProperty.cpp OtherProperty.h Player.h Property.h
OwnableProperty.o: OwnableProperty.cpp OwnableProperty.h Player.h  Property.h
RailroadProperty.o: RailroadProperty.cpp RailroadProperty.h Player.h Property.h
UtilityProperty.o: UtilityProperty.cpp UtilityProperty.h Player.h Property.h