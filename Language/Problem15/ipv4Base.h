
#include <iostream>
#include <array>
#include <sstream>

class ipv4Base
{
public:
    ipv4Base()
    {
    };

    ipv4Base( std::string   aInput )
    {
        setIPv4FromString( aInput );
    };

    ~ipv4Base()
    {
    };

    friend std::ostream& operator<< ( std::ostream & aOut, 
                                      ipv4Base     & aIpv4 )
    {
        aOut << aIpv4.mIPAddress[0] << "." << aIpv4.mIPAddress[1] << "." <<
                aIpv4.mIPAddress[2] << "." << aIpv4.mIPAddress[3];

        return aOut;
    }

    friend std::istream& operator>> ( std::istream & aIn, 
                                      ipv4Base     & aIpv4 )
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

    std::string getStringFormat()
    {
        std::ostringstream  sStringSteam;

        sStringSteam << mIPAddress[0] << "." << mIPAddress[1] << "." <<
                        mIPAddress[2] << "." << mIPAddress[3];

        return sStringSteam.str();
    }

protected:
    std::array<int, 4>  mIPAddress;

    bool setIPv4FromString( std::string  aFrom )
    {
        std::istringstream  sIss( aFrom );
        std::string         sToken;
        int                 sIndex = 0;
        int                 sValue = 0;
        bool                sIsValid = true;

        std::cout << aFrom << "\n";

        while ( ( std::getline( sIss, sToken, '.' ) ) &&
                ( sIsValid == true ) )
        {
            sValue = std::atoi( sToken.c_str() );
            if ( ( sValue >= 0 ) && ( sValue <= 255 ) )
            {
//              mIPAddress[sIndex] = sToken.stoul();
                mIPAddress[sIndex] = sValue;
                sIndex++;
            }
            else
            {
                std::cout << "value is over\n";
                sIsValid = false;
            }

            if ( sIndex > 5 )
            {
                std::cout << "dot is over\n";
                sIsValid = false;
            }
        }

        if ( sIsValid == false )
        {
            std::cout << "invalid" << "\n";
            std::fill( mIPAddress.begin(), mIPAddress.end(), NULL );
        }

        return sIsValid;
    };
};
