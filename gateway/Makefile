# Gateway Makefile
CC = gcc
SRC = src
CFLAGS = -Wall -c -Iinclude 
INCLUDE = include/socket.h
OBJ = main.o socket.o
TARGET = gateway

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

main.o: $(SRC)/main.c $(INCLUDE)
	$(CC) $(CFLAGS) $(SRC)/main.c -o main.o

socket.o: $(SRC)/socket.c $(INCLUDE)
	$(CC) $(CFLAGS) $(SRC)/socket.c -o socket.o

clean:
	rm -f *.o $(TARGET)