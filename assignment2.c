/*Program of a Lotto Game that allows the user to chose from a set menu of 6 choices.
Each choice calls a function and within these functions parts of the lotto game are implemented.
Entering option 6 will end the program.
Date:22/02/18
Author: Glory Pierce Eguare
Compiler Used: Code Blocks
OS Used: Windows 10
*/

#include <stdio.h>
#include <stdlib.h>
#define SIZE 6
#define SIZE2 43

//Function Prototypes
void enter_numbers(float*,float*);
void display_numbers(float*);
void arrange_numbers(float*);
void winning_numbers(float*);
void number_frequency(float*,float*);
float end_program();

int main()
{
    //Declaring variables
    int option;
    float numbers[SIZE];
    float range[SIZE2]={0};
    int first=0;

    //Begin the do-while loop that implements the lotto game
    do
    {
        option=0;
        printf("MAIN MENU\n\n1. Enter Your Numbers\n2. Check Your Numbers\n3. Arrange Your Numbers in Assending Order\n4. Check the Winning Numbers\n5. The Frequency of Numbers Entered\n6. Exit Program\n\n");
        scanf("%d",&option);
        fflush(stdin);

        if(option==1||option==6)
        {
            first++;
        }//end if

        //While loop to make sure that the user either selects 1 or 6 first
        while(first==0)
        {
            printf("You need to either select option (1) to start the lotto or option (6) to end the program first! Try again.\n");
            scanf("%d",&option);
            fflush(stdin);

            if(option==1||option==6)
            {
                //first is incremented by one so that the user can now enter option 2, 3, 4 or 5
                first++;
            }//end if
        }//end while


        //Start the switch statement that implement the options in the lotto game
        switch(option)
        {
            case 1:
            {
                //Call enter_numbers()
                enter_numbers(numbers,range);
                break;
            }

            case 2:
            {
                //Call display_numbers
                display_numbers(numbers);
                break;
            }

            case 3:
            {
                //Call arange_numbers
                arrange_numbers(numbers);
                break;
            }

            case 4:
            {
                //Call winning_numbers
                winning_numbers(numbers);
                break;
            }

            case 5:
            {
                //Call number_frequency
                number_frequency(numbers,range);
                break;
            }

            case 6:
            {
                //Call end_program
                end_program();
                break;
            }

            default:
            {
                //Error message for when the user doesn't select option 1-6
                printf("\nError you did not enter one of the options between 1-6. Please try again!\n\n");
                break;
            }//end default
        }//end switch
    }
    while(option!=6);//Loop stops when 6 is is entered as an option

    return 0;
}//end main()

/*Implement enter_numbers()
*/
void enter_numbers(float numbers[SIZE], float range[SIZE2])
{
    //Declaring i and j for reading the arrays
    int i,j;

    //Let user enter their lotto numbers
    printf("Please enter the six numbers between 1-42 that you wish to enter into the Lotto Draw\n");

    for(i=0;i<SIZE;i++)
    {
        //Lotto numbers are read into the array
        *(numbers+i)=0;
        scanf("%f", &*(numbers+i));
        fflush(stdin);

        //Error message if the user doesn't enter a number between 1-42 and make user reenter
        while(*(numbers+i)>42||*(numbers+i)<1)
        {
            printf("\nError, you did not enter a number between 1-42. Try again\n");
            scanf("%f", &*(numbers+i));
            fflush(stdin);
        }//end while

        //For loop to check if the user enters the same number more than once by checking the previous numbers in the array and to check if the number is between 1-42
        for(j=0;j<i;j++)
        {
            while(*(numbers+i)==*(numbers+j))
            {
                printf("You have already entered this number into the Lotto! Enter a different number.\n");
                scanf("%f", &*(numbers+i));
                fflush(stdin);

                while(*(numbers+i)>42||*(numbers+i)<1)
                {
                    printf("\nError, you did not enter a number between 1-42. Try again\n");
                    scanf("%f", &*(numbers+i));
                    fflush(stdin);
                }//end inner while
            }//end outer while
        }//end innr for
    }//end outer for

    //Nested for loop to add the frequency of the numbers entered into the array for lotto numbers
    for(j=0;j<SIZE;j++)
    {
        for(i=0;i<=SIZE2;i++)
        {
            //If your entered a number that is equal to the position in the array (range) the value in that position is incremented by 1
            if(*(numbers+j)==i)
            {
                (*(range+i))++;
            }//end if
        }//end inner for
    }//end outer for
    system("cls");//clear the screen
}

