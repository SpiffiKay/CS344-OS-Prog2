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

void GetRooms(char*); 
void GetRecentDir(char*);
void GetFiles(char*);
void PlayGame();


/********************************************************************************
*Function: main									*
* Description: 									*
********************************************************************************/
int main(){
	//struct room* myrooms = (struct room*) malloc(7 * sizeof(struct room));
	char* dirname = calloc(25, sizeof(char));
	memset(dirname, '\0', 25);	//get rooms from files into array
	GetRooms(dirname);
	
	//free allocated mem
	//free(myrooms);
	free(dirname);

	return 0;
}

/********************************************************************************
*Function: GetRooms 								*
* Description: 									*
********************************************************************************/
void GetRooms(char* subdir){
	//find most recent game directory
	GetRecentDir(subdir);
	GetFiles(subdir);
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
void GetFiles(char* subdir){
	DIR* currdir;
	DIR* mydir;
	FILE* fname = NULL;
	char line[50];
	memset(line, '\0', 50);
	char info[11];
	memset(info, '\0', 11);
	char extra[11];
	memset(extra, '\0',11);
	char extra2[11];
	memset(extra2, '\0',11);
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
			PlayGame(subdir);
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
					
					
					//read lines from file
					while(fgets(line, 50, fname)!=NULL)
					{
						sscanf(line,"%s %s %s", extra, extra2, info);
						//printf("parsed: %s\n", info);
						
						if(strcmp(extra, "ROOM")==0 && strcmp(extra2, "NAME:")==0)
						{
						
						}
						else if(strcmp(extra, "CONNECTION")==0)
						{
							
						}
						else
						{
						
						}
						j = 0;
					}
					
					i++;
					
      				}		
    			}	

		}

	}
	//close directory
  	closedir(mydir);
	closedir(currdir);
	
}


