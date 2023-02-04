CC = g++
CFLAGS += -Wall -O3
CLIBS += -lncurses

TARGET = revercpp
SRCS = $(shell ls *.cpp ui/*.cpp)
OBJS = $(SRCS:.cpp=.o)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(CLIBS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

.PHONY: clean
clean:
	rm -f $(TARGET) $(OBJS)
