////////////////////////////////////////////////////////////////////////////////
// Main File:        cache2Drows.c
// This File:        cache2Drows.c
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

#define ROWS 3000 // Number of rows
#define COLS 500  // Number of columns

int arr2D[ROWS][COLS]; // Global array of rows and columns

/* Have an inner loop iterate through the elements of a single row of the array
 * and have an outer loop iterate through the rows of the array. As the array
 * is traversed, set each element of the array to the sum of its row and col
 * indexes.
 *
 * No parameter
 * No return
 */
int main(){

	for(int row = 0; row < ROWS; row++){

		for (int col = 0; col < COLS; col++){
			arr2D[row][col] = row + col;
		}
	}
}
