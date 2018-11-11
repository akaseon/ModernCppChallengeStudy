//#include <gsl/gsl>
#include <iostream>
#include <vector>

std::vector<int> getNextPascalTriangleRow( std::vector<int> aRow )
{
    std::vector<int>    sNextRow;
    int                 sNumber = 0;
    int                 sPrevNumber = 0;

    for ( auto n: aRow )
    {
        sNumber = sPrevNumber + n;
        sPrevNumber = n;
        
        sNextRow.push_back( sNumber );
    }

    sNextRow.push_back( aRow.back() );

    return sNextRow;
}

void printRow( std::vector<int> aRow )
{
    for ( auto n: aRow )
    {
        std::cout << n << " ";
    }

    std::cout << "\n";
}

void printPascalTriangle( int aDepth )
{
    std::vector<int>    sPrevRow = { 1 };
    std::vector<int>    sRow;

    printRow( sPrevRow );

    for ( int i = 1; i < aDepth; i++ )
    {
        sRow = getNextPascalTriangleRow( sPrevRow );

        printRow( sRow );

        sPrevRow.swap( sRow );
        sRow.clear();
    }
}

int main(int argc, char* argv[])
{
    printPascalTriangle( 10 );

    return 0;
}
