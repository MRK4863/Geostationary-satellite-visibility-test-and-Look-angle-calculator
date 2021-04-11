

//This is the first line of comments
#include<stdio.h>
#include<math.h>
#include<string.h>

#define pi 3.142

float deg_to_rad(float deg)
{
    float rad;
    rad = deg*(pi/180);
    //printf("\nrad = %f, deg = %f", rad, deg);
    return rad;
}

float rad_to_deg(float rad)
{
    float deg;
    deg = rad*(180/pi);
    //printf("\nrad = %f, deg = %f", rad, deg);
    return deg;
}

float elevation_calc(float d, float rs, float g)
{
    float el_rad, el_deg ;
    el_rad=(atan((6.610735-cos(g))/sin(g)))-g;
    el_deg = rad_to_deg(el_rad);
    
    return el_deg;
}

float azimuth_calc(float s_long, float e_long, float e_lat, char e_lat_dir)
{
    float intermediate_angle, diff;
    diff = e_long - s_long;

    if(diff<0)
        diff = -diff;

    intermediate_angle = atan(tan(diff)/sin(e_lat));
    intermediate_angle = rad_to_deg(intermediate_angle);
    if (e_lat_dir=='N')
    {
        if (e_long <= s_long)
            return 180 - intermediate_angle;
        else
            return 180 + intermediate_angle;
    }

    else
    {
        if (e_long <= s_long)
            return intermediate_angle;
        else
            return 360 - intermediate_angle;

    }
}

int visibility_test(float gamma)
{
    if(rad_to_deg(gamma)<81.3)
        return 1;
    else    
        return 0;
}

char * read_database()
{

}

void main()
{
    float e_lat, e_long, s_lat, s_long, s_alt=35786, rs=6374, re,gamma, dist, elevation, azimuth;
    char e_lat_dirn;
    
    printf("\nEnter the LAT of EARTH_STATION : ");
    scanf("%f", &e_lat);
    printf("\nEnter the Hemisphere of the EARTH_STATION (N/S): ");
    scanf("%c", &e_lat_dirn);

    e_lat_dirn = toupper(e_lat_dirn);
    printf("\nEnter the LONG of EARTH_STATION (if west, enter the angle in negative): ");
    scanf("%f", &e_long);

    printf("\nEnter the LONG of SATELLITE (if west, enter the angle in negative): ");
    scanf("%f", &s_long);
    
    e_lat = deg_to_rad(e_lat);
    s_long = deg_to_rad(s_long);
    e_long = deg_to_rad(e_long); 
    
    gamma = (acos((cos(e_lat)*cos(e_long-s_long))));
    rs=re+s_alt;
    
    dist = sqrt(pow(rs,2)+pow(re,2)-2*re*rs*cos(gamma));
    
    printf("\n Visibility test : ");
    if(visibility_test(gamma))
    {
        printf("\nSATELLITE IS VISIBLE FROM THE EARTH_STAION");
        elevation = elevation_calc(dist, rs, gamma);
        azimuth = azimuth_calc(s_long, e_long, e_lat, 'N');
        printf("\nelevation = %f degrees (from the horizon)", elevation);
        printf("\nazimuth = %f degrees (clockwise from true-north)", azimuth);
        //printf("\ngamma = %f degrees", (rad_to_deg(gamma)));
    }
    else
        printf("\nSatellite NOT within visible region");
}
