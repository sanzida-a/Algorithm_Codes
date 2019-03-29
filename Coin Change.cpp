#include <stdio.h>
#include<conio.h>
#include <stdlib.h>

int i , no_of_denominations , denominations [ 10000 ] , total_cost , cost [ 10000 ] ;

int min ( int idx )
{
    int min_cost = 99999 , j ;
    cost [ 0 ] = 0 ;
    for ( j = 0 ; j < no_of_denominations ; j++ )
    {
        if( ( i >= denominations [ j ] ) && ( min_cost > cost [ i - denominations [ j ] ] ) )
        {
            min_cost = cost [ i - denominations [ j ] ] ;
        }
    }
    return min_cost ;
}

void input()
{
    printf ( "Coin Change with min no. of coins\nEnter the total change you want: " ) ;
    scanf_s( "%d" , &total_cost ) ;

    printf ( "Enter the no. of different denominations of coins available: " ) ;
    scanf_s( "%d" , &no_of_denominations ) ;

    printf ( "Enter the different denominations in ascending order: \n" ) ;
    for ( i = 0 ; i < no_of_denominations ; i++ )
    {
        scanf_s( "%d" , &denominations [ i ] ) ;
    }
}

void calc_print ()
{
    for ( i = 1 ; i <= total_cost ; i++ )
     {
         cost [ i ] = 1 + min ( i ) ;
     }

     printf ( "min no of coins = %d" , cost [ total_cost ] ) ;
}

int main()
{
    input () ;
    calc_print () ;
	_getch();
    return 0;
}