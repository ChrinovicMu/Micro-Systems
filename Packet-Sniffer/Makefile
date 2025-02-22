
CC := gcc
CFLAGS := -O2
SRC_DIR := src
TARGET := ./main
PROGLIB_FLAG = -lpcap 

SRCS := $(wildcard $(SRC_DIR)/*.c)

.PHONY: build run clean

build:
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET) $(PROGLIB_FLAG)

run: build
	sudo $(TARGET)

clean:
	rm -f $(TARGET)

test: build
	valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all --verbose ./main
.PHONY: git-push 
git-push:
	@git add .
	@read -p "commit msg : " msg; \
	git commit -m "$$msg"; \
	git push origin main 

