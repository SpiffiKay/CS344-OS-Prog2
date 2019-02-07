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
	char* dirname;	
	//create and initialize array for directory name
	dirname = malloc(20 * sizeof(char));
	memset(dirname, '\0', 20);
	//make new directory and generate files
	makeDirectory(dirname);
	//makeFile(dirname);

	//create room map

	//free allocated mem
	free(dirname);

	return 0;
}

/*********************************************************************************
 *Function: makeDirectory								 *
 * Description:  *
 ********************************************************************************/
void makeDirectory(char* name){
	int result, pid;
	//char* dirname;

	//create and initialize array
	//dirname = malloc(20 * sizeof(char));
	//memset(dirname, '\0', 20);
	
	//get pid and append to directory name
	pid = getpid();
	sprintf(name, "frieseti.rooms.%d", pid);

	//create directory
	result = mkdir(name, 0755);
	
	//return dirname;
}

/********************************************************************************
 *Function: makeFile								*
 * Description: *
 *******************************************************************************/
void makeFile(char* dirname){
	//int i=0;
	//char* rmnames[7];
	//memset(rmnames, '\0', 7);

	//initialize array of ptrs to room names
	//rmnames[0] = roomNames();
	//printf("in makeFile() %s\n", rmnames[0]);
	
		
}

/********************************************************************************
 *Function: *
 * Description: *
 *******************************************************************************/

void roomNames(){
}
