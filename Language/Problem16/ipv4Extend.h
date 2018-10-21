//#include <gsl/gsl>

#include "../Problem15/ipv4Base.h"

class ipv4Extend : public ipv4Base
{
public:
    ipv4Extend() : ipv4Base()
    {
    };

    ipv4Extend( std::string   aInput ) : ipv4Base( aInput )
    {
    };

    ~ipv4Extend()
    {
    };

    ipv4Extend& operator= ( const ipv4Extend & aOther )
    {
        if ( this != & aOther )
        {
            mIPAddress = aOther.mIPAddress;
        }

        return *this;
    }

    //ipv4Extend& operator= ( ipv4Extend && aOther )
    //{
    //    if ( this != &aOther )
    //    {
    //    }

    //    return *this;
    //}

    ipv4Extend& operator++()
    {
        increase();

        return *this;
    }

    ipv4Extend operator++( int )
    {
        ipv4Extend sTemp( *this );
        operator++();
        return sTemp;
    }

    friend bool operator== ( const ipv4Extend   & aLhs,
                             const ipv4Extend   & aRhs )
    {
        return (aLhs.mIPAddress == aRhs.mIPAddress);
    }

    friend bool operator!= ( const ipv4Extend   & aLhs,
                             const ipv4Extend   & aRhs )
    {
        return !( aLhs == aRhs );
    }

    friend bool operator < ( const ipv4Extend   & aLhs,
                             const ipv4Extend   & aRhs )
    {
        bool    sIsRigthBigger = false;
        
        for ( int i = 0; i < 4; i++ )
        {
            if ( aLhs.mIPAddress[i] < aRhs.mIPAddress[i] )
            {
                sIsRigthBigger = true;
                break;
            }
        }

        return sIsRigthBigger;
    }

    friend bool operator > ( const ipv4Extend   & aLhs,
                             const ipv4Extend   & aRhs )
    {
        return aRhs < aLhs;
    }

    friend bool operator <= ( const ipv4Extend   & aLhs,
                              const ipv4Extend   & aRhs )
    {
        return !( aLhs > aRhs );
    }
    
    friend bool operator >= ( const ipv4Extend   & aLhs,
                              const ipv4Extend   & aRhs )
    {
        return !( aLhs < aRhs );
    }

private:

    void increase()
    {
        bool    sIsRoundUp = false;

        mIPAddress[3]++;

        for ( auto sIt = mIPAddress.rbegin();
              sIt != mIPAddress.rend();
              sIt++ )
        {
            //std::cout << *sIt << "\n";
            if ( sIsRoundUp == true )
            {
                *sIt = *sIt + 1;
                //*sIt++;
            }

            //std::cout << *sIt << "\n";
            if ( (*sIt) > 255 )
            {
                sIsRoundUp = true;
                *sIt = 0;
            }
            else
            {
                sIsRoundUp = false;
            }
        }

        if ( sIsRoundUp == true )
        {
            mIPAddress[3]++;
        }
    }

    void decrease()
    {
        bool sIsRoundDown = false;
    }
};
