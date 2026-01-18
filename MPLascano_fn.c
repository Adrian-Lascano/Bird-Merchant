
#include <stdio.h>

//GAME UI

// Display the whole user interface with values
// Pre-conditions: day, seed and corn have own values
//                 location and nchoice are dependent on choice (unless starting)
// @param Day: days have past every after travel
// @param Seed: total seed
// @param Corn: total corn gathered
// @param *Location: send value of location
// @param *nChoice: send value of choice
    void displayGame(int Day, float Seed, float Corn, int *location, int *nChoice, int *nCode){
        
        printf("\nLocation: ");
            //display correct location
            switch (*location)
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
            

        printf("\nSeed: %.2f\n", Seed);
        printf("Corn: %.2f\n", Corn);
        printf("Days: %d\n", Day);
        printf("---- ---- ----\n");
        
        // This will display options depending on location
        if (*location == 1) {
            printf("D - Go Duck Land (5 days)\n");
            printf("T - Go Turkey Land (3 days)\n");
            printf("S - Buy Seed (1.00 corn)\n");
            printf("C - Buy Corn (1.50 seed)\n");
            if (Seed > 10 || Corn > 10){printf("B - Buy Bulk Seed/Corn (buy everything)\n");}
        } else if (*location == 2) {
            printf("Q - Go Quail Land (5 days)\n");
            printf("T - Go Turkey Land (3 days)\n");
            printf("P - Go Parrot Land (2 days)\n");
            printf("S - Buy Seed (0.75 corn)\n");
            printf("C - Buy Corn (1.50 seed)\n");
            if (Seed > 10 || Corn > 10){printf("B - Buy Bulk Seed/Corn (buy everything)\n");}
        } else if (*location == 3) {
            printf("Q - Go Quail Land (3 days)\n");
            printf("P - Go Parrot Land (4 days)\n");
            printf("D - Go Duck Land (3 days)\n");
            printf("S - Buy Seed (2.00 corn)\n");
            printf("C - Buy Corn (1.00 seed)\n");
            if (Seed > 10 || Corn > 10){printf("B - Buy Bulk Seed/Corn (buy everything)\n");}
        } else if (*location == 4) {
            printf("T - Go Turkey Land (4 days)\n");
            printf("D - Go Duck Land (2 days)\n");
            printf("S - Buy Seed (1.00 corn)\n");
            printf("C - Buy Corn (0.75 seed)\n");
            if (Seed > 10 || Corn > 10){printf("B - Buy Bulk Seed/Corn (buy everything)\n");}
        }

        //gather user input
        printf("---- ---- ----\n");
        printf("Select Action: ");
        char cChoice;
        scanf(" %c", &cChoice);

        //assign values for nChoice from 
        switch (cChoice){
            case 'q':case 'Q':
                *nChoice = 1; //travel to Quail Land
                break;
            case 'd':case 'D':
                *nChoice = 2; //travel to Duck Land
                break;
            case 't':case 'T':
                *nChoice = 3; //travel to Turkey Land
                break;
            case 'p':case 'P':
                *nChoice = 4; //travel to Parrot Land
                break;
            case 's':case 'S':
                *nChoice = 5; //buy seed
                break;
            case 'c':case 'C':
                *nChoice = 6; //buy corn
                break;
            case 'b':case 'B':
                *nChoice = 7; //buy bulk with everything
                break;
            default:
                *nChoice = -1;
                break;}

        //SECRET CODE - assign values for nChoice from 
        switch (cChoice){
            case 'l':case 'L':
                *nCode = (*nCode * 10) + 1; // 1st number of code
                break;
            case 'a':case 'A':
                *nCode = (*nCode * 10) + 2; //second number
                break;
            case 'u':case 'U':
                *nCode = (*nCode * 10) + 3; //third number
                break;
            case 'r':case 'R':
                *nCode = (*nCode * 10) + 4; //fourth nunmber
                break;
            case 'e':case 'E':
                *nCode = (*nCode * 10) + 5; //fifth number
                break;
            case 'n':case 'N':
                *nCode = (*nCode * 10) + 6; //sixth number
                break;
            default:
                break;}
    }



    //GAME PROCESS


// Returns the code to obtain more seed (twice can be executed)
// Pre-conditions: digits are all positive, defined from char user input
// @param fullCode: the previous digit
// @param nCode: the input value of the user
// @return: returns the added last digit
    int crackCode(int fullCode, int nCode){
        return (fullCode * 10) + nCode;     // Move current last digit to tens place and add the new number as last digit
    }

