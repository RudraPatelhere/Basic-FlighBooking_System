#include<stdio.h>
#include"Seat_Sorting.h"

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

void Seat_Sorting(struct Plane_Passenger_Information* Array[], int End_value)
{
    int Top_Of_List;
    int Finding;

    struct Plane_Passenger_Information* Temp_var;

    for (Top_Of_List = 0; Top_Of_List < End_value - 1; Top_Of_List++)

        for (Finding = Top_Of_List + 1; Finding < End_value; Finding++)

            if (strcmp(Array[Finding]->Last_Name_Of_Passenger, Array[Top_Of_List]->Last_Name_Of_Passenger) < 0)
            {
                Temp_var = Array[Finding];
                Array[Finding] = Array[Top_Of_List];
                Array[Top_Of_List] = Temp_var;
            }
}