#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "Function_Ant.h"

/*	*******************		----- FUNCTIONS DEFINITION ----- *******************	*/



/*	*******************		Checking if there is an element in the Array among the previous values		*******************	*/
unsigned int is_in(unsigned int x, unsigned int a[], unsigned int length) {
	unsigned int flag = 0, i = 1;
	
	while ((i < length) && (flag != 1)) {
		if (a[i] == x)
			flag = 1;
		i++;
	}
	
	return flag;
} 
/*  **********************************************************************************************************************  */



/* 	*******************		Reading the Number of cities <=> N		*******************	*/
unsigned int read_number(char Data[]) {
	FILE *f;	
	f = fopen(Data, "r");
    if (f == NULL) {
	 	printf("Error to open file %s\n\n", Data);
	 	return EXIT_FAILURE;
	}
	
	/* The first element in the file in the number of cities */
	/* If we know this number, then after we know all the dimensions of all arrays */
	unsigned int i = 0, res;
	while ( !feof(f) && (i == 0) ) { 
		fscanf(f, "%d", &(res));
		i = 1;
	}
	fclose(f);

	return res;
}
/*  ************************************************************************************ */



/* 	*******************		Reading Data from the file to 2D Array --> Distance		*******************	*/
void read_data(char Data[], unsigned int Temp_Array[]) {
	FILE *f;	
	f = fopen(Data, "r");
    if (f == NULL) {
	 	/* printf("Error to open file %s\n\n", Data); */
	 	/* return EXIT_FAILURE; */
	}
	
	unsigned int i = 0, x;
	while ( !feof(f) && (i == 0) ) { 
		fscanf(f, "%d", &(x));
		i = 1;
	}
    /* Since the first element is the number of cities, we write this value into a variable "N" */

	unsigned int N = x;

    unsigned long int dimension = ((N - 1) * N) / 2;

    i = 1;
	while ( !feof(f) ) { 
		fscanf(f, "%d", &(Temp_Array[i]));
		i++;
	}
	fclose(f);

}	
/*  *************************************************************************************************** */



/* 	*******************		Array Distance between cities is Symmetric 2D Array/Matrix with "0" on the diagonal		*******************	*/
void distance(unsigned int Temp_Array[], unsigned int N, unsigned int Distance[N][N]) {

	unsigned int i, j, l = 1;

	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			if (i >= j) {
				Distance[i][j] = 0;
			}
			else {
				Distance[i][j] = Temp_Array[l];
				l++;
			}
		}
	}
	/* free(Temp_Array); */
	
	for (i = 2; i <= N; i++) {
		for (j = 1; j <= (i - 1); j++) {
			Distance[i][j] = Distance[j][i];
		}
	}	

}
/*  *********************************************************************************************************************************** */



/*	*******************		Display an Array Distance	******************* */
void display_array_distance(FILE *f, unsigned int N, char Data[], unsigned int Distance[N][N]) {
	unsigned int i, j;
	
	fprintf(f, " -------   We work with File : %s   -------\n\n", Data);
	fprintf(f, "Display an Array Distance between cities : \n\n");
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			fprintf(f, "%3d ", Distance[i][j]);
		}
		fprintf(f, "\n");
	}
	fprintf(f, "\n\n");	

}
/*  **********************************************************************  */



/*	*******************		Display an Array Closeness		******************* */
void display_array_closeness(FILE *f, unsigned int N, float Closeness[N][N]) {
	unsigned int i, j;
	
	fprintf(f, "Display an Array Closeness between cities : \n");
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			fprintf(f, "%.3f ", Closeness[i][j]);
		}
		fprintf(f, "\n");
	}
	fprintf(f, "\n\n");

}
/*  **************************************************************************  */



/*	*******************		Display an Array Pheromone before the start == EPOCH_0		******************* */
void display_array_pheromone (FILE *f, unsigned int N, float Pheromone[N][N]) {
	unsigned int i, j;

	fprintf(f, "Display an Array Pheromone before the start :\n");
	fprintf(f, "\n ------- Pheromone EPOCH 0 -------\n\n");
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			fprintf(f, "%.3f ", Pheromone[i][j]);
		}
		fprintf(f, "\n");
	}
	fprintf(f, "\n\n");	

}
/*  ******************************************************************************************************* */