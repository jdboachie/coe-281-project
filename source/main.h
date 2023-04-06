#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>

char profile_name[50];

void type_it(char *str);
int game_loop(int step);
int save_game();
int play_step();
void fail();

int start();
int choice1(int GAME_STATE);
int choice2(int GAME_STATE);
int choice3(int GAME_STATE);

#endif // MAIN_H
