#include <gsl/gsl>

int main(int argc, char* argv[])
{
    int     sInput = 0;
    int     i = 0;
    int     sum = 0;

    sInput = atoi( argv[1] );

    for ( i = 0; i <= sInput; i++ )
    {
        if ( ( ( i % 3 ) == 0 ) ||
             ( ( i % 5 ) == 0 ) )
        {
            sum = sum + i;
        }
    }

    printf( "%d\n", sum );

    return 0;
}
