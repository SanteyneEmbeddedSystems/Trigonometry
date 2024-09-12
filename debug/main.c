#include <stdio.h>
#include <stdlib.h>

#include "Trigonometry.h"

int main()
{
    uint16_t angle;
    int16_t cosine;
    int16_t sine;

    angle = 0;
    Compute_Cosine_Sine( angle, &cosine, &sine );
    printf( "0 : %u | %i | %i\n", angle, cosine, sine );

    angle = ONE_QUARTER_PI_RAD;
    Compute_Cosine_Sine( angle, &cosine, &sine );
    printf( "pi/4  : %u | %i | %i\n", angle, cosine, sine );

    angle = ONE_HALF_PI_RAD;
    Compute_Cosine_Sine( angle, &cosine, &sine );
    printf( "pi/2 : %u | %i | %i\n", angle, cosine, sine );

    return 0;
}


