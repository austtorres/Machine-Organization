////////////////////////////////////////////////////////////////////////////////
// Main File:        intdate.c
// This File: 	     intdate.c
// Other Files:      sendsig.c, division.c
// Semester: 	     CS 354 Fall 2019
//
// Author: 	     Austin Torres
// Email: 	     artorres3@wisc.edu
// CS Login: 	     atorres
//
/////////////////////////// OTHER SOURCES OF HELP //////////////////////////////
// 		     fully acknowledge and credit all sources of help,
// 		     other than Instructors and TAs.
//
// Persons: N/A
//
// Online sources: Computer Systems: A Programmer's Perspective Chapter 8
// 		   Exceptional Control Flow
//
//		   Using time in C
//		   https://en.wikibooks.org/wiki/C_Programming/time.h/time_t
//
//		   ctime
//		   https://en.cppreference.com/w/cpp/header/ctime
//
////////////////////////////////////////////////////////////////////////////////

#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

int globaltime = 3; // strong global symbol: alarm time
int count = 0; // strong global symbol: SIGUSR1 count

/**
  * Prints pid and time every 3 seconds. Handles SIGUSR1 by keeping a count of
  * the number of SIGUSR1 instances. Handles SIGINT by ending process and 
  * displaying the number of times that SIGUSR1 was caught while running
  */


/** 
  * Handles SIGALRM and prints alarm message
  */
void sigalrmHandler() {
	time_t currTime;
	time(&currTime);

	// Print message according to assignment specifications
	printf("PID: %d", getpid());
	printf(" | Current Time: %s", ctime(&currTime));

	if(alarm(globaltime) != 0) {
		printf("Error when setting up alarm\n");
		exit(0);
	}
}

/**
  * Handles SIGINT by printing how many times SIGUSR1 was caught, then exits
*/
void sigintHandler(){
	printf("\nSIGINT received.\n");
	printf("SIGUSR1 was received %i times. Exiting now.\n", count);
	exit(0);
}

/**
  * Handles SIGUSR1 by printing message stating SIGUSR1 was received. Then,
  * maintains counter
  */
void sigusr1Handler() {
	printf("SIGUSR1 caught!\n");
	count++;
}

/**
  * Main function sets up handlers and produces the alarm in an infinite loop
  * until SIGINT received
  */
int main(int argc, char *argv[]) {

	// Print messages according to assignment specifications
	printf("Pid and time will be printed every 3 seconds.\n");
	printf("Enter ^C to end the program.\n");

	if(alarm(3) != 0) {
		printf("Error occurred when starting alarm process.\n");
	}

	//SIGALRM handler
	struct sigaction alrmAct;

	// sigaction initialized to 0 before use
	memset(&alrmAct, 0, sizeof(alrmAct));

	alrmAct.sa_handler = sigalrmHandler;

	// Handle error conditions
	if(sigaction(SIGALRM, &alrmAct, NULL) != 0) {
		printf("Error with SIGALRM sigaction() call.");
		exit(0);
	}

	//SIGUSR1 handler
	struct sigaction usrAct;

	// sigaction initialized to 0 before use
	memset(&usrAct, 0, sizeof(usrAct));

	usrAct.sa_handler = sigusr1Handler;

	// Handle error conditions
	if(sigaction(SIGUSR1, &usrAct, NULL) != 0) {
		printf("Error with SIGUSR1 sigaction() call\n");
		exit(0);
	}

	//SIGINT handler
	struct sigaction sigintAct;

	// sigaction initialized to 0 before use
	memset(&sigintAct, 0, sizeof(sigintAct));

	sigintAct.sa_handler = sigintHandler;

	// Handle errors conditions 
	if(sigaction(SIGINT, &sigintAct, NULL) != 0) {
		printf("Error with SIGINT sigaction() call.\n");
		exit(0);
	}
	
	// Infinite loop
	while(1) {
	}

	return 0;
}
