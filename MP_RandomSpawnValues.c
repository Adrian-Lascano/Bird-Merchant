//gcc -Wall -std=c99 MP_RandomSpawnValues.c -o run.exe && ./run.exe

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
#include <stdlib.h>             //include random generator
#include <time.h>               //generates new random number per run
#include "MPLascano_fn.c"       // Normal Game Mode
#include "MPLascano_fn2.c"      //Addtional Harder Game Mode

int main(){
    srand(time(NULL));  //different generated numbers per run

    //initialize values 
    float nSeed = 5.00, nCorn = 0.00;
    int nDay = 0;
    int nChoice, nCode = 0;
    int nUsed123456 = 0;                //Ensure 123456 is used only once

    
        //recognizes the start of the game without storing anything, no error as well
        printf("Welcome to Bird Merchant!!!\n");
        printf("Input any character to start: ");
    char dummy;
        scanf(" %c", &dummy);


        //USER INPUTS GAMES MODE
        printf("---- ---- ----\n");
        printf("Game Modes:\n");
        printf("1 - Original Bird Merchant\n");
        printf("2 - Extreme Bird Merchant (Random Spawn and Changing Values)\n");
        printf("Select a Mode: ");
    int nGameMode;
        scanf(" %d", &nGameMode);

    // Main Game
    switch (nGameMode)
    {
    case 1:     //Normal Gameplay

        int location = 1;                       //Starts in Quail Land

        while (nDay<=25 && nCorn < 30.00){

            displayGame(nDay, nSeed, nCorn, &location, &nChoice, &nCode); //displays the whole UI

                if (nChoice == -1) {
                    printf("\nINVALID INPUT!\n\n");
                }else{
                    // Check for secret code and add seeds (only one time can use the code) (Code = LAUREN or lauren)
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
        break;

    case 2:     //Extreme Gameplay

        int location2 = randomSpawn();           //Randomly Starts in Any Land
        float nRSeed, nRCorn;

        printf("\nExtreme Game Mode Includes:\n");       //further Explanation
        printf("Random Start (start in any land)\n");
        printf("Changing values EVERY transaction\n");
        printf("Bulk buying rate is constant and whole\n");
        printf("batch will be bought in one rate\n");
        printf("---- ---- ----\n");
        printf("Start Game? Yes or No? ");
        scanf(" %s", &dummy);

        while (nDay<=25 && nCorn < 30.00){
            
            displayLand(nDay, nSeed, nCorn, &location2); //displays the Travel Choices
            randomValues(&nRSeed, &nRCorn);

                //display other actions
                printf("S - Buy Seed (%.2f corn)\n", nRSeed);   //Seed Rate
                printf("C - Buy Corn (%.2f seed)\n", nRCorn);   //Corn Rate

                if (nSeed > 10 || nCorn > 10){printf("B - Buy Bulk Seed/Corn (buy everything)\n");}

            userInput(&nChoice, &nCode);                //asks for user input (includes code cracker)

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
                    if (nChoice == location2) {
                        printf("\nCannot wait in the same location! Travel to another.\n");
                    } else if ((location2 == 4 && nChoice == 1) || (location2 == 1 && nChoice == 4)) {
                        printf("\nLocation Not Found!\n");
                    } else {
                        printf("\nTravel Successful!\n");
                        int nTravel = travelDays(location2, nChoice);
                        if (nTravel > 0) {
                            nDay += nTravel;
                            location2 = updateLocation(location2, nChoice);
                            nSeed = addSeedTravel(nSeed, nTravel);
                        }
                    }
                }
            //If choice is corn to seed
            else if (nChoice == 5) {
                nCode = 0;
                if (enoughCornToSeed(nCorn, nRSeed) == 1)
                {
                    nCorn = buySeed(nCorn, nRSeed);
                    nSeed += 1.00;
                    printf("\nPurchase Successful!\n\n");
                }else{
                    printf("\nNot Enough Corns!\n\n");
                }
            }

            //If choice is seed to corn
            else if (nChoice == 6) {
                nCode = 0;
                if (enoughSeedToCorn(nSeed, nRCorn) == 1)
                {
                    nSeed = buyCorn(nSeed, nRCorn);
                    nCorn += 1.00;
                    printf("\nPurchase Successful!\n\n");
                }else{
                    printf("\nNot Enough Seeds!\n\n");
                }
            }

            //If choice is buy bulk or seed/corn
            else if (nChoice == 7 && ((nSeed > 10) || nCorn > 10))
            {   
                int nblkChoice, nCount = 0; //display how much bought, instead of assigning prev stock

                    printf("\nBulk Buying\n");
                    printf("\n1 - Seeds\n");
                    printf("2 - Corns\n");
                    printf("\nChoice: ");
                    scanf("%d", &nblkChoice);   //choice of user, either seed or corn
                
                switch (nblkChoice)
                {
                case 1:
                        //bulk buying seeds
                        if (nCorn >= nRSeed)
                        {
                            while (nCorn >= nRSeed){
                                nCorn = buySeed(nCorn, nRSeed);
                                nSeed += 1.0;
                                nCount++;
                            }
                                printf("\nBulk purchase complete! Bought %d seed/s.\n\n", nCount);
                        }
                        else if (nCorn < nRSeed){
                            printf("\nNot enough Corns!\n\n");
                        }
                        
                    break;
                case 2:
                        //bulk buying corn
                        if (nSeed >= nRCorn)
                        {
                            while (nSeed >= nRCorn){
                                nSeed = buyCorn(nSeed, nRCorn);
                                nCorn += 1.0;
                                nCount++;
                            }
                                printf("\nBulk purchase complete! Bought %d corn/s.\n\n", nCount);
                        }
                        else if (nSeed < nRCorn){
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
        }
        break;

    default:
        printf("\n\033[31mInvalid Game Mode!!! Play Again!!!\033[0m\n\n");
        break;
    }
        
        return 0;

}