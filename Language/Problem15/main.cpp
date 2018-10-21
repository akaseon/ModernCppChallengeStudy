//#include <gsl/gsl>
#include <iostream>
#include <array>
#include <sstream>

class ipv4
{
public:
    ipv4()
    {
        mIPAddress[0] = 1;
        mIPAddress[1] = 2;
        mIPAddress[2] = 3;
        mIPAddress[3] = 4;
    };

    ~ipv4()
    {
    };

    friend std::ostream& operator<< ( std::ostream & aOut, 
                                      ipv4         & aIpv4 )
    {
        aOut << aIpv4.mIPAddress[0] << "." << aIpv4.mIPAddress[1] << "." <<
                aIpv4.mIPAddress[2] << "." << aIpv4.mIPAddress[3];

        return aOut;
    }

    friend std::istream& operator>> ( std::istream & aIn, 
                                      ipv4         & aIpv4 )
    {
        std::string     sInputString;
        aIn >> sInputString;

        if ( aIpv4.setIPv4FromString( sInputString ) == false )
        {
            aIn.setstate( std::ios::failbit );
        }
        else
        {
            /* do nothing */
        }

        return aIn;
    }

private:
    std::array<int, 4>  mIPAddress;

    bool setIPv4FromString( std::string  aFrom )
    {
        std::istringstream  sIss( aFrom );
        std::string         sToken;
        int                 sIndex = 0;
        int                 sValue = 0;
        bool                sIsValid = true;

        while ( ( std::getline( sIss, sToken, '.' ) ) &&
                ( sIsValid == true ) )
        {
            sValue = std::atoi( sToken.c_str() );
            if ( ( sValue > 0 ) && ( sValue <= 255 ) )
            {
//              mIPAddress[sIndex] = sToken.stoul();
                mIPAddress[sIndex] = sValue;
                sIndex++;
            }
            else
            {
                sIsValid = false;
            }

            if ( sIndex > 5 )
            {
                sIsValid = false;
            }
        }

        if ( sIsValid == false )
        {
            std::fill( mIPAddress.begin(), mIPAddress.end(), NULL );
        }

        return sIsValid;
    };
};

int main(int argc, char* argv[])
{
    ipv4    sIpV4;

    std::cout << sIpV4 << "\n";

    std::cin >> sIpV4;

    std::cout << sIpV4 << "\n";

    return 0;
}
