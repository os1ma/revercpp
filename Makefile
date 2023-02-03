CC = g++
CFLAGS += -Wall -O3
CLIBS += -lncurses

TARGET = revercpp
SRCS = $(shell ls *.cpp)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $@ $^ $(CLIBS)

.PHONY: clean
clean:
	rm -f $(TARGET)
