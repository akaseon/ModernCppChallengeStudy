#include <gsl/gsl>

#include <cmath>
#include <iostream>

int getDigitNumber( int aNumber )
{
    int sDigitNumber = 0;
    int sNumber = aNumber;

    do {
        sDigitNumber++;
        sNumber = sNumber / 10;
    } while ( sNumber != 0 );

    return sDigitNumber;
}

double getArmstrongNumber( int aNumber )
{
    int     sDigitValue = 0;
    int     sDigitNumber = 0;
    int     sNumber = aNumber;
    double  sArmstrongNumber = 0;

    sDigitNumber = getDigitNumber( aNumber );

    do {
        sDigitValue = sNumber % 10;
        sNumber = sNumber / 10;
        sArmstrongNumber += std::pow( sDigitValue, sDigitNumber );
    } while ( sNumber != 0 );

    return sArmstrongNumber;
}

int main(int argc, char* argv[])
{
    int sNumber = 0;

    sNumber = atoi( argv[1] );

    if ( sNumber == getArmstrongNumber( sNumber ) )
    {
        std::cout << sNumber << " is ArmstrongNumber\n" ;
    }
    else
    {
        std::cout << sNumber << " is not ArmstrongNumber\n" ;
    }


    return 0;
}
