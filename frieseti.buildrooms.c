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
	char* roomType;
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

	//create room structs
	struct room utopia;
	utopia.id = 0;
	utopia.name = calloc(9, sizeof(char));
	strcpy(utopia.name, "Utopia");
	
	printf("Struct's name and id: %s %d\n", utopia.name, utopia.id);

	struct room notopia;
	notopia.id = 1;
	notopia.name = calloc(9, sizeof(char));
	strcpy(notopia.name, "NoTopia");
	
	printf("Struct's name and id: %s %d\n", notopia.name, notopia.id);

	struct room youtopia;
	youtopia.id = 2;
	youtopia.name = calloc(9, sizeof(char));
	strcpy(youtopia.name, "YouTopia");
	
	printf("Struct's name and id: %s %d\n", youtopia.name, youtopia.id);

	struct room mehtopia;
	mehtopia.id = 3;
	mehtopia.name = calloc(9, sizeof(char));
	strcpy(mehtopia.name, "MehTopia");
	
	printf("Struct's name and id: %s %d\n", mehtopia.name, mehtopia.id);

	struct room cattopia;
	cattopia.id = 4;
	cattopia.name = calloc(9, sizeof(char));
	strcpy(cattopia.name, "CatTopia");
	
	printf("Struct's name and id: %s %d\n", cattopia.name, cattopia.id);

	struct room dogtopia;
	dogtopia.id = 5;
	dogtopia.name = calloc(9, sizeof(char));
	strcpy(dogtopia.name, "DogTopia");
	
	printf("Struct's name and id: %s %d\n", dogtopia.name, dogtopia.id);

	struct room bottopia;
	bottopia.id = 6;
	bottopia.name = calloc(9, sizeof(char));
	strcpy(bottopia.name, "BotTopia");
	
	printf("Struct's name and id: %s %d\n", bottopia.name, bottopia.id);

	struct room dietopia;
	dietopia.id = 7;
	dietopia.name = calloc(9, sizeof(char));
	strcpy(dietopia.name, "DieTopia");
	
	printf("Struct's name and id: %s %d\n", dietopia.name, dietopia.id);

	struct room mootopia;
	mootopia.id = 8;
	mootopia.name = calloc(9, sizeof(char));
	strcpy(mootopia.name, "MooTopia");
	
	printf("Struct's name and id: %s %d\n", mootopia.name, mootopia.id);

	struct room vimtopia;
	vimtopia.id = 9;
	vimtopia.name = calloc(9, sizeof(char));
	strcpy(vimtopia.name, "VimTopia");
	
	printf("Struct's name and id: %s %d\n", vimtopia.name, vimtopia.id);



	//create room map

	//free allocated mem
	free(utopia.name);
	free(notopia.name);
	free(youtopia.name);
	free(mehtopia.name);
	free(cattopia.name);
	free(dogtopia.name);
	free(bottopia.name);
	free(dietopia.name);
	free(mootopia.name);
	free(vimtopia.name);



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
 * Description: Takes a pointer to the directory name as an arg, then creates   *
 * files in said directory.
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

