//#include <gsl/gsl>

#include <vector>
#include <iostream>
#include <sstream>

std::vector<int> convertInteger( std::string aFrom )
{
    std::vector<int>    sVector;
    std::stringstream   sStream;

    for ( int i = 0; i < aFrom.size(); i = i + 2 )
    {
        auto sToken = aFrom.substr( i, 2 );
        int  sValue = 0;

        sStream.clear();
        sStream.str( sToken );

        sStream >> std::hex >> sValue;

        sVector.push_back( sValue );

    }

    return sVector;
}
int main(int argc, char* argv[])
{
    std::string     sString( "CDABEF" );

    auto sConverted = convertInteger( sString );

    for ( auto sLoop = sConverted.begin();
          sLoop != sConverted.end();
          sLoop++ )
    {
        std::cout << std::showbase << std::hex <<  *sLoop << " ";
    }

    std::cout << "\n";

    return 0;
}
