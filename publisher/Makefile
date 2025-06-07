# Publisher Makefile

CC = gcc
SRC = src
THREAD = -pthread
CFLAGS = -Wall -c -Iinclude $(THREAD)
INCLUDE_PATH = include/utils.h include/sensor.h include/socket.h
OBJ = main.o utils.o sensor.o socket.o
TARGET = publisher

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET) $(THREAD)

main.o: $(SRC)/main.c $(INCLUDE_PATH)
	$(CC) $(CFLAGS) $(SRC)/main.c -o main.o

utils.o: $(SRC)/utils.c include/utils.h
	$(CC) $(CFLAGS) $(SRC)/utils.c -o utils.o

sensor.o: $(SRC)/sensor.c include/sensor.h
	$(CC) $(CFLAGS) $(SRC)/sensor.c -o sensor.o

socket.o: $(SRC)/socket.c include/socket.h include/sensor.h
	$(CC) $(CFLAGS) $(SRC)/socket.c -o socket.o 

clean:
	rm -f *.o $(TARGET)
