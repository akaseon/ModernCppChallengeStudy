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

bool isAmicableNumber( int    aNumber,
                       int  & aPairNumber )
{
    bool             sIsAmicableNumber = false;
    std::vector<std::tuple<int,int>> sDivederOfNumber;
    int              sPairNumber = 0;
    std::vector<std::tuple<int,int>> sDivederOfPairNumber;
    int              sSum = 0;
    int              sSumWithoutNumber = 0;

    getDivider( aNumber, 
                sDivederOfNumber );

    if ( gDebug == 1 )
        printDivider( sDivederOfNumber );

    sSum = sumDivider( sDivederOfNumber );
    if ( gDebug == 1 )
        std::cout << sSum << "\n";

    sPairNumber = sSum - aNumber;
    if ( gDebug == 1 )
        std::cout << sPairNumber << "\n";

    getDivider( sPairNumber,
                sDivederOfPairNumber );
    sSum = sumDivider( sDivederOfPairNumber );

    if ( gDebug == 1 )
        std::cout << sSum << "\n";

    if ( aNumber == ( sSum - sPairNumber ) )
    {
        aPairNumber = sPairNumber;
        sIsAmicableNumber = true;
    }
    else
    {
        sIsAmicableNumber = false;
    }

    if ( gDebug == 1 )
        std::cout << sIsAmicableNumber << "\n";

    return sIsAmicableNumber;
}

int main(int argc, char* argv[])
{
    int              sNumber = 0;
    int              sPairNumber = 0;

    sNumber = atoi( argv[1] );
    if ( argc == 3 )
        gDebug = atoi( argv[2] );

    for ( int i = 2; i < sNumber; i++ )
    {
        if ( isAmicableNumber( i, sPairNumber ) == true )
        {
            std::cout << "( " << i << ", " << sPairNumber << " ) ";
        }
    }

    std::cout << "\n";

    return 0;
}
