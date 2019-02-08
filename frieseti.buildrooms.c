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
void AddRandomConnection(struct room* arr[]);
struct room GetRandomRoom(struct room* arr[]);
int CanAddConnectionFrom(struct room); 
int ConnectionAlreadyExists(struct room, struct room);



//room struct
struct room {
	int id;
	char* name;
	int cnct;
	char* rtype;
	struct room* outcncts[6];
};

/*********************************************************************************
 *Function: main								 *
 * Description:  *
 ********************************************************************************/
int main(){
	//seed rand
	srand(time(NULL));

	char dirname[20];	
	memset(dirname, '\0', 20);
	int* usednames = calloc(7,sizeof(int));
	memset(usednames, '\0', 7);
	struct room* myrooms[7];	

	//create room structs
	struct room rm0;
	rm0.id = 0;
	rm0.name = calloc(9, sizeof(char));
	memset(rm0.name, '\0', 9);
	rm0 = AssignRoomName(rm0, usednames);
	myrooms[0] = &rm0;
	//printf("rm0 name: %s\n", myrooms[0]->name);

	struct room rm1;
	rm1.id = 1;
	rm1.name = calloc(9, sizeof(char));
	memset(rm1.name, '\0', 9);
	rm1 = AssignRoomName(rm1, usednames);
	myrooms[1] = &rm1;
	//printf("rm1 name: %s\n", myrooms[1]->name);

	struct room rm2;
	rm2.id = 2;
	rm2.name = calloc(9, sizeof(char));
	memset(rm2.name, '\0', 9);
	rm2 = AssignRoomName(rm2, usednames);
	myrooms[2] = &rm2;
	//printf("rm2 name: %s\n", myrooms[2]->name);

	struct room rm3;
	rm3.id = 3;
	rm3.name = calloc(9, sizeof(char));
	memset(rm3.name, '\0', 9);
	rm3 = AssignRoomName(rm3, usednames);
	myrooms[3] = &rm3;
	//printf("rm3 name: %s\n", myrooms[3]->name);

	struct room rm4;
	rm4.id = 4;
	rm4.name = calloc(9, sizeof(char));
	memset(rm4.name, '\0', 9);
	rm4 = AssignRoomName(rm4, usednames);
	myrooms[4] = &rm4;
	//printf("rm4 name: %s\n", myrooms[4]->name);

	struct room rm5;
	rm5.id = 5;
	rm5.name = calloc(9, sizeof(char));
	memset(rm5.name, '\0', 9);
	rm5 = AssignRoomName(rm5, usednames);
	myrooms[5] = &rm5;
	//printf("rm5 name: %s\n", myrooms[5]->name);

	struct room rm6;
	rm6.id = 6;
	rm6.name = calloc(9, sizeof(char));
	memset(rm6.name, '\0', 9);
	rm6 = AssignRoomName(rm6, usednames);
	myrooms[6] = &rm6;
	//printf("rm6 name: %s\n", myrooms[6]->name);

	
	//make game graph
	// Create all connections in graph
	//while (IsGraphFull() == false)
	//{
		 AddRandomConnection(myrooms);
	//}

	// Returns true if all rooms have 3 to 6 outbound connections, false otherwise
	//bool IsGraphFull()  
	//{
	//}

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
	free(usednames);

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
 * Description: Takes a room struct and an array of ints keepings track of      *
 * already assigned names. It then uses rand() to randomly assign room names to * 
 * the struct passed. Once a new room name is chosen, the struct is set to 	*
 * point at the name, the number representing the name is saved to the array of`*
 * ints, then the struct is returned.						*
 *******************************************************************************/
struct room AssignRoomName(struct room blank, int assigned[]){
	struct room newname = blank;
	int r = 0, i = 0;
	
	//randomly assign roomname
	r = rand() % 10;
	for(i; i < newname.id; i++) 
	{
		//check if name has been used already, if so, get new #
		 if(r == assigned[i])
	  	{
			r = rand() % 10;
			i = -1;
		}
	}
	
	//set struct pointer to assigned roomname
	switch (r)
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

	//keep track of roomnames already used
	assigned[newname.id] = r;

	return newname;
}

/********************************************************************************
 *Function: AddRandomConnection							*
 * Description: * Adds a random, valid outbound connection from a Room to
 *  another Room
 *******************************************************************************/
void AddRandomConnection(struct room* rooms[]){
	struct room a;  
	struct room b;

	a = GetRandomRoom(rooms);
	printf("a: %s\n", a.name);
//	while(true)
//	{	
		a = GetRandomRoom(rooms);
		printf("a: %s\n", a.name);

		if (CanAddConnectionFrom(a) == 1)
		{	 
			printf("in if, true is real!\n");
			//break;
		}
//	}

//	do
//	{
		b = GetRandomRoom(rooms);
		printf("b: %s\n", b.name);
//	}
//	while(CanAddConnectionFrom(B) == false || IsSameRoom(A, B) == true || ConnectionAlreadyExists(A, B) == true);

	ConnectionAlreadyExists(a,b);

//	ConnectRoom(A, B);  // TODO: Add this connection to the real variables, 
//	ConnectRoom(B, A);  //  because this A and B will be destroyed when this function terminates

}

/********************************************************************************
 *Function: GetRandomRoom							*
 * Description: *Returns a random Room, does NOT validate if connection can be 
 * added
 *******************************************************************************/
struct room GetRandomRoom(struct room* rooms[]){
	int r = 0;
	struct room random;

	//randomly assign roomname
	r = rand() % 7;
	random = *rooms[r];
	printf("random: %s\n", random.name);	

	return random;
}

/********************************************************************************
 *Function: CanAddConnectionFrom						*
 * Description: Returns true if a connection can be added from Room x (< 6 
 * outbound connections), false otherwise
 *******************************************************************************/
int CanAddConnectionFrom(struct room x){
	int cnct = 0;

	//change bool to true if connections is <6
	if(x.cnct < 6)
	{
		cnct = 1;
	}

	return cnct;
}

/*********************************************************************************
 *Function: ConnectionAlreadyExists						 *
 * Description: * Returns true if a connection from Room x to Room y already
 * exists, false otherwise
 ********************************************************************************/
int ConnectionAlreadyExists(struct room x, struct room y){
	int cnct = 0, i = 0;

	for(i; i < y.cnct; i++)
	{
		//change bool to true if connection exists
		if(x.id == y.outcncts[i]->id)
		{
			cnct = 1;
			break;
		}
	}
	
	printf("In ConnectionAlreadyExists, cnct: %d\n", cnct);
	return cnct;
}

// Connects Rooms x and y together, does not check if this connection is valid
//void ConnectRoom(Room x, Room y) 
//{
//}

// Returns true if Rooms x and y are the same Room, false otherwise
//bool IsSameRoom(Room x, Room y) 
//{
//}
