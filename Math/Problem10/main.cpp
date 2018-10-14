#include <gsl/gsl>

#include <bitset>
#include <iostream>

int convertGreyCode( int    aBit )
{
    int sGreyCode = ( aBit & 0B10000 ) |
                    ( ( ( aBit & 0B10000 ) >> 1 ) ^ ( aBit & 0B01000 ) ) |
                    ( ( ( aBit & 0B01000 ) >> 1 ) ^ ( aBit & 0B00100 ) ) |
                    ( ( ( aBit & 0B00100 ) >> 1 ) ^ ( aBit & 0B00010 ) ) |
                    ( ( ( aBit & 0B00010 ) >> 1 ) ^ ( aBit & 0B00001 ) ); 

    return sGreyCode;
}

int main(int argc, char* argv[])
{
    for ( int i = 0B00000; i <= 0B11111; i++ )
    {
        std::cout << std::bitset<5>( i ) << " -> "; 
        std::cout << std::bitset<5>( convertGreyCode( i ) ) << "\n";
    }

    return 0;
}
