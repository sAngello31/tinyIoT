#include "utils.h"
#include <stdlib.h>


float generate_rand_number(float min, float max){
    return min + ((float)rand()/RAND_MAX) * (max - min);
}
