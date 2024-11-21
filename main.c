#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char* hangmanArt(int numberWrong);
char *randomWord();
char *obfuscateWord(char* wordChosen);
void validateLetter(char *wordChosen, char *obWord, char letterInputted, int *numberWrong);
void checkWin(char *wordChosen, char *obWord, int *wordFinished);

int main() {
	srand(time(NULL));

	int numberWrong = 0;
	char *word = randomWord();
	char *obfuscatedWord = obfuscateWord(word);
	int wordFinished = 0;

	while (numberWrong < 10 && wordFinished == 0) {
		int attemptsLeft = 11 - numberWrong;

		printf("WORD: %s\n", obfuscatedWord);
		printf("%s\n", hangmanArt(numberWrong));
		char inputtedLetter;
		scanf_s(" %c", &inputtedLetter);
		getchar();

		validateLetter(word, obfuscatedWord, inputtedLetter, &numberWrong);
		checkWin(word, obfuscatedWord, &wordFinished);
		printf("---------------------.\n");
	}

	if (wordFinished == 1) {
		printf("You won!\n");
	}
	else {
		printf("You lost! \n");
		printf("The word was: %s\n", word);
	}

	free(word);
	free(obfuscatedWord);

	return 0;
}

char* hangmanArt(int numberWrong)
{
	switch (numberWrong) {
	case 0:
		return "  -----\n  |   |\n      |\n      |\n      |\n      |\n  =====";
	case 1:
		return "  -----\n  |   |\n  O   |\n      |\n      |\n      |\n  =====";
	case 2:
		return "  -----\n  |   |\n  O   |\n  |   |\n      |\n      |\n  =====";
	case 3:
		return "  -----\n  |   |\n  O   |\n  |   |\n /    |\n      |\n  =====";
	case 4:
		return "  -----\n  |   |\n  O   |\n  |   |\n / \\  |\n      |\n  =====";
	case 5:
		return "  -----\n  |   |\n  O   |\n  |   |\n / \\  |\n  |   |\n  =====";
	case 6:
		return "  -----\n  |   |\n  O   |\n  |   |\n / \\  |\n  |   |\n  /    \n  =====";
	case 7:
		return "  -----\n  |   |\n  O   |\n  |   |\n / \\  |\n  |   |\n /     \n  =====";
	case 8:
		return "  -----\n  |   |\n  O   |\n  |   |\n / \\  |\n  |   |\n / \\   \n  =====";
	case 9:
		return "  -----\n  |   |\n  O   |\n  |   |\n / \\  |\n  |   |\n / \\   \n  =====\n  Game Over!";
	default:
		return "  -----\n  |   |\n  O   |\n  |   |\n / \\  |\n  |   |\n / \\   \n  =====\n  You lost!";
	}
}

char *randomWord() {
	char wordsList[5][13] = { "banana", "apple", "computer", "programming", "jesusChrist" };

	char *wordChosen = wordsList[rand() % 5];

	size_t length = strlen(wordChosen) + 1;
	char* wordCopy = malloc(strlen(wordChosen) + 1);

	if (wordChosen == NULL) {
		printf("failed");
		exit(1);
	}

	strcpy_s(wordCopy, length ,wordChosen);

	return wordCopy;
}

char *obfuscateWord(char* wordChosen) {
	char *obfuscated = malloc(strlen(wordChosen) + 1);
	
	for (int i = 0; i < strlen(wordChosen); i++) {
		obfuscated[i] = '_';
	}
	
	obfuscated[strlen(wordChosen)] = '\0';

	return obfuscated;
}

void validateLetter(char *wordChosen, char *obWord, char letterInputted, int *numberWrong)
{	
	int wrongLetter = 1;
	for (int i = 0; i < strlen(wordChosen); i++) {
		if (letterInputted == wordChosen[i]) {
			obWord[i] = wordChosen[i];
			wrongLetter = 0;
		}
		
	}

	if (wrongLetter == 1) {
		(*numberWrong)++;
	}

	
}

void checkWin(char* wordChosen, char* obWord, int *wordFinished)
{
	for (int i = 0; i < strlen(wordChosen); i++) {
		if (wordChosen[i] != obWord[i]) {
			return;
		}
	}
	*wordFinished = 1;
}

