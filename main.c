#include "code/ocr.h"

int main()
{
    char **grid = file_to_list("test/grid1");
    for(int i = 0; i < 9; i++)
    {
        printf("%s\n", grid[i]);
    }
}