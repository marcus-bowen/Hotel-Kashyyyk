#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include<string.h>
#include <ctype.h>

char bookingData[100][8];
char bookingID[100][100];
int Table_available[6] = {0,0,0,0,0,0};

void quit();
void checkIn();
void Booking_Dinner();
void checkOut();

int main(void) {
    sprintf(bookingID[1],"Marcus001");
    sprintf(bookingData[1],"HN4N15N");
    printf("Welcome to Hotel Kashyyk\n");
    char mainInput;
    fflush(stdin);
    printf("What would you like to do?\n(a) CHECK IN\n(b) BOOK A TABLE\n(c) CHECK OUT\nEnter Here");
    scanf(" %c",&mainInput);
    if (mainInput == 'a') {
        checkIn();
    }
    else if (mainInput == 'b') {
        Booking_Dinner();
    }
    else if (mainInput == 'c') {
        checkOut();
    }
    else {
        quit();
    }
}
void quit() {
    main();
}
void checkIn() {
    char firstName[50];
    char lastName[50];
    int dob;
    char numOfGuests;
    char numOfChildren;
    char boardType;
    char numOfDays;
    char newspaper;
    char whichRoom;
    char nameFlag = 'f';
    char alphabet[27] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

    //GETS NAME
    do {
        nameFlag = 'f';
        fflush(stdin);
        printf("\nWhat is your first name: ");
        gets(firstName);
        for (int j = 0;j<strlen(firstName);j++) {
            if (isalpha(firstName[j])==0) {
                nameFlag = 't';
            }
        }
    } while (nameFlag != 'f');

    do {
        nameFlag = 'f';
        fflush(stdin);
        printf("\nWhat is your last name: ");
        gets(lastName);
        for (int j = 0;j<strlen(lastName);j++) {
            if (isalpha(lastName[j])==0) {
                nameFlag = 't';
            }
        }
    } while (nameFlag != 'f'||strlen(lastName)>65);

    fflush(stdin);
    //ADDS TO BOOKING ID ARRAY
    int bookingColumn;
    for (int i= 0; i<100; i++){
        if (strlen(bookingID[i]) == 0) {
            bookingColumn = i;
            i=101;
        }
        else if (i>= 99) {
            printf("No existing spaces in hotel");
            exit(main());
        }
    }

    //GETS DATE OF BIRT
    char dateFlag='f';
    char charYear[8];
    do{
        dateFlag = 'f';
        printf("\nWhat is your year of birth, enter in format YYYY: ");
        scanf("%d",&dob);
        sprintf(charYear,"%d",dob);
        for (int i =0; i<4;i++) {
            if (isdigit(charYear[i])>0) {
                dateFlag = 'f';
            }
            else if (isdigit(charYear[i])==0) {
                dateFlag = 't';
            }
            fflush(stdin);
        }
    }while (dob>2010 || dateFlag != 'f' || dob <1920);

    if (dob<1960) {
        bookingData[bookingColumn][3]='Y';
    }
    else {
        bookingData[bookingColumn][3]='N';
    }
    //HOW MANY IN ROOM

    do {
        printf("\nHow many are staying in the room?: ");
        scanf(" %c",&numOfGuests);
        fflush(stdin);
    }while (numOfGuests != '1' && numOfGuests != '2' && numOfGuests != '3' && numOfGuests != '4');

    bookingData[bookingColumn][2]=numOfGuests;
    do {
        printf("\nHow many children are staying in the room?: ");
        scanf(" %c",&numOfChildren);
        fflush(stdin);
    }while (isdigit(numOfChildren)==0);

    bookingData[bookingColumn][7]=numOfChildren;
    //BOARD
    char boardFlag='f';
    do {
        printf("\nWhich board do you want: (F) Full board, (H) Half board, (B) Bed and Breakfast: ");
        scanf(" %c",&boardType);

        fflush(stdin);
    }while (isalpha(boardType)==0 ||( boardType!='F' && boardType!='f' && boardType!='H' && boardType!='h'&& boardType!='B' && boardType!='b'));
    bookingData[bookingColumn][0]=boardType;
    //DAYS STAYED
    do {
        fflush(stdin);
        printf("\nHow many days are you staying for?: ");
        scanf(" %c",&numOfDays);
    }while (isdigit(numOfDays)==0 || numOfDays<9);
    fflush(stdin);
    bookingData[bookingColumn][5]=numOfDays;
    //NEWSPAPER
    do {
        printf("Do you want a daily newspaper?: Enter with Y or N:  ");
        scanf(" %c",&newspaper);
    }while (newspaper != 'y' && newspaper != 'n' && newspaper != 'Y' && newspaper != 'N');
    bookingData[bookingColumn][6]=newspaper;
    fflush(stdin);
    //WHICH ROOM
    do {
        printf("These are the available rooms and their prices: Room rates per room, per day: \n\tRoom 1 & 2 = $100,\n\tRoom 3 = $85, \n\tRoom 4 & 5 = $75 \n\tand \n\tRoom 6 = $50, \nwhich do you choose:");
        scanf(" %c",&whichRoom);
    }while (whichRoom != '1' && whichRoom != '2' && whichRoom != '3' && whichRoom != '4' && whichRoom != '6');
    bookingData[bookingColumn][4]=whichRoom;
    fflush(stdin);
    //GIVES BOOKING ID
    char bookingIDstring[65];
    char randString[65];

    srand(time(NULL));
    int random = rand() % 999;
    if (random<100) {
        random = random + 100;
    }

    sprintf(bookingIDstring,lastName);
    sprintf(randString,"%d",random);
    strcat(bookingIDstring,randString);
    sprintf(bookingID[bookingColumn],bookingIDstring);
    printf("Your booking ID is: "); puts(bookingIDstring); printf("\n\n");
    quit();
}
void Booking_Dinner() {
    char BookingIDresponse[150];
    int key = 0;
    fflush(stdin);
    printf("\nWhat is your BookingID?  Answer here: "); //In future, we will need to link this with the other systems in order to create persistant BookingID, until then I will use a placeholder of BOB123 until then.
    scanf("%s", BookingIDresponse);
    fflush(stdin);
    for(int x = 0; x<7; x++) {
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
                        do {
                            printf("Please enter the key of the Table you would like to book. Answer here:");
                            scanf("%d", &key);
                        }while (isdigit(key)>0);

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

                        else if (key > 39) {
                            //printf("There are no tables available for your booking size.");
                        }
                    }
                }
                else if(bookingData[x][0] == 'F') {
                    printf("You have full board.\n");
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
                        scanf(" %d", &key);

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
    quit();
}


