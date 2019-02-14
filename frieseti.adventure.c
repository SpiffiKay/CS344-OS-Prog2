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
	char (*cnctnames)[9];
};

void GetRooms(char*, struct room*); 
void GetRecentDir(char*, struct room*);
void GetFiles(char*, struct room*);
void PlayGame(struct room*);
void PrintToScreen(struct room);

/********************************************************************************
*Function: main									*
* Description: 									*
********************************************************************************/
int main(){
	struct room* myrooms = (struct room*) malloc(7 * sizeof(struct room));
	char* dirname = calloc(25, sizeof(char));
	memset(dirname, '\0', 25);	//get rooms from files into array
	
	//create room structs
	struct room rm0;
	rm0.id = 0;
	rm0.name = calloc(9, sizeof(char));
	memset(rm0.name, '\0', 9);
	rm0.rtype = calloc(11, sizeof(char));
	memset(rm0.rtype, '\0', 11);
	rm0.cnct = 0;
	rm0.outcncts = (struct room*) malloc(6 * sizeof(struct room));
	memset(rm0.outcncts, '\0', 6);
	rm0.cnctnames = malloc(6 * 9 * sizeof(char));
	memset(rm0.cnctnames, '\0', sizeof(char[0][0]) * 6 * 9);
	myrooms[0] = rm0;

	struct room rm1;
	rm1.id = 1;
	rm1.name = calloc(9, sizeof(char));
	memset(rm1.name, '\0', 9);
	rm1.rtype = calloc(11, sizeof(char));
	memset(rm1.rtype, '\0', 11);
	rm1.cnct = 0;
	rm1.outcncts = (struct room*) malloc(6 * sizeof(struct room));
	memset(rm1.outcncts, '\0', 6);
	rm1.cnctnames = malloc(6 * 9 * sizeof(char));
	memset(rm1.cnctnames, '\0', sizeof(char[0][0]) * 6 * 9);
	myrooms[1] = rm1;

	struct room rm2;
	rm2.id = 2;
	rm2.name = calloc(9, sizeof(char));
	memset(rm2.name, '\0', 9);
	rm2.rtype = calloc(11, sizeof(char));
	memset(rm2.rtype, '\0', 11);
	rm2.cnct = 0;
	rm2.outcncts = (struct room*) malloc(6 * sizeof(struct room));
	memset(rm2.outcncts, '\0', 6);
	rm2.cnctnames = malloc(6 * 9 * sizeof(char));
	memset(rm2.cnctnames, '\0', sizeof(char[0][0]) * 6 * 9);
	myrooms[2] = rm2;

	struct room rm3;
	rm3.id = 3;
	rm3.name = calloc(9, sizeof(char));
	memset(rm3.name, '\0', 9);
	rm3.rtype = calloc(11, sizeof(char));
	memset(rm3.rtype, '\0', 11);
	rm3.cnct = 0;
	rm3.outcncts = (struct room*) malloc(6 * sizeof(struct room));
	memset(rm3.outcncts, '\0', 6);
	rm3.cnctnames = malloc(6 * 9 * sizeof(char));
	memset(rm3.cnctnames, '\0', sizeof(char[0][0]) * 6 * 9);
	myrooms[3] = rm3;

	struct room rm4;
	rm4.id = 4;
	rm4.name = calloc(9, sizeof(char));
	memset(rm4.name, '\0', 9);
	rm4.rtype = calloc(11, sizeof(char));
	memset(rm4.rtype, '\0', 11);
	rm4.cnct = 0;
	rm4.outcncts = (struct room*) malloc(6 * sizeof(struct room));
	memset(rm4.outcncts, '\0', 6);
	rm4.cnctnames = malloc(6 * 9 * sizeof(char));
	memset(rm4.cnctnames, '\0', sizeof(char[0][0]) * 6 * 9);
	myrooms[4] = rm4;

	struct room rm5;
	rm5.id = 5;
	rm5.name = calloc(9, sizeof(char));
	memset(rm5.name, '\0', 9);
	rm5.rtype = calloc(11, sizeof(char));
	memset(rm5.rtype, '\0', 11);
	rm5.cnct = 0;
	rm5.outcncts = (struct room*) malloc(6 * sizeof(struct room));
	memset(rm5.outcncts, '\0', 6);
	rm5.cnctnames = malloc(6 * 9 * sizeof(char));
	memset(rm5.cnctnames, '\0', sizeof(char[0][0]) * 6 * 9);
	myrooms[5] = rm5;

	struct room rm6;
	rm6.id = 6;
	rm6.name = calloc(9, sizeof(char));
	memset(rm6.name, '\0', 9);
	rm6.rtype = calloc(11, sizeof(char));
	memset(rm6.rtype, '\0', 11);
	rm6.cnct = 0;
	rm6.outcncts = (struct room*) malloc(6 * sizeof(struct room));
	memset(rm6.outcncts, '\0', 6);
	rm6.cnctnames = malloc(6 * 9 * sizeof(char));
	memset(rm6.cnctnames, '\0', sizeof(char[0][0]) * 6 * 9);
	myrooms[6] = rm6;

	//Get room info from files
	GetRooms(dirname, myrooms);
	
	//Play Game
	PlayGame(myrooms);

	//free allocated mem
	free(rm0.name);
	free(rm1.name);
	free(rm2.name);
	free(rm3.name);
	free(rm4.name);
	free(rm5.name);
	free(rm6.name);
	free(rm0.outcncts);
	free(rm1.outcncts);
	free(rm2.outcncts);
	free(rm3.outcncts);
	free(rm4.outcncts);
	free(rm5.outcncts);
	free(rm6.outcncts);
	free(rm0.rtype);
	free(rm1.rtype);
	free(rm2.rtype);
	free(rm3.rtype);
	free(rm4.rtype);
	free(rm5.rtype);
	free(rm6.rtype);
	free(rm0.cnctnames);
	free(rm1.cnctnames);
	free(rm2.cnctnames);
	free(rm3.cnctnames);
	free(rm4.cnctnames);
	free(rm5.cnctnames);
	free(rm6.cnctnames);
	free(myrooms);
	free(dirname);

	return 0;
}

