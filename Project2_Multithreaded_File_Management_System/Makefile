CC = gcc
CFLAGS = -pthread -Wall -Iinclude
LDFLAGS = -lz
SRC = src
OBJ = $(SRC)/main.o $(SRC)/file_ops.o $(SRC)/sync.o $(SRC)/metadata.o $(SRC)/logger.o $(SRC)/compression.o $(SRC)/utils.o
TARGET = fs_manager

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -o $@ $(OBJ) $(LDFLAGS)

$(SRC)/main.o: $(SRC)/main.c include/file_ops.h include/metadata.h include/logger.h include/sync.h include/compression.h include/utils.h
	$(CC) $(CFLAGS) -c $< -o $@

$(SRC)/file_ops.o: $(SRC)/file_ops.c include/file_ops.h include/sync.h include/logger.h
	$(CC) $(CFLAGS) -c $< -o $@

$(SRC)/sync.o: $(SRC)/sync.c include/sync.h
	$(CC) $(CFLAGS) -c $< -o $@

$(SRC)/metadata.o: $(SRC)/metadata.c include/metadata.h include/logger.h
	$(CC) $(CFLAGS) -c $< -o $@

$(SRC)/logger.o: $(SRC)/logger.c include/logger.h
	$(CC) $(CFLAGS) -c $< -o $@

$(SRC)/compression.o: $(SRC)/compression.c include/compression.h include/logger.h
	$(CC) $(CFLAGS) -c $< -o $@

$(SRC)/utils.o: $(SRC)/utils.c include/utils.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(SRC)/*.o $(TARGET)
