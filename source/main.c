#include "main.h"
#include "type_it.c"
#include "save_game.c"
#include "game.c"


int restore_game()
{
    FILE *fp;
    int step;
    char filename[60];

    // Get user's profile name
    printf("Enter your profile name: ");
    scanf("%s", profile_name);

    // Open save file
    sprintf(filename, "%s.dat", profile_name);
    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("Error: Could not open save file.");
        return 1;
    }
    fscanf(fp, "%d", &step);
    fclose(fp);
    return game_loop(step);
}

int new_game()
{
    // Get user's profile name
    printf("Enter your profile name: ");
    scanf("%s", profile_name);

    return game_loop(0);
}

int main()
{
    int step;
    char menu_choice;
    printf("A. New Game\nB. Resume Game\nC. Exit\n$ ");
    scanf("%c", &menu_choice);
    switch (menu_choice)
    {
        case 'a':
            new_game();
            break;
        case 'b':
            restore_game();
            break;
        case 'c':
            exit(0);
            break;
        default:
            step = 1;
            break;
    }
    return 0;
}
