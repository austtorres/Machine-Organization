////////////////////////////////////////////////////////////////////////////////
// Main File:        cache1D.c
// This File:        cache1D.c
// Other Files:      cache2Drows.c, cache2Dcols.c, cache2Dclash.c
// Semester:         Fall 2019
//
// Author:           Austin Torres
// Email:            artorres3@wisc.edu
// CS Login:         atorres
//
/////////////////////////// OTHER SOURCES OF HELP //////////////////////////////
//                   fully acknowledge and credit all sources of help,
//                   other than Instructors and TAs.
//
// Persons:          N/A
//                   
//
// Online sources:   N/A
//                    
//                   
//////////////////////////// 80 columns wide ///////////////////////////////////

#define SIZE 100000 // Size of array

int arr[SIZE]; // Array of size 100,000

/*
* Iterate over the entire array and set the value of each element in the array
* to its index
*
* No parameter
* No return
*/
int main(){
	for (int i = 0; i < SIZE; i++){
		arr[i] = i;
	}
}
