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
#include <fcntl.h>

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
	int file_descriptor, i=0;
	char* rmname;
	char file[20] ;
	memset(file, '\0', 20);
		
	//create room files
	for(i; i < 10; i++)
	{
		memset(file, '\0', 20);
		
		//roomnames
		switch (i)
		{
			case 0:
				rmname = "Utopia";
				break;
			case 1:
				rmname = "Notopia";
				break; 	
			case 2:
				rmname = "Youtopia";
				break; 
			case 3:
				rmname = "Mehtopia";
				break; 	
			case 4:
				rmname = "Cattopia";
				break;
			case 5:
				rmname = "Dogtopia";
				break; 	
			case 6:
				rmname = "Bottopia";
				break;
			case 7:
				rmname = "Dietopia";
				break;
			case 8:
				rmname = "Mootopia";	
				break; 	
			case 9:
				rmname = "Vimtopia";
				break;	
		}
		
		sprintf(file, "%s/%s", dname, rmname);
		//printf("file:%s\n", file);	

		file_descriptor = open(file, O_WRONLY | O_CREAT, 0600);
		
		if(file_descriptor < 0)
		{
			//fprintf(stderr, "Could not open %s\n", file);
			printf("Could not open %s\n", file);
			exit(1);
		}
	

	}
	
}

