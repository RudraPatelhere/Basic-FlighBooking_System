#include<stdio.h>
#include"Seat_Assigned_To_Passengers.h"

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

void Seat_Assigned_To_Passengers(struct Plane_Passenger_Information Plane_[], int number)
{
    char The_List[3 * NUMBER_OF_SEATS];
    int seat, loop;

    if (Number_Of_Seats_Available(Plane_, number) == 0)

        puts("All seats are assigned.");
    else
    {
        Creating_The_List(Plane_, The_List, EMPTY_SEAT);

        puts("Please select the seat you want to choose fro mthe list");

        puts(The_List);
        do
        {
            while (scanf_s("%d", &seat) != 1)
            {
                scanf_s("%*s");

                puts("Enter a number from this list:");

                puts(The_List);
            }
            if (seat < 1 || seat > NUMBER_OF_SEATS || Plane_[seat - 1].Status_Of_Plane == SEAT_TAKEN)
            {
                puts("Enter a number from this list:");

                puts(The_List);

                loop = CONTINUE;
            }
            else
                loop = FINISH;
        } while (loop == CONTINUE);

        while (getchar() != '\n')

            continue;

        puts("Please enter Passengers's firstname:");

        Getting_String(Plane_[seat - 1].First_Name_Of_Passenger, NAME_LENGTH);

        puts("Please enter passengers's lastname:");

        Getting_String(Plane_[seat - 1].Last_Name_Of_Passenger, NAME_LENGTH);

        printf("%s %s assigned to seat %d.\n", Plane_[seat - 1].First_Name_Of_Passenger, Plane_[seat - 1].Last_Name_Of_Passenger, seat);

        puts("Enter a to accept assignment, c to cancel it.");

        if (Getting_The_Letter("ac") == 'a')
        {
            Plane_[seat - 1].Status_Of_Plane = SEAT_TAKEN;

            puts("The seat has been assigned to the passenger");
        }
        else

            puts("Seat has not been assigned to teh passenger");
    }
}