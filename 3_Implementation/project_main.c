
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>


#define pi 3.142

struct Node
{
        char sat_name[100];
        float sat_long;
        struct Node *next;
};

void display(struct Node *n)
{
    printf("SATELLITE_NAME\t\tLATITUDE");
    while(n!=NULL)
    {
        printf("%10s\t%f", n->sat_name, n->sat_long);
        n = n->next;
    }
}

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

struct Node* read_database()
{
    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    size_t read;
    char  s_name[100], lat[100], temp[100];
    int flag, loc, i;
    fp = fopen("database.txt", "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);

        struct Node *head_return=NULL;
        struct Node *head=NULL;

    char *file_contents = malloc(1000*sizeof(char));
    while (fscanf(fp, "%[^\n] ", file_contents) != EOF)
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
    printf("\nprinting from linked list\n");
    /*while(head!=NULL)
    {
            printf("%s\t\t%f",head->sat_name, head->sat_long);
            printf("\n");
            head = head->next;
    }*/

}

void main()
{
    float e_lat, e_long, s_lat, s_long, s_alt=35786, rs=6374, re,gamma, dist, elevation, azimuth;
    char e_lat_dirn, c;
    printf("\nEnter the Hemisphere of the EARTH_STATION (N/S): ");
    scanf("%c", &c);
    e_lat_dirn = toupper(c);

    printf("\nEnter the LAT of EARTH_STATION : ");
    scanf("%f", &e_lat);
    
    printf("\nEnter the LONG of EARTH_STATION (if west, enter the angle in negative): ");
    scanf("%f", &e_long);

    struct Node* h;
    h = read_database();
    while(h!=NULL)
    {
        s_long = h->sat_long;
        e_lat = deg_to_rad(e_lat);
        s_long = deg_to_rad(s_long);
        e_long = deg_to_rad(e_long); 
        
        gamma = (acos((cos(e_lat)*cos(e_long-s_long))));
        rs=re+s_alt;
        
        dist = sqrt(pow(rs,2)+pow(re,2)-2*re*rs*cos(gamma));
        
        printf("\n\n\n\nSATELLITE %s IS BIENG PROCESSED............",h->sat_name);
        printf("\n\n Visibility test : ");
        if(visibility_test(gamma))
        {
            printf("\nSatellite %s is VISIBLE from THE EARTH_STAION", h->sat_name);
            elevation = elevation_calc(dist, rs, gamma);
            azimuth = azimuth_calc(s_long, e_long, e_lat, 'N');
            printf("\nThe following are the parameters required by the EARTH_STAION antennae : ");
            printf("\n\televation = %f degrees (from the horizon)", elevation);
            printf("\n\tazimuth = %f degrees (clockwise from true-north)\n", azimuth);
            //printf("\ngamma = %f degrees", (rad_to_deg(gamma)));
        }
        else
            printf("\nSatellite %s NOT VISIBLE from the EARTH_STATION\n", h->sat_name);

        h = h->next;
    }
    
}
