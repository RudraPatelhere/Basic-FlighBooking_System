#include<stdio.h>
#include"Number_Of_Seats_Available.h"

#define NAME_LENGTH        22
#define NUMBER_OF_FLIGHTS      4
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

int Number_Of_Seats_Available(const struct Plane_Passenger_Information pl[], int n)
{
    int Number_Count = 0;
    int seat;

    for (seat = 0; seat < n; seat++)

        if (pl[seat].Status_Of_Plane == EMPTY_SEAT)

            Number_Count++;

    return Number_Count;
}