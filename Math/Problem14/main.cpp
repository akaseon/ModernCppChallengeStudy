#include <gsl/gsl>

#include <cstdlib>
#include <iostream>

bool isValildISBN( std::string  aISBN )
{
    char    sCheckDigit;
    int     sCheckDigitNumber = 0;
    int     sWeightSum = 0;
    bool    sIsValid = false;

    sCheckDigit = aISBN[9];

    if ( ( sCheckDigit == 'x' ) ||
         ( sCheckDigit == 'X' ) )
    {
        sCheckDigitNumber = 10;
    }
    else
    {
        sCheckDigitNumber = sCheckDigit - '0';
    }

    sWeightSum = sCheckDigitNumber;

    for ( int i = 0; i < aISBN.length() - 1; i++ )
    {
        sWeightSum = sWeightSum + ( ( aISBN[i] - '0' ) * ( 10 - i ) );
    }

    if ( ( sWeightSum % 11 ) == 0 )
    {
        sIsValid = true;
    }
    else
    {
        sIsValid = false;
    }

    return sIsValid;
}


int main(int argc, char* argv[])
{
    if ( isValildISBN( argv[1] ) == true )
    {
        std::cout << argv[1] << " is valid\n";
    }
    else
    {
        std::cout << argv[1] << " is invalid\n";
    }

    return 0;
}
