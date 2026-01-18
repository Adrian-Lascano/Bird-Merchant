//gcc -Wall -std=c99 MPLascano_SecretCode.c -o run.exe && ./run.exe

/******************************************************************************
This is to certify that this project is my own work, based on my personal
efforts in studying and applying the concepts learned. I have constructed
the functions and their respective algorithms and corresponding code by
myself. The program was run, tested, and debugged by my own efforts. I
further certify that I have not copied in part or whole or otherwise
plagiarized the work of other students and/or persons.
Adrian George Andres B. Lascano - 12514640 - S20B
******************************************************************************/

/*
    Description: This program implements the Bird Merchant game in C, where the player must gather 30 units of corn within 25 days by traveling between locations, buying and selling seed and corn. The game follows specific mechanics, including travel times, exchange rates, and win/lose conditions.
    Programmer: Adrian George Andres B. Lascano  |  S20B
    Last Modified: November 20, 2025
    Version: 2.2
    Acknowledgements: CCPROG1 Modules, Final Project Document, https://www.w3schools.com/c/c_intro.php
*/

#include <stdio.h>
#include "MPLascano_fn.c"       // Normal Game Mode

int main(){

    //initialize values 
    float nSeed = 5.00, nCorn = 0.00;
    int nDay = 0, location = 1;
    int nChoice, nCode = 0;

    int nUsed123456 = 0;        // Ensure 123456 is used only once

        //recognizes the start of the game without storing anything, no error as well
        printf("Welcome to Bird Merchant!!!\n");
        printf("Input any character to start: ");
        char dummy;
        scanf(" %c", &dummy);

    // Main Game Loop
    while (nDay<=25 && nCorn < 30.00){

        displayGame(nDay, nSeed, nCorn, &location, &nChoice, &nCode); //displays the whole UI

            if (nChoice == -1) {
                printf("\nINVALID INPUT!\n\n");
            }else{
                // Check for secret code and add seeds (only one timee can use the code) (Code = LAUREN or lauren)
                    if (nCode == 123456 && !nUsed123456) {
                        printf("\n\033[31mYou Have Cracked One Of The Codes: %d\033[0m\n\n", nCode);
                        nSeed += 10;
                        nUsed123456 = 1;
                        nCode = 0;                      // Reset nCode to allow building a new code for the other option
                    }
            }


            // If choice is travel
            if (nChoice >= 1 && nChoice <= 4) {
                nCode = 0;
                if (nChoice == location) {
                    printf("\nCannot wait in the same location! Travel to another.\n");
                } else if ((location == 4 && nChoice == 1) || (location == 1 && nChoice == 4)) {
                    printf("\nLocation Not Found!\n");
                } else {
                    printf("\nTravel Successful!\n");
                    int nTravel = travelDays(location, nChoice);
                    if (nTravel > 0) {
                        nDay += nTravel;
                        location = updateLocation(location, nChoice);
                        nSeed = addSeedTravel(nSeed, nTravel);
                    }
                }
            }

            // If choice is corn to seed
            else if (nChoice == 5) {
                nCode = 0;
                if (enoughCornToSeed(nCorn, buySeedRate(location)) == 1)
                {
                    nCorn = buySeed(nCorn, buySeedRate(location));
                    nSeed += 1.00;
                    printf("\nPurchase Successful!\n\n");
                }else{
                    printf("\nNot Enough Corns!\n\n");
                }
            }

            // If choice is seed to corn
            else if (nChoice == 6) {
                nCode = 0;
                if (enoughSeedToCorn(nSeed, buyCornRate(location)) == 1)
                {
                    nSeed = buyCorn(nSeed, buyCornRate(location));
                    nCorn += 1.00;
                    printf("\nPurchase Successful!\n\n");
                }else{
                    printf("\nNot Enough Seeds!\n\n");
                }
            }

            
            else if (nChoice == 7)
            {   
                int nblkChoice, nCount = 0; //display how much bought, instead of assigning prev stock

                    printf("\nBulk Buying\n");
                    printf("\n1 - Seeds\n");
                    printf("2 - Corns\n");
                    printf("\nChoice: ");
                    scanf("%d", &nblkChoice);
                
                switch (nblkChoice)
                {
                case 1:
                        // bulk buying seeds
                        if (nCorn >= buySeedRate(location))
                        {
                            while (nCorn >= buySeedRate(location)){
                                nCorn = buySeed(nCorn, buySeedRate(location));
                                nSeed += 1.0;
                                nCount++;
                            }
                                printf("\nBulk purchase complete! Bought %d seed(s).\n\n", nCount);
                        }
                        else if (nCorn < buySeedRate(location)){
                            printf("\nNot enough Corns!\n\n");
                        }
                        
                    break;
                case 2:
                        // bulk buying corn
                        if (nSeed >= buyCornRate(location))
                        {
                            while (nSeed >= buyCornRate(location)){
                                nSeed = buyCorn(nSeed, buyCornRate(location));
                                nCorn += 1.0;
                                nCount++;
                            }
                                printf("\nBulk purchase complete! Bought %d seed(s).\n\n", nCount);
                        }
                        else if (nSeed < buyCornRate(location)){
                            printf("\nNot enough Seeds!\n\n");
                        }
                    break;
                default:
                    break;
                }

                
            }
            

        // Check game status
        int gStatus = gameStatus(nCorn, nDay);

            //display current stats
                    if (gStatus == 1){
                        printf("Location: ");
                            //display correct location
                            switch (location)
                            {
                            case 1:
                                printf("Quail Land");
                                break;
                            case 2:
                                printf("Duck Land");
                                break;
                            case 3:
                                printf("Turkey Land");
                                break;
                            case 4:
                                printf("Parrot Land");
                                break;
                            default:
                                break;
                            }
                        

                        printf("\nSeed: %.2f\n", nSeed);
                        printf("Corn: %.2f\n", nCorn);
                        printf("Days: %d\n", nDay);
                        printf("---- ---- ----\n");
                
                        printf("Win!\n\n");
                    }
                    else if (gStatus == 2){
                        printf("Location: ");
                            //display correct location
                            switch (location)
                            {
                            case 1:
                                printf("Quail Land");
                                break;
                            case 2:
                                printf("Duck Land");
                                break;
                            case 3:
                                printf("Turkey Land");
                                break;
                            case 4:
                                printf("Parrot Land");
                                break;
                            default:
                                break;
                            }
                        

                        printf("\nSeed: %.2f\n", nSeed);
                        printf("Corn: %.2f\n", nCorn);
                        printf("Days: %d\n", nDay);
                        printf("---- ---- ----\n");

                        printf("Lose!\n\n");
                    }

    } //While end
        
        return 0;


}