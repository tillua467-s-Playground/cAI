CC = gcc
CFLAGS = -Wall -O2 -Iheaders

OUT = out
SRC = src

TARGET = main
T2 = genrate
T3 = memory
T4 = phraser
T5 = node
SRC_FILES = $(SRC)/genrate.c $(SRC)/memory.c $(SRC)/phraser.c  $(SRC)/node.c $(SRC)/main.c

all: $(OUT)/$(TARGET)
	./$(OUT)/$(TARGET)


$(OUT)/$(TARGET): $(SRC_FILES) | $(OUT)
	$(CC) $(CFLAGS) $(SRC_FILES) -o $@

# Individual component builds
$(OUT)/$(T2): $(SRC)/genrate.c | $(OUT)
	$(CC) $(CFLAGS) $< -o $@
	./$@

$(OUT)/$(T3): $(SRC)/memory.c | $(OUT)
	$(CC) $(CFLAGS) $< -o $@
	./$@

$(OUT)/$(T4): $(SRC)/phraser.c | $(OUT)
	$(CC) $(CFLAGS) $< -o $@
	./$@

$(OUT)/$(T5): $(SRC)/node.c | $(OUT)
	$(CC) $(CFLAGS) $< -o $@
	./$@

gen: $(OUT)/$(T2)
mem: $(OUT)/$(T3)
phar: $(OUT)/$(T4)
node: $(OUT)/$(T5)
main: $(OUT)/$(TARGET)
	./$(OUT)/$(TARGET)

$(OUT):
	mkdir $(OUT)

clean:
	del $(OUT)\*.*   # Windows
	# rm -f $(OUT)/* # Linux
