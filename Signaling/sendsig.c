//////////////////////////////////////////////////////////////////////////////
   // Main File:        intdate.c
   // This File:        sendsig.c
   // Other Files:      sendsig.c, division.c
   // Semester:         CS 354 Fall 2019
   //
   // Author:           Austin Torres
   // Email:            artorres3@wisc.edu
   // CS Login:         atorres
  //
  /////////////////////////// OTHER SOURCES OF HELP //////////////////////////////
  //                   fully acknowledge and credit all sources of help,
  //                   other than Instructors and TAs.
  //
  // Persons: N/A
  //
  // Online sources: Computer Systems: A Programmer's Perspective Chapter 8
  //                 Exceptional Control Flow
 //
  //                 Using time in C
  //                 https://en.wikibooks.org/wiki/C_Programming/time.h/time_t
  //
  //                 ctime
  //                 https://en.cppreference.com/w/cpp/header/ctime
  //
  ////////////////////////////////////////////////////////////////////////////////

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

/**
  * Sends a signal to another process
  */

int main(int argc, char *argv[]) {

	// Make sure user inputs correct usage
	if (argc != 3) {
		printf("Usage: <signal type> <pid>\n");
		exit(0);
	}

	pid_t pid = atoi(argv[2]);

	// For sending SIGUSR1 signal, -u must be argument 1
	int uString = strcmp("-u", argv[1]);

	// For sending SIGINT signal, -i must be argument 1
	int uInt = strcmp("-i", argv[1]);

	// Send signals to process at pid
	if (uString == 0) {
		kill(pid, SIGUSR1);
	}
	if(uInt == 0) {
		kill(pid, SIGINT);
	}

}
