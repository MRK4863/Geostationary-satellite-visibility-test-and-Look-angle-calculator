#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node
{
        char sat_name[100];
        float sat_long;
        struct Node *next;
};

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
        printf("\n%s", file_contents);
        strcpy(temp, file_contents);
        printf("\n%c", temp);
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

        printf("\nspace_location : %d", loc);
        printf("\nsat_name extracted : %s", s_name);
        printf("\nlongitude extracted : %s", lat);

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
        struct Node* h;
        h = read_database();
        
        /*char s[]="-100.0";
        float t;
        t=atof(s);
        printf("%f", t);*/

}
