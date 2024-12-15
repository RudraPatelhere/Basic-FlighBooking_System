//Name:Jiya Pandit
//Subject:Programming Priciples(PROG71985)
//Assignment 4 Refactor
//...........................FEEDBACK.....................................

//Question 2: Modeling a hotel reservation system
//o Specifications : 0.0 / 8.0
//—Program does not compile
//o Readability : 3.0 / 4.0 (The code is fairly easy to read or the following issues were noted : )
//—Capitalize your constants(and use const or #define)
//o Reusability : 3.0 / 4.0 (Most of the code could be reused in other programs or the following issues were noted : )
//—Globally scoped variables should be avoided unless absolutely required
//o Documentation : 2.0 / 4.0 (The documentation is simply comments embedded in the code with some simple header comments separating routines or the program is producing incorrect results or the following issues were noted : )
//—Some files in project missing top - of - file comment block(name, class, assignment#, etc)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include"Getting_The_Letter.h"
#include"Number_Of_Seats_Available.h"
#include"Main_Menu.h"
#include"Deleting_The_Assigned_Seats.h"
#include"List_Of_The_Assigned_Passengers.h"
#include"Number_Of_Seats_Available.h"
#include"Option_List_Menu.h"
#include"Seat_Assigned_To_Passengers.h"
#include"Showing_Number_Of_Empty_Seats.h"
#include"Seat_Sorting.h"
#include"Creating_The_List.h"
#include"Confirming_The_Passenger_Seat.h"
#include"Displaying_The_Seats.h"
#include"Getting_String.h"

#pragma warning(disable:4996)

#define NAME_LENGTH        22
#define NUMBER_OF_FLIGHTS  4
#define NUMBER_OF_SEATS       12
#define EMPTY_SEAT        0
#define SEAT_TAKEN        1
#define SEAT_CONFIRMED      1
#define SEAT_UNCONFIRMED  0
#define CONTINUE     1
#define FINISH         0

struct Plane_Passenger_Information {

    int Seat_ID;
    int Status_Of_Plane;
    int Seat_Confirmation;
    char Last_Name_Of_Passenger[NAME_LENGTH];
    char First_Name_Of_Passenger[NAME_LENGTH];
};

struct Flight_Information {

    struct Plane_Passenger_Information Plane_No_1[NUMBER_OF_SEATS], * planeseatt[NUMBER_OF_SEATS];
    int Flight_ID_Number;
};



int main(void)
{
    struct Flight_Information Flight[NUMBER_OF_FLIGHTS];
    int Flight_Options;
    int Option;
    int i;
    int j;
    FILE* File_Pointer;
    size_t Size = sizeof(struct Flight_Information);

    for (j = 0; j < NUMBER_OF_FLIGHTS; j++)

        for (i = 0; i < NUMBER_OF_SEATS; i++)

            Flight[j].planeseatt[i] = &Flight[j].Plane_No_1[i];

    if ((File_Pointer = fopen("AirPlane.dat", "rb")) == NULL)

        for (j = 0; j < NUMBER_OF_FLIGHTS; j++)

            for (i = 0; i < NUMBER_OF_SEATS; i++)
            {
                Flight[j].Plane_No_1[i].Status_Of_Plane = EMPTY_SEAT;
                Flight[j].Plane_No_1[i].Seat_Confirmation = SEAT_UNCONFIRMED;
                Flight[j].Plane_No_1[i].Seat_ID = i + 1;
            }
    else
    {
        for (i = 0; i < NUMBER_OF_FLIGHTS; i++)

         fread(Flight[i].Plane_No_1, Size, NUMBER_OF_SEATS, File_Pointer);

        fclose(File_Pointer);
    }
    while ((Flight_Options = Main_Menu()) != 'q')
    {
        int Index_Number;

        switch (Flight_Options)
        {
        case '1': Index_Number = 0;
            
            break;

        case '2': Index_Number = 1;
            
            break;

        case '3': Index_Number = 2;
            
            break;

        case '4': Index_Number = 3;
            
            break;

        case '5': Index_Number = 4;

            break;

        default: puts("Switch trouble");
            
            break;
        }

        while ((Option = Option_List_Menu()) != 'q')
        {
            switch (Option)
            {
            case 'a': printf("There are %d empty seats.\n",Number_Of_Seats_Available(Flight[Index_Number].Plane_No_1, NUMBER_OF_SEATS));

                break;

            case 'b': Showing_Number_Of_Empty_Seats(Flight[Index_Number].Plane_No_1, NUMBER_OF_SEATS);

                break;

            case 'c': List_Of_The_Assigned_Passengers(Flight[Index_Number].planeseatt, NUMBER_OF_SEATS);

                break;

            case 'd': Seat_Assigned_To_Passengers(Flight[Index_Number].Plane_No_1, NUMBER_OF_SEATS);

                break;

            case 'e': Deleting_The_Assigned_Seats(Flight[Index_Number].Plane_No_1, NUMBER_OF_SEATS);

                break;

            case 'f': Confirming_The_Assigned_Passenger_Seat(Flight[Index_Number].Plane_No_1, NUMBER_OF_SEATS);
                
                break;

            

            default: puts("Inalid input!");

                break;
            }
        }
    }
    if ((File_Pointer = fopen("plane_file.dat", "wb")) == NULL)

        puts("Can't save data to file.");
    else
    {
        for (i = 0; i < NUMBER_OF_FLIGHTS; i++)

        fwrite(Flight[i].Plane_No_1, Size, NUMBER_OF_SEATS, File_Pointer);

        fclose(File_Pointer);
    }
    puts("Successfully exited from the airplane program !");

    return 0;
}

