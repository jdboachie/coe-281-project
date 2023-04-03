#include "main.h"
#include "fail.c"


int GAME_STATE;
int CURRENT_CHOICE;


int play_step(int GAME_STATE)
{
	switch (GAME_STATE)
	{
		case 0: start();
		case 1: choice1(GAME_STATE);
		case 2: choice2(GAME_STATE);
		// case 3: choice3();
		// case 4: choice4();
		// case 5: choice5();
		// case 6: choice6();
		// case 7: choice7();
		// case 8: choice8();
		// case 9: choice9();
		// case 10: choice10();
		default:
			type_it("Error: Invalid game state.");
			GAME_STATE = -1;
	}
	return (0);
}


int validate_choice(int choice, int valid_choice)
{
	if (choice == valid_choice)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


int start()
{
	type_it("Detective Jones had been on the trail of the notorious thief, known as the \"Midnight Bandit\", for months.\nThe thief had been targeting jewelry stores in the city, and had so far managed to evade capture.\nHowever, Jones had recently received a tip-off about the thief's next target - a high-end jewelry store on the outskirts of town.\n");
	choice1(0);
	return 0;
}

int choice1(int GAME_STATE)
{
	GAME_STATE = 2;
	type_it("Jones arrived at the store early in the morning, setting up surveillance equipment and preparing for the thief's arrival.\nAs he waited, he noticed a suspicious-looking individual hanging around the store.\nJones approached the individual, who claimed to be waiting for a friend.\n");
	type_it("What should Jones do?\n");
	type_it("1. Detain the individual.\n2. Let the individual go.\n3. Follow the individual.\n$ ");
	scanf("%d", &CURRENT_CHOICE);
	if (validate_choice(CURRENT_CHOICE, 3))
	{
		play_step(GAME_STATE);
	}
	else
	{
		if (CURRENT_CHOICE == 1)
		{
			type_it("Jones detained the individual, but the individual turned out to be an undercover police officer. Jones was arrested for false imprisonment.\n");
			fail(GAME_STATE);
		}
		else
		{
			type_it("Jones lets the individual go, and the real thief is able to make off with the jewels without being detected.\n");
			fail(GAME_STATE);
		}
	}
}


int choice2(int GAME_STATE)
{
	// pass
}

int game_loop()
{
	while (1)
	{
		play_step(GAME_STATE);
		printf("GAME_STATE: %d", GAME_STATE);
		if (GAME_STATE == -1)
		{
			break;
		}
	}
}