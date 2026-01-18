//gcc -Wall -std=c99 MPTEST.c -o run.exe && ./run.exe

#include <stdio.h>
#include <time.h>
#include <stdlib.h>           

//functions in fn.c
    int travelDays(int From, int To) {
        int nDays = 0;
        if ((From == 1 && To == 2) || (From == 2 && To == 1)) nDays = 5;   // Quail - Duck
        if ((From == 1 && To == 3) || (From == 3 && To == 1)) nDays = 3;   // Quail - Turkey
        if ((From == 2 && To == 3) || (From == 3 && To == 2)) nDays = 3;   // Duck - Turkey
        if ((From == 2 && To == 4) || (From == 4 && To == 2)) nDays = 2;   // Duck - Parrot
        if ((From == 3 && To == 4) || (From == 4 && To == 3)) nDays = 4;   // Turkey - Parrot
        return nDays;
    }
    float addSeedTravel(float Seed, int Days) {
        return Seed + Days;
    }
    int updateLocation(int currentLoc, int nChoice) {
        switch (nChoice) {
        case 1: return 1; // Quail Land
        case 2: return 2; // Duck Land
        case 3: return 3; // Turkey Land
        case 4: return 4; // Parrot Land
        default: return currentLoc; // stay in place if buying/invalid
        }
    }
    float buySeedRate(int location) {
        float rate = 0.00; // Invalid location
        if (location == 1) {rate=1.00;}
        if (location == 2) {rate=0.75;}
        if (location == 3) {rate=2.00;}
        if (location == 4) {rate=1.00;}
        return rate;
    }
    float buyCornRate(int location) {
        float rate = 0.00; // Invalid location, though shouldn't happen
        if (location == 1) {rate=1.50;}
        if (location == 2) {rate=1.50;}
        if (location == 3) {rate=1.00;}
        if (location == 4) {rate=0.75;}
        return rate;
    }
    int enoughCornToSeed(float corn, float rate) {
        return (corn >= rate) ? 1 : 0;
    }
    int enoughSeedToCorn(float seed, float rate) {
        return (seed >= rate) ? 1 : 0;
    }
    float buySeed(float corn, float rate) {
        return corn - rate;
    }
    float buyCorn(float seed, float rate) {
        return seed - rate;
    }
    int gameStatus(float corns, int days) {
        int nRet = 0;
        if (corns >= 30 && days <= 25) nRet = 1; // win
        if (days > 25) nRet = 2;               // lose
        return nRet;                               // continue game
    }
    int crackCode(int fullCode, int nCode){
        return (fullCode * 10) + nCode;     // Move current last digit to tens place and add the new number as last digit
    }

//functions in fn2.c
    int randomSpawn(){

        int nRand = (rand() % 4) + 1;
        return nRand;
    }

