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
		case 3: choice3(GAME_STATE);
		default: type_it("Error: Invalid game state.");
	}
	return (GAME_STATE);
}


int validate_choice(int choice)
{
	for (int i = 1; i < 4; i++)
	{
		if (choice == i)
		{
			return 1;
		}
	}
	printf("Invalid choice. Try again.");
	play_step(GAME_STATE+1);
	return 0;
}


int start()
{
	GAME_STATE = 0;
	type_it("Detective Jones had been on the trail of the notorious thief, known as the \"Midnight Bandit\", for months.\nThe thief had been targeting jewelry stores in the city, and had so far managed to evade capture.\nHowever, Jones had recently received a tip-off about the thief's next target - a high-end jewelry store on the outskirts of town.\n");
	play_step(GAME_STATE+1);
	return 0;
}

int choice1(int GAME_STATE)
{
	type_it("Jones arrived at the store early in the morning, setting up surveillance equipment and preparing for the thief's arrival.\nAs he waited, he noticed a suspicious-looking individual hanging around the store.\nJones approached the individual, who claimed to be waiting for a friend.\n");
	type_it("What should Jones do?\n");
	type_it("1. Detain the individual.\n2. Let the individual go.\n3. Follow the individual.\n$ ");
	scanf("%d", &CURRENT_CHOICE);
	validate_choice(CURRENT_CHOICE);
	if (CURRENT_CHOICE == 3)
	{
		type_it("Jones follows the individual, and catches the thief in the act. The thief is arrested, and the jewels are recovered.\n");
		GAME_STATE = 2;
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
	type_it("\nAfter arresting the thief, Jones begins to interrogate him, trying to uncover more information about the Midnight Bandit's network.\nThe thief is initially resistant, but Jones is able to use his charm and experience to get him to talk.\n");
	type_it("Pick a revelation to work with:\n");
	type_it("1.\n2.\n3.\n$ ");
	scanf("%d", &CURRENT_CHOICE);
	validate_choice(CURRENT_CHOICE);
	if (CURRENT_CHOICE == 2)
	{
		type_it("The thief reveals the location of the Midnight Bandit's hideout.\nJones is able to raid the hideout, and arrest several members of the network.\n");
		GAME_STATE = 3;
		play_step(GAME_STATE);
	}
	else
	{
		if (CURRENT_CHOICE == 1)
		{
			type_it("The thief reveals that he was working alone, and has no knowledge of the Midnight Bandit's network.\nJones is forced to release him, and the case remains unsolved.\n");
			type_it("\n\tGAME OVER\n\n");
			fail(GAME_STATE);
		}
		else
		{
			type_it("The thief reveals that he was only a small-time crook, and has no knowledge of the Midnight Bandit's network. Jones is forced to release him, and the case remains unsolved.");
			type_it("\n\tGAME OVER\n\n");
			fail(GAME_STATE);
		}
	}
}


int choice3(int GAME_STATE)
{
	type_it("Jones continues to investigate the case, following up on leads and analyzing evidence.\nFinally, he discovers a link between the Midnight Bandit and a wealthy businessman, who had been using the stolen jewelry to fund his own lavish lifestyle.\n");
	type_it("In a final move, Jones needs to decide whether to confront the businessman, or to present his evidence to the prosecutor.\n");
	type_it("Do you:\n");
	type_it("1. Confront the businessman\n2. Present the evidence to the prosecutor\n3. Let it rest.\n$ ");
	scanf("%d", &CURRENT_CHOICE);
	validate_choice(CURRENT_CHOICE);
	if (CURRENT_CHOICE == 2)
	{
		type_it("Jones presents the evidence to the prosecutor, who is able to use it to convict the businessman.\nThe businessman is sentenced to prison, and the Midnight Bandit is finally brought to justice.\n");
		type_it("\n\tYOU WIN!\n\n");
		exit(0);
	}
	else
	{
		if (CURRENT_CHOICE == 1)
		{
			type_it("Jones confronts the businessman, who is able to bribe his way out of the situation.\nJones is forced to release the businessman, and the case remains unsolved.\n");
			type_it("\n\tGAME OVER\n\n");
			fail(GAME_STATE);
		}
		else
		{
			type_it("Boring, Jones. BORING!");
			type_it("\n\tGAME OVER\n\n");
			fail(GAME_STATE);
		}
	}
}


int game_loop()
{
	while (1)
	{
		GAME_STATE = play_step(GAME_STATE);
	}
}