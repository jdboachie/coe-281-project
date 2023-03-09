#include "main.h"

void fail()
{
    type_it("You have failed to catch the thief. The thief has escaped with the jewels.\n");
    type_it("Would you like to try again? (y/n)\n");

    char choice;
    printf("get choice");
    scanf("%c", &choice);
    printf("got choice");
    if (choice == 'y') {
        game();
    }
    exit(0);
}
