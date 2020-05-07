

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int count; // track of the number of divisions

/**
  * Handles the SIGFPE interrupt by printing the number of successful operations and
  * then exits
  */
void sigfpeHandler() {

	// Print message as given in assignment specifications
	printf("Error: a division by 0 operation was attempted.\n");
	printf("Total number of operations completed successfully: %i\n", count);
	printf("The program will be terminated.\n");

	// Exit
	exit(0);
}

/**
  * Handles the SIGINT interrupt by printing the number of successful operations and
  * then exits
  */
void sigintHandle() {

	// Prints message as given in assignment specifications
	printf("\nThe total number of operations completed successfully: %i\n", count);
	printf("The program will be terminated.\n");

	// Exit
	exit(0);
}

/**
  * Main function that performs the division and sets up handlers
  */
int main() {

	count = 0;

	// SIGFPE handler
	struct sigaction sigfpeAct;

	// Initialize sigaction() to 0
	memset(&sigfpeAct, 0, sizeof(sigfpeAct));

	sigfpeAct.sa_handler = sigfpeHandler;

	// In case of SIGFPE error
	if(sigaction(SIGFPE, &sigfpeAct, NULL) != 0) {
		printf("SIGFPE error.\n");

		// Exit peacefully
		exit(0);
	}

	// SIGINT handler
	struct sigaction sigintAc;

	// Initialize sigaction to 0
	memset(&sigintAc, 0, sizeof(sigintAc));

	sigintAc.sa_handler = sigintHandle;

	// In case of SIGINT error
	if(sigaction(SIGINT, &sigintAc, NULL) != 0) {
		printf("SIGINT error\n");
	
		// Exit peacefully
		exit(0);
	}

	while(1) {
		
		// Numerator and denominator
		int num, dem;

		// buffer
		char nums[100];

		// Prompt user to input an integer to be divided
		printf("Enter first integer: ");
		fgets(nums, 100, stdin);
		num = atoi(nums);

		// Prompt user to input an integer to divide by
		printf("Enter second integer: ");
		fgets(nums, 100, stdin);
		dem = atoi(nums);

		// Calculate quotient (int does whole number division
		int ans = num / dem;
		int rem = num % dem;

		// Print out quotient with remainder
		printf("%i / %i is %i with a remainder of %i\n", num, dem, ans, rem);
		
		// Count successful operations
		count++;

	}

	return 0;

}
