#include "main.h"
#include "fail.c"

int game()
{
    // Variable declarations
    char choice;

    // Game loop
    while (1) {
        // Introduction
        type_it("Detective Jones had been on the trail of the notorious thief, known as the \"Midnight Bandit\", for months. The thief had been targeting jewelry stores in the city, and had so far managed to evade capture. However, Jones had recently received a tip-off about the thief's next target - a high-end jewelry store on the outskirts of town.\n");
        type_it("Jones arrived at the store early in the morning, setting up surveillance equipment and preparing for the thief's arrival. As he waited, he noticed a suspicious-looking individual hanging around the store. Jones approached the individual, who claimed to be waiting for a friend.\n");

        // Question 1
        type_it("Do you:\n");
        type_it("1. Detain the individual\n");
        type_it("2. Let the individual go\n");
        type_it("3. Follow the individual\n");
        scanf("%c", &choice);

        while (choice != '0')
        {
            if (choice == '1')
            {
                type_it("Jones decides to detain the individual, who turns out to be an innocent bystander. The real thief manages to get away with the jewels.\n");
                type_it("\n\tGAME OVER\n\n");
                fail();
            }
            else if (choice == '2')
            {
                type_it("Jones lets the individual go, and the real thief is able to make off with the jewels without being detected.");
                fail();
            }
            else if (choice == '3')
            {
                type_it("Jones follows the individual, and catches the thief in the act. The thief is arrested, and the jewels are recovered.\n");
                choice = '0';
            }
            else
            {
                type_it("Invalid choice. Please try again.\n");
            }
        }

        // The Interrogation
        type_it("After arresting the thief, Jones begins to interrogate him, trying to uncover more information about the Midnight Bandit's network. The thief is initially resistant, but Jones is able to use his charm and experience to get him to talk.\n");

        // Question 2
        type_it("Pick a revelation to work with:\n");
        type_it("1.\n");
        type_it("2.\n");
        type_it("3.\n");
        scanf("%c", &choice);

        while (choice != '0')
        {
            if (choice == '1')
            {
                type_it(" The thief reveals that he was working alone, and has no knowledge of the Midnight Bandit's network. Jones is forced to release him, and the case remains unsolved.\n");
                type_it("\n\tGAME OVER\n\n");
                fail();
            }
            else if (choice == '2')
            {
                type_it(" The thief reveals the location of the Midnight Bandit's hideout. Jones is able to raid the hideout, and arrest several members of the network.\n");
                choice = '0';
            }
            else if (choice == '3')
            {
                type_it("The thief reveals that he was only a small-time crook, and has no knowledge of the Midnight Bandit's network. Jones is forced to release him, and the case remains unsolved.");
                type_it("\n\tGAME OVER\n\n");
                fail();
            }
            else
            {
                type_it("Invalid choice. Please try again.\n");
            }
        }

        // The Link
        type_it("Jones continues to investigate the case, following up on leads and analyzing evidence. Finally, he discovers a link between the Midnight Bandit and a wealthy businessman, who had been using the stolen jewelry to fund his own lavish lifestyle.\n");
        type_it("In a final move, Jones needs to decide whether to confront the businessman, or to present his evidence to the prosecutor.\n");

        // Question 3
        type_it("Do you:\n");
        type_it("1. Confront the businessman\n");
        type_it("2. Present the evidence to the prosecutor\n");
        scanf("%c", &choice);

        while (choice != '0')
        {
            if (choice == '1')
            {
                type_it("Jones confronts the businessman, who is able to bribe his way out of the situation. Jones is forced to release the businessman, and the case remains unsolved.\n");
                type_it("\n\tGAME OVER\n\n");
                fail();
            }
            else if (choice == '2')
            {
                type_it("Jones presents the evidence to the prosecutor, who is able to use it to convict the businessman. The businessman is sentenced to prison, and the Midnight Bandit is finally brought to justice.\n");
                type_it("\n\tYOU WIN!\n\n");
                exit(0);
            }
            else
            {
                type_it("Invalid choice. Please try again.\n");
            }
        }

    }
}
