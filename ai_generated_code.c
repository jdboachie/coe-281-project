#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHOICES 5
#define MAX_SAVE_DATA_LENGTH 100

typedef struct {
	int choice;
	int outcome;
} Progress;

typedef struct {
	char name[50];
	Progress progress[MAX_CHOICES];
} Player;

Player players[10];
int num_players = 0;
int current_player = -1;

void new_game() {
	Progress initial_progress[MAX_CHOICES] = {
		{0, 0},
		{0, 0},
		{0, 0},
		{0, 0},
		{0, 0}
	};
	strcpy(players[num_players].name, "Player");
	sprintf(players[num_players].name + strlen(players[num_players].name), "%d", num_players + 1);
	memcpy(players[num_players].progress, initial_progress, sizeof(initial_progress));
	current_player = num_players;
	num_players++;
}

void load_game() {
	FILE *fp;
	char filename[50];
	printf("Enter player name: ");
	scanf("%s", filename);
	for (int i = 0; i < num_players; i++) {
		if (strcmp(filename, players[i].name) == 0) {
			current_player = i;
			fp = fopen(filename, "r");
			fread(players[current_player].progress, sizeof(players[current_player].progress), 1, fp);
			fclose(fp);
			printf("Game loaded for %s\n", players[current_player].name);
			return;
		}
	}
	printf("Player not found.\n");
}

void save_game() {
	if (current_player == -1) {
		printf("No game to save.\n");
		return;
	}
	FILE *fp;
	char filename[55];
	sprintf(filename, "%s.save", players[current_player].name);
	fp = fopen(filename, "w");
	fwrite(players[current_player].progress, sizeof(players[current_player].progress), 1, fp);
	fclose(fp);
	printf("Game saved for %s\n", players[current_player].name);
}

void print_progress() {
	if (current_player == -1) {
		printf("No game in progress.\n");
		return;
	}
	printf("Current progress for %s:\n", players[current_player].name);
	for (int i = 0; i < MAX_CHOICES; i++) {
		printf("Choice %d: %d\n", i + 1, players[current_player].progress[i].choice);
	}
}

void new_choice(int choice, int outcome) {
	if (current_player == -1) {
		printf("No game in progress.\n");
		return;
	}
	if (choice < 1 || choice > MAX_CHOICES) {
		printf("Invalid choice.\n");
		return;
	}
	players[current_player].progress[choice - 1].choice = choice;
	players[current_player].progress[choice - 1].outcome = outcome;
}

int main() {
	int choice;
	int outcome;
	int quit = 0;
	while (!quit) {
		printf("\n");
		printf("1. New game\n");
		printf("2. Load game\n");
		printf("3. Save game\n");
		printf("4. Print progress\n");
		printf("5. Make new choice\n");
		printf("6. Quit\n");
		printf("Enter choice: ");
		scanf("%d", &choice);
		switch (choice)
		{
			case 1:
				new_game();
				break;
			case 2:
				load_game();
				break;
			case 3:
				save_game();
				break;
			case 4:
				print_progress();
				break;
			case 5:
				printf("Enter choice (1-%d): ", MAX_CHOICES);
				scanf("%d", &choice);
				printf("Enter outcome: ");
				scanf("%d", &outcome);
				new_choice(choice, outcome);
				break;
			case 6:
				quit = 1;
				break;
			default:
				printf("Invalid choice.\n");
				break;
		}
	}
	return 0;
}