void checkOut(){

            fflush(stdin);
            //ASKS USER TO ENTER BOOKING ID
            char enterString[100];
            puts("Enter booking ID:");
            gets(enterString);
            if (strlen(enterString)==0 ) {
                checkOut();
                return;
            }
            //FINDS THE BOOKING ID THE USER HAS ENTERED
            int newNum = 0;
            for (int i= 0; i<100; i++){
                char newString[100] = "";
                for (int j= 0; j<100; j++) {
                    newString[j] = bookingID[i][j];
                }
                if (strcmp(newString,enterString) == 0) {
                    newNum = i;
                    i=101;
                }
                else if (i>= 99) {
                    char bookingIDwrongChoice;
                    printf("\nYou entered your booking ID wrong or it is not in the system");
                    printf("\nDo you wish to \n   a)Enter again \nor\n   b)Return to main menu\n\nEnter Choice Here: ");
                    fflush(stdin);
                    scanf(" %c",&bookingIDwrongChoice);
                    switch (bookingIDwrongChoice) {
                        case 'a':
                            checkOut();
                            break;
                        case 'b':
                            main();
                            break;
                    }

                }
            }
            const int bookingColumn = newNum;
            //BILL CALCULATION STARTS:
            int bill = 0;
            //CONVERTS NUMBER OF DAYS TO AN INTEGER:
            char daysChar = bookingData[bookingColumn][5];

            int intDays = 0;

            for (int i = 0; i < 9; i++) {
                char numbArray[11] = {'1','2','3','4','5','6','7','8','9'};
                char value = numbArray[i];
                if (daysChar == value) {
                    intDays = i+1;
                    i=11;
                }
                ;
            }

            //CONVERTS NUMBER OF PEOPLE TO AN INTEGER:
            char numPeopleChar = bookingData[bookingColumn][5];
            int intNumPeople = 0;

            for (int i = 0; i < 9; i++) {
                char numArray[11] = {'1','2','3','4','5','6','7','8','9'};
                char value = numArray[i];
                if (numPeopleChar == value) {
                    intNumPeople = i+1;
                    i=11;
                }

            }
            //CONVERTS NUMBER OF CHILDREN TO AN INTEGER:
            char numChildrenChar = bookingData[bookingColumn][7];

            int intNumChildren = 0;

            for (int i = 0; i < 9; i++) {
                char numArray[11] = {'1','2','3','4','5','6','7','8','9'};
                char value = numArray[i];
                if (numChildrenChar == value) {
                    intNumChildren = i+1;
                    i=11;
                }

            }
            //FINDS THE TOTAL FOR THE ROOMS
            int subtotalRoom = 0;

            if (bookingData[bookingColumn][4]=='1' || bookingData[bookingColumn][4]=='2') {
                bill += intDays*100;
                subtotalRoom = intDays*100;
            }
            else if (bookingData[bookingColumn][4]=='3' ) {
                bill += intDays*80;
                subtotalRoom = intDays*80;
            }
            if (bookingData[bookingColumn][4]=='4' || bookingData[bookingColumn][4]=='5') {
                bill += intDays*75;
                subtotalRoom = intDays*75;
            }
            else if (bookingData[bookingColumn][4]=='6' ) {
                bill += intDays*50;
                subtotalRoom = intDays*50;
            }


            //FINDS THE TOTAL FOR THE BOARDS
            int subtotalBoard = 0;
            char childDiscount = 'N';

            if (bookingData[bookingColumn][0] == 'H') {
                int halfPrice=7;
                bill += 15 * intDays * intNumPeople;
                subtotalBoard = 15 * intDays * intNumPeople;
                if (intNumChildren>0) {
                    childDiscount = 'Y';
                    bill -= intNumChildren*halfPrice;
                    subtotalBoard -= intNumChildren*halfPrice;
                }
            }
            else if (bookingData[bookingColumn][0] == 'F') {
                int halfPrice=10;
                bill += 20 * intDays * intNumPeople;
                subtotalBoard = 20 * intDays * intNumPeople;
                if (intNumChildren>0) {
                    childDiscount = 'Y';
                    bill -= intNumChildren*halfPrice;
                    subtotalBoard -= intNumChildren*15*halfPrice;
                }
            }
            else if (bookingData[bookingColumn][0] == 'B') {
                int halfPrice=2;
                bill += 5 * intDays * intNumPeople;
                subtotalBoard = 5 * intDays * intNumPeople;
                if (intNumChildren>0) {
                    childDiscount = 'Y';
                    bill -= intNumChildren*halfPrice;
                    subtotalBoard -= intNumChildren*halfPrice;
                }
            }

            //ADDS NEWSPAPERS TO BILL
            int subtotalNewspaper=0;
            char outputFloatSubtotalNewspaper[100];

            if (bookingData[bookingColumn][6]=='Y'   ) {
                subtotalNewspaper = 5;
                sprintf(outputFloatSubtotalNewspaper, "5.50 ---", subtotalBoard);
            }
            else {

                subtotalNewspaper = 0;

                int floatSubtotalNewspaper = 0;

                sprintf(outputFloatSubtotalNewspaper,"  0 ---");

            }
            //CHECKS TO ADD OVER 65 DISCOUNT
            float fltBill = 0;
            char applied65Discount = 'N';
            fltBill = bill;
            if (bookingData[bookingColumn][3]=='Y') {

                fltBill = fltBill * 0.9;
                applied65Discount = 'Y';
            }
            else {
                applied65Discount = 'N';
            }

            printf("\n\nFINAL TOTAL RECEIPT FOR YOUR STAY:");
            printf("\n--------------------------------");
            printf("\n---Room Total:          $%d ---",subtotalRoom);
            printf("\n---Board Total:         $%d ---",subtotalBoard);
            printf("\n---Newspaper Total:     $"); puts(outputFloatSubtotalNewspaper);
            printf("---Got child discount:     %c ---",childDiscount);
            printf("\n---Got under 65 discount:  %c ---", applied65Discount);
            printf("\n--------------------------------");
            printf("\nTOTAL: $%.2f",fltBill*1);



        }
