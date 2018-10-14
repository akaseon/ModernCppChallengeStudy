#include <gsl/gsl>
#include <numeric>
#include <iostream>
#include <tuple>
#include <vector>
#include <iomanip>

int gDebug = 0;

void getDivider( int                   aNumber, 
                 std::vector<std::tuple<int,int>>    & aDiveder )
{
    int     i = 2;
    int     sRemainder = 0;
    int     sLimit = 0;

    auto    sTuple = std::make_tuple( 1, aNumber );
    aDiveder.push_back( sTuple );

    sLimit = aNumber;
    
    while ( i < sLimit )
    {
        sRemainder = aNumber % i;

        if ( sRemainder == 0 )
        {
            sLimit = aNumber / i;
            sTuple = std::make_tuple( i, sLimit );
            aDiveder.push_back( sTuple );
        }
        else
        {
            /* do nothing */
        }
        
        i++;
    }
}

void printDivider( std::vector<std::tuple<int,int>>  & aDiveder )
{
    auto sPrintFunction = [](const std::tuple<int,int> & aTuple) { 
        std::cout << "( " << std::get<0>(aTuple) << ", "
                          << std::get<1>(aTuple) << " ) "; 
    };

    std::for_each( aDiveder.begin(), aDiveder.end(), sPrintFunction );
    std::cout << "\n";
}

int sumDivider( std::vector<std::tuple<int,int>> & aDiveder )
{
    int sSum = 0;

    for ( auto & sTuple : aDiveder )
    {
        sSum += std::get<0>( sTuple );
        if ( std::get<0>( sTuple ) != std::get<1>( sTuple ) )
        {
            sSum += std::get<1>( sTuple );
        }
        else
        {
            /* do nothing */
        }
    }

    return sSum;
}

bool isAbundantNumber( int  aNumber )
{
    bool             sIsAbundantNumber = false;
    std::vector<std::tuple<int,int>> sDiveder;
    int              sSum = 0;

    getDivider( aNumber, 
                sDiveder );

    if ( gDebug == 1 )
        printDivider( sDiveder );

    sSum = sumDivider( sDiveder );

    if ( gDebug == 1 )
        std::cout << sSum << "\n";

    if ( ( sSum - aNumber ) > aNumber )
    {
        sIsAbundantNumber = true;
    }
    else
    {
        sIsAbundantNumber = false;
    }

    if ( gDebug == 1 )
        std::cout << sIsAbundantNumber << "\n";

    return sIsAbundantNumber;
}

int main(int argc, char* argv[])
{
    int              sNumber = 0;

    sNumber = atoi( argv[1] );

    if ( argc == 3 )
        gDebug = atoi( argv[2] );

    for ( int i = 1; i <= sNumber; i++ )
    {
        if ( isAbundantNumber( i ) == true )
        {
            std::cout << i << " ";
        }
        else
        {
            /* do nothing */
        }
    }

    std::cout << "\n";

    return 0;
}
