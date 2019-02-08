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
#include <time.h>

void MakeDirectory(char*);
void MakeFile(char*);
struct room AssignRoomName(struct room, int arr[]);


//room struct
struct room {
	int id;
	char* name;
	int numConnect;
	char* roomType;
	struct room* outConnections[6];
};

/*********************************************************************************
 *Function: main								 *
 * Description:  *
 ********************************************************************************/
int main(){
	char dirname[20];	
	int usednames[7];
	memset(dirname, '\0', 20);

	//seed rand
	srand(time(NULL));

	//create room structs
	struct room rm0;
	rm0.id = 0;
	rm0.name = calloc(9, sizeof(char));
	memset(rm0.name, '\0', 9);
	rm0 = AssignRoomName(rm0, usednames);
	printf("rm0 name: %s\n", rm0.name);

	struct room rm1;
	rm1.id = 1;
	rm1.name = calloc(9, sizeof(char));
	memset(rm1.name, '\0', 9);
	rm1 = AssignRoomName(rm1, usednames);
	printf("rm1 name: %s\n", rm1.name);

	struct room rm2;
	rm2.id = 2;
	rm2.name = calloc(9, sizeof(char));
	memset(rm2.name, '\0', 9);
	rm2 = AssignRoomName(rm2, usednames);
	printf("rm2 name: %s\n", rm2.name);

	struct room rm3;
	rm3.id = 3;
	rm3.name = calloc(9, sizeof(char));
	memset(rm3.name, '\0', 9);
	rm3 = AssignRoomName(rm3, usednames);
	printf("rm3 name: %s\n", rm3.name);

	struct room rm4;
	rm4.id = 4;
	rm4.name = calloc(9, sizeof(char));
	memset(rm4.name, '\0', 9);
	rm4 = AssignRoomName(rm4, usednames);
	printf("rm4 name: %s\n", rm4.name);

	struct room rm5;
	rm5.id = 5;
	rm5.name = calloc(9, sizeof(char));
	memset(rm5.name, '\0', 9);
	rm5 = AssignRoomName(rm5, usednames);
	printf("rm5 name: %s\n", rm5.name);

	struct room rm6;
	rm6.id = 6;
	rm6.name = calloc(9, sizeof(char));
	memset(rm6.name, '\0', 9);
	rm6 = AssignRoomName(rm6, usednames);
	printf("rm6 name: %s\n", rm6.name);



	//make game graph
	

	//make new directory and generate files
	//MakeDirectory(dirname);
	//MakeFile(dirname);

	//free allocated mem
	free(rm0.name);
	free(rm1.name);
	free(rm2.name);
	free(rm3.name);
	free(rm4.name);
	free(rm5.name);
	free(rm6.name);

	return 0;
}

/*********************************************************************************
 *Function: MakeDirectory								 *
 * Description: Takes a char pointer as an arg, and sets it to point to the new  *
 * directory name, then creates that directory.
 ********************************************************************************/
void MakeDirectory(char* name){
	int pid;

	//get pid and append to directory name
	pid = getpid();
	sprintf(name, "frieseti.rooms.%d", pid);

	//create directory
	mkdir(name, 0755);
}

/********************************************************************************
 *Function: MakeFile								*
 * Description: Takes a pointer to the directory name as an arg, then creates   *
 * files in said directory.
 *******************************************************************************/
void MakeFile(char* dname){
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
				rmname = "utopia";
				break;
			case 1:
				rmname = "notopia";
				break; 	
			case 2:
				rmname = "youtopia";
				break; 
			case 3:
				rmname = "mehtopia";
				break; 	
			case 4:
				rmname = "cattopia";
				break;
			case 5:
				rmname = "dogtopia";
				break; 	
			case 6:
				rmname = "bottopia";
				break;
			case 7:
				rmname = "dietopia";
				break;
			case 8:
				rmname = "mootopia";	
				break; 	
			case 9:
				rmname = "vimtopia";
				break;	
		}
		
		//create file path
		sprintf(file, "%s/%s", dname, rmname);	

		//create files
		file_descriptor = open(file, O_WRONLY | O_CREAT, 0600);
		if(file_descriptor < 0)
		{
			//fprintf(stderr, "Could not open %s\n", file);
			printf("Could not open %s\n", file);
			exit(1);
		}
	}
}

/********************************************************************************
 *Function: AssignRoomName							*
 * Description: *
 *******************************************************************************/
struct room AssignRoomName(struct room blank, int assigned[]){
	struct room newname = blank;
	int i = 0;
	
	i = rand() % 10;
	
	
	switch (i)
	{
		case 0:
			sprintf(newname.name, "Utopia");
			break;
		case 1:
			sprintf(newname.name, "NoTopia");
			break; 	
		case 2:
			sprintf(newname.name, "YouTopia");
			break; 
		case 3:
			sprintf(newname.name, "MehTopia");
			break; 	
		case 4:
			sprintf(newname.name, "CatTopia");
			break;
		case 5:
			sprintf(newname.name, "DogTopia");
			break; 	
		case 6:
			sprintf(newname.name, "BotTopia");
			break;
		case 7:
			sprintf(newname.name, "DieTopia");
			break;
		case 8:
			sprintf(newname.name, "MooTopia");	
			break; 	
		case 9:
			sprintf(newname.name, "VimTopia");
			break;	
	}
	return newname;
}

