/********************************************************************************
 * THIS IS TO CERTIFY THAT THIS PROJECT IS MY OWN & PARTNERS WORK, BASED ON 
 * MY/OUR PERSONAL EFFORTS I STUDYING AND APPLYING THE CONCEPTS LEARNED. I/WE
 * HAVE CONSTRUCTED THE FUNCTIONS AND THEIR RESPECTIVE ALGORITHMS AND
 * CORRESPONDING CODE BY ME (AND MY PARTNER). THE PROGRAMWAS RUN, TESTED, AND
 * DEBUGGED BY MY OWN EFFORTS. I FURTHER CERTIFY THAT I HAVE NOT COPIED IN 
 * PART OR WHOLE OR OTHERWISE PLAGIARIZED THE WORK OF OTHER STUDENTS AND/OR PERSONS.
 * 
 * KEIRA GABRIELLE CAFE ALCANTARA - 12205737 - S13
 * CANDICE AURA TOMAS FERNANDEZ   - 12207071 - S13
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//#define DLSU_POPULATION 25000
#define MAX_RESERVATIONS 3
#define NUM_RESERVE 100
#define CLASSROOM_LIMIT 12
#define LAB_LIMIT 8
#define TRAINING_ROOM_LIMIT 6
#define SEMINAR_LIMIT 4
#define AUDITORIUM_LIMIT 2

typedef char Str3[4];
typedef char Str5[6]; 
typedef char Str8[9];  // for ID num
typedef char Str10[11];
typedef char Str20[21];
typedef char Str30[31];
typedef char Str50[51];
typedef char Str100[101];

struct nameTag{
    Str20 first;
    Str20 last;
};
typedef struct nameTag nameType;

struct dateTag{
    int month;
    int day;
    int year;
};
typedef struct dateTag dateType;

struct roomTag{
    Str3 building; // 
    Str20 classification; // (auditorium etc.)
    int floor;
    int number;
};
typedef struct roomTag roomType;

struct studentInfoTag {
  Str8 IDnum;
  nameType name;
  Str100 program;
  dateType date;    // date for reservation
  int participants; // number of participants
  roomType room;    //room to reserve
  Str100 activity;  // description of activity
  char dAY;         // day of the week 
  Str20 time;

};
typedef struct studentInfoTag studentInfoType; 

void displayHeader() {
  printf("\t\t\t\t*************************************************\n");
  printf("\t\t\t\t*                                               *\n");
  printf("\t\t\t\t*          DLSU Room Reservation Program        *\n");
  printf("\t\t\t\t*                                               *\n");
  printf("\t\t\t\t*************************************************\n");
}

int roomReserveBuildings (struct studentInfoTag student[], int position){
    if ((strcmp(student[position].room.building, "LS")==0)|| strcmp(student[position].room.building, "ls")==0 || strcmp(student[position].room.building, "Ls")==0 || strcmp(student[position].room.building, "lS")==0)
    {
        if(student[position].room.floor<=5 && student[position].room.floor>=1)
            return 1;
        else 
            return 0;
    }
    else if (strcmp(student[position].room.building, "Y")== 0 || strcmp(student[position].room.building, "y")== 0 )
    {
        if(student[position].room.floor<=7 && student[position].room.floor>=1)
          return 1;
        else 
            return 0;
    }
    else if (strcmp(student[position].room.building, "J")== 0 || strcmp(student[position].room.building, "j")== 0 )
    {
        if(student[position].room.floor<=4 && student[position].room.floor>=0)
            return 1;
        else 
            return 0;
    }
    else if (strcmp(student[position].room.building, "HS")== 0 || strcmp(student[position].room.building, "hs")== 0 ||  strcmp(student[position].room.building, "Hs")== 0 ||  strcmp(student[position].room.building, "hS")== 0 )
    {
        if(student[position].room.floor>1 && student[position].room.floor<=15)
            return 1;
        else 
            return 0;
    }
    else if (strcmp(student[position].room.building, "V")== 0 || strcmp(student[position].room.building, "v")== 0 )
    {
        if(student[position].room.floor<=5 && student[position].room.floor>=0)
            return 1;
        else 
            return 0;
    }
    else if (strcmp(student[position].room.building, "M")== 0|| strcmp(student[position].room.building, "m")== 0 )
    {
        if(student[position].room.floor<=4 && student[position].room.floor>=0)
            return 1;
        else 
            return 0;
    }
    else if (strcmp(student[position].room.building, "G")== 0 || strcmp(student[position].room.building, "g")== 0 )
    {
        if(student[position].room.floor<=4 && student[position].room.floor>=1)
            return 1;
        else 
            return 0;
    }
    else if (strcmp(student[position].room.building, "ST")== 0 || strcmp(student[position].room.building, "st")== 0 || strcmp(student[position].room.building, "St")== 0 || strcmp(student[position].room.building, "sT")== 0 )
    {
        if(student[position].room.floor<=4 && student[position].room.floor>=1)
            return 1;
        else 
            return 0;
    }
    else if (strcmp(student[position].room.building, "R")== 0 || strcmp(student[position].room.building, "r")== 0 )
    {
        if(student[position].room.floor<=10 && student[position].room.floor>=0)
            return 1;
        else 
            return 0;
    }
    else if(strcmp(student[position].room.building, "A")==0 || strcmp(student[position].room.building, "a")==0)
    {
        if(student[position].room.floor<=22 && student[position].room.floor>=1)
            return 1;
        else 
            return 0;
    }
    else 
        return 0;
}

int roomReserveType (struct studentInfoTag student[], int position){
    int classroomCap = 45; // maximum capacity 
    int seminarCap = 75; 
    int auditoriumCap = 150;
    int trainingCap = 60;
    int labCap = 25;

    if (strcmp(student[position].room.classification, "classroom")==0 || strcmp(student[position].room.classification, "CLASSROOM")==0 || strcmp(student[position].room.classification, "Classroom")==0)
    { 
            return 1;
    }
    else 
            return 0;
    	if (student[position].participants<=classroomCap && student[position].participants > 0)
    	{
    		return 1; //available
		}
		else return 0; //not available
		
		
	if (strcmp(student[position].room.classification, "seminar room")==0|| strcmp(student[position].room.classification, "SEMINAR ROOM")|| strcmp(student[position].room.classification, "Seminar room")==0|| strcmp(student[position].room.classification, "Seminar Room")==0)
    { 
            return 1;
    }
    else 
            return 0;
    	if (student[position].participants<=seminarCap && student[position].participants > 0)
    	{
    		return 1; //available
		}
		else return 0; //not available
		
	if (strcmp(student[position].room.classification, "auditorium")==0|| strcmp(student[position].room.classification, "AUDITORIUM")==0|| strcmp(student[position].room.classification, "Auditorium")==0)
    { 
            return 1;
    }
    else 
            return 0;
    	if (student[position].participants<=auditoriumCap && student[position].participants > 0)
    	{
    		return 1; //available
		}
		else return 0; //not available

	if (strcmp(student[position].room.classification, "training room")==0|| strcmp(student[position].room.classification, "TRAINING ROOM")==0|| strcmp(student[position].room.classification, "Training room")==0|| strcmp(student[position].room.classification, "Training Room")==0)
    { 
            return 1;
    }
    else 
            return 0;
    	if (student[position].participants<=trainingCap && student[position].participants > 0)
    	{
    		return 1; //available
		}
		else return 0; //not available
		
	if (strcmp(student[position].room.classification, "Laboratory")==0|| strcmp(student[position].room.classification, "LABORATORY")==0|| strcmp(student[position].room.classification, "laboratory")==0|| strcmp(student[position].room.classification, "lab")==0|| strcmp(student[position].room.classification, "LAB")==0)
    { 
            return 1;
    }
    else 
            return 0;
    	if (student[position].participants<=labCap && student[position].participants > 0)
    	{
    		return 1; //available
		}
		else return 0; //not available
	
    return 0;
}

int MaximReserve(struct studentInfoTag student[], int count){
    int ctr=0;
    int i;
    printf("Enter your ID number: ");
    scanf("%s", student[count].IDnum);
    for(i=1; i<=count; i++){
        if (strcmp(student[count].IDnum,student[i].IDnum)==0)
            ctr ++;
    }
    if (ctr<=3)
        return 0;
    else 
        return 1;
}

// Function to check if a date is a future date
int isFutureDate(dateType date) {
    time_t currentTime;
    struct tm* localTime;

    // Get the current time
    currentTime = time(NULL); //calendar time equivalents to data type time 
    localTime = localtime(&currentTime); //gets the local time here in the PH and gets the current time from the time (function)

    // Compare the input date with the current date
    if (date.year < localTime->tm_year + 1900) {
        return 0; // Year is in the past
    } else if (date.year == localTime->tm_year + 1900) {
        if (date.month < localTime->tm_mon + 1) {
            return 0; // Month is in the past
        } else if (date.month == localTime->tm_mon + 1) {
            if (date.day <= localTime->tm_mday) {
                return 0; // Day is in the past or today
            }
        }
    }

    return 1; // future date
}

void inputInfo(struct studentInfoTag student[], int position){
    //printf("Enter your ID number: ");
    //scanf("%s", student[position].IDnum);

    printf("Enter your first name: ");
    scanf("%*c%[^\n]s", student[position].name.first);

    printf("Enter your last name: ");
    scanf("%*c%[^\n]s", student[position].name.last);

    printf("Enter your degree program: ");
    scanf("%*c%[^\n]s", student[position].program);

    printf("Enter the date for your reservation in numeric form (mm dd yyyy): ");
    scanf("%d %d %d", &student[position].date.month, &student[position].date.day, &student[position].date.year);
    	// Validate if it's a future date
    	while (!isFutureDate(student[position].date)) {
      	  printf("Invalid date. Please enter a future date.\n");
      	  printf("Enter the date for your reservation in numeric form (mm/dd/yyyy): ");
  		  scanf("%d %d %d", &student[position].date.month, &student[position].date.day, &student[position].date.year);
       	 //return;
   		 }

    printf("Enter day of the week for your reservation: ");
    scanf(" %c", &student[position].dAY);

    printf("Enter time slot: ");
    scanf("%*c%[^\n]s", student[position].time);

    printf("Enter building: ");
    scanf("%s", student[position].room.building);

    printf("Enter floor number: ");
    scanf("%d", &student[position].room.floor);

    printf("Enter room number: ");
    scanf("%d", &student[position].room.number);

    printf("Enter Room classification: ");
    scanf("%*c%[^\n]s", student[position].room.classification);

    printf("Enter number of participants: ");
    scanf("%d", &student[position].participants);

    printf("Description of Activity: ");
    scanf("%*c%[^\n]s", student[position].activity);
}

void printInfo (struct studentInfoTag student[], int position){
    printf("ID number             :  %s\n", student[position].IDnum);
    printf("First Name            :  %s\n", student[position].name.first);
    printf("Last Name             :  %s\n", student[position].name.last);
    printf("Degree                :  %s\n", student[position].program);
    printf("Date                  :  %d/%d/%d\n", student[position].date.month, student[position].date.day,student[position].date.year);
    printf("Day                   :  %c\n", student[position].dAY);
    printf("Time slot             :  %s\n", student[position].time);
    printf("Room                  :  %s%d%d\n", student[position].room.building, student[position].room.floor,student[position].room.number);
    printf("room classification   :  %s\n", student[position].room.classification);
    printf("participants          :  %d\n", student[position].participants);
    printf("Activity              :  %s\n", student[position].activity);
}


void printInfoToFile(struct studentInfoTag student[], int *count) {
   
	int i;   
    FILE *ptr = fopen("recordFile.txt", "a");

    if (ptr == NULL) {
        printf("Error opening the file.\n");
       // return;
    }

    for (i = 1; i < *count; i++) 
	{
        fprintf(ptr, "ID number             :  %s\n", student[i].IDnum);
	    fprintf(ptr, "Name                  :  %s%s\n", student[i].name.first, student[i].name.last);
	    fprintf(ptr, "Degree                :  %s\n", student[i].program);
	    fprintf(ptr, "Date                  :  %d/%d/%d\n", student[i].date.month, student[i].date.day, student[i].date.year);
	    fprintf(ptr, "Day                   :  %c\n", student[i].dAY);
        fprintf(ptr, "Time slot             :  %s\n", student[i].time);
	    fprintf(ptr, "Room                  :  %s%d%d\n", student[i].room.building, student[i].room.floor, student[i].room.number);
	    fprintf(ptr, "room classification   :  %s\n", student[i].room.classification);
	    fprintf(ptr, "participants          :  %d\n", student[i].participants);
	    fprintf(ptr, "Activity              :  %s\n", student[i].activity);
        fprintf(ptr, "\n");
    }

    fflush(ptr);
    fclose(ptr);
}

int timeValidation(struct studentInfoTag student[], int position) 
{
    if (strcmp(student[position].time, "09:15-10:45") == 0 ||
        strcmp(student[position].time, "09:15 - 10:45") == 0 ||
        strcmp(student[position].time, "0915 - 1045") == 0 ||
        strcmp(student[position].time, "11:00-12:30") == 0 ||
        strcmp(student[position].time, "11:00 - 12:30") == 0 ||
        strcmp(student[position].time, "11 - 1230") == 0 ||
        strcmp(student[position].time, "11-1230") == 0 ||
        strcmp(student[position].time, "12:45-14:15") == 0 ||
        strcmp(student[position].time, "12:45 - 14:15") == 0 ||
        strcmp(student[position].time, "1215 - 1445") == 0 ||
        strcmp(student[position].time, "1215-1445") == 0 ||
        strcmp(student[position].time, "14:30-16:00") == 0 ||
        strcmp(student[position].time, "14:30 - 16:00") == 0 ||
        strcmp(student[position].time, "1430 - 1600") == 0 ||
        strcmp(student[position].time, "1430-1600") == 0 ||
        strcmp(student[position].time, "1430 - 16") == 0 ||
        strcmp(student[position].time, "1430-16") == 0 ||
        strcmp(student[position].time, "16:15-17:45") == 0 ||
        strcmp(student[position].time, "16:15 - 17:45") == 0 ||
        strcmp(student[position].time, "1615 - 1745") == 0 ||
        strcmp(student[position].time, "1615-1745") == 0 ||
        strcmp(student[position].time, "18:00-19:00") == 0 ||
        strcmp(student[position].time, "18:00 - 19:00") == 0 ||
        strcmp(student[position].time, "18 - 19") == 0 ||
        strcmp(student[position].time, "18-19") == 0 ||
        strcmp(student[position].time, "1800 - 1900") == 0 ||
        strcmp(student[position].time, "1800-1900") == 0 ||
        strcmp(student[position].time, "09:00-12:00") == 0 ||
        strcmp(student[position].time, "09:00 - 12:00") == 0 ||
        strcmp(student[position].time, "9:00 - 12:00") == 0 ||
        strcmp(student[position].time, "13:00-16:00") == 0 ||
        strcmp(student[position].time, "13:00 - 16:00") == 0 ||
        strcmp(student[position].time, "13 - 16") == 0 ||
        strcmp(student[position].time, "13-16") == 0 ||
        strcmp(student[position].time, "16:15-19:15") == 0 ||
        strcmp(student[position].time, "16:15 - 19:15") == 0 ||
        strcmp(student[position].time, "1615 - 1945") == 0 ||
        strcmp(student[position].time, "1615-1945") == 0) 
        {
            return 1;
        } 
        else 
            return 0;
}

/*
	This function checks if the current reservation info is duplicated while comparing it to the previous reservations
	@param student[] : passed array containing reservation information
	@param position : reservation number of the user
	@param count : the maximum number of current reservations
*/
int checkForDoubleRes(struct studentInfoTag student[], int position, int count)
{
    int found;
    found = 0;
    if(strcmp(student[count].room.building, student[position].room.building) == 0)
    {
     found++;
    }

    if(strcmp(student[count].time, student[position].time) == 0)
    {
        found++;
    }

    if(student[count].room.number == student[position].room.number)
    {
        found++;
    }

    if(student[count].room.floor == student[position].room.floor)
    {
        found++;
    }

    if(student[count].dAY == student[position].dAY)
    {
        found++;
    }

    return found;
}