/*Implement display_numbers()
*/
void display_numbers(float numbers[])
{
    int i;//To read the array

    printf("Your six numbers are: ");

    //For loop to display your entered numbers
    for(i=0;i<SIZE;i++)
    {
        printf("%.0f ", *(numbers+i));
    }
    printf("\n*********************************************************\n");
}

/*Implement arrange_numbers
*/
void arrange_numbers(float numbers[])
{
    int i,j;
    int tmp;

    //Bubble Sort to sort out the array from smallest to largest
    for (i=0;i<SIZE;i++)
    {
        for (j=i+1;j<SIZE;j++)
        {
            if (*(numbers+i) > *(numbers+j))
            {
                tmp = *(numbers+i);
                *(numbers+i) = *(numbers+j);
                *(numbers+j) = tmp;
            }//end if
        }//end inner for
    }//end outer for

    //For loop to display the user's numbers in order
    printf("Your Lotto Numbers in order: ");
    for(i=0;i<SIZE;i++)
    {
        printf("%.0f ",*(numbers+i));
    }//end for
    printf("\n*********************************************************\n");
}

/*Implement winning_numbers
*/
void winning_numbers(float numbers[])
{
    int winning_nums[]={1,3,5,7,9,11};
    int matches=0;
    int i,j=0;

    //Nested while loop to compare the user's lotto numbers with the winning numbers
    //Each of the user's lotto numbers is compared with the winning number array
    while(j!=SIZE)
    {
        i=0;
        while(i!=SIZE)
        {
            if(*(numbers+i)== *(winning_nums+j))
            {
                matches = matches + 1;//1 match = matches incremented by 1
            }//end if
            i++;
        }//end inner while
        j++;
    }//end outer while

    //For loop to check if the user entered the bounus number
    for(i=0;i<SIZE;i++)
    {
        if(*(numbers+i)==42)
        {
            matches = matches + 10;//if bonus number has been entered = matches incremented by 10
        }//end if
    }//end for

    //If statements to display a different messages depending on how many numbers the user matched
    //6 matches
    if(matches==6)
    {
        printf("\nYou matched 6 winning numbers: Jackpot\n");
    }//end if

    //5 matches + bonus
    if(matches==15)
    {
        printf("\nYou matched 5 winning numbers and the bonus number: New Car\n");
    }//end if

    //5 matches
    if(matches==5)
    {
        printf("\nYou matched 5 winning numbers: Holiday\n");
    }//end if

    //4 matches + bonus
    if(matches==14)
    {
        printf("\nYou matched 4 winning numbers and the bonus number: Weekend Away\n");
    }//end if

    //4 matches
    if(matches==4)
    {
        printf("\nYou matched 4 winning numbers: Night Out\n");
    }//end if

    //3 matches + bonus
    if(matches==13)
    {
        printf("\nYou matched 3 winning numbers and the bonus number: Cinema Ticket\n");
    }//end if

    if(matches<4||matches==12||matches==10||matches==11)
    {
        printf("\nSorry, you didn't win anything.");
    }//end if
    printf("\n*********************************************************\n");
}

/*Implement number_frequency
*/
void number_frequency(float numbers[],float range[])
{
    int i,j;
    float counter=0;

    //For loop to display the frequency of the numbers that the user has entered since the program has began
    //Counter is the number of which frequency will be checked
    //Range is the array of 42 elements to mark the frequency of each number between 1-42
    for(i=0;i<SIZE2;i++)
    {
        if(range[i]!=0)
        {
            printf("You entered - %.0f: %.0f time(s)\n", counter, *(range+i));
        }//end if
        counter++;
    }//end for

    printf("\n*********************************************************\n");
}

/*Implement end_program
*/
float end_program()
{
    //Display message and then the game
    system("cls");//clear the screen
    printf("\n*********************************************************\n");
    printf("Thanks for playing. Goodbye\n");
}