/********************************************************************************
*Function: GetRooms 								*
* Description: 									*
********************************************************************************/
void GetRooms(char* subdir, struct room* rooms){
	//find most recent game directory
	GetRecentDir(subdir, rooms);
	GetFiles(subdir, rooms);
}

/********************************************************************************
*Function: GetRecentDir 							*
* Description: 	Modded from 2.4 Manipulating Directories								*
********************************************************************************/
void GetRecentDir(char* subdir, struct room* rooms){
	int newTime = -1; // newest subdir examined timestamp
 	char *trgtPrfx = "frieseti.rooms."; // subdir prefix searching for
	char newDirName[25]; // newest dir with prefix
	memset(newDirName, '\0', 25);
	DIR* dirToCheck; //current directory
 	struct dirent *fileInDir; // current subdir
 	struct stat dirAttrib; // dir info

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
	DIR* currdir;	//current dir
	DIR* mydir;	//current subdir
	FILE* fname = NULL;	//filename
	char line[50];		//file line to parse
	memset(line, '\0', 50);	
	char info[11];		//info wanted from line
	memset(info, '\0', 11);
	char extra[11];		//extra info from line
	memset(extra, '\0',11);
	char extra2[11];	//extra info from line
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
			//while there are files and directories to check
			while ((fileInDir = readdir(mydir)) != NULL) 
  			{	
				//checks all subdirs with prefix for tiemstamp 
     				if (strstr(fileInDir->d_name, trgtPrfx) != NULL)
 				{
        				//file name
					sprintf(newfile, "%s/%s", subdir, fileInDir->d_name);
					//printf("file found: %s\n", newfile);
		
					//open file and check that it opened
					fname = fopen(newfile, "r");
					if(fname == NULL)
					{
						printf("File not found!\n");
						exit(1);
					}
								
					//read lines from file
					while(fgets(line, 50, fname)!=NULL)
					{	//parse file information
						sscanf(line,"%s %s %s", extra, extra2, info);

						//room name
						if(strcmp(extra, "ROOM")==0 && strcmp(extra2, "NAME:")==0)
						{
							sprintf(rooms[i].name, info);
							//printf("rooms[%d].name: %s\n",i,rooms[i].name);
						}
						//connections
						else if(strcmp(extra, "CONNECTION")==0)
						{
							sprintf(rooms[i].cnctnames[j], info);
							//printf("rooms[%d].cnctnames[%d]: %s\n", i, j, info);
							j++;
						}
						//room types
						else
						{
							sprintf(rooms[i].rtype, info);
							//printf("rooms[%d].rtype: %s\n",i,info);
						}
					}
					//number of connections
					rooms[i].cnct = j;
					//printf("rooms[%d].cncts: %d\n\n",i,rooms[i].cnct);
					j = 0;
					i++;
					fclose(fname);
      				}		
    			}	
		}
	}
	//close directories
  	closedir(mydir);
	closedir(currdir);	
}

/********************************************************************************
*Function: PlayGame 								*
* Description: 									*
********************************************************************************/
void PlayGame(struct room* rooms){
	int i = 0, j = 0, id = 0;
	char rmname[9]; //current room
	memset(rmname,'\0',9);
	char response[20];
	memset(response, '\0', 20);

	//begin game
	if(i == 0)
	{
		for(j; j < 7; j++)
		{
			if(strcmp(rooms[j].rtype, "START_ROOM")==0)
			{	
			
				//sprintf(rmname, rooms[j].name);
				printf("rooms[%d].rtype: %s %s\n", j, rooms[j].rtype, rmname);
				id = j;
				break;
			}
		}	
	
	
	}				switch (id)
			{
				case 0:
					PrintToScreen(rooms[0]);
					break;
				case 1:
					PrintToScreen(rooms[1]);
					break; 	
				case 2:
					PrintToScreen(rooms[2]);
					break; 
				case 3:
					PrintToScreen(rooms[3]);
					break; 	
				case 4:
					PrintToScreen(rooms[4]);
					break;
				case 5:
					PrintToScreen(rooms[5]);
					break; 	
				case 6:
					PrintToScreen(rooms[6]);
					break;
			}
	
	

	



}


/********************************************************************************
*Function: PrintToScreen 								*
* Description: 									*
********************************************************************************/
void PrintToScreen(struct room current){
	int i = 0;
	//start prompts
	printf("CURRENT LOCATION: %s\nPOSSIBLE CONNECTIONS:", current.name);
	//loop through connections
	for(i; i < current.cnct; i++)
	{
		if(i+1 != current.cnct)
			printf(" %s,", current.cnctnames[i]);
		else
			printf(" %s.\n", current.cnctnames[i]);
	}
        //prompt
	printf("WHERE TO? >");
}
