/********************************************************************************
 * Title: frieseti.buildrooms.c                                                 *
 * Name: Tiffani Auer								*
 * Due: Feb 14, 2019								*
 *******************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>
#include <time.h>

//room struct
struct room {
	int id;
	char* name;
	char* rtype;
	int cnct;
	struct room* outcncts;
};

void MakeDirectory(char*);
void MakeRoomFile(struct room*, char*);
struct room AssignRoomName(struct room, int arr[]);
void AddRandomConnection(struct room*);
struct room GetRandomRoom(struct room*);
int CanAddConnectionFrom(int); 
int ConnectionAlreadyExists(int, struct room);
int IsSameRoom(int, int); 
int IsGraphFull(struct room*);
void SetRoomsOrder(struct room*);
  
/********************************************************************************
*Function: main									*
* Description: Initializes all structs, as well as pointers to the structs. It 	*
* also initializes an array that keeps track of what room names that have been  *
* assigned. It then calls the appropriate functions to set up the rooms and 	*
* graph as needed for the adventure game. It then frees all dynamically alloc	*
* memory.									*
********************************************************************************/
int main(){
	//seed rand
	srand(time(0));
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
	rm0.rtype = calloc(11, sizeof(char));
	memset(rm0.rtype, '\0', 11);
	rm0.cnct = 0;
	rm0.outcncts = (struct room*) malloc(6 * sizeof(struct room));
	memset(rm0.outcncts, '\0', 6);
	rm0 = AssignRoomName(rm0, usednames);
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
	rm1 = AssignRoomName(rm1, usednames);
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
	rm2 = AssignRoomName(rm2, usednames);
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
	rm3 = AssignRoomName(rm3, usednames);
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
	rm4 = AssignRoomName(rm4, usednames);
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
	rm5 = AssignRoomName(rm5, usednames);
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
	rm6 = AssignRoomName(rm6, usednames);
	myrooms[6] = rm6;

	//make game graph
	SetRoomsOrder(myrooms);
	while (IsGraphFull(myrooms) == 0)
	{
		 AddRandomConnection(myrooms);
	}
	
	//make new directory and generate files
	MakeDirectory(dirname);
	MakeRoomFile(myrooms, dirname);

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
	free(usednames);
	free(myrooms);

	return 0;
}

/********************************************************************************
*Function: MakeDirectory							*
* Description: Takes a char pointer as an arg, and sets it to point to the new  *
* directory name, then creates that directory.					*
*******************************************************************************/
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
*Function: AssignRoomName							*
* Description: Takes a room struct and an array of ints keepings track of       *
* already assigned names. It then uses rand() to randomly assign room names to  * 
* the struct passed. Once a new room name is chosen, the struct is set to 	*
* point at the name, the number representing the name is saved to the array of` *
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
* Description: Takes an array of room structs as an arg, and generates two 	*
* random rooms to connect, and tests if they are a valid connection. If so, 	*
* they are connected both ways, and their connection counters are incremented.	*	
*******************************************************************************/
void AddRandomConnection(struct room* rooms){
	struct room a;  
	struct room b;

	//generate first random room to connect
	while(1)
	{	
		a = GetRandomRoom(rooms);
		
		//check if connections are full
		if (CanAddConnectionFrom(a.cnct) == 1)	 
			break;
	}

	//generate second random room. Checks if connects are full, if same room
	//as first room, or if room a and b are already connected. If not, they
	//can be connected.
	do
	{
		b = GetRandomRoom(rooms);
	}
	while(CanAddConnectionFrom(b.cnct) == 0 || IsSameRoom(a.id,b.id) == 1 || ConnectionAlreadyExists(a.id,b) == 1);


	//store room connections in permanent rooms array
	rooms[a.id].outcncts[rooms[a.id].cnct] = b;
	rooms[b.id].outcncts[rooms[b.id].cnct] = a;
	
	//increment connection counter for each room
	rooms[a.id].cnct++;
	rooms[b.id].cnct++;
}

/********************************************************************************
*Function: GetRandomRoom							*
* Description: Takes an array of room structures as an arguemnt, and generates  *
* a random number that correlates with the ID# of a rooom. That room is saved   *
* in a temporary struct, and returned to the calling function.			*	
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
*Function: CanAddConnectionFrom							*
* Description: Takes the # of connections as an argument. If it is less than	*
* 6 returns ture, otherwise returns false.					*
*******************************************************************************/
int CanAddConnectionFrom(int cncts){
	if(cncts < 6)
		return 1;
	return 0;
}

/********************************************************************************
*Function: ConnectionAlreadyExists						*
* Description: Takes the ID of one room x and the struct of room y as args. It  *
* then compares the ID of room x against the ID's of room y's connections. If   *
* there's a connection, it returns true, otherwise, false.			* 
*******************************************************************************/
int ConnectionAlreadyExists(int xid, struct room y){
	int i = 0;

	for(i; i < y.cnct; i++)
	{
		if(xid == y.outcncts[i].id)
			return 1;
	}
	return 0;
}

/********************************************************************************
*Function: IsSameRoom								*
* Description: Takes the IDs of rooms x and y and compares them. If they are 	*
* the same it returns true. If not, it returns false.				*
*******************************************************************************/
int IsSameRoom(int xid, int yid){
	if(xid == yid)
		return 1;
	return 0;
}

/********************************************************************************
*Function: IsGraphFull								*
* Description: Takes an array of rooms as an arg. It then cycles through the    *
* rooms to check how many connections each room has. If all rooms have 3 or 	*
* more connections it returns true, otherwise returns false.			*
*******************************************************************************/
int IsGraphFull(struct room* rooms){
	int i = 0, c0 = 0, c1 = 0, c2 = 0, c3 = 0, c4 = 0, c5 = 0, c6 = 0;

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
		return 1;
	
	return 0;
}

/********************************************************************************
*Function: SetRoomsOrder							*
* Description: Takes an array of room structs as an arg. Then assigns all the 	*
* rooms as mid rooms. The first two rooms are then reassigned as the first and  *
* last rooms in the game.							*
*******************************************************************************/
void SetRoomsOrder(struct room* rooms){
	int i = 0;
	
	for(i; i < 7; i++)
		sprintf(rooms[i].rtype, "MID_ROOM");

	sprintf(rooms[0].rtype, "START_ROOM");
	sprintf(rooms[1].rtype, "END_ROOM");
}
