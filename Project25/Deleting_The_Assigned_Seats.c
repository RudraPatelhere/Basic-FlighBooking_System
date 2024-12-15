#include<stdio.h>
#include"Deleting_The_Assigned_Seats.h"
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


void Deleting_The_Assigned_Seats(struct Plane_Passenger_Information pl[], int n)
{
    int seat;
    int loop;
    char The_List[3 * NUMBER_OF_SEATS];

    if (Number_Of_Seats_Available(pl, n) == NUMBER_OF_SEATS)

        puts("Seats are all empty");
    else
    {
        Displaying_the_Seats(pl, n);

        Creating_The_List(pl, The_List, SEAT_TAKEN);

        puts("Enter the number of the seat to be cancelled:");

        do
        {
            while (scanf_s("%d", &seat) != 1)
            {
                scanf_s("%*s");

                puts("Enter a number from this list:");

                puts(The_List);
            }
            if (seat < 1 || seat > NUMBER_OF_SEATS || pl[seat - 1].Status_Of_Plane == EMPTY_SEAT)
            {
                puts("Please enter a number from this list only :");

                puts(The_List);

                loop = CONTINUE;
            }
            else
                loop = FINISH;

        } while (loop == CONTINUE);

        while (getchar() != '\n')

            continue;

        printf("%s %s to be cancelled for seat %d.\n", pl[seat - 1].First_Name_Of_Passenger, pl[seat - 1].Last_Name_Of_Passenger, seat);

        puts("Enter d to delete assignment, c to cancel this action.");

        if (Getting_The_Letter("dc") == 'd')
        {
            pl[seat - 1].Status_Of_Plane = EMPTY_SEAT;

            puts("The passenger is no longer onboard");
        }
        else

            puts("Passenger is onboard!");
    }
}