#include <gsl/gsl>

int getGcd( int aNumber1, int aNumber2 )
{
    int     sRemainder = 0;
    int     sQuotient = 0;

    sQuotient = aNumber1 / aNumber2;
    sRemainder = aNumber1 - ( aNumber2 * sQuotient );

    printf( "%d =  %d * %d  + %d\n", aNumber1, aNumber2, sQuotient, sRemainder );

    if ( sRemainder == 0 )
    {
        return aNumber2;
    }
    else
    {
        return getGcd( aNumber2, sRemainder );
    }
}

int main(int argc, char* argv[])
{
    int sNumber1 = 0;
    int sNumber2 = 0;
    int sGcd = 0;
    int sLcm = 0;

    sNumber1 = atoi( argv[1] );
    sNumber2 = atoi( argv[2] );

    if ( sNumber1 > sNumber2 )
    {
        sGcd = getGcd( sNumber1, sNumber2 );
    }
    else
    {
        sGcd = getGcd( sNumber2, sNumber1 );
    }

    sLcm = ( sNumber1 / sGcd ) *
           ( sNumber2 / sGcd ) *
           sGcd;

    printf( "%d\n", sLcm );

    return 0;
}
