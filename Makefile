SRC = main.c code/solver.c
FLAGS = -Wall -Wextra -fsanitize=address -g 

all :
	gcc $(FLAGS) $(SRC) -o main

clean :
	rm main