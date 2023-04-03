#include "main.h"
#include "game.c"

int restore_game(char profile_name)
{
    FILE *fp;
    int step;
    char filename[20];
    sprintf(filename, "%s.dat", profile_name);
    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("Error: Could not open save file.");
        return 1;
    }
    fscanf(fp, "%d", &step);
    fclose(fp);
    return step;
}


int main()
{
    int step;
    char menu_choice;
    printf("A. New Game\nB. Resume Game\nC.Exit")
    scanf("%c", &menu_choice);
    switch (menu_choice)
    {
        case 'A':
            step = 0;
            break;
        case 'B':
            step = restore_game();
            break;
        case 'C':
            step = 3;
            break;
        default:
            step = 1;
            break;
    }
    game_loop(step);
    return 0;
}
