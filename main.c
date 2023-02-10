#include <stdlib.h>
#include <stdio.h>
#include <time.h> //for rand()
#include <string.h> //for strncmp()
#include <unistd.h> //for sleep()

/*this is a funny guessing game*/
int startrange, endrange, nugget, guess, i ;
char finger[7] = "finger" , usrinput[7] ;
time_t t ; //time passed since jesus died, in nano-seconds//


int main()
{

/*prints intro message*/
    sleep( 1 );
    printf( "        $$$$$$$$$$$$$$       \n......Thanks for Choosing......\n$$$ Golden Nugget Cassino! $$$\n        $$$$$$$$$$$$$$       \n" );
    sleep( 2 );
    printf( "Choose your own odds, (it's more enjoyable).\n") ;
    sleep( 2 ) ;

/*prompt to select start of range from which to guess and asks for user input */
    printf( "\nWhat is your starting range?\n   Start Range: " );
    scanf( " %d" , &startrange );

/*prompt to select upper range and asks for user input */
    printf( "What is your ending range?\n   End Range: " );
    scanf( " %d" , &endrange );
    if( endrange <= startrange ) //continues if upper range is larger
    {
        while( endrange <= startrange ) //presents error message if lower
        {
            printf( "pick a bigger number than %d\n   End Range: " , startrange );
            scanf( " %d" , &endrange );
        }
    }

/*generates random seed*/
    srand( time( &t ) ) ;

        /* rand() references the seed output
        *  of srand(), which determines the 
        *  randomness of rand() each time the 
        *  program is run. 
        * Next the operator %, called modulo,
        *  takes the number to the left of it 
        *  and to the right ( opposing adjacent
        *  numbers ) and divides them as such: 
        *  lnumber/rnumber : dividend/divisor,
        *  and ignores the quotient, and returns
        *  only the remainder (0-9). */

    nugget = startrange + ( rand() % ( endrange - startrange + 1 )) ;
    /*| startrange + | sets startrange as 
    *  first in the sequence of possible
    *  random numbers.
    * inside the braces, the total elements 
    *  in the sequence is found by taking
    *  the difference between endrange and
    *  startrange
    * 1 is added to the total number of 
    *  elements in the sequence to force
    *  the modulo to include the endrange 
    *  or upper range value in the formula
    *  since it is not included by rand() 
    *  by default.            // I think? not really certain without practice using it.
    * then that's modulo'd,  producing a 
    *  random remainder which is added to 
    *  the start range to determine the 
    *  random number within the custom range.
    * NOTE: Don't confuse modulo symbol w/ 
    * the conversion character in printf() */


/*user prompted to guess nugget number in their defined range*/
    sleep( 1 ) ;
    printf( "\nOk, now what's your guess?\n   Guess: " ) ;
    scanf( " %d" , &guess );
    if( guess < startrange || guess > endrange ) // continues if in range
    {
        while ( guess < startrange || guess > endrange ) // presents error message if user guess is outside of range
        {
            printf( "\nGuess a number between %d and %d\n   Guess: " , startrange , endrange );
            scanf( " %d" , &guess ) ;
        }
    }

/*funny game making prompt*/
    sleep(1);
    printf( "\nNow, present your butthole to me,\nwhen you are ready, type 'finger'.\n" );
    sleep( 2 ) ;
    printf( "\n   You got this.\nButthole status: Not Ready\n   finger: " ) ;
    scanf( "%s" , usrinput);
    if( strncmp( usrinput , finger , 6 ) != 0 ) // continues if user types 'finger'
    {
        while( strncmp( usrinput , finger , 6 ) != 0 ) // presents error message if user input is not exactly 'finger'
        {
            printf( "\nthat's not your finger!\nsimply type, 'finger', to proceed" ) ;
            sleep(1) ;
            printf( "\n   finger: " ) ;
            scanf( " %s" , usrinput);
        }
    }
    puts( "" ) ;

/*display winning / losing messages*/
    sleep( 1 ) ;
    for( i = 0 ; i < 3 ; i++ )
    {
        sleep( 1 ) ;
        printf( "digging...\n" ) ;
    }
    printf( "...I feel something!\n" ) ;
    sleep( 2 ) ;
    if( guess == nugget )
    {
        printf( "Holy shit!" ) ;
        sleep( 1 ) ;
        printf( " Literally!\n" ) ;
        sleep( 1 ) ;
        printf( "\n       %d is a nugget!\n           WINNER\n\n" , guess ) ;
    }
    else
    {
        printf( "Aw shit!" ) ;
        sleep( 1 ) ;
        printf( " Literally!\n" ) ;
        sleep( 1 ) ;
        printf( "\n     %d is a regular turd!\n            LOSER\n\n" , guess ) ;
    }
return 0 ;
}
