#include <gsl/gsl>

#include <iostream>
#include <string>

char getRomanSymbol( int    aValue )
{
    char    sRomanSymbol;

    switch( aValue )
    {
        case 1000:
            sRomanSymbol = 'M';
            break;
            
        case 500:
            sRomanSymbol = 'D';
            break;
            
        case 100:
            sRomanSymbol = 'C';
            break;
            
        case 50:
            sRomanSymbol = 'L';
            break;
            
        case 10:
            sRomanSymbol = 'X';
            break;
            
        case 5:
            sRomanSymbol = 'V';
            break;
            
        default:
        //case 1:
            sRomanSymbol = 'I';
            break;
    }

    return sRomanSymbol;
}

std::string convertRomanNumeral( int aNumber )
{
    int             sNumber = aNumber;
    int             sRomanValue = 0;
    int             sRemainder = 0;
    int             sQuotient = 0;

    std::string     sRomanNumeral;

    while ( sNumber != 0 )
    {
        if ( sNumber >= 1000 )
        {
            sQuotient = sNumber / 1000;
            sRemainder = sNumber % 1000;
            sRomanValue = 1000;
        }
        else if ( sNumber >= 500 )
        {
            sQuotient = sNumber / 500;
            sRemainder = sNumber % 500;
            sRomanValue = 500;
        }
        else if ( sNumber >= 100 )
        {
            sQuotient = sNumber / 100;
            sRemainder = sNumber % 100;
            sRomanValue = 100;
        }
        else if ( sNumber >= 50 )
        {
            sQuotient = sNumber / 50;
            sRemainder = sNumber % 50;
            sRomanValue = 50;
        }
        else if ( sNumber >= 10 )
        {
            sQuotient = sNumber / 10;
            sRemainder = sNumber % 10;
            sRomanValue = 10;
        }
        else if ( sNumber >= 5 )
        {
            sQuotient = sNumber / 5;
            sRemainder = sNumber % 5;
            sRomanValue = 5;
        }
        else
        {
            sQuotient = sNumber / 1;
            sRemainder = sNumber % 1;
            sRomanValue = 1;
        }

        while ( sQuotient != 0 )
        {
            sRomanNumeral.push_back( getRomanSymbol( sRomanValue ) );
            sQuotient--;
        }
        sNumber = sRemainder;
    }

    return sRomanNumeral;
}


int main(int argc, char* argv[])
{
    int     sNumber = atoi( argv[1] );

    std::cout << convertRomanNumeral( sNumber ) << "\n";
    return 0;
}
