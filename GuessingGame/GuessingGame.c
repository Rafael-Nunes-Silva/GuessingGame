#include <stdio.h>

int points = 1000;
int userGuess = 0, secretNumber = 0;

int main() {
	int chances=0;

	printf("*********************************\n");
	printf("* Welcome to the Guessing Game! *\n");
	printf("*********************************\n");

	chances = NumberOfChances();

	secretNumber = RandomNumber(0, 10 * chances);

	printf("The secret number is between %i and %i.\n", 0, 10 * chances);

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
		if (userGuess != secretNumber)
			printf("You lost!\n");
	}

	printf("Game Over!\n");

	printf("You finished the game with %i", points);

	return 0;
}

/// <summary>
/// return 0 if the user input was equal, 0 if it was lower and 1 if it was highier then the secret number
/// </summary>
int GetUserGuess() {
	unsigned int pointsToLose = (secretNumber-userGuess)/2;
	printf("Guess a number: \n");
	scanf_s("%i", &userGuess);

	if (userGuess == secretNumber) {
		printf("Congratulations! you won!\n\n");
		return 0;
	}

	points -= pointsToLose*10;

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
	printf("Choose how many chances you want for you to guess the secret number.\n(min 1 | max 10 | -1 for infinite tries).\n");
	printf("Remember, the difficulty will raise with the ammount of chances you got.\n");

	int chances = 0;
	scanf_s("%i", &chances);

	if (chances > 10) chances = 10;
	else if (chances < -1) chances = -1;

	return chances;
}

/// <summary>
/// return a random number between a min and max value
/// </summary>
int RandomNumber(int min, int max) {
	int r = rand() % max + min;
	return r;
}