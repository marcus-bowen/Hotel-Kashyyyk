#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Cannot check if the rooms got booked

void checkIn();

char bookingData[100][8];

int main(void) {
    checkIn();
}

void checkIn() {
    char bookingID[100], broadType, userFirstName[100], userSurname[100], userDOB[9], dailyNewspaper, childPresent;
    int numOfGuests = 0, tempNumOfGuests = 0, numOfDays = 0, numOfRooms = 0, userRoom = 0;
    int DD = 0, MM = 0, YY = 0, numOfAdults = 0, numOfChildren = 0;
    srand(time(NULL));

    //Entering and storing user's name
    printf("Please enter your first name: ");
    scanf("%s", userFirstName);
    printf("Please enter your surname: ");
    scanf("%s", userSurname);

    //Entering date of birth
    do {
        printf("\n Please enter the date of your birth: ");
        scanf("%2d", &DD);
        printf("Please enter the month of your birth: ");
        scanf("%2d", &MM);
        printf("Please enter the year of your birth: ");
        scanf("%4d", &YY);
    } while(DD<1 || DD>31 || MM < 1 || MM>12 || DD<28 && MM==2);
    snprintf(userDOB, sizeof(userDOB), "%02d/%02d/%02d", DD, MM, YY % 100); //Test

    //Entering number of guests
    printf("\nPlease enter the number of adults: ");
    scanf("%d", &numOfAdults);
    printf("Please enter the number of children (16 or below): ");
    scanf("%d", &numOfChildren);
    if (numOfChildren > 0) {
        childPresent = 'Y';
    }
    else {
        childPresent = 'N';
    }
    numOfGuests = numOfAdults + numOfChildren;
    tempNumOfGuests = numOfAdults + numOfChildren;

    //Choosing rooms
    do {
        //Entering room number
        printf("\nRoom rates per room, per day:\n - Room 1 & 2 = £100\n - Room 3 = £85\n - Room 4 & 5 = £75\n - Room 6 = £50");
        do {
            printf("\nEnter room number: ");
            scanf(" %d", &userRoom);
        } while (userRoom < 1 || userRoom > 6);

        //Entering broad type
        printf("\nBoard rates are per person, per day:\n - Full board = £20\n - half board = £15\n - B&B = £5");
        do {
            printf("\nEnter broad type (F/H/B): ");
            scanf(" %c", &broadType);
            numOfRooms += 1;
        } while (broadType != 'F' && broadType != 'H' && broadType != 'B');
        tempNumOfGuests -= 1;
    } while (tempNumOfGuests > 4);

    //Entering the amount of day staying
    printf("\nHow long are you going to stay: ");
    scanf("%d", &numOfDays);

    //If the user wants the newspaper
    do {
        printf("\nAre you interested in the newspaper? (y/n) ");
    scanf(" %c", &dailyNewspaper);
    } while (dailyNewspaper != 'y' && dailyNewspaper != 'n');

    //Booking ID
    sprintf(bookingID, "%s%d", userSurname, rand()%900+100);
    printf("\nYour booking ID is %s", bookingID);
}
