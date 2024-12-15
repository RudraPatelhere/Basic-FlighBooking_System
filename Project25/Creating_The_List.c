#include<stdio.h>
#include<string.h>
#include"Creating_The_List.h"


#define CRT_NO_SECURE_WARNINGS
#define NAME_LENGTH        22
#define NUMBER_OF_FLIGHTS     4
#define NUMBER_OF_SEATS       12
#define EMPTY_SEAT        0
#define SEAT_TAKEN        1
#define SEAT_CONFIRMED      1
#define SEAT_UNCONFIRMED  0
#define CONTINUE     1
#define FINISH         0


#define NUMBER_OF_FLIGHT_OPTIONS 5

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

void Creating_The_List(const struct Plane_Passenger_Information pl[], char* str, int type)
{
    int seat;

    char Temporary_Variable[NAME_LENGTH];

    str[0] = '\0';

    for (seat = 0; seat < NUMBER_OF_SEATS; seat++)

        if (pl[seat].Status_Of_Plane == type)
        {
            sprintf(Temporary_Variable, " %d", pl[seat].Seat_ID);

            strcat(str, Temporary_Variable);
        }
}