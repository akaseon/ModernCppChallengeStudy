//#include <gsl/gsl>

#include <sstream>
#include <string>
#include <iostream>

std::string capitalizing( std::string   aFrom )
{
    std::string sTo;

    std::istringstream  sIss( aFrom );
    std::string         sToken;

    bool                sNeedSpace = false;

    while (  std::getline( sIss, sToken, ' ' ) )
    {
        if ( sNeedSpace == true )
        {
            sTo.push_back( ' ' );
        }

        if ( ( sToken[0] >= 'a' ) && ( sToken[0] <= 'z' ) )
        {
            sToken[0] = sToken[0] + 'A' - 'a';
        }

        sTo += sToken;

        sNeedSpace = true;
    }

    return sTo;
}

int main(int argc, char* argv[])
{
    std::string     sString( "the c++ challenger" );

    std::cout << capitalizing( sString ) << "\n";

    return 0;
}
