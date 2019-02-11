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
void AddRandomConnection(struct room* arr);
struct room GetRandomRoom(struct room* arr);
int CanAddConnectionFrom(struct room); 
int ConnectionAlreadyExists(int, struct room);
int IsSameRoom(int, int); 
void ConnectRoom(struct room, struct room);
int IsGraphFull(struct room* arr);

  
//room struct
struct room {
	int id;
	char* name;
	int cnct;
	char* rtype;
	struct room* outcncts;
};

/*********************************************************************************
 *Function: main								 *
 * Description:  *
 ********************************************************************************/
int main(){
	//seed rand
	char dirname[20];	
	memset(dirname, '\0', 20);
	int* usednames = calloc(7,sizeof(int));
	memset(usednames, '\0', 7);
	struct room* myrooms;
	myrooms = (struct room*) malloc(7 * sizeof(struct room));	


	//create room structs
	struct room rm0;
	rm0.id = 0;
	rm0.name = calloc(9, sizeof(char));
	memset(rm0.name, '\0', 9);
	rm0.cnct = 0;
	rm0.outcncts = (struct room*) malloc(6 * sizeof(struct room));
	memset(rm0.outcncts, '\0', 6);
	rm0 = AssignRoomName(rm0, usednames);
	myrooms[0] = rm0;
	//printf("rm0 name: %s\n", myrooms[0]->name);

	struct room rm1;
	rm1.id = 1;
	rm1.name = calloc(9, sizeof(char));
	memset(rm1.name, '\0', 9);
	rm1.cnct = 0;
	rm1.outcncts = (struct room*) malloc(6 * sizeof(struct room));
	memset(rm1.outcncts, '\0', 6);
	rm1 = AssignRoomName(rm1, usednames);
	myrooms[1] = rm1;
	//printf("rm1 name: %s\n", myrooms[1]->name);

	struct room rm2;
	rm2.id = 2;
	rm2.name = calloc(9, sizeof(char));
	memset(rm2.name, '\0', 9);
	rm2.cnct = 0;
	rm2.outcncts = (struct room*) malloc(6 * sizeof(struct room));
	memset(rm2.outcncts, '\0', 6);
	rm2 = AssignRoomName(rm2, usednames);
	myrooms[2] = rm2;
	//printf("rm2 name: %s\n", myrooms[2]->name);

	struct room rm3;
	rm3.id = 3;
	rm3.name = calloc(9, sizeof(char));
	memset(rm3.name, '\0', 9);
	rm3.cnct = 0;
	rm3.outcncts = (struct room*) malloc(6 * sizeof(struct room));
	memset(rm3.outcncts, '\0', 6);
	rm3 = AssignRoomName(rm3, usednames);
	myrooms[3] = rm3;
	//printf("rm3 name: %s\n", myrooms[3]->name);

	struct room rm4;
	rm4.id = 4;
	rm4.name = calloc(9, sizeof(char));
	memset(rm4.name, '\0', 9);
	rm4.cnct = 0;
	rm4.outcncts = (struct room*) malloc(6 * sizeof(struct room));
	memset(rm4.outcncts, '\0', 6);
	rm4 = AssignRoomName(rm4, usednames);
	myrooms[4] = rm4;
	//printf("rm4 name: %s\n", myrooms[4]->name);

	struct room rm5;
	rm5.id = 5;
	rm5.name = calloc(9, sizeof(char));
	memset(rm5.name, '\0', 9);
	rm5.cnct = 0;
	rm5.outcncts = (struct room*) malloc(6 * sizeof(struct room));
	memset(rm5.outcncts, '\0', 6);
	rm5 = AssignRoomName(rm5, usednames);
	myrooms[5] = rm5;
	//printf("rm5 name: %s\n", myrooms[5]->name);

	struct room rm6;
	rm6.id = 6;
	rm6.name = calloc(9, sizeof(char));
	memset(rm6.name, '\0', 9);
	rm6.cnct = 0;
	rm6.outcncts = (struct room*) malloc(6 * sizeof(struct room));
	memset(rm6.outcncts, '\0', 6);
	rm6 = AssignRoomName(rm6, usednames);
	myrooms[6] = rm6;
	//printf("rm6 name: %s\n", myrooms[6]->name);

	
	//make game graph
	while (IsGraphFull(myrooms) == 0)
	{
		 AddRandomConnection(myrooms);
	}

//	IsGraphFull(myrooms);

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
	free(rm0.outcncts);
	free(rm1.outcncts);
	free(rm2.outcncts);
	free(rm3.outcncts);
	free(rm4.outcncts);
	free(rm5.outcncts);
	free(rm6.outcncts);
	free(usednames);
	free(myrooms);

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
void AddRandomConnection(struct room* rooms){
	struct room a;  
	struct room b;

	while(1)
	{	
		a = GetRandomRoom(rooms);
		printf("\na: %s id: %d\n", a.name, a.id);
		
		if (CanAddConnectionFrom(a) == 1)
		{	 
			break;
		}
	}

	do
	{
		b = GetRandomRoom(rooms);
		printf("b: %s id: %d\n", b.name, b.id);
	}
	//while(CanAddConnectionFrom(b) == 0 || IsSameRoom(a.id,b.id) == 1);
	while(CanAddConnectionFrom(b) == 0 || IsSameRoom(a.id,b.id) == 1 || ConnectionAlreadyExists(a.id,b) == 1);

//	ConnectionAlreadyExists(a.id,b);

	//store room connections in permanent rooms
	rooms[a.id].outcncts[rooms[a.id].cnct] = b;
	rooms[b.id].outcncts[rooms[b.id].cnct] = a;
	
	
	printf("rooms[a.id:%d].outcncts[%d] points to %s\n", a.id, rooms[a.id].cnct, rooms[a.id].outcncts[a.cnct].name);
	printf("rooms[b.id:%d].outcncts[%d] points to %s\n", b.id, rooms[b.id].cnct, rooms[b.id].outcncts[b.cnct].name);
	
	
	//increment connection counter for each room
	rooms[a.id].cnct++;
	rooms[b.id].cnct++;
	
	printf("#of connections: %s: %d, %s: %d\n\n", rooms[a.id].name, rooms[a.id].cnct, rooms[b.id].name, rooms[b.id].cnct);
}

/********************************************************************************
 *Function: GetRandomRoom							*
 * Description: *Returns a random Room, does NOT validate if connection can be 
 * added
 *******************************************************************************/
struct room GetRandomRoom(struct room* rooms){
	int r = 0;
	struct room random;

	//randomly assign roomname
	r = rand() % 7;
	random = rooms[r];	

	return random;
}

/********************************************************************************
 *Function: CanAddConnectionFrom						*
 * Description: Returns true if a connection can be added from Room x (< 6 
 * outbound connections), false otherwise
 *******************************************************************************/
int CanAddConnectionFrom(struct room x){
	printf("\nIN CanAddConnectionFrom: ");

	//change bool to true if connections is <6
	if(x.cnct < 6)
	{
		printf("connection less than 6\n");
		return 1;
	}
	printf("connections full!\n");
	return 0;
}

/*********************************************************************************
 *Function: ConnectionAlreadyExists						 *
 * Description: * Returns true if a connection from Room x to Room y already
 * exists, false otherwise
 ********************************************************************************/
int ConnectionAlreadyExists(int xid, struct room y){
	int i = 0;

	printf("\nIN ConnectionAlreadyExists() xid: %d\n y.cnct: %d: ", xid, y.cnct);
	
	for(i; i < y.cnct; i++)
	{
		printf("y.outcncts[i].id: %d\n", y.outcncts[i].id);
		if(xid == y.outcncts[i].id)
		{
			printf("THERE'S ALREADY A CONNECTION: xid: %d y.outcncts[i].id: %d\n", xid, y.outcncts[i].id);
			return 1;
		}
	}
	printf("NO CONNECTION!\n");
	return 0;
}
	



/********************************************************************************
 *Function: IsSameRoom								*
 * Description: Returns true if Rooms x and y are the same Room, false otherwise*
 *******************************************************************************/
int IsSameRoom(int xid, int yid){
	printf("\nIN IsSameRoom(): ");
	if(xid == yid)
	{
		printf("same room!\n");
		return 1;
	}
	printf("not same room!\n");
	return 0;
}

/********************************************************************************
 *Function: IsGraphFull								*
 * Description: Returns true if all rooms have 3 to 6 outbound connections, 	*
 * false otherwise
 *******************************************************************************/
int IsGraphFull(struct room* rooms){
	int full = 0, i = 0;
	int c0 = 0, c1 = 0, c2 = 0, c3 = 0, c4 = 0, c5 = 0, c6 = 0;

	//check connect count for each room
	for(i; i<7; i++)
	{
		//if a room has 3 or more connects, its bool changes to true
		if(rooms[i].cnct >= 3)
		{
			switch (i)
			{
				case 0:
					c0 = 1;
					break;
				case 1:
					c1 = 1;
					break; 	
				case 2:
					c2 = 1;
					break; 
				case 3:
					c3 = 1;
					break; 	
				case 4:
					c4 = 1;
					break;
				case 5:
					c5 = 1;
					break; 	
				case 6:
					c6 = 1;
					break;
			}
		}
	}
	
	//if all rooms have 3 or more connections, change bool to true	
	if (c0 == 1 && c1 == 1 && c2 == 1 && c3 == 1 && c4 == 1 && c5 == 1 && c6 == 1)
		full = 1;
	
	printf("\nIN IsGraphFull. full: %d\n\n", full);
	return full;
}
