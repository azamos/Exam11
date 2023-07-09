#include "exam.h"

int* FromMatToArr(int matrix[][COLS], int rows, int cols, int* rsize)
{
	int* minimized = NULL;
	*rsize = 0;
	for (int i = 1; i < rows; i++) {/*instructions: there are no 1's in the first row*/
		//int onesInRow_i_counter = 0;
		for(int j = 1; j < cols; j++){/*there are no 1's in first column*/
			if (matrix[i][j] == 1) {
				int k = j;
				while (k < cols && matrix[i][k] == 1) {
					k++;
				}
				int* updated = (int*)realloc(minimized, (1 + *rsize) * sizeof(int));
				if (updated == NULL) {
					free(minimized);
					return NULL;
				}
				minimized = updated;
				minimized[*rsize] = 100 * i + 10 * j + 1 * (k-1);//315 = 3*100 + 10*1 + 1*5
				(*rsize)++;
				break;//Breaks from the j loop, thus ending this iteration of i, and checking for next row
			}
		}
	}
	return minimized;
}