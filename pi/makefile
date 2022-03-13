CC = gcc

build:
	$(CC) main.c -o main -pthread
	@ echo "Program compiled successfully"

run: main
	./main 16 100000000

clean: main
	rm main
