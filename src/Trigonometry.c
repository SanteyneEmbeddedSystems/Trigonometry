#include "Trigonometry.h"


/******************************************************************************/
/** Constants **/
/******************************************************************************/
/* Angles of rotation table */
/* The first rotation angle (pi/4) is removed because
rotation_sum is initialized to pi/4 */
static const int32_t rotation_angles[10] ={
    248918915,
    131521918,
    66762579,
    33510843,
    16771758,
    8387925,
    4194219,
    2097141,
    1048575,
    524288 };


/******************************************************************************/
/** Public function definition **/
/******************************************************************************/
void Compute_Cosine_Sine(
    uint16_t angle,
    int16_t* const cosine,
    int16_t* const sine )
{
    /* Set computation on [0, pi/2] */
    if( angle > THREE_HALVES_PI_RAD )
    {
        Compute_Cosine_Sine( TWO_PI_RAD - angle , cosine, sine );
        *sine = -*sine;
    }
    else if( angle > PI_RAD )
    {
        Compute_Cosine_Sine( angle - PI_RAD, cosine, sine );
        *cosine = -*cosine;
        *sine = -*sine;
    }
    else if( angle > ONE_HALF_PI_RAD )
    {
        Compute_Cosine_Sine( PI_RAD - angle, cosine, sine );
        *cosine = -*cosine;
    }
    /* CORDIC algorithm */
    else
    {
        /* Switch to 32 bits */
        int32_t angle_32bits = ((int32_t)angle)<<16;
        /* allowed because max(angle) = ONE_HALF_PI_RAD = 12868
        and  12868<<16 < INT32_MAX */

        int32_t rotations_sum = 421657428; /* (pi/4 / 2^-13 )<< 16 */

        /* Following value are not exactly sine and cosine as the K factor is
        applied by advance (to avoid a multiplication). */
        int32_t cosine_32bits = 652032874; /*  cos(pi/4) / 2^-30 * K'(29) */
        int32_t sine_32bits = 652032874;   /*  sin(pi/4) / 2^-30 * K'(29) */


        /* Select first rotation angle */
        int32_t rotation = rotation_angles[0];

        /* 29 rotations to make rotations_sum converge towards angle_32bits */
        for ( uint8_t rotation_idx=1 ; rotation_idx<=29 ; rotation_idx++ )
        {
            int32_t cosine_32bits_copy = cosine_32bits;
            if( angle_32bits > rotations_sum )
            {
                cosine_32bits -= (sine_32bits>>rotation_idx);
                sine_32bits += (cosine_32bits_copy>>rotation_idx);
                rotations_sum += rotation;
            }
            else
            {
                cosine_32bits += (sine_32bits>>rotation_idx);
                sine_32bits -= (cosine_32bits_copy>>rotation_idx);
                rotations_sum -= rotation;
            }

            /* Select next rotation angle */
            if ( rotation_idx < 10 )
            {
                rotation = rotation_angles[rotation_idx];
            }
            else
            {
                rotation = rotation/2;
            }
        }

        /* Go back to 16 bits */
        *cosine = cosine_32bits>>16;
        *sine = sine_32bits>>16;
    }
}
