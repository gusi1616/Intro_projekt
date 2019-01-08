#pragma once
/*
* File: Header.h
* ------------------------
* Provides toools for ...
*/

#ifndef _Header_h
#define _Header_h

/* Include files necessary for the headerfile */
//#include <yyy.h>
#include "genlib.h"
#include "simpio.h"

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>

/*
* Constants
* ---------
* Defines ...
*/

#define TRUE 1

/*
* Typedefinitions
* ---------
* Description ...
*/
typedef char *string;

/* Function prototypes */

/* Menu functions */
int mainMenu(void);
void menuDef();

/* Main menu functions */

void magicSquareGame(int arr[4][4]);	// Option 1: To play a game of missing hexadecimals in a 4x4 matrix
void inputMatrix(int arr[4][4]);		// Option 2: Lets the user input their own 4x4 magic square
void loadMatrix(int arr[4][4]);		// Option 3: Loads a 4x4 matrix and checks whether it is a magic square or not
void saveMatrix(int arr[4][4]);		// Option 4: Saves a matrix to a textfile (string text, string fileName)
void quit();			// Option 0: Exits the program

/* math functions */

void magicSquareGen();						 // An attempt on generating a random magic square
void checkMatrix(int arr[4][4]);	 // checks whether the array is a magic square or not
int removeMatrixSlots(int arr[4][4]);		 // Removes a numer(random between 1-8) and replace it by 'X'
int fillMatrix(int arr[4][4]);				 // Lets the user replace the 'X' in the game matrix
void printMatrix(int arr[4][4]);

#endif