/*
	This function prints out the guide for the user to see specific information
	no parameters
*/
void printGuide(){
    printf("SCHEDULING: \n"); 
    printf("|      MTHF      |       WS         |     ");     printf("choose room classification             \n");
    printf("| 09:15 - 10:45  |  09:00 - 12:00   |     ");     printf("Classroom       (capacity = 45 people) \n");
    printf("| 11:00 - 12:30  |  13:00 - 16:00   |     ");     printf("Seminar room    (capacity = 75 people) \n");
    printf("| 12:45 - 14:15  |  16:15 - 19:15   |     ");     printf("Auditorium      (capacity = 150 people)\n");
    printf("| 14:30 - 16:00  |                  |     ");     printf("Training room   (capacity = 60 people) \n");
    printf("| 16:15 - 17:45  |                  |     ");     printf("Laboratory      (capacity = 25 people) \n");
    printf("| 18:00 - 19:00  |                  |     \n");

    printf("\nGUIDE : buildings to reserve : \n ");
    printf("LS    =   St. La Salle Hall \n ");
    printf("Y     =   Don Enrique Yuchengco Hall \n ");
    printf("J     =   St. Joseph Hall \n ");
    printf("HS    =   Henry Sy Sr. Hall \n ");
    printf("V     =   Velasco Hall \n ");
    printf("M     =   St. Miguel Hall \n ");
    printf("G     =   John Gokongwei Hall \n ");
    printf("ST    =   Science and Technology Research Center \n ");
    printf("R     =   Enrique Razon Sports Center \n ");
    printf("A     =   Br. Andrew Gonzales Hall \n");

    printf("12 - classroom\n");
    printf("4 - Seminar room\n");
    printf("8 - Laboratory\n");
    printf("2 - Auditorium\n");
    printf("6 - training room\n");
}


