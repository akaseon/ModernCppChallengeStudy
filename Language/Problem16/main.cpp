//#include <gsl/gsl>

#include "ipv4Extend.h"

int main(int argc, char* argv[])
{
    ipv4Extend    sFrom( "127.0.0.1" );
    ipv4Extend    sTo( "127.0.10.1" );

    while ( sFrom < sTo )
    {
        std::cout << sFrom << "\n";
        sFrom++;
    }

    return 0;
}
