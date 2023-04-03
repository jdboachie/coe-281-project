#include "main.h"

void fail(int GAME_STATE)
{
    char buffer_overflow;
    char choice;

    type_it("You have failed to catch the thief. The thief has escaped with the jewels.\n");
    type_it("Would you like to try again? (y/n)\n");

    scanf("%c", &buffer_overflow);
    scanf("%c", &choice);
    if (choice == 'y') {
        scanf("%c", &buffer_overflow);
        play_step(GAME_STATE);
    }
    exit(0);
}
