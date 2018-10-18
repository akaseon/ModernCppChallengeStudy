//#include <gsl/gsl>

#include <iostream>
#include <map>
#include <utility>

std::map<long long, std::pair<long long, long long>>   gCollatzMap;

long long getCollatz( long long aNumber )
{
    long long     sSequence = 0;

    if ( aNumber % 2 == 0 )
    {
        sSequence = aNumber / 2;
    }
    else
    {
        sSequence = aNumber * 3 + 1;
    }

    return sSequence;
}

void makeCollatzSequence( std::map<long long, std::pair<long long, long long>>   & aMap,
                          long long                                    aNumber )
{
    long long     sNumber = aNumber;
    long long     sNextNumber = aNumber;

    while ( sNumber != 1 )
    {
        auto sNextCollatz = aMap.find( sNumber );

        if ( sNextCollatz == aMap.end() )
        {
            sNextNumber = getCollatz( sNumber );

            aMap.insert( std::make_pair( sNumber, 
                                         std::make_pair( sNextNumber, 0 ) ) );

            sNumber = sNextNumber;
        }
        else
        {
            break;
        }
    }
}

long long getCollatzSequence( long long aNumber )
{
    long long sLength = 0;
    long long sNextNumber = 0;
    auto sNextCollatz = gCollatzMap.find( aNumber );

    if ( sNextCollatz == gCollatzMap.end() )
    {
        makeCollatzSequence( gCollatzMap, aNumber );
        sNextCollatz = gCollatzMap.find( aNumber );
    }
    else
    {
        /* do nothing */
    }

    sLength = std::get<1>( sNextCollatz->second );

    if ( sLength != 0 )
    {
        /* do nothing */
    }
    else
    {
        sNextNumber = std::get<0>( sNextCollatz->second );

        if ( sNextNumber != 0 )
        {
            sLength = getCollatzSequence( sNextNumber ) + 1;
        }

        (sNextCollatz->second).second = sLength;
    }

    return sLength;
}

void printCollatz( long long  aNumber )
{
    long long     sNumber = aNumber;
    long long     sNextNumber = aNumber;
    long long     sLength = 0;

    while ( sNumber != 1 )
    {
        auto sNextCollatz = gCollatzMap.find( sNumber );

        if ( sNextCollatz == gCollatzMap.end() )
        {
            break;
        }
        else
        {
            std::cout << sNextCollatz->first << " "
                      << std::get<0>(sNextCollatz->second) << " "
                      << std::get<1>(sNextCollatz->second) << " "
                      << "\n";
            sNumber = std::get<0>( sNextCollatz->second );
        }
    }
}

int main(int argc, char* argv[])
{
    long long     i = 0;
    long long     sNextSequence = 0;;
    long long     sLength = 0;        

    long long     sLongestNumber = 0;
    long long     sLongestLength = 0;

    gCollatzMap.insert( std::make_pair( 1, 
                                        std::make_pair<long long, long long>( 0, 1 ) ) );

    sNextSequence = atoi( argv[1] );

//    makeCollatzSequence( gCollatzMap, sNextSequence );

//    sLength = getCollatzSequence( sNextSequence );
//    std::cout << sLength << "\n";

//    printCollatz( sNextSequence );

    for ( i = 2; i <= sNextSequence; i++ )
    {
        sLength = getCollatzSequence( i );
        std::cout << i << " " << sLength << "\n";

        if ( sLength > sLongestLength )
        {
            sLongestLength = sLength;
            sLongestNumber = i;
        }
        else
        {
            /* do nothing */
        }
    }

    std::cout << "longest Collatz " << sLongestNumber << ", Length : " << sLongestLength << "\n"; 


    return 0;
}
