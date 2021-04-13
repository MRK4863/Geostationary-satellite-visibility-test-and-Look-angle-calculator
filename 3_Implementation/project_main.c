#include "calc_operations.h"

#define pi 3.142
/**
 * @brief 
 * A dynamic linked list to read and store the 
 * Names and Locations of various Geostationary satellites
 */
struct Node
{
        char sat_name[100];
        float sat_long;
        struct Node *next;
};

/**
 * @brief 
 * Displays the List of satellites available in the database
 * @param n 
 */
void display(struct Node *n)
{
    printf("SATELLITE_NAME\t\tLATITUDE");
    while(n!=NULL)
    {
        printf("%10s\t%f", n->sat_name, n->sat_long);
        n = n->next;
    }
}

/**
 * @brief 
 * Converts angles from Degrees to Radians
 * @param deg 
 * @return float 
 */
float deg_to_rad(float deg)
{
    float rad;
    rad = deg*(pi/180);
    //printf("\nrad = %f, deg = %f", rad, deg);
    return rad;
}

/**
 * @brief 
 * Converts angles from Radian to Degrees
 * @param rad 
 * @return float 
 */
float rad_to_deg(float rad)
{
    float deg;
    deg = rad*(180/pi);
    //printf("\nrad = %f, deg = %f", rad, deg);
    return deg;
}

/**
 * @brief 
 * Calculates the ELEVATION angle of the antennae placed at EARTH_STATION for best SIGNAL reception
 * @param d 
 * @param rs 
 * @param g 
 * @return float 
 */
float elevation_calc(float d, float rs, float g)
{
    float el_rad, el_deg ;
    el_rad=(atan((6.610735-cos(g))/sin(g)))-g;
    el_deg = rad_to_deg(el_rad);
    
    return el_deg;
}

/**
 * @brief 
 * Calculates the AZIMUTH angle of the antennae placed at EARTH_STATION for best SIGNAL reception
 * @param s_long 
 * @param e_long 
 * @param e_lat 
 * @param e_lat_dir 
 * @return float 
 */
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

/**
 * @brief 
 * Checks if the SATELLITE is visible from the EARTH_STATION 
 * @param gamma 
 * @return int 
 */
int visibility_test(float gamma)
{
    if(rad_to_deg(gamma)<81.3)
        return 1;
    else    
        return 0;
}
/**
 * @brief 
 * A function to read the satellite databse, store the values in a dynamic linked list and return the pointer to the HEAD of the Linked-List
 * @return struct Node* 
 */
struct Node* read_database()
{
    FILE * fp;
    char * line = NULL;
    //size_t len = 0;
    //size_t read;
    char  s_name[100], lat[100], temp[100];
    int loc, i;
    fp = fopen("database.txt", "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);

        struct Node *head_return=NULL;
        struct Node *head=NULL;

    char *file_contents = malloc(1000*sizeof(char));
    while (fscanf(fp, "%30[^\n] ", file_contents) != EOF)
    {
        //printf("\n%s", file_contents);
        strcpy(temp, file_contents);
        //printf("\n%c", temp);
        //printf("\n%d", strlen(temp));

        for(i=0;i<strlen(temp);i++)
        {
                if(temp[i]==' ')
                {
                        loc = i;
                }   
        }
        for(i=0;i<strlen(temp);i++)
        {
                if(i<loc)
                {
                        s_name[i]=temp[i];
                }
                if(i>loc)
                {
                        lat[i-loc-1] =  temp[i];
                }  
                if(i==loc)
                {
                        s_name[i]='\0';
                }
                if(i==(strlen(temp)-1))
                {
                        lat[strlen(temp)-loc-1]='\0';
                }
        }

        //printf("\nspace_location : %d", loc);
        //printf("\nsat_name extracted : %s", s_name);
        //printf("\nlongitude extracted : %s", lat);
        //
        struct Node *t;
        t = (struct Node*)malloc(sizeof(struct Node));
        t->next=head;
        strcpy(t->sat_name, s_name);
        t->sat_long = atof(lat);
        head = t;
    }
    
    fclose(fp);
    return head;
    //printf("\nprinting from linked list\n");
    /*while(head!=NULL)
    {
            printf("%s\t\t%f",head->sat_name, head->sat_long);
            printf("\n");
            head = head->next;
    }*/

}
/**
 * @brief 
 * The MAIN function
 * It takes the location of EARTH_STATION from the user and displays the parameters of the satellites visible from the EARTH_STATION 
 */
void main()
{
    float e_lat, e_long,  re=6374, rs=42160, elevation, azimuth;
    char e_lat_dirn;
    printf("\nEnter the Hemisphere of the EARTH_STATION (N/S): ");
    scanf("%c", &e_lat_dirn);

    printf("\nEnter the LAT of EARTH_STATION : ");
    scanf("%f", &e_lat);
    
    printf("\nEnter the LONG of EARTH_STATION (if west, enter the angle in negative): ");
    scanf("%f", &e_long);

    struct Node* h;
    h = read_database();
    while(h!=NULL)
    {
       
        float gamma, dist, s_long;
        s_long = h->sat_long;
        e_lat = deg_to_rad(e_lat);
        s_long = deg_to_rad(s_long);
        e_long = deg_to_rad(e_long); 
        
        gamma = (acos((cos(e_lat)*cos(e_long-s_long))));
        
        dist = sqrt(pow(rs,2)+pow(re,2)-2*re*rs*cos(gamma));
        
        printf("\n\n\n\nSATELLITE %s IS BIENG PROCESSED............",h->sat_name);
        printf("\n\n Visibility test : ");
        if(visibility_test(gamma))
        {
            printf("\nSatellite %s is VISIBLE from THE EARTH_STAION", h->sat_name);
            elevation = elevation_calc(dist, rs, gamma);
            azimuth = azimuth_calc(s_long, e_long, e_lat, 'N');
            printf("\nDistance from satellite to Earth_station: %f", dist);
            printf("\nThe following are the parameters required by the EARTH_STAION antennae : ");
            printf("\n\televation = %f degrees (from the horizon)", elevation);
            printf("\n\tazimuth = %f degrees (clockwise from true-north)\n", azimuth);
            printf("\ngamma = %f degrees", (rad_to_deg(gamma)));
        }
        else
            printf("\nSatellite %s NOT VISIBLE from the EARTH_STATION\n", h->sat_name);

        h = h->next;
    }
    
}