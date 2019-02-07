/********************************************************************************
 * Title: frieseti.buildrooms.c                                                 *
 * Name: Tiffani Auer								*
 * Due: Feb 14, 2019								*
 * Description: *
 *******************************************************************************/

/********************************************************************************
 *Function: *
 * Description: *
 *******************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>

void makeDirectory();
/*********************************************************************************
 *Function: main								 *
 * Description:  *
 ********************************************************************************/
int main(){
	
	//make new directory
	makeDirectory();

	//generate room files in directory

	return 0;
}

/*********************************************************************************
 *Function: makeDirectory								 *
 * Description:  *
 ********************************************************************************/
void makeDirectory(){
	int result, pid, i = 0;
	char dirname[20];

	//initialize array
	memset(dirname, '\0', 20);

	//get pid and append to directory name
	pid = getpid();
	sprintf(dirname, "frieseti.rooms.%d", pid);

	//create directory
	result = mkdir(dirname, 0755);
}