/*
	This function edits information about the student's details from the struct when there are errors
	@param student[] : passed array containing reservation information
	@param option : choice made by user to determine which edit function to go to
	@param position : reservation number of the user
*/
void editStudInf(struct studentInfoTag student[], int position,int option){
    Str8 idTemp;
    Str10 prgTemp;
    Str20 firstNameTemp;
    Str20 lastNameTemp;

    if(option == 1)
    {
        printf("Enter your ID number: ");
        scanf("%s", idTemp);

        strcpy(student[position].IDnum,idTemp);
    }
    else if (option == 2)
    {
        printf("Enter your first name:");
        scanf("%*c%[^\n]s", firstNameTemp);
        printf("Enter your last name:");
        scanf("%*c%[^\n]s", lastNameTemp);

        strcpy(student[position].name.first,firstNameTemp);
        strcpy(student[position].name.last,lastNameTemp);
    }
    else if (option == 3)
    {
        printf("Enter new input: ");
        scanf("%*c%[^\n]s", prgTemp);

        strcpy(student[position].program,prgTemp);
    }
    else 
        printf("    INVALID INPUT   \n");
}

/*
	This function edits information about the room details from the struct when there are errors
	@param student[] : passed array containing reservation information
	@param option : choice made by user to determine which edit function to go to
	@param position : reservation number of the user
*/
void editRoomDets(struct studentInfoTag student[], int position, int option){
    Str3 buildTemp;
    // int *floorTemp;
    Str20 classificationTemp;
    //int participantsTemp;
    Str100 activityTemp;

    if(option == 1)
    {
        printf("Enter building");
        scanf("%s", buildTemp);

        strcpy(student[position].room.building,buildTemp);
    }
    else if (option == 2)
    {
        printf("Enter floor number");
        scanf("%d",&student[position].room.floor);
    }
    else if (option == 3)
    {
        printf("Enter room number  :  ");
        scanf("%d",&student[position].room.number);
    }
    else if (option == 4)
    {
        printf("Enter room classification");
        scanf("%*c%[^\n]s",classificationTemp);

        strcpy(student[position].room.classification, classificationTemp);
    }
    else if (option == 5)
    {
        printf("Enter number of participants");
        scanf("%d",&student[position].participants);
    }
    else if (option == 6)
    {
        printf("Description of Activity");
        scanf("%*c%[^\n]s",activityTemp);

        strcpy(student[position].activity, activityTemp);
        
    }
    else 
        printf("    INVALID INPUT   \n");

}

