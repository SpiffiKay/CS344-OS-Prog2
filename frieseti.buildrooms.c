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
	char* rmname;
	//memset(rmname, '\0', 9);

	//set pointers in array to room names
	for(i; i < 7; i++)
	{
		switch (i)
		{
			case 0:
				rmname = "Utopia";
				printf("rmname for i=%d: %s\n", i, rmname);
				break;
			case 1:
				printf("case%d\n", i);
				break; 	
			case 2:
				printf("case%d\n", i);
				break; 
			case 3:
				printf("case%d\n", i);
				break; 	
			case 4:
				printf("case%d\n", i);
				break;
			case 5:
				printf("case%d\n", i);
				break; 	
			case 6:
				printf("case%d\n", i);
				break;
		}	
	
	}
	
}

