#include<stdio.h>
#include"Main_Menu.h"

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

int Main_Menu(void)
{
    const char* Different_Flights[NUMBER_OF_FLIGHT_OPTIONS] = {
        "102",
        "311",
        "444",
        "519",
        "Quit"
    };

    const char Labels[NUMBER_OF_FLIGHT_OPTIONS + 1] = "1234q";

    int i;

    puts("To choose a flight, enter its letter label");

    for (i = 0; i < NUMBER_OF_FLIGHT_OPTIONS; i++)

        printf("%c) %s\n", Labels[i], Different_Flights[i]);

    return Getting_The_Letter(Labels);
}