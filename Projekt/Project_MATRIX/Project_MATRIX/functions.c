#include "Header.h"
/*
* Function: mainMenu
* Usage: mainMenu();
* --------------------------
* Introduction to the program with a main menu with 4 options.
*/
int mainMenu(void)
{
	int pick;
	system("cls");
	printf("\n ^ * - * < Welcome to the matrix game. > * - * ^\n\n");

	printf(" 1. The Magic Square Game \n");
	printf(" 2. Create your own magic square \n");
	printf(" 3. Load magic square from textfile \n");
	printf(" 4. Save your magic square to a textfile \n");
	printf(" 0. Quit \n");

	printf("\n What would you like to do? ");
	scanf_s("%d", &pick);
	return pick;
}
void menuDef()
{
	printf(" Incorrect input, please try again!");
	return;
}
void quit()
{
	return;
}
/*
* Function: magicSquareGame()
* Usage: magicSquareGame();
* --------------------------
* Shows a hexadecimal matrix and removes up to 8 squares
* to let the user input the correct ones and check if it is correct.
*/
void magicSquareGame(int arr[4][4])
{
	system("cls");
	int a, b, again;
	int tempMatrix[4][4] = {6,11,0,13,1,12,7,10,15,2,9,4,8,5,14,3};

	/* Gives the set values to the imported array */
	for (a = 0; a < 4; a++)
	{
		for (b = 0; b < 4; b++)
		{
				arr[a][b] = tempMatrix[a][b];
		}
	}

	do
	{
		system("cls");
		printf(" = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = \n");
		printf(" = = = = = = = = = = = = THE MAGIC SQUARE GAME = = = = = = = = = = = = \n");
		printf(" = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = \n");

		/* Removes a random amount between 0-8 of slots in the magic square */
		removeMatrixSlots(arr);

		/* Prints the modified matrix */
		for (a = 0; a < 4; a++)
		{
			for (b = 0; b < 4; b++)
			{
				if (arr[a][b] != 0)
					printf("\t %x \t", arr[a][b]);
				else
					printf("\t X \t");
			}
			printf("\n\n");
		}

		/* User to replace all the X's in the magic square */
		fillMatrix(arr);

		/* Check whether the filled in matrix is a magic square or not */
		checkMatrix(arr);

		printMatrix(arr);
		/* Asks the user depending on result in the magic square game */
		printf("\n Do you want to go again? Yes(1) / No (0): ");
		scanf_s("%d", &again);
		getchar();

	} while (again != 0);
}
/*
* Function: inputMatrix()
* Usage: inputMatrix();
* --------------------------
* Lets the user input hexadecimals into the matrix.
*/
void inputMatrix(int arr[4][4])
{
	int a, b, again;
	int inputs[16] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
	do
	{
		system("cls");
		printf(" = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = \n");
		printf(" = = = = = = = = = = CREATE YOUR OWN MAGIC SQUARE  = = = = = = = = = = \n");
		printf(" = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = \n\n");
		printf(" HINT: All rows/columns/diagonals shall have the same sum(30) when added together\n");
		printf(" HINT: All numbers between 0 and 15 must be used. See what you have left by looking at your previous row\n");
		for (a = 0; a < 4; a++)
		{
			printf("\n Enter a number between(0-15) in row: %d of your magic square: ", a + 1);

			for (b = 0; b < 4; b++)
			{
				scanf_s("%d", &arr[a][b]);
			}
		}
		system("cls");
		printf(" = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = \n");
		printf(" = = = = = = = = = = = = = YOUR MAGIC SQUARE = = = = = = = = = = = = = \n");
		printf(" = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = \n\n");
		for (a = 0; a < 4; a++)
		{
			for (b = 0; b < 4; b++)
			{
				printf("\t %x \t", arr[a][b]);
			}
			printf("\n\n");
		}

		checkMatrix(arr);

		//printMatrix(arr);

		printf("\n Do you want to go again? Yes(1) / No (0): ");
		scanf_s("%d", &again);
		getchar();

	} while (again != 0);
}
/*
* Function: loadMatrix()
* Usage: loadMatrix();
* --------------------------
* Loads a matrix from a textfile.
*/
void loadMatrix(int arr[4][4])
{
	system("cls");
	int a, b;
	FILE *infile;
	infile = fopen("hexkvadrater.txt", "r");
	if (infile == NULL)
		Error(" Can't open file!");

	for (a = 0; a < 4; a++)
	{
		for (b = 0; b < 4; b++)
			fscanf(infile, "%x\n", &arr[a][b]);
	}
	fclose(infile);

	printf(" = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = \n");
	printf(" = = = = = = = = = = = = IMPORTED MAGIC SQUARE = = = = = = = = = = = = \n");
	printf(" = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = \n\n");
	
	for (a = 0; a < 4; a++)
	{
		for (b = 0; b < 4; b++)
			printf("\t %x \t", arr[a][b]);
		printf("\n");
	}
	// checks whether the matrix is a magic square or not
	//checkMatrix(arr);
	printf("\n");
}
/*
* Function: saveMatrix()
* Usage: saveMatrix();
* --------------------------
* Saves the matrix into a textfile.
*/
void saveMatrix(int arr[4][4])
{
	FILE *outfile;
	fopen_s(&outfile, "savedmatrix.txt", "w");
	if (outfile == NULL)
		printf(" Can't open file!");

	printMatrix(arr);

	for (int a = 0; a < 4; a++)
	{
		for (int b = 0; b < 4; b++)
		{
			fprintf(outfile," %x ", arr[a][b]);
		}
		fprintf(outfile,"\n");
	}
	fclose(outfile);
	printf("\n Your latest matrix is now saved to file: savedmatrix.txt\n");
}
/*
* Function: removeMatrixSlots(int arr[4][4])
* Usage: removeMatrixSlots();
* --------------------------
* Randomizes a number between 0-8 and blanks out the squares.
*/
int removeMatrixSlots(int arr[4][4])
{
	int a, b, x, y, z, cBlanks;
	srand((int)time(NULL));

	printf("\n How many squares, between 1-8 would you like to remove? \n");
	scanf_s("%d", &cBlanks);

	for (z = 0; z < cBlanks; z++)
	{
		x = rand() % 4;
		y = rand() % 4;
		printf(" x: %d, y: %d \n", x, y);
		
		if (arr[x][y] = 0)
		{
			z--;
		}
		else
			arr[x][y] == 0;
	}
	printf("\n");
	return arr[x][y];
}
/*
* Function: fillMatrix(int arr[4][4])
* Usage: fillMatrix();
* --------------------------
* Lets the user fill in the randomized amount of X's in the magic square.
*/
int fillMatrix(int arr[4][4])
{
	int a, b;
	for (a = 0; a < 4; a++)
	{
		for (b = 0; b < 4; b++)
		{
			if (arr[a][b] == 0)
			{
				printf("\n Help me to replace the X in => (x, y): (%d.%d): ", a+1, b+1);
				scanf_s("%d", &arr[a][b]);
			}		
		}
	}
	printf("\n");
	return arr[a][b];
}
/*
* Function: magicSquareGen()
* Usage: magicSquareGen();
* --------------------------
* Attempt on generating a randomized magic square
*/
void magicSquareGen()
{
	int matrix[4][4], a, b;

	//fill array with values between 0 - 15
	for (a = 0; a < 4; a++)
	{
		for (b = 0; b < 4; b++)
		{
			matrix[a][b] = (4 * a) + b;
			printf(" %x", matrix[a][b]);
		}
	}
	printf("\n");
	/* Assigning corners first */
	/* Slot 1.1 */
	for (a = 0; a < 1; a++)
		for (b = 0; b < 1; b++)
			matrix[a][b] = 15 - matrix[a][b];
	printf(" 1.1: %x \n", matrix[a][b]);
	/* Slot 1.4 */
	for (a = 0; a < 4; a++)
		for (b = 3; b < 4; b++)
			matrix[a][b] = 15 - matrix[a][b];
	printf(" 1.4: %x \n", matrix[a][b]);
	/* Slot 4.1 */
	for (a = 3; a < 4; a++)
		for (b = 0; b < 1; b++)
			matrix[a][b] = 15 - matrix[a][b];
	printf(" 4.1: %x \n", matrix[a][b]);
	/* Slot 4.4 */
	for (a = 3; a < 4; a++)
		for (b = 3; b < 4; b++)
			matrix[a][b] = 15 - matrix[a][b];
	printf(" 4.4: %x \n", matrix[a][b]);
	/* Centre of matrix (2x2) */
	for (a = 1; a < 3; a++)
		for (b = 1; b < 3; b++)
			matrix[a][b] = 15 - matrix[a][b];
	/* Print magic square */
	for (a = 0; a < 4; a++)
	{
		for (b = 0; b < 4; b++)
			printf(" %3x \t", matrix[a][b]);
		printf("\n");
	}
	/* CHECK IF MAGIC SQUARE */
	checkMatrix(matrix);
}
/*
* Function: checkMatrix()
* Usage: checkMatrix();
* --------------------------
* Check whether the matrix is correct or not.
*/
void checkMatrix(int arr[4][4])
{
	int num = 15, rSum, cSum, dSum, a, b;

	/* Controll ROW */
	rSum = 0;
	for (a = 0; a < 1; a++)
	{
		for (b = 0; b < 4; b++)
		{
			rSum = rSum + arr[a][b];
		}
	}

	/* Controll COLUMN */
	cSum = 0;
	for (a = 0; a < 4; a++)
	{
		for (b = 0; b < 1; b++)
		{
			cSum = cSum + arr[a][b];
		}
	}

	/* Controll DIAGONAL */
	dSum = 0;
	for (a = 0; a < 4; a++)
	{
		for (b = 0; b < 4; b++)
		{
			if (a == b)
			{
				dSum = dSum + arr[a][b];
			}
		}
	}
	//printf("\n Row: %d, Column: %d, Diagonal: %d", rSum, cSum, dSum);

	if (rSum == dSum && rSum == cSum)
		printf("\n WELL DONE! You created a magic square!\n");
	else
		printf("\n Ooops! You did not create a magic square!\n");
		
}
/*
* Function: printMatrix()
* Usage: printMatrix();
* --------------------------
* Prints the 4x4 array of the inputted 2D array 
*/
void printMatrix(int arr[4][4])
{
	int a, b;
	for (a = 0; a < 4; a++)
	{
		for (b = 0; b < 4; b++)
			printf(" %x ", arr[a][b]);
		printf("\n");
	}
}