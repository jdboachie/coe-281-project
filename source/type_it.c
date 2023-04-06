#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void type_it(char* text) {
    srand(time(NULL)); // seed the random number generator with the current time
    int i;
    for (i = 0; text[i] != '\0'; i++) {
        usleep(rand() % 10 * 100); // sleep for a random amount of time between 0 and 100 milliseconds
        printf("%c", text[i]);
        fflush(stdout);
    }
}