/*
	This function edits information about the date details from the struct when there are errors
	@param student[] : passed array containing reservation information
	@param option : choice made by user to determine which edit function to go to
	@param position : reservation number of the user
*/
void editDateDets(struct studentInfoTag student[],int option, int position){
    Str20 tempTime;

    if(option==1)
    {
        printf("Enter day of the week for your reservation :");
        scanf(" %c", &student[position].dAY);
        printf("Enter date(mm dd yyyy): ");
        scanf("%d%d%d", &student[position].date.month, &student[position].date.day, &student[position].date.year);
    		// Validate if it's a future date
    		while (!isFutureDate(student[position].date)) {
      	  printf("Invalid date. Please enter a future date.\n");
      	  printf("Enter the date for your reservation in numeric form (mm/dd/yyyy): ");
  		  scanf("%d %d %d", &student[position].date.month, &student[position].date.day, &student[position].date.year);
       	 	// You may handle this error by asking the user to input the date again or any other way you prefer.
       		 //return;
   			 }
	}
    else if(option==2)
    {
        printf("Enter time slot :");
        scanf("%s", tempTime);

        //strcmp(tempTime,student[position].time);
    }
}

/*
	This function deletes a record from the struct
	@param student[] : passed array containing reservation information
	@param position : reservation number of the user
	@param count : the maximum number of current reservations
*/

