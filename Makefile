CC = g++
CFLAGS += -Wall -O3
CLIBS += -lncurses

TARGET = revercpp
SRCS = revercpp.cpp

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $@ $^ $(CLIBS)

.PHONY: clean
clean:
	rm -f $(TARGET)
