SRC = main.c code/solver.c
FLAGS = -Wall -Wextra -fsanitize=address -g 

all :
	gcc $(FLAGS) $(SRC) -o main

solver : code/solver.c code/ocr.h
	gcc	$(FLAGS) code/solver.c -o solver

clean :
	rm main