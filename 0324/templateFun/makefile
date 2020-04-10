TARGET := test 
CC := g++

BUILD_DIR := tmp
INC_DIR := ./
OBJECTS := main.o


CFLAGS  := -std=c++11

$(TARGET):$(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)
	rm -f $(OBJECTS)

main.o : main.cpp
	$(CC)  $(CFLAGS) -c main.cpp

.PHONY : clean
clean:
	rm -rf  main.o test

