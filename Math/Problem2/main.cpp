#include <gsl/gsl>

int getGcd( int aNumber1, int aNumber2 )
{
    int     sRemainder = 0;
    int     sQuotient = 0;

    if ( aNumber1 > aNumber2 )
    {
        sQuotient = sNumber1 / sNumber2;
        sRemainder = sNumber1 - ( sNumber2 * sQuotient );
    }
    else
    {
        sQuotient = sNumber2 / sNumber1;
        sRemainder = sNumber2 - ( sNumber1 * sQuotient );
    }

    if ( sRemainder == 0 )
    {
    }
    else
    {
        return sGcd;

    }


}

int main(int argc, char* argv[])
{
    int num1 = 0;
    int num2 = 0;

    num1 = atoi( argv[1] );
    num2 = atoi( argv[2] );

    return 0;
}
