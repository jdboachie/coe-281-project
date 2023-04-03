#include "main.h"
#include "type_it.c"
#include "game.c"

int main()
{
    int step;
    char menu_choice;
    printf("A. New Game\nB. Resume Game\nC.Exit")
    game_loop(step);
    return 0;
}