// Test functions
    int travelDaysTest(int From, int To, int nExpected) {
        int nRes = travelDays(From, To);
        char cStatus;
        printf(" 	Parameters: From = %d\n", From);
        printf("             	To = %d\n", To);
        printf(" 	Result	: %d\n", nRes);
        printf(" 	Expected  : %d\n", nExpected);
        if (nRes == nExpected)
            cStatus = 'P';
        else
            cStatus = 'F';
        printf(" 	Status	: %c\n\n", cStatus);
        return 'P' == cStatus;
    }

    int addSeedTravelTest(float Seed, int Days, float nExpected) {
        float nRes = addSeedTravel(Seed, Days);
        char cStatus;
        printf(" 	Parameters: Seed = %.2f\n", Seed);
        printf("             	Days = %d\n", Days);
        printf(" 	Result	: %.2f\n", nRes);
        printf(" 	Expected  : %.2f\n", nExpected);
        if (nRes == nExpected)
            cStatus = 'P';
        else
            cStatus = 'F';
        printf(" 	Status	: %c\n\n", cStatus);
        return 'P' == cStatus;
    }

    int updateLocationTest(int currentLoc, int nChoice, int nExpected) {
        int nRes = updateLocation(currentLoc, nChoice);
        char cStatus;
        printf(" 	Parameters: currentLoc = %d\n", currentLoc);
        printf("             	nChoice = %d\n", nChoice);
        printf(" 	Result	: %d\n", nRes);
        printf(" 	Expected  : %d\n", nExpected);
        if (nRes == nExpected)
            cStatus = 'P';
        else
            cStatus = 'F';
        printf(" 	Status	: %c\n\n", cStatus);
        return 'P' == cStatus;
    }

    int buySeedRateTest(int location, float nExpected) {
        float nRes = buySeedRate(location);
        char cStatus;
        printf(" 	Parameters: location = %d\n", location);
        printf(" 	Result	: %.2f\n", nRes);
        printf(" 	Expected  : %.2f\n", nExpected);
        if (nRes == nExpected)
            cStatus = 'P';
        else
            cStatus = 'F';
        printf(" 	Status	: %c\n\n", cStatus);
        return 'P' == cStatus;
    }

    int buyCornRateTest(int location, float nExpected) {
        float nRes = buyCornRate(location);
        char cStatus;
        printf(" 	Parameters: location = %d\n", location);
        printf(" 	Result	: %.2f\n", nRes);
        printf(" 	Expected  : %.2f\n", nExpected);
        if (nRes == nExpected)
            cStatus = 'P';
        else
            cStatus = 'F';
        printf(" 	Status	: %c\n\n", cStatus);
        return 'P' == cStatus;
    }

    int enoughCornToSeedTest(float corn, float rate, int nExpected) {
        int nRes = enoughCornToSeed(corn, rate);
        char cStatus;
        printf(" 	Parameters: corn = %.2f\n", corn);
        printf("             	rate = %.2f\n", rate);
        printf(" 	Result	: %d\n", nRes);
        printf(" 	Expected  : %d\n", nExpected);
        if (nRes == nExpected)
            cStatus = 'P';
        else
            cStatus = 'F';
        printf(" 	Status	: %c\n\n", cStatus);
        return 'P' == cStatus;
    }

    int enoughSeedToCornTest(float seed, float rate, int nExpected) {
        int nRes = enoughSeedToCorn(seed, rate);
        char cStatus;
        printf(" 	Parameters: seed = %.2f\n", seed);
        printf("             	rate = %.2f\n", rate);
        printf(" 	Result	: %d\n", nRes);
        printf(" 	Expected  : %d\n", nExpected);
        if (nRes == nExpected)
            cStatus = 'P';
        else
            cStatus = 'F';
        printf(" 	Status	: %c\n\n", cStatus);
        return 'P' == cStatus;
    }

    int buySeedTest(float corn, float rate, float nExpected) {
        float nRes = buySeed(corn, rate);
        char cStatus;
        printf(" 	Parameters: corn = %.2f\n", corn);
        printf("             	rate = %.2f\n", rate);
        printf(" 	Result	: %.2f\n", nRes);
        printf(" 	Expected  : %.2f\n", nExpected);
        if (nRes == nExpected)
            cStatus = 'P';
        else
            cStatus = 'F';
        printf(" 	Status	: %c\n\n", cStatus);
        return 'P' == cStatus;
    }

    int buyCornTest(float seed, float rate, float nExpected) {
        float nRes = buyCorn(seed, rate);
        char cStatus;
        printf(" 	Parameters: seed = %.2f\n", seed);
        printf("             	rate = %.2f\n", rate);
        printf(" 	Result	: %.2f\n", nRes);
        printf(" 	Expected  : %.2f\n", nExpected);
        if (nRes == nExpected)
            cStatus = 'P';
        else
            cStatus = 'F';
        printf(" 	Status	: %c\n\n", cStatus);
        return 'P' == cStatus;
    }

    int gameStatusTest(float corns, int days, int nExpected) {
        int nRes = gameStatus(corns, days);
        char cStatus;
        printf(" 	Parameters: corns = %.2f\n", corns);
        printf("             	days = %d\n", days);
        printf(" 	Result	: %d\n", nRes);
        printf(" 	Expected  : %d\n", nExpected);
        if (nRes == nExpected)
            cStatus = 'P';
        else
            cStatus = 'F';
        printf(" 	Status	: %c\n\n", cStatus);
        return 'P' == cStatus;
    }
    int crackCodeTest(int fullCode, int nCode, int nExpected) {
        int nRes = crackCode(fullCode, nCode);
        char cStatus;
        printf(" \tParameters: fullCode = %d\n", fullCode);
        printf("             \tnCode = %d\n", nCode);
        printf(" \tResult\t: %d\n", nRes);
        printf(" \tExpected  : %d\n", nExpected);
        if (nRes == nExpected)
            cStatus = 'P';
        else
            cStatus = 'F';
        printf(" \tStatus\t: %c\n\n", cStatus);
        return 'P' == cStatus;
    }
    int randomSpawnTest(int seed, int nExpected) {
        srand(seed);
        int nRes = randomSpawn();
        char cStatus;
        printf(" 	Parameters: seed = %d\n", seed);
        printf(" 	Result	: %d\n", nRes);
        printf(" 	Expected  : %d\n", nExpected);
        if (nRes == nExpected)
            cStatus = 'P';
        else
            cStatus = 'F';
        printf(" 	Status	: %c\n\n", cStatus);
        return 'P' == cStatus;
    }


