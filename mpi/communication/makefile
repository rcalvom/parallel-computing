MPICC = mpicc

build:
	$(MPICC) main.c -o main 
	@ echo "Program compiled successfully"

run: main
	mpirun -np 4 main

clean: main
	rm main
