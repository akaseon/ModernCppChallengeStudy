//#include <gsl/gsl>

#include <vector>
#include <iostream>
#include <sstream>
#include <iomanip>

std::string convertString( std::vector<int> aFrom )
{

    std::ostringstream sStringStream;

    for ( auto sIt = aFrom.begin();
          sIt != aFrom.end();
          sIt++ )
    {
        //std::cout << std::hex < *sIt << " ";
        sStringStream << std::setfill( '0' ) << std::setw(2) << std::hex << *sIt;
        //sStringStream << *sIt;
    }

    std::cout << sStringStream.str() << "\n";

    return sStringStream.str();
}
int main(int argc, char* argv[])
{
    std::vector<int>    sVector;

    sVector.push_back( 10 );
    sVector.push_back( 11 );
    sVector.push_back( 12 );
    convertString( sVector );
    return 0;
}
