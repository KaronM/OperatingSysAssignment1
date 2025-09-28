CC = gcc
CFLAGS = -Wall -g
LDFLAGS =

SRCS = lab1.c 
OBJS = $(SRCS:.c=.o)
TARGET = _explode_

all: $(TARGET)

$(TARGET): $(OBJS)
		$(CC) $(LDFLAGS) $(OBJS) -o $(TARGET)

%.o: %.c 
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		rm -f $(OBJS) $(TARGET)
