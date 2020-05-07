////////////////////////////////////////////////////////////////////////////////
// Main File:        cache2Dclash.c
// This File:        cache2Dclash.c
// Other Files:      cache1D.c, cache2Drows.c, cache2Dcols.c
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
// Persons:          N/A
//                   
//
// Online sources:   N/A
//                  
//                   
//////////////////////////// 80 columns wide ///////////////////////////////////

#define ROWS 128 // Number of rows
#define COLS 8   // Number of columns

int arr2D[ROWS][COLS]; // 2D array of rows and columns

/* Innermost loop iterates over columns of array, middle loop iterates over the
 * rows incrementing by 64, NOT 1, and the outermost loop repeats this 100
 * times. As the array is traversed, each element is set to the sum of the 
 * three corresponding indexes
 */
int main(){
	for (int iteration = 0; iteration < 100; iteration++){
		for (int row = 0; row < ROWS; row += 64){
			for (int col = 0; col < COLS; col++){
				arr2D[row][col] = iteration + row + col;
			}
		}
	}
}
