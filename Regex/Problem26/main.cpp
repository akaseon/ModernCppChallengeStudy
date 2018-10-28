//#include <gsl/gsl>

#include <vector>
#include <string>
#include <iostream>

std::string joiningString( std::vector<std::string> aInputString,
                           char                     aDelimiter )
{
    std::string     sJoiningString;
    bool            sNeedDelimiter = false;

    for ( auto sToken: aInputString )
    {
        if ( sNeedDelimiter == true )
        {
            sJoiningString.push_back( aDelimiter );
        }

        sJoiningString += sToken;

        sNeedDelimiter = true;
    }

    return sJoiningString;
}

int main(int argc, char* argv[])
{
    std::vector<std::string>    sInput = { "this", "is", "an", "example" };
    char                        sDelimiter = ' ';

    std::cout << joiningString( sInput,
                                sDelimiter ) << "\n";

    return 0;
}
