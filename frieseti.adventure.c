/********************************************************************************
 * Title: frieseti.adventure.c                                                 *
 * Name: Tiffani Auer								*
 * Due: Feb 14, 2019								*
 *******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>

//room struct
struct room{
	int id;
	char* name;
	char* rtype;
	int cnct;
	struct room* outcncts;
};

void GetRooms(struct room*, char*); 
void GetRecentDir(char*);
void GetFiles(char*, struct room*);



/********************************************************************************
*Function: main									*
* Description: 									*
********************************************************************************/
int main(){
	struct room* myrooms = (struct room*) malloc(7 * sizeof(struct room));
	char* dirname = calloc(25, sizeof(char));
	memset(dirname, '\0', 25);
	//get rooms from files into array
	GetRooms(myrooms, dirname);

		

	//free allocated memory
	free(myrooms);
	free(dirname);
	return 0;
}
/********************************************************************************
*Function: MakeFile								*
* Description: Takes a pointer to the directory name as an arg, creates files in*
* said directory, then populates them with the room information.		*
********************************************************************************/
void MakeRoomFile(struct room* rooms, char* dname){
	int i = 0, j = 0;
	FILE *fname = NULL;
	char file[50];
	memset(file, '\0', 50);

	//create room files
	for(i; i < 7; i++)
	{
		//create file path
		sprintf(file, "%s/room_%s", dname, rooms[i].name);	

		//create file and check if opened
		fname = fopen(file, "w");
		if(fname == NULL)
		{
			fprintf(stderr, "Could not open %s\n", file);
			exit(1);
		}
		//write to file
		fprintf(fname, "ROOM NAME: %s\n", rooms[i].name);	
		for(j; j < rooms[i].cnct; j++)
		{
			fprintf(fname, "CONNECTION %d: %s\n",(j+1),rooms[i].outcncts[j].name);
		}
		fprintf(fname, "ROOM TYPE: %s\n", rooms[i].rtype);
		j = 0;
		
		//close file
		fclose(fname);
	}
}


/********************************************************************************
*Function: GetRooms 								*
* Description: 									*
********************************************************************************/
void GetRooms(struct room* rooms, char* subdir){
	//find most recent game directory
	GetRecentDir(subdir);
	printf("\nIN GetRooms subdir: %s\n\n", subdir);
	GetFiles(subdir, rooms);
}

/********************************************************************************
*Function: GetRecentDir 							*
* Description: 	Modded from 2.4 Manipulating Directories								*
********************************************************************************/
void GetRecentDir(char* subdir){
	int newTime = -1; // Modified timestamp of newest subdir examined
 	char *trgtPrfx = "frieseti.rooms."; // Prefix we're looking for
	char newDirName[25]; // Holds the name of the newest dir that contains prefix
	memset(newDirName, '\0', 25);
	DIR* dirToCheck; //current directory
 	struct dirent *fileInDir; // current subdir
 	struct stat dirAttrib; // Holds information we've gained about subdir

	//open and check if current directory is open
  	dirToCheck = opendir("."); 
  	if (dirToCheck > 0) 
  	{
    		//while there are files and directories to check
		while ((fileInDir = readdir(dirToCheck)) != NULL) 
    		{	
			//checks all subdirs with prefix for tiemstamp to find newest
      			if (strstr(fileInDir->d_name, trgtPrfx) != NULL)
    			{
        			stat(fileInDir->d_name, &dirAttrib); 

				//copies name of newest subdir
        			if ((int)dirAttrib.st_mtime > newTime) 
        			{				
         				 newTime = (int)dirAttrib.st_mtime;
        				 sprintf(newDirName, fileInDir->d_name);
				}		
      			}		
    		}
  	}

	//close directory
  	closedir(dirToCheck);
	//save current subdirectory to pointer passed in
	sprintf(subdir, newDirName);
}

/********************************************************************************
*Function: GetFiles 								*
* Description: 									*
********************************************************************************/
void GetFiles(char* subdir, struct room* rooms){
	DIR* currdir;
	DIR* mydir;
	FILE* fname = NULL;
	int i = 0, j = 0;
 	char *trgtPrfx = "room_";
	char newfile[30]; 
	memset(newfile, '\0', 30);
 	struct dirent *fileInDir; // current subdir
 



	//open and check if current directory is open
  	currdir = opendir("."); 
  	if (currdir > 0) 
  	{
		//open and check if subdirectory is open
		mydir = opendir(subdir);
		if (mydir > 0)
		{
			printf("opened the subdir!\n");
			//while there are files and directories to check
			while ((fileInDir = readdir(mydir)) != NULL) 
    			{	
				//checks all subdirs with prefix for tiemstamp 
      				if (strstr(fileInDir->d_name, trgtPrfx) != NULL)
    				{
        				//file name
					sprintf(newfile, "%s/%s", subdir, fileInDir->d_name);
					printf("file found: %s\n", newfile);
		
					//open file and check that it opened
					fname = fopen(newfile, "r");
					if(fname == NULL)
					{
						printf("\nerror!\n");
						exit(1);
					}
					
					//read from 						
      				}		
    			}	

		}

	}
	//close directory
  	closedir(mydir);
	closedir(currdir);
	
}
