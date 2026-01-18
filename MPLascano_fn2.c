
#include <stdio.h>

//GAME UI

// Display the upper user interface with travel options
// Pre-conditions: day, seed and corn have own positive integers
//                 location is random from 1-4
// @param Day: days have past every after travel
// @param Seed: total seed
// @param Corn: total corn gathered
// @param *Location: send value of location
    void displayLand(int Day, float Seed, float Corn, int *location){
        
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
        } else if (*location == 2) {
            printf("Q - Go Quail Land (5 days)\n");
            printf("T - Go Turkey Land (3 days)\n");
            printf("P - Go Parrot Land (2 days)\n");
        } else if (*location == 3) {
            printf("Q - Go Quail Land (3 days)\n");
            printf("P - Go Parrot Land (4 days)\n");
            printf("D - Go Duck Land (3 days)\n");
        } else if (*location == 4) {
            printf("T - Go Turkey Land (4 days)\n");
            printf("D - Go Duck Land (2 days)\n");
        }
    }

// Display the lower user interface with random values and still changing every travel
// Pre-conditions: nChoice and nCode have positive integers
// @param *nChoice: send value of location
// @param *nCode: send value of choice
    void userInput(int *nChoice, int *nCode){
        
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

// generate a random number that will match the assigned numbers per land
// Pre-conditions: nRand is random positive integer
// @param nRand: generates random number from 1 - 4
// return: returns the random number generated
    int randomSpawn(){

        int nRand = (rand() % 4) + 1;
        return nRand;
    }

// generates the random rates after every transactionor travel
// Pre-conditions: *firstValue and *secondValue are both positive numbers within given range
// @param *firstValue: send the seed rate
// @param *secondValue: send hthe corn rate
    void randomValues(float *firstValue, float *secondValue) {

        for (int i = 0; i < 3; i++) {

            int r = rand() % 4;                  // 0,1,2,3
            float newValue = 0.75 + (0.25 * r);  // 0.75 – 1.50

            *secondValue = *firstValue;          // shift previous value
            *firstValue = newValue;              // assign new value
        }
    }