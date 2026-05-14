#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


char bookingData[100][8];
char bookingID[100][100];




void checkOut();
void addToBookingData(); //This is only for developing separately
void quit();//This is only for developing separately

int main(void){
   addToBookingData();
   checkOut();
}

//ONLY FOR DEVELOPMENT
void quit() {
   printf("Quitted");
}

//ONLY FOR DEVELOPMENT
void addToBookingData(){

   sprintf(bookingID[0],"BOB123");
   bookingData[0][0] = 'H';
   bookingData[0][1] = 'Y';
   bookingData[0][2] = '3';
   bookingData[0][3] = 'Y';
   bookingData[0][4] = '3';
   bookingData[0][5] = '6';
   bookingData[0][6] = 'N';
   bookingData[0][7] = '6';
   sprintf(bookingID[4],"CHRIS217");
   bookingData[4][0] = 'F';
   bookingData[4][1] = 'Y';
   bookingData[4][2] = '3';
   bookingData[4][3] = 'Y';
   bookingData[4][4] = '5';
   bookingData[4][5] = '9';
   bookingData[4][6] = 'Y';
   bookingData[4][7] = '1';

}
void checkOut() {
   //ASKS USER TO ENTER BOOKING ID
   char enterString[100];
   puts("Enter booking ID:");
   gets(enterString);
   char blank[100] = "" ;
   if (enterString==" " || strlen(enterString)==0 ) {
       checkOut();
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
           scanf("%c",&bookingIDwrongChoice);
           switch (bookingIDwrongChoice) {
               case 'a':
                   checkOut();
               case 'b':
                   main();
           }

       }
   }
   const int bookingColumn = newNum;
   // for (int i = 0; i < 100; i++) {
   //     for (int j = 0; j < strlen(bookingID[i]); j++) {
   //         newString[j] = bookingID[i][j];
   //     }
   //     if (strcmp(newString, bookingID[i]) == 0) {
   //         bookingColumn = i;
   //         i=101;
   //     }
   //     if (i == 99) {
   //         quit();
   //     }
   // }
   //-------------------------------------------------------------------------------
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
       subtotalRoom = intDays*80;
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

   if (bookingData[bookingColumn][3]=='Y') {

       fltBill = bill;
       fltBill = fltBill * 0.9;
       applied65Discount = 'Y';
   }
   else {
       applied65Discount = 'N';
   }

   //
   //
   // printf("\n---Room Total:            $%d ---",subtotalRoom);
   // printf("\n---Board Total:           $%d ---",subtotalBoard);
   // printf("\n---Newspaper Total:       $%d ---",subtotalNewspaper);
   // printf("\n---Got child discount:     %c ---",childDiscount);
   // printf("\n---Got under 65 discount:  %c ---", applied65Discount);
   // printf("\n--------------------------------");
   // printf("\nTOTAL: %f",fltBill);




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

