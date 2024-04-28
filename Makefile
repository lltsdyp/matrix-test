CC = gcc
CFLAGS = -m64 -std=gnu11
OUTPUT_DIR = ./bin
O_FILE = $(OUTPUT_DIR)/matrix.o $(OUTPUT_DIR)/timeconvert.o

all: $(OUTPUT_DIR)/mmul1 $(OUTPUT_DIR)/mmul2 $(OUTPUT_DIR)/mmul3 $(OUTPUT_DIR)/mmul4 $(OUTPUT_DIR)/mmul5 \
	$(OUTPUT_DIR)/mmul6

$(OUTPUT_DIR)/mmul1: $(O_FILE) mmul1.c
	$(CC) $(CFLAGS) -o $@ $(O_FILE) mmul1.c

$(OUTPUT_DIR)/mmul2: $(O_FILE) mmul2.c
	$(CC) $(CFLAGS) -o $@ $(O_FILE) mmul2.c

$(OUTPUT_DIR)/mmul3: $(O_FILE) mmul2.c
	$(CC) $(CFLAGS) -O2 -o $@ $(O_FILE) mmul2.c

$(OUTPUT_DIR)/mmul4: $(O_FILE) mmul4.c
	$(CC) $(CFLAGS) -O2 -o $@ $(O_FILE) mmul4.c

$(OUTPUT_DIR)/mmul5: $(O_FILE) mmul5.c
	$(CC) $(CFLAGS) -O2 -o $@ $(O_FILE) mmul5.c

$(OUTPUT_DIR)/mmul6: $(O_FILE) mmul6.c
	$(CC) $(CFLAGS) -fopenmp -O2 -o $@ $(O_FILE) mmul6.c

$(OUTPUT_DIR)/matrix.o: matrix.h matrix.c
	$(CC) $(CFLAGS) -c -o $(OUTPUT_DIR)/matrix.o matrix.c

$(OUTPUT_DIR)/timeconvert.o: timeconvert.h timeconvert.c
	$(CC) $(CFLAGS) -c -o $(OUTPUT_DIR)/timeconvert.o timeconvert.c

.PHONY: clean
clean:
	rm -f ./bin/*
	rm -f *.o
