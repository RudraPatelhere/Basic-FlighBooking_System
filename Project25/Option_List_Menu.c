#include<stdio.h>
#include"Option_List_Menu.h"
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


#define TOTAL_OPTIONS 7

int Option_List_Menu(void)
{
    const char* Different_Flights[TOTAL_OPTIONS] = {
        "Show number of empty seats",
        "Show list of empty seats",
        "Show alphabetical list of seat assignments",
        "Assign a customer to a seat",
        "Delete a seat assignment",
        "Confirm a seat assignment",
        "Exit to the top-level menu"
    };
    const char Letters[TOTAL_OPTIONS + 1] = "abcdefq";

    int i;

    puts("To select the functionality, please choose the corresponding label");

    for (i = 0; i < TOTAL_OPTIONS; i++)

        printf("%c>> %s\n", Letters[i], Different_Flights[i]);

    return Getting_The_Letter(Letters);
}