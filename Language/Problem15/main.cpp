//#include <gsl/gsl>

#include "ipv4Base.h"

int main(int argc, char* argv[])
{
    ipv4Base    sIpV4( "127.0.0.1" );

	if ( "127.0.0.1" == sIpV4.getStringFormat() )
    {
        std::cout << "OK" << "\n";
    }
    else
    {
        std::cout << "NOK : " << sIpV4.getStringFormat() << "\n";
    }

    return 0;
}
