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

void makeDirectory(char*);
void makeFile(char*);
void roomNames();

//room struct
struct room {
	int id;
	char* name;
	int numConnect;
	struct room* outConnections[6];
};

/*********************************************************************************
 *Function: main								 *
 * Description:  *
 ********************************************************************************/
int main(){
	char dirname[20];	
	memset(dirname, '\0', 20);

	//make new directory and generate files
	makeDirectory(dirname);
	makeFile(dirname);

	//create room map

	//free allocated mem
	//free(dirname);

	return 0;
}

/*********************************************************************************
 *Function: makeDirectory								 *
 * Description: Takes a char pointer as an arg, and sets it to point to the new  *
 * directory name, then creates that directory.
 ********************************************************************************/
void makeDirectory(char* name){
	int pid;

	//get pid and append to directory name
	pid = getpid();
	sprintf(name, "frieseti.rooms.%d", pid);

	//create directory
	mkdir(name, 0755);
}

/********************************************************************************
 *Function: makeFile								*
 * Description: *
 *******************************************************************************/
void makeFile(char* dname){
	int i=0;
	char* rmnames[7];
	memset(rmnames, '\0', 7);

	//initialize array of ptrs to room names
	//rmnames[0] = roomNames();
	
		
}

/********************************************************************************
 *Function: *
 * Description: *
 *******************************************************************************/

void roomNames(int i){
}
