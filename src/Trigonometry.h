#ifndef TRIGONOMETRY_H
#define TRIGONOMETRY_H


#include <stdint.h>


/******************************************************************************/
/** Predefined angle values **/
/******************************************************************************/
#define ONE_QUARTER_PI_RAD     6434U
#define ONE_HALF_PI_RAD       12868U
#define PI_RAD                25736U
#define THREE_HALVES_PI_RAD   38604U
#define TWO_PI_RAD            51472U


/******************************************************************************/
/** Public functions declaration **/
/******************************************************************************/
/* Compute_Cosine_Sine

Parameters :
   angle  : rad | resol = 2^-13 | min = 0      ;  0 | max = 51472 ; 2pi
   cosine :  -  | resol = 2^-14 | min = -16384 ; -1 | max = 16384 ; 1
   sine   :  -  | resol = 2^-14 | min = -16384 ; -1 | max = 16384 ; 1
*/
void Compute_Cosine_Sine(
    uint16_t angle,
    int16_t* const cosine,
    int16_t* const sine );

#endif
