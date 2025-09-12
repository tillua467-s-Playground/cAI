CC = gcc
CFLAGS = -Wall -O2

OUT = out
SRC = src

TARGET = main
SRC_FILES = $(SRC)/genrate.c $(SRC)/memory.c $(SRC)/phraser.c $(SRC)/main.c

T2 = genrate
T3 = memory
T4 = phraser

all: $(OUT)/$(TARGET)
	./$(OUT)/$(TARGET)

$(OUT)/$(TARGET): $(SRC_FILES) | $(OUT)
	$(CC) $(CFLAGS) $(SRC_FILES) -o $@

$(OUT)/$(T2): $(SRC)/genrate.c | $(OUT)
	$(CC) $(CFLAGS) $< -o $@
	./$@

$(OUT)/$(T3): $(SRC)/memory.c | $(OUT)
	$(CC) $(CFLAGS) $< -o $@
	./$@

$(OUT)/$(T4): $(SRC)/phraser.c | $(OUT)
	$(CC) $(CFLAGS) $< -o $@
	./$@

$(OUT):
	mkdir $(OUT)

clean:
	del $(OUT)\*.*   
