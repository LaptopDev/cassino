#include <stdlib.h>
#include <stdio.h>
#include <time.h> //for rand()
#include <string.h> //for strncmp()
#include <unistd.h> //for sleep()

/*this is a funny guessing game*/

int startrange, endrange, nugget, guess, i ;
char finger[6] = "finger" , usrinput[6] ;
time_t t ; /*gets the current time 
             elapsed since jesus died 
             which is used by srand()
             to define a pseudo-random
             sequence of numbers based
             off some algorithm used by
             rand() in some under-the-
             -hood formula to select
             from a "seed" sequence 
             a sub-sequence that will be 
             practically considered
             a random number output
             of the rand() function 
             which, without further
             calculations, is limited
             in range to 0-32767 */


int main()
{
    sleep( 1 );
    /*prints intro message*/
    printf( "        $$$$$$$$$$$$$$       \n......Thanks for Choosing......\n$$$ Golden Nugget Cassino! $$$\n        $$$$$$$$$$$$$$       \n" );
    sleep( 2 );
/*prompt says: select start range from which to guess*/
    puts( "" ) ;
    printf( "Choose your own odds, (it's more enjoyable).\n") ;
    sleep( 1 ) ;
    printf( "What is your starting range?\nStart Range: " );
/*user prompted to make entry*/
    scanf( " %d" , &startrange );
    printf( "What is your ending range?\nEnd Range: " );
/*user prompted for end range and
 * is presented a message prompting
 * them to change their entry until 
 * the number is larger than the
 * start range*/
    scanf( " %d" , &endrange );
    if( endrange <= startrange )
    {
        while( endrange <= startrange )
        {
            printf( "pick a bigger number than %d\nEnd Range: " , startrange );
            scanf( " %d" , &endrange );
        }
    }
/*
 * rand() references the seed output
 * of srand(), which determines the 
 * randomness of rand() each time the 
 * program is run. 
 * Next the operator %, called modulo,
 *  takes the number to the left of it 
 *  and to the right ( opposing adjacent
 *  numbers ) and divides them as such: 
 *  lnumber/rnumber : dividend/divisor,
 *  and ignores the quotient, and returns
 *  only the remainder (0-9).
 * | startrange + | sets startrange as 
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

    srand( time( &t ) ) ;
    nugget = ( rand() % ( endrange - startrange + 1 )) + startrange ;

//
/*user prompted for guess within defined range,
 * if improper guess, clear guess value for reentry*/
    sleep( 1 ) ;
    puts("");
    printf( "Ok, now what's your guess?\nGuess: " ) ;
    scanf( " %d" , &guess );
    if( guess < startrange || guess > endrange )
    {
        while ( guess < startrange || guess > endrange )
        {
            printf( "guess is not between\nstarting range of %d\nand ending range of %d\nGuess: " , startrange , endrange );
            scanf( " %d" , &guess ) ;
        }
    }
/*funny game making prompt*/
    sleep(1);
    puts("");
    printf( "Now, present your butthole to me, " ) ;
    printf( "when you are ready, type 'finger'.\n " ) ;
    printf( "You got this\n" );
    sleep( 1 ) ;
    printf( "butthole status: " ) ;
    fflush( stdout );
    sleep( 2 ) ; /* not sleeping, flush buffer or set buffer to unbuffered*/
    printf( "not ready\n" );
    sleep(1);
    printf( "\nfinger: " ) ;
/*game hangs up until player enters 'finger'*/
    scanf( " %s" , usrinput); /* I don't know how to pass user input into my usrinput[] array to compare my finger[] array to*/
    if( strncmp( usrinput , finger , 6 ) == 1 )
    {
        while( strncmp( usrinput , finger , 6 ) == 1 )
        {
            puts( "" ) ; /*advances to next line in terminal*/
            printf( "that's not your finger!\n" ) ;
            sleep(2) ;
            printf( "simply type, 'finger', to proceed" ) ;
            sleep(1) ;
            printf( "finger: " ) ;            
            scanf( " %s" , usrinput);
        }
    }
    else
    {
        puts( "" );
    }
    /*display winning/losing messages*/
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
        printf( "%d is a nugget!\n     WINNER\n" , guess ) ;
    }
    else
    {
        printf( "Aw shit!" ) ;
        sleep( 1 ) ;
        printf( " Literally!\n" ) ;
        sleep( 1 ) ;
        printf( "%d is a regular turd!\n LOSER\n" , guess ) ;
    }
return 0 ;
}    
            
        
    
