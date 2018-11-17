//#include <gsl/gsl>

#include <ctime>
#include <iostream>

//#define CLEAR_UNDER_DAY( aDate ) ( aDate.tm_hour = 0;   \
//                                   aDate.tm_min = 0;    \
//                                   aDate.tm_sec = 0; )

double diffDay( std::tm aDate1, std::tm aDate2 )
{
//    CLEAR_UNDER_DAY( aDate1 );
//    CLEAR_UNDER_DAY( aDate2 );
    
    aDate1.tm_hour = 0;   
    aDate1.tm_min = 0;    
    aDate1.tm_sec = 0; 
    aDate2.tm_hour = 0;   
    aDate2.tm_min = 0;    
    aDate2.tm_sec = 0; 

    std::time_t sTime1 = std::mktime( &aDate1 );
    std::time_t sTime2 = std::mktime( &aDate2 );

    return std::difftime( sTime1, sTime2 ) / ( 60 * 60 * 24 );
}

int main(int argc, char* argv[])
{
    std::time_t t = std::time( nullptr );

    std::tm     sDate1 = *std::localtime( &t );
    
    std::tm     sDate2 = sDate1;
    
    sDate2.tm_mday += 2;
    
    double day = diffDay( sDate2, sDate1 );

    std::cout << day << "\n";




    
    return 0;
}
