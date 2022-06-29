#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int minChances = 1, maxChances = 100;

int points = 1000;
int userGuess = 0, secretNumber = 0;

int main() {
	int chances=0;

	printf("*********************************\n");
	printf("* Welcome to the Guessing Game! *\n");
	printf("*********************************\n");

	chances = NumberOfChances();

	secretNumber = RandomNumber(0, 10 * chances);

	printf("The secret number is between %i and %i.\n", 0, chances * 10);

	if (chances == -1) {
		while (userGuess != secretNumber)
			if (GetUserGuess() == 0)
				break;
	}
	else {
		for (int turn = 1; turn <= chances; turn++) {
			if (GetUserGuess() == 0)
				break;

			printf("Chances left: %i\n", chances - turn);
		}
		if (userGuess != secretNumber) {
			printf("You lost!\n");
			printf("The number was %i\n", secretNumber);
		}
	}

	printf("You finished the game with %i\n", points);

	return 0;
}

/// <summary>
/// return 0 if the user input was equal, 0 if it was lower and 1 if it was highier then the secret number
/// </summary>
int GetUserGuess() {
	printf("Guess a number: \n");
	scanf_s("%i", &userGuess);

	if (userGuess == secretNumber) {
		printf("Congratulations! You won!\n\n");
		return 0;
	}

	int pointsToLose = (((secretNumber - userGuess) / 2) * 10);
	if (pointsToLose < 0) points += pointsToLose;
	else points -= pointsToLose;

	if (points < 0) points = 0;

	if (userGuess < secretNumber) {
		printf("Your guess was too low.\n\n");
		return -1;
	}

	printf("Your guess was too high.\n\n");
	return 1;
}

/// <summary>
/// return the number of chances the user want to have with a minimum of 1, max of 10 or -1 for ifinite tries
/// </summary>
int NumberOfChances() {
	printf("Choose how many chances you want for you to guess the secret number.\n");
	printf("(min %i | max %i | -1 for infinite tries).\n", minChances, maxChances);
	printf("Remember, the difficulty will raise with the ammount of chances you got.\n");

	int chances = 0;
	scanf_s("%i", &chances);

	if (chances > maxChances)
		chances = maxChances;
	else if (chances < -1)
		chances = -1;

	return chances;
}

/// <summary>
/// return a random number between a min and max value
/// </summary>
int RandomNumber(int min, int max) {
	srand(time(0));
	int r = rand() % max + min;
	return r;
}