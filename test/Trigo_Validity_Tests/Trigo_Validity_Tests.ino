extern "C" {
  #include <Trigonometry.h>
}

#define NB_TESTED_VALUES 26

uint16_t angle_values[NB_TESTED_VALUES] = {
  0, 1, 2, 3, 3217, 4289, 6434,
  8579, 9651, 12867, 12868, 12869, 16085,
  25735, 25736, 25737, 32170, 35387, 38603,
  38604, 38605, 42893, 47183, 51470, 51471, 51472 };

int16_t expected_cosines[NB_TESTED_VALUES] = {
  16384, 16383, 16383, 16383, 15136, 14189, 11585,
  8191, 6269, 1, 0, -2, -6269,
  -16383, -16383, -16383, -11585, -6269, -1,
  0, 2, 8191, 14189, 16383, 16383, 16383 };

int16_t expected_sines[NB_TESTED_VALUES] = {
  0, 1, 3, 5, 6269, 8191, 11585,
  14189, 15136, 16383, 16383, 16383, 15136,
  1, 0, -2, -11585, -15136, -16383,
  -16383, -16383, -14189, -8191, -3, -1, 0 };

void setup( void )
{
    Serial.begin(9600);
    while (!Serial) {
    }
    Serial.println("Serial communication ready");

    int16_t cosine = 0;
    int16_t sine = 0;

    for( int test_idx=0 ; test_idx<NB_TESTED_VALUES ; test_idx++ )
    {
        Compute_Cosine_Sine( angle_values[test_idx], &cosine, &sine );
        Serial.print("Test #");
        Serial.print(test_idx+1);
        Serial.print(" | Angle = ");
        Serial.println(angle_values[test_idx]);
        
        Serial.print("Cosine : expected = ");
        Serial.print(expected_cosines[test_idx]);
        Serial.print(" computed = ");
        Serial.print(cosine);
        if( cosine==expected_cosines[test_idx] )
        {
            Serial.println("   OK");
        }
        else
        {
            Serial.println("   NOT OK");
        }

        Serial.print("Sine : expected = ");
        Serial.print(expected_sines[test_idx]);
        Serial.print(" computed = ");
        Serial.print(sine);
        if( sine==expected_sines[test_idx] )
        {
            Serial.println("   OK");
        }
        else
        {
            Serial.println("   NOT OK");
        }

        Serial.println("");
    }
}

void loop( void )
{
}
