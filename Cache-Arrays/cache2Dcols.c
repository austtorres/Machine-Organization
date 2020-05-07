////////////////////////////////////////////////////////////////////////////////
// Main File:        cache2Dcols.c
// This File:        cache2Dcols.c
// Other Files:      cache2Drows.c, cache1D.c, cache2Dclash.c
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

int arr2D[ROWS][COLS]; // 2D array of rows and columns

/* Have an inner loop iterate through the elements of a single column of the
 * array, and have the outer loop iterate through the columns of the array
 * (Column-wise)
 *
 * No parementers
 * No return
 */
int main(){
	for (int col = 0; col < COLS; col++){
		for (int row = 0; row < ROWS; row++){
			arr2D[row][col] = row + col;
		}
	}
}
