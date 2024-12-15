#include<stdio.h>
#include"List_Of_The_Assigned_Passengers.h"

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


void List_Of_The_Assigned_Passengers(struct Plane_Passenger_Information* plane_Seat[], int n)
{
    int i;

    if (Number_Of_Seats_Available(*plane_Seat, n) == NUMBER_OF_SEATS)

        puts("All seats are empty.");
    else
    {
        Seat_Sorting(plane_Seat, n);

        for (i = 0; i < NUMBER_OF_SEATS; i++)

            if (plane_Seat[i]->Status_Of_Plane == SEAT_TAKEN)
            {
                printf("Seat %d: %s, %s", plane_Seat[i]->Seat_ID, plane_Seat[i]->Last_Name_Of_Passenger, plane_Seat[i]->First_Name_Of_Passenger);

                if (plane_Seat[i]->Seat_Confirmation == SEAT_CONFIRMED)

                    puts(", confirmed");
                else
                    puts(", unconfirmed");
            }

    }
}