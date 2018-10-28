//#include <gsl/gsl>

#include <array>
#include <string>
#include <iostream>

std::string transForm( std::string   aFrom,
                       std::string   aDelimiter )
{
    std::string   sTo;
    char        * sToken = NULL;
    std::array<std::string, 3>   sDate;
    int           sIndex = 0;

    sToken = std::strtok( const_cast<char*>( aFrom.c_str() ), 
                          aDelimiter.c_str() );
    while( sToken != NULL )
    {
        sDate[sIndex]= sToken;

        sToken = std::strtok( NULL, aDelimiter.c_str() );
        sIndex++;
    }

    sTo = sDate[2] + "-" + sDate[1] + "-" + sDate[0];

    return sTo;
}

int main(int argc, char* argv[])
{
    std::string sDate( "23.10.1981" );
    std::string sDelimiter( "-.");

    std::cout << transForm( sDate, sDelimiter ) << "\n";

    return 0;
}
