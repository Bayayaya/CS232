#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
void get_valid_number(int *n);
bool is_prime(int x);

//main() uses a sentinel controlled loop to test the primality of numbers
//, without knowing how many numbers to be tested.
// -1 is the sentinel value
// the loop repeats the cycle of read->test->process->read ...
int main() {
	int n = 0;

	while ( 1 ) { //test
		get_valid_number(&n); //read
		//process
		if (n == -1) {
			printf("Exit\n");

			break;
		} else if (is_prime (n)) {
			printf("%d is a prime number!\n", n);
		} else {

			printf("%d is not a prime number!\n", n);

		}
	}

	return 0;
}

bool is_prime(int n) {
	//if n is divisible by any number greater or equal to 2 and less than n, then n is not prime.
	int i;
	for (i = 2; i < n; i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;

}

void get_valid_number(int* n) {
	//The valid number is either -1 (to exit the program) or an integer greater than 2.
	//A loop is used to implement input validation, that is, user will be asked to
	//enter a valid number over and over again until a valid number is received.

	if (*n != -1) {
		printf("Please enter an integer greater than 2 to test its primality, enter -1 to exit \n");
		scanf("%d", n);
		while (*n < 2 && *n != -1) {
			printf("Please enter an integer greater than 2 to test its primality, enter -1 to exit \n");
			scanf("%d", n);
		}
	}

}
