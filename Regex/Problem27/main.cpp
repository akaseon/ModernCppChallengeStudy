//#include <gsl/gsl>

#include <vector>
#include <string>
#include <iostream>

std::vector<std::string> splittingString( std::string   aFrom,
                                          std::string   aDelimiter )
{
    std::vector<std::string>   sTo;
    char                     * sToken = NULL;

    sToken = std::strtok( const_cast<char*>( aFrom.c_str() ), 
                          aDelimiter.c_str() );
    while( sToken != NULL )
    {
        sTo.push_back( sToken );
        sToken = std::strtok( NULL, aDelimiter.c_str() );
    }

    return sTo;
}

int main(int argc, char* argv[])
{
    std::string sString( "this,is.a sample!!" );
    std::string sDelimiter( ",.! ");
    std::vector<std::string>    sResult;

    sResult = splittingString( sString, sDelimiter );

    for( auto sToken: sResult )
        std::cout << sToken << "\n";

    return 0;
}
