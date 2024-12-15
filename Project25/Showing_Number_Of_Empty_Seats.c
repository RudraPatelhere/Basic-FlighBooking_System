#include<stdio.h>
#include"Showing_Number_Of_Empty_Seats.h"

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

void Showing_Number_Of_Empty_Seats(const struct Plane_Passenger_Information Plane_[], int Number)
{
    char Seatingg[3 * NUMBER_OF_SEATS];

    if (Number_Of_Seats_Available(Plane_, Number) == 0)

        puts("All seats are assigned");
    else
    {
        puts("The following seats are available for booking:");

        Creating_The_List(Plane_, Seatingg, EMPTY_SEAT);

        puts(Seatingg);
    }
}