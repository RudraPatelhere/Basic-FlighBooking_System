#include<stdio.h>
#include"Displaying_The_Seats.h"

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

void Displaying_the_Seats(const struct Plane_Passenger_Information pl[], int n)
{
    int i;

    puts("Seats which are full :");

    for (i = 0; i < NUMBER_OF_SEATS; i++)

        if (pl[i].Status_Of_Plane == SEAT_TAKEN)
        {
            printf("Seat %d: %s, %s", pl[i].Seat_ID, pl[i].Last_Name_Of_Passenger, pl[i].First_Name_Of_Passenger);

            if (pl[i].Seat_Confirmation == SEAT_CONFIRMED)

                puts("Confirmed");
            else
                puts("Unconfirmed");
        }
}