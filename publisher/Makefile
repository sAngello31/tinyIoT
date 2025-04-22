# Publisher Makefile

CC = gcc
SRC = src
THREAD = -pthread
CFLAGS = -Wall -c -Iinclude $(THREAD)
OBJ = main.o utils.o sensor.o
TARGET = publisher

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET) $(THREAD)

main.o: $(SRC)/main.c include/utils.h include/sensor.h
	$(CC) $(CFLAGS) $(SRC)/main.c -o main.o

utils.o: $(SRC)/utils.c include/utils.h
	$(CC) $(CFLAGS) $(SRC)/utils.c -o utils.o

sensor.o: $(SRC)/sensor.c include/sensor.h
	$(CC) $(CFLAGS) $(SRC)/sensor.c -o sensor.o

clean:
	rm -f *.o $(TARGET)