// Test Main function (with expected values)
    int main() {
        int nTotal = 0, nTestCases = 0;

    printf("Function: travelDays\n");
        printf("  1) Two positive numbers\n");
        nTotal += travelDaysTest(1, 2, 5);
        nTestCases++;

        printf("  2) Zero and a positive number\n");
        nTotal += travelDaysTest(0, 1, 0);
        nTestCases++;

        printf("  3) Two negative values\n");
        nTotal += travelDaysTest(-1, -2, 0);
        nTestCases++;

    printf("Function: addSeedTravel\n");
        printf("  1) Two positive numbers\n");
        nTotal += addSeedTravelTest(5.00, 3, 8.00);
        nTestCases++;

        printf("  2) Zero and a positive number\n");
        nTotal += addSeedTravelTest(0.00, 5, 5.00);
        nTestCases++;

        printf("  3) Two negative values\n");
        nTotal += addSeedTravelTest(-2.00, -3, -5.00);
        nTestCases++;

    printf("Function: updateLocation\n");
        printf("  1) Two positive numbers\n");
        nTotal += updateLocationTest(1, 2, 2);
        nTestCases++;

        printf("  2) Zero and a positive number\n");
        nTotal += updateLocationTest(0, 3, 3);  // Fixed: Choice 3 returns 3, not 0
        nTestCases++;

        printf("  3) Two negative values\n");
        nTotal += updateLocationTest(-1, -2, -1);
        nTestCases++;

    printf("Function: buySeedRate\n");
        printf("  1) Two positive numbers\n");
        nTotal += buySeedRateTest(1, 1.00);
        nTestCases++;

        printf("  2) Zero and a positive number\n");
        nTotal += buySeedRateTest(0, 0.00);
        nTestCases++;

        printf("  3) Two negative values\n");
        nTotal += buySeedRateTest(-1, 0.00);
        nTestCases++;

    printf("Function: buyCornRate\n");
        printf("  1) Two positive numbers\n");
        nTotal += buyCornRateTest(1, 1.50);
        nTestCases++;

        printf("  2) Zero and a positive number\n");
        nTotal += buyCornRateTest(0, 0.00);
        nTestCases++;

        printf("  3) Two negative values\n");
        nTotal += buyCornRateTest(-1, 0.00);
        nTestCases++;

    printf("Function: enoughCornToSeed\n");
        printf("  1) Two positive numbers\n");
        nTotal += enoughCornToSeedTest(2.00, 1.00, 1);
        nTestCases++;

        printf("  2) Zero and a positive number\n");
        nTotal += enoughCornToSeedTest(0.00, 1.00, 0);
        nTestCases++;

        printf("  3) Two negative values\n");
        nTotal += enoughCornToSeedTest(-2.00, -1.00, 0);  // Fixed: -2.00 >= -1.00 is false, so 0
        nTestCases++;

    printf("Function: enoughSeedToCorn\n");
        printf("  1) Two positive numbers\n");
        nTotal += enoughSeedToCornTest(2.00, 1.00, 1);
        nTestCases++;

        printf("  2) Zero and a positive number\n");
        nTotal += enoughSeedToCornTest(0.00, 1.00, 0);
        nTestCases++;

        printf("  3) Two negative values\n");
        nTotal += enoughSeedToCornTest(-2.00, -1.00, 0);  // Fixed: -2.00 >= -1.00 is false, so 0
        nTestCases++;

    printf("Function: buySeed\n");
        printf("  1) Two positive numbers\n");
        nTotal += buySeedTest(2.00, 1.00, 1.00);
        nTestCases++;

        printf("  2) Zero and a positive number\n");
        nTotal += buySeedTest(0.00, 1.00, -1.00);
        nTestCases++;

        printf("  3) Two negative values\n");
        nTotal += buySeedTest(-2.00, -1.00, -1.00);
        nTestCases++;

    printf("Function: buyCorn\n");
        printf("  1) Two positive numbers\n");
        nTotal += buyCornTest(2.00, 1.00, 1.00);
        nTestCases++;

        printf("  2) Zero and a positive number\n");
        nTotal += buyCornTest(0.00, 1.00, -1.00);
        nTestCases++;

        printf("  3) Two negative values\n");
        nTotal += buyCornTest(-2.00, -1.00, -1.00);
        nTestCases++;

    printf("Function: gameStatus\n");
        printf("  1) Two positive numbers\n");
        nTotal += gameStatusTest(30.00, 20, 1);
        nTestCases++;

        printf("  2) Zero and a positive number\n");
        nTotal += gameStatusTest(0.00, 10, 0);
        nTestCases++;

        printf("  3) Two negative values\n");
        nTotal += gameStatusTest(-5.00, -10, 0);
        nTestCases++;

    printf("Function: crackCode\n");
        printf("  1) Two positive numbers\n");
        nTotal += crackCodeTest(5, 3, 53);
        nTestCases++;

        printf("  2) Zero and a positive number\n");
        nTotal += crackCodeTest(0, 7, 7);
        nTestCases++;

        printf("  3) Two negative values\n");
        nTotal += crackCodeTest(-2, -3, -23);
        nTestCases++;

    printf("Function: randomSpawn\n");
        printf("  1) Two positive numbers\n");
        nTotal += randomSpawnTest(1, 4);
        nTestCases++;
        printf("  2) Zero and a positive number\n");
        nTotal += randomSpawnTest(0, 3);
        nTestCases++;
        printf("  3) Two negative values\n");
        nTotal += randomSpawnTest(-1, 4);
        nTestCases++;

        printf("Passed: %d/%d\n", nTotal, nTestCases);
        return 0;
    }
