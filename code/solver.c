#include "ocr.h"


char **file_to_list(char *filename) // transforme une grille presentte dans un fichier en un tableau
{
    FILE *file = fopen(filename, "r");
    if(file == NULL)
    {
        printf("erreur lors de l'ouverture du fichier : %s\n", filename);
        return NULL;
    }
    size_t height = 1;
    size_t length = 1;
    char **grid = malloc(height * sizeof(char*));
    if (grid == NULL)
    {
        printf("erreur lors de l'alocation de mémoire");
        return NULL;
    }
    grid[0] = malloc(length * sizeof(char));
    if(grid[0] == NULL)
    {
        printf("erreur lors de l'alocation de mémoire");
        return NULL;
    }
    char line[1000];
    int i = 0;
    while(fgets(line, 999*sizeof(char), file) != NULL)
    {
        line[strcspn(line, "\r\n")] = '\0'; //permet de suprimer le \r et \n 
        grid[i] = malloc((strlen(line)+1)*sizeof(char));
        if(grid[i] == NULL)
        {
            printf("erreur lors de l'alocation de mémoire");
            return NULL;
        }
        strcpy(grid[i], line);
        height++;
        grid = realloc(grid, height *sizeof(char *));
        if(grid == NULL)
        {
            printf("erreur lors de l'alocation de mémoire");
            return NULL;
        }
        i++;
    }
    grid[i] = NULL;
    return grid;
}



int *search(char **grid, int *initial, enum direction d, char *word)
{

}

int *next_letter(char ** grid, int *initial, char *word)
{
    int x = initial[1];
    int y = initial[0];
    int *result;
    if (y != 0 && grid[y-1][x] == word[1])
    {
        result = search(grid, initial, NORTH, word);
        if (result != NULL)
        {
            return result;
        }
    }
    if (y != 0 && x < strlen(grid[y]) && grid[y-1][x+1] == word[1])
    {
        result = search(grid, initial, NORTH_WEST, word);
        if (result != NULL)
        {
            return result;
        }
    }
    if (x < strlen(grid[y]) && grid[y][x+1] == word[1])
    {
        result = search(grid, initial, WEST, word);
        if (result != NULL)
        {
            return result;
        }
    }
    if (y < strlen(grid[y]) && x < strlen(grid[y]) && grid[y+1][x+1] == word[1])
    {
        result = search(grid, initial, SOUTH_WEST, word);
        if (result != NULL)
        {
            return result;
        }
    }
    if (y < strlen(grid[y]) && grid[y+1][x] == word[1])
    {
        result = search(grid, initial, SOUTH, word);
        if (result != NULL)
        {
            return result;
        }
    }
    if (y < strlen(grid[y]) && x != 0 && grid[y+1][x-1] == word[1])
    {
        result = search(grid, initial, SOUTH_EAST, word);
        if (result != NULL)
        {
            return result;
        }
    }
    if (x != 0 && grid[y][x-1] == word[1])
    {
        result = search(grid, initial, EAST, word);
        if (result != NULL)
        {
            return result;
        }
    }
    return search(grid, initial, NORTH_EAST, word);
}

int *solver(char *filename, char *word )
{
    int res[4];  //stock les coordonées sous cette forme [x initial, y initial, x final, y final]
    char **grid = file_to_list(filename);
    if (grid == NULL)
    {
        return NULL;
    }
    for (int i = 0; grid[i] != NULL; i++)
    {
        for(int j = 0; grid[i][j] != NULL; j++)
        {
            if(grid[i][j] == word[0])
            {
                int *initial ={i,j};
                int *final[2] = next_letter(grid, initial, word);
                if (final != NULL)
                {
                    res[0] = initial[1];
                    res[1] = initial[0];
                    res[2] = final[0];
                    res[3] = final[1];
                    return res;
                }
            }
        }
    }

}
