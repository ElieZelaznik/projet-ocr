#ifndef OCR_h
#define OCR_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>



enum direction{
    NORTH,
    NORTH_WEST,
    WEST,
    SOUTH_WEST,
    SOUTH,
    SOUTH_EAST,
    EAST,
    NORTH_EAST
};


char **file_to_list(char *filename);
int *search(char **grid, int *initial, char *word);
enum direction next_letter(char ** grid, int *initial, char *word);
int *solver(char *filename, char *word );




#endif