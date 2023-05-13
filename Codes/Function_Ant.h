/*	*******************		----- FUNCTIONS DECLARATION ----- *******************	*/



/*	*******************		Checking if there is an element in the Array 1D among the previous values		*******************	*/
unsigned int is_in(unsigned int, unsigned int *, unsigned int);
/*  **********************************************************************************************************************  */



/* 	*******************		Reading the Number of cities <=> N		*******************	*/
unsigned int read_number(char Data[]);
/*  *********************************************************************************** */



/* 	*******************		Reading Data from the file to 2D Array --> Distance		*******************	*/
void read_data(char Data[], unsigned int Temp_Array[]);
/*  *************************************************************************************************** */



/* 	*******************		Array Distance between cities is Symmetric 2D Array/Matrix with "0" on the diagonal		*******************	*/
void distance(unsigned int Temp_Array[], unsigned int N, unsigned int Distance[N][N]);
/*  *********************************************************************************************************************************** */



/*	*******************		Display an Array Distance	******************* */
void display_array_distance(FILE *, unsigned int N, char Data[], unsigned int Distance[N][N]);
/*  **********************************************************************  */



/*	*******************		Display an Array Closeness		******************* */
void display_array_closeness(FILE *, unsigned int N, float Closeness[N][N]);
/*  **************************************************************************  */



/*	*******************		Display an Array Pheromone before the start == EPOCH_0		******************* */
void display_array_pheromone (FILE *f, unsigned int N, float Pheromone[N][N]);
/*  ******************************************************************************************************* */