void deleteReservation(struct studentInfoTag student[], int position,
                       int *count) {
  int i, j;
  studentInfoType temp;

  // finds if entry number is in the array
  if (position < 1 || position > *count) {
    printf("Entry number not found.\n");
    // return;
  }
  
  // Shift elements in the array to overwrite the record to be deleted
  for (i = position - 1; i < *count - 1; i++) {
    //student[i] = student[i + 1];

	//swapping the index of the deleted reservations
     for (j = i+1; j < *count - 1; j++) {
       temp = student[i];
       student[i] = student[j];
       student[j] = temp;
     }
  }

  (*count)--;
  printf("Reservation at entry number %d has been deleted.\n", position);
}

/*
	This function acts as the main menu for the program 
	@param student[] : passed array containing reservation information

*/
void MainMenu(struct studentInfoTag student[]) {
  int nChoice = 0;
  studentInfoType studentReserve[5]; 
  int count = 1;
  int editOption;
  int editStudentInfo;
  int editRoomDetails;
  int editReserveDate;
  int position;
  int entryNum;
  
   //studentInfoType studentDelete[3]; 
  //struct studentInfoTag student[DLSU_POPULATION];

  do {
    printf("===== Main Menu =====\n");
    printf("Choose from these options:\n");
    printf("[1] Reserve a Room\n");
    printf("[2] Edit reservation\n");
    printf("[3] Delete Reservation\n");
    printf("[4] View Reservation\n");
    printf("[5] Exit Application\n");
    scanf("%d", &nChoice);

    switch (nChoice) {
    case 1: //function for room reservation
        printGuide();
        printf("\n\n   YOUR RESRVATION NUMBER IS : %d\n\n", count); 
        if (MaximReserve(studentReserve, count)==0)
        {
            inputInfo(studentReserve,count);

            //inadd ni ck, tanggal if need//
            if(count > 1)
            {
                for(int i=1; i < count; i++)
                {
                    int foundRepeat = checkForDoubleRes(studentReserve, count, i);
                    if(foundRepeat == 5)
                    {
                        printf("sorry but reservation is same with reservation: ");
                        printf("%d", i);
                        printf("\nKindly delete or edit your reservation!\n");
                    }
                    
                }
            }

            //ckcode ends here

            if (roomReserveType(studentReserve,count)==1 && roomReserveBuildings(studentReserve,count)==1 && timeValidation(studentReserve, count)==1)
                printf("\n\nEverything looks good so far!\nKindly recheck your reservation before exiting\n\n");
            else if(roomReserveBuildings(studentReserve,count)!=1)
                printf("\n\nKindly edit your building and or floor and or room number details:\n\n");
            else if(roomReserveType(studentReserve,count)!=1)
                printf("\n\nKindly edit your Classification and or Number of participants details:\n\n");
            else if(timeValidation(studentReserve, count)!=1) 
                printf("\n\nKindly edit your Time slot to the specified Day of week details:\n\n");
            else{
            	printf("\n\nKindly edit the details of your reservation : \n\n");
			}
                
             
        	//checkReservation(studentReserve, &count, position);
            count ++;
        }
        else 
            printf("reached Maximum number of reservations\n");
      break;
      

    case 2:
      printf("Enter Reservation number: ");
      scanf("%d", &entryNum);
      if (entryNum<=count)
      {
        do
      {
        printf("pick information you wish to edit: \n");
        printf("1  =  Student's Information\n");
        printf("2  =  Room details\n");
        printf("3  =  Reservation date\n");
        printf("4  =  exit \n");

        scanf("%d", &editOption);

        if (editOption==1)
        {
            printf("Which information do you wish to change: \n");
            printf("1  =  ID number\n");
            printf("2  =  Name\n");
            printf("3  =  Degree program\n");

            scanf("%d", &editStudentInfo);
            editStudInf(studentReserve, entryNum, editStudentInfo);
        }
        else if (editOption==2)
        {
            printGuide();
            printf("Which information do you wish to change: \n");
            printf("1  =  Building\n");
            printf("2  =  Floor\n");
            printf("3  =  Classification\n");
            printf("4  =  Number of participants\n");
            printf("5  =  Activity\n");

            scanf("%d", &editRoomDetails);
            editRoomDets(studentReserve, entryNum, editRoomDetails);
        }
        else if (editOption==3)
        {
            printf("Which information do you wish to change: \n");
            printf("1  =  Date\n");
            printf("2  =  Time\n");

            scanf("%d",&editReserveDate);
            editDateDets(studentReserve, editReserveDate, entryNum);
        }
      }while(editOption!=4);
      printInfo(studentReserve,entryNum);
		
      }
      else
      {
      	printf("INVALID RESERVATION NUMBER");
	  }
        
        break;

    case 3:
    	// function for deleting reservation
      printf("Enter entry number to cancel reservation: ");
      scanf("%d", &position);
      deleteReservation(student, position, &count);
      break;

    case 4:
      //view reservation
      printf("Enter Reservation number:  ");
      scanf("%d", &position);
      if (position<=count){
        printInfo(studentReserve, position);
      }
      else
        printf("INVALID RESERVATION NUMBER\n");
      break; 
     // printAllInfo(studentReserve,count);

    case 5:
      printf("\nThank you for reserving a room!");
      printInfoToFile(studentReserve, &count);
      printf("\nProgram exited.\n");
      break;

    default:
      printf("\nInvalid input\n\n");
      break;
    }

  } while (nChoice != 5);
}



int main() {
	struct studentInfoTag student[6000];
	
	displayHeader();
    MainMenu(student);


  return 0;
}