// Return the correct TRAVEL DAYS depending from point to point
// Pre-conditions: from and to are (1-4)
// @param From: starting location (location)
// @param To: destination location (choice)
// @return: travel days if connected, 0 otherwise
    int travelDays(int From, int To) {
        int nDays = 0;
        if ((From == 1 && To == 2) || (From == 2 && To == 1)) nDays = 5;   // Quail - Duck
        if ((From == 1 && To == 3) || (From == 3 && To == 1)) nDays = 3;   // Quail - Turkey
        if ((From == 2 && To == 3) || (From == 3 && To == 2)) nDays = 3;   // Duck - Turkey
        if ((From == 2 && To == 4) || (From == 4 && To == 2)) nDays = 2;   // Duck - Parrot
        if ((From == 3 && To == 4) || (From == 4 && To == 3)) nDays = 4;   // Turkey - Parrot
        return nDays;
    }

// Return the correct TRAVEL DAYS depending from point to point
// Pre-conditions: from and to are (1-4)
// @param From: starting location (location)
// @param To: destination location (choice)
// @return: travel days if connected, 0 otherwise
    float addSeedTravel(float Seed, int Days) {
        return Seed + Days;
    }

// Update location
// Pre-conditions: currenLoc and nChoice are (1-4)
// @param currentloc: Current location
// @param nChoice: Target location
// @return: returns correct location value
    int updateLocation(int currentLoc, int nChoice) {
        int newLoc;
        switch (nChoice) {
        case 1: newLoc = 1; break;              // Quail Land
        case 2: newLoc = 2; break;              // Duck Land
        case 3: newLoc = 3; break;              // Turkey Land
        case 4: newLoc = 4; break;              // Parrot Land
        default: newLoc = currentLoc; break;    // stay in place if buying/invalid
        }
        return newLoc;
    }

// checks game status (win, lose, or continue)
// Pre-conditions: win if corns >= 30 within 25 days
// @param corn: total corns
// @param days: days travelled
// @return: returns correct location value
    int gameStatus(float corns, int days) {
        int nRet = 0;
        if (corns >= 30 && days <= 25) nRet = 1;    // win
        if (days > 25) nRet = 2;                    // lose
        return nRet;                                // continue game
    }



    //SEEDS AND CORNS


// Checks the seed rate
// Pre-conditions: loc is a positive ranging 1-4
// @param location: checks location
// @return: corn required per seed
    float buySeedRate(int location) {
        float rate = 0.00; // Invalid location
        if (location == 1) {rate=1.00;}
        if (location == 2) {rate=0.75;}
        if (location == 3) {rate=2.00;}
        if (location == 4) {rate=1.00;}
        return rate;
    }

// checks the corn rate
// Pre-conditions: location is a positive ranging 1-4
// @param location: checks location
// @return: seed required per corn
    float buyCornRate(int location) {
        float rate = 0.00; // Invalid location, though shouldn't happen
        if (location == 1) {rate=1.50;}
        if (location == 2) {rate=1.50;}
        if (location == 3) {rate=1.00;}
        if (location == 4) {rate=0.75;}
        return rate;
    }

// Checks if corns are enough compared to rate
// Pre-conditions: corn >= 0.00, rate > 0
// @param corn: current corn
// @param rate: corn per seed
// @return: 1 if can buy (enough corn TRUE)
    int enoughCornToSeed(float corn, float rate) {
        return (corn >= rate) ? 1 : 0;             
    }

// check if seeds are enough compared to rate
// Pre-conditions: seed >= 0, rate > 0
// @param seed: current seed
// @param rate: seed per corn
// @return: 1 if can buy (enough TRUE)
    int enoughSeedToCorn(float seed, float rate) {
        return (seed >= rate) ? 1 : 0;
    }

// this function buys seed
// Pre-conditions: corn >= rate
// @param corn: current corn stock
// @param rate: corn per seed
// @return: new corn stock after buying 1 seed
    float buySeed(float corn, float rate) {
        return corn - rate;
    }

// this function buys corn
// Pre-conditions: seed >= rate
// @param seed: current seed stock
// @param rate: seed per corn
// @return: new seed stock after buying 1 corn
    float buyCorn(float seed, float rate) {
        return seed - rate;
    }