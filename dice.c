#include <stdio.h>
#include <time.h>
#include <stdlib.h>


const int SIDES_DEFAULT = 6;
const int ROLLS_DEFAULT = 10;

int sides, rolls;
time_t seed;
int **results;
int *stats;

void rollDice() {
	for (int i = 0; i < rolls; i++) {
		results[i][0] = rand() % sides + 1;
		results[i][1] = rand() % sides + 1;
		stats[results[i][0] - 1] += 1;
		stats[results[i][1] - 1] += 1;
		printf("Rolled %2d & %2d\n", results[i][0], results[i][1]);
	}
}

int main(int argc, char *argv[]) {
	time_t SEED_DEFAULT = time(0);
	sides = SIDES_DEFAULT, rolls = ROLLS_DEFAULT;
	seed = SEED_DEFAULT;

	if (argc >= 2) {
		sides = atoi(argv[1]);
	}
	if (argc >= 3) {
		rolls = atoi(argv[2]);
	}
	if (argc == 4) {
		seed = atoi(argv[3]);
	}

	printf("Rolling 2, %d sided dice %d times using the seed %ld\n", sides, rolls, seed);

	results = malloc(sizeof(int) * rolls);
	for (int i = 0; i < rolls; i++) {
		results[i] = malloc(sizeof(int) * 2);
	}

	stats = calloc(sides, sizeof(int));

	rollDice();

	printf("%7s | %12s |%12s\n", "Side", "Roll Count", "Percentage");
	printf("------------------------------------\n");
	for (int i = 0; i < sides; i++) {
		printf("%7d | %12d | %12f\n", i + 1, stats[i], ((double)stats[i])/(rolls * 2));
	}

  return 0;
}


