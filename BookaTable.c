//
// Created by charlie.counihan25 on 10/11/2025.
//
#include <stdio.h>
#include <string.h>

void Booking_Dinner();

char bookingID[6][150];
char bookingData[100][8];
int Table_available[6] = {0,0,0,0,0,0}; //If a table is available it should be a zero on this array, the array goes: Endor(7:00), Endor(9:00), Naboo(7:00), Naboo(9:00), Tatooine(7:00), Tatooine(9:00)

int main(void){
    Booking_Dinner();
}

void Booking_Dinner() {
    char BookingIDresponse[150];
    int key = 0;
    printf("What is your BookingID?  Answer here: "); //In future, we will need to link this with the other systems in order to create persistant BookingID, until then I will use a placeholder of BOB123 until then.
    scanf("%s", BookingIDresponse);
    sprintf(bookingID[1], "BOB123");
    sprintf(bookingData[1], "HN4N15N");
    sprintf(bookingID[2], "LARRY425");
    sprintf(bookingData[2], "BN4N15N");
    for(int x = 0; x<6; x++) {
        int n = strcmp(bookingID[x], BookingIDresponse);
        if(n == 0) {
            printf("Welcome, %s\n", bookingID[x]);
            if(bookingData[x][0] == 'H') {
                printf("You have half board.\n");
                if (bookingData[x][2] <= '4') {
                    printf("The tables and their keys are as follows:\n");
                    if(Table_available[0] == 0) {
                        printf("\n Endor at 7 o'clock (Key 17) (Available)\n");
                    }
                    if(Table_available[0] == 1) {
                        printf("\n Endor at 7 o'clock (Booked)\n");
                    }
                    if(Table_available[1] == 0) {
                        printf("\n Endor at 9 o'clock (Key 19) (Available)\n");
                    }
                    if(Table_available[1] == 1) {
                        printf("\n Endor at 9 o'clock (Booked)\n");
                    }
                    if(Table_available[2] == 0) {
                        printf("\n Naboo at 7 o'clock (Key 27) (Available)\n");
                    }
                    if(Table_available[2] == 1) {
                        printf("\n Naboo at 7 o'clock (Booked)\n");
                    }
                    if(Table_available[3] == 0) {
                        printf("\n Naboo at 9 o'clock (Key 29) (Available)\n");
                    }
                    if(Table_available[3] == 1) {
                        printf("\n Naboo at 9 o'clock (Booked)\n");
                    }
                    if(Table_available[4] == 0) {
                        printf("\n Tatooine at 7 o'clock (Key 37) (Available)\n");
                    }
                    if(Table_available[4] == 1) {
                        printf("\n Tatooine at 7 o'clock (Booked)\n");
                    }
                    if(Table_available[5] == 0) {
                        printf("\n Tatooine at 9 o'clock (Key 39) (Available)\n\n");
                    }
                    if(Table_available[5] == 1) {
                        printf("\n Tatooine at 9 o'clock (Booked)\n\n");
                    }
                    printf("Please enter the key of the Table you would like to book. Answer here:");
                    scanf("%d", &key);
                    if(key == 17) {
                        printf("\n You have been booked for the Endor table at 7 o'clock.\n");
                        Table_available[0] = 1;
                    }
                    if(key == 19) {
                        printf("\n You have been booked for the Endor table at 9 o'clock.\n");
                        Table_available[1] = 1;
                    }
                    if(key == 27) {
                        printf("\n You have been booked for the Naboo table at 7 o'clock.\n");
                        Table_available[2] = 1;
                    }
                    if(key == 29) {
                        printf("\n You have been booked for the Naboo table at 9 o'clock.\n");
                        Table_available[3] = 1;
                    }
                    if(key == 37) {
                        printf("\n You have been booked for the Tatooine table at 7 o'clock.\n");
                        Table_available[4] = 1;
                    }
                    if(key == 39) {
                        printf("\n You have been booked for the Tatooine table at 9 o'clock.\n");
                        Table_available[5] = 1;
                    }
                    // Put a quit function here and after all of the available tables.
                }
                else {
                    printf("There are no tables available for your booking size.");
                }
            }
            else if(bookingData[x][0] == 'F') {
                printf("You have full board.\n");if (bookingData[x][2] <= '4') {
                    printf("The tables and their keys are as follows:\n");
                    if(Table_available[0] == 0) {
                        printf("\n Endor at 7 o'clock (Key 17) (Available)\n");
                    }
                    if(Table_available[0] == 1) {
                        printf("\n Endor at 7 o'clock (Booked)\n");
                    }
                    if(Table_available[1] == 0) {
                        printf("\n Endor at 9 o'clock (Key 19) (Available)\n");
                    }
                    if(Table_available[1] == 1) {
                        printf("\n Endor at 9 o'clock (Booked)\n");
                    }
                    if(Table_available[2] == 0) {
                        printf("\n Naboo at 7 o'clock (Key 27) (Available)\n");
                    }
                    if(Table_available[2] == 1) {
                        printf("\n Naboo at 7 o'clock (Booked)\n");
                    }
                    if(Table_available[3] == 0) {
                        printf("\n Naboo at 9 o'clock (Key 29) (Available)\n");
                    }
                    if(Table_available[3] == 1) {
                        printf("\n Naboo at 9 o'clock (Booked)\n");
                    }
                    if(Table_available[4] == 0) {
                        printf("\n Tatooine at 7 o'clock (Key 37) (Available)\n");
                    }
                    if(Table_available[4] == 1) {
                        printf("\n Tatooine at 7 o'clock (Booked)\n");
                    }
                    if(Table_available[5] == 0) {
                        printf("\n Tatooine at 9 o'clock (Key 39) (Available)\n\n");
                    }
                    if(Table_available[5] == 1) {
                        printf("\n Tatooine at 9 o'clock (Booked)\n\n");
                    }
                    printf("Please enter the key of the Table you would like to book. Answer here:");
                    scanf("%d", &key);
                    if(key == 17) {
                        printf("\n You have been booked for the Endor table at 7 o'clock.\n");
                        Table_available[0] = 1;
                    }
                    if(key == 19) {
                        printf("\n You have been booked for the Endor table at 9 o'clock.\n");
                        Table_available[1] = 1;
                    }
                    if(key == 27) {
                        printf("\n You have been booked for the Naboo table at 7 o'clock.\n");
                        Table_available[2] = 1;
                    }
                    if(key == 29) {
                        printf("\n You have been booked for the Naboo table at 9 o'clock.\n");
                        Table_available[3] = 1;
                    }
                    if(key == 37) {
                        printf("\n You have been booked for the Tatooine table at 7 o'clock.\n");
                        Table_available[4] = 1;
                    }
                    if(key == 39) {
                        printf("\n You have been booked for the Tatooine table at 9 o'clock.\n");
                        Table_available[5] = 1;
                    }
                    // Put a quit function here and after all of the available tables.
                }
                else {
                    printf("There are no tables available for your booking size.");
                }
            }
            else{
                printf("You are not eligible for booking a table.\n");
            }
        }
    }
}

