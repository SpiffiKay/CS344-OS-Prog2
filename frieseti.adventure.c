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
int ParseInput(char*, struct room*, int);
int IsEndRoom(struct room);
int GetStartRoom(struct room*);
void EndOfGame(int, char*);

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
	int i = 0, j = 0, id = 0, end = 0;
	char rmname[9]; //current room
	memset(rmname,'\0',9);
	char path[200]; //keeping path
	memset(path, '\0', 200);
	size_t bfsize = 50;
	char* buffer = (char *)malloc(bfsize * sizeof(char)); //input buffer
	memset(buffer, '\0', bfsize);
	
	do
	{
		//begin game with start room
		if(i == 0)	
			id = GetStartRoom(rooms);

		
		//interact with user	
		PrintToScreen(rooms[id]);
		getline(&buffer, &bfsize, stdin);
		id = ParseInput(buffer, rooms, id);

		//test if chosen room is end room
		end = IsEndRoom(rooms[id]);
		
		//keep path
		sprintf(rmname, "%s\n",rooms[id].name);
		strcat(path, rmname);
		

		i++; //step count
	}while(end == 0);

	//end of game prompt
	EndOfGame(i,path);

	//free alloc mem
	free(buffer);
}

/********************************************************************************
*Function: GetStartRoom 							*
* Description: 									*
********************************************************************************/
int GetStartRoom(struct room* rooms){
	int i = 0;
	for(i; i < 7; i++)
	{
		if(strcmp(rooms[i].rtype, "START_ROOM")==0)
			return i;
	}	
		
}

/********************************************************************************
*Function: PrintToScreen 							*
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

/********************************************************************************
*Function: ParseInput								*
* Description: 									*
********************************************************************************/
int ParseInput(char* input, struct room* rooms, int id){
	int valid = 0;
	char info[11];		//info wanted from line
	memset(info, '\0', 11);
	size_t bfsize = 50;
	char* buffer = (char *)malloc(bfsize * sizeof(char)); //input buffer
	memset(buffer, '\0', bfsize);
		
	
	do{
		sscanf(input,"%s", info);
	
		if(strcmp(rooms[0].name, info)==0)
			return 0;
		else if(strcmp(rooms[1].name, info)==0)
			return 1;
		else if(strcmp(rooms[2].name, info)==0)
			return 2;
		else if(strcmp(rooms[3].name, info)==0)
			return 3;
		else if(strcmp(rooms[4].name, info)==0)
			return 4;
		else if(strcmp(rooms[5].name, info)==0)
			return 5;
		else if(strcmp(rooms[6].name, info)==0)
			return 6;
		else if(strcmp(info, "time")==0)
		{
			
			printf("\nWHERE TO? >");
			valid = 1;
			getline(&buffer, &bfsize, stdin);
			input = buffer;
		}
		else
		{
			printf("\nHUH? I DON'T UNDERSTAND THAT ROOM. TRY AGAIN.\n\n");
			valid = 1;
			PrintToScreen(rooms[id]);
			getline(&buffer, &bfsize, stdin);
			input = buffer;
		}
	}
	while(valid == 1);
}


/********************************************************************************
*Function: IsEndRoom								*
* Description: 									*
********************************************************************************/
int IsEndRoom(struct room current){
	if(strcmp(current.rtype, "END_ROOM")==0)
		return 1;
	return 0;
}


void EndOfGame(int steps, char* path){
	printf("YOU HAVE FOUND THE END ROOM. CONGRATULATIONS!\n");
	printf("YOU TOOK %d STEPS. YOUR PATH TO VICTORY WAS:\n%s", steps, path);

}
