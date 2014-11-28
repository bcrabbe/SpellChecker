CFLAGS = -O4 -Wall -pedantic -g
TARGET = dict
SOURCES = Dictionary.cpp main.cpp
INCS = Dictionary.h
LIBS = 
CC = g++

all: $(TARGET)

$(TARGET): $(SOURCES) $(INCS)
	$(CC) $(SOURCES) -o $(TARGET) $(CFLAGS) $(LIBS)

