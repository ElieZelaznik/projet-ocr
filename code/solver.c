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
    char **grid = malloc(height * sizeof(char*));
    if (grid == NULL)
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
    fclose(file);
    return grid;
}

int *search(char ** grid, int *initial, char *word)
{
    int x = initial[1];
    int y = initial[0];
    int word_length = (int)strlen(word);
    int *result = malloc(2 * sizeof(int));
    if (result == NULL)
    {
        return NULL;
    }
    if (word_length == 1)
    {
        result[0] = x;
        result[1] = y;
        return result;
    }
    if (y != 0 && x < (int)strlen(grid[y-1]) && grid[y-1][x] == word[1])
    {
        if(strlen(word) == 2)
        {
            result[0] = x;
            result[1] = y-1;
            return result;
        }
        int i;
        for(i = 2; y-i >= 0 && x < (int)strlen(grid[y-i]) && word[i] != 0; i++)
        {
            if(word[i] != grid[y-i][x])
            {
                break;
            }
        }
        if (i == word_length)
        {
            result[0] = x;
            result[1] = y - i + 1;
            return result;
        }
    }
    if (y != 0 && x + 1 < (int)strlen(grid[y-1]) && grid[y-1][x+1] == word[1])
    {
        if(strlen(word) == 2)
        {
            result[0] = x+1;
            result[1] = y-1;
            return result;
        }
        int i;
        for(i = 2; y-i >= 0 && x + i < (int)strlen(grid[y-i]) && word[i] != 0; i++)
        {
            if(word[i] != grid[y-i][x+i])
            {
                break;
            }
        }
        if (i == word_length)
        {
            result[0] = x + i - 1;
            result[1] = y - i + 1;
            return result;
        }
    }
    if (x + 1 < (int)strlen(grid[y]) && grid[y][x+1] == word[1])
    {
        if (word_length == 2)
        {
            result[0] = x+1;
            result[1] = y;
            return result;
        }
        int i;
        for(i = 2; x + i < (int)strlen(grid[y]) && word[i] != 0; i++)
        {
            if(word[i] != grid[y][x+i])
            {
                break;
            }
        }
        if (i == word_length)
        {
            result[0] = x + i - 1;
            result[1] = y;
            return result;
        }
    }
    if (grid[y+1] != NULL && x + 1 < (int)strlen(grid[y+1]) && grid[y+1][x+1] == word[1])
    {
        if (word_length == 2)
        {
            result[0] = x+1;
            result[1] = y+1;
            return result;
        }
        int i;
        for(i = 2; grid[y+i] != NULL && x + i < (int)strlen(grid[y+i]) && word[i] != 0; i++)
        {
            if(word[i] != grid[y+i][x+i])
            {
                break;
            }
        }
        if (i == word_length)
        {
            result[0] = x + i - 1;
            result[1] = y + i - 1;
            return result;
        }
    }
    if (grid[y+1] != NULL && x < (int)strlen(grid[y+1]) && grid[y+1][x] == word[1])
    {
        if (word_length == 2)
        {
            result[0] = x;
            result[1] = y+1;
            return result;
        }
        int i;
        for(i = 2; grid[y+i] != NULL && x < (int)strlen(grid[y+i]) && word[i] != 0; i++)
        {
            if(word[i] != grid[y+i][x])
            {
                break;
            }
        }
        if (i == word_length)
        {
            result[0] = x;
            result[1] = y + i - 1;
            return result;
        }
    }
    if (grid[y+1] != NULL && x != 0 && x - 1 < (int)strlen(grid[y+1]) && grid[y+1][x-1] == word[1])
    {
        if (word_length == 2)
        {
            result[0] = x-1;
            result[1] = y+1;
            return result;
        }
        int i;
        for(i = 2; grid[y+i] != NULL && x - i >= 0 && word[i] != 0; i++)
        {
            if(x - i >= (int)strlen(grid[y+i]) || word[i] != grid[y+i][x-i])
            {
                break;
            }
        }
        if (i == word_length)
        {
            result[0] = x - i + 1;
            result[1] = y + i - 1;
            return result;
        }
    }
    if (x != 0 && grid[y][x-1] == word[1])
    {
        if (word_length == 2)
        {
            result[0] = x-1;
            result[1] = y;
            return result;
        }
        int i;
        for(i = 2; x - i >= 0 && word[i] != 0; i++)
        {
            if(word[i] != grid[y][x-i])
            {
                break;
            }
        }
        if (i == word_length)
        {
            result[0] = x - i + 1;
            result[1] = y;
            return result;
        }
    }
    if (y != 0 && x != 0 && x - 1 < (int)strlen(grid[y-1]) && grid[y-1][x-1] == word[1])
    {
        if (word_length == 2)
        {
            result[0] = x-1;
            result[1] = y-1;
            return result;
        }
        int i;
        for(i = 2; y - i >= 0 && x - i >= 0 && word[i] != 0; i++)
        {
            if(x - i >= (int)strlen(grid[y-i]) || word[i] != grid[y-i][x-i])
            {
                break;
            }
        }
        if (i == word_length)
        {
            result[0] = x - i + 1;
            result[1] = y - i + 1;
            return result;
        }
    }
    free(result);
    return NULL;
}

int *solver(char *filename, char *word )
{
    char **grid = file_to_list(filename);
    if (grid == NULL)
    {
        return NULL;
    }
    int *res = NULL;
    for (int i = 0; grid[i] != NULL && res == NULL; i++)
    {
        for(int j = 0; grid[i][j] != '\0' && res == NULL; j++)
        {
            if(grid[i][j] == word[0])
            {
                int initial[2] = {i,j};
                int *final = search(grid, initial, word);
                if (final != NULL)
                {
                    res = malloc(4 * sizeof(int));
                    if (res != NULL)
                    {
                        res[0] = initial[1];
                        res[1] = initial[0];
                        res[2] = final[0];
                        res[3] = final[1];
                    }
                    free(final);
                }
            }
        }
    }
    for (int i = 0; grid[i] != NULL; i++)
    {
        free(grid[i]);
    }
    free(grid);
    return res;
}


int main(int argc, char **argv)
{
    if(argc != 3)
    {
        printf("L'appel doit etre de la forme %s <path> <word>\n", argv[0]);
        return 0;
    }
    int *res = solver(argv[1], argv[2]);
    if(res == NULL)
    {
        printf("Not found\n");
        return 0;
    }
    printf("(%d,%d)(%d,%d)\n", res[0], res[1], res[2], res[3]);
    free(res);
}