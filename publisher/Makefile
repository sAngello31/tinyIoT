# Publisher Makefile

CC = gcc
SRC = src
CFLAGS = -Wall -c -Iinclude
OBJ = main.o utils.o
TARGET = publisher

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

main.o: $(SRC)/main.c include/utils.h
	$(CC) $(CFLAGS) $(SRC)/main.c -o main.o

utils.o: $(SRC)/utils.c include/utils.h
	$(CC) $(CFLAGS) $(SRC)/utils.c -o utils.o

clean:
	rm -f *.o $(TARGET)
