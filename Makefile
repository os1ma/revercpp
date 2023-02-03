CC = g++
CFLAGS = -Wall -O3

TARGET = revercpp
SRCS = revercpp.cpp

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $@ $^
