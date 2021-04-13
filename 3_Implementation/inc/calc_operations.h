#ifndef __CALC_OPERATIONS_H__
#define __CALC_OPERATIONS_H__

#include<stdio.h>
#include<math.h>
#include<string.h>
#include <stdlib.h>

float deg_to_rad(float deg);
float rad_to_deg(float rad);
float elevation_calc(float d, float rs, float g);
float azimuth_calc(float s_long, float e_long, float e_lat, char e_lat_dir);
int visibility_test(float gamma);

#endif
