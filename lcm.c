#include <stdlib.h>
#include <stdio.h>

long long unsigned int euklid ( const long long unsigned int a, const long long unsigned int b ) {
	if ( b == 0 ) {
		return a;
	} else {
		return euklid ( b, a % b );
	}
}

int main ( int argc, char **argv ) {
    int n_numbers;
    long long unsigned int gcd, lcm, product, *numbers;

    /* Parse arguments */
    if ( argc < 3 ) {
        printf ( "Usage: lcm number1 number2 [...]\n" );
        return -1;
    } else {
    	numbers = (long long unsigned int *) malloc ( (argc-1) * sizeof(int) );
    	n_numbers = argc-1;

        for ( int i = 0; i < n_numbers; i++ ) {
        	numbers[i] = atoll ( argv[i+1] );
        	if ( numbers[i] == 0 ) {
        		printf ( "Invalid arguments.\n" );
        		return -1;
        	}
        }
    }

    /* gcd and lcm */
    lcm = numbers[0];
    gcd = lcm;
    for ( int i = 1; i < n_numbers; i++ ) {
    	product = lcm * numbers[i];
    	gcd = euklid ( gcd, numbers[i] );
    	lcm = product / euklid ( lcm, numbers[i] );
    }
    printf ( "gcd=%llu, lcm=%llu\n", gcd, lcm );
    return (int) lcm;
}
