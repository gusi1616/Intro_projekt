/*
* Information about sourcedevelopment
* -----------------------------------
* Initial creator: Simon Gustafsson
* Date created: 2017-11-30
* Last updated by:
* Date for update:
*/

/*
* File:
* ------------------------
* This program gets two given cartesian coordinates from user and converts it to polar coordinates.
*/
#include "Header.h"

/* Main program */
int main(void)
{
	int mPick, matrix[4][4];
	do
	{
		mPick = mainMenu();
		{
			switch (mPick)
			{
				case 0: quit(); break;
				case 1: magicSquareGame(matrix); break;
				case 2: inputMatrix(matrix); break;
				case 3: loadMatrix(matrix); break;
				case 4: saveMatrix(matrix); break;
				default: menuDef();
			}
		}
		printf("\n");
		system("pause");
	} while (mPick != 0);

	return 0;
}
