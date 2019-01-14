/*this file contains the linked list
 for highscores*/
#include "highscores.h"

/*highscorenode structure*/
struct Scorenode
{
    int userid;
    char username[20];
    int highscore;
    struct Scorenode* next;
};

/*head for highscore linked list*/
struct Scorenode* HEAD = NULL;

// void insert_head(int userid,char username[20],int highscore)
// {
//     struct Scorenode* newNode = (struct Scorenode*)malloc(sizeof(struct Scorenode));
//     newNode->highscore = highscore;
//     newNode->next=NULL;
//     newNode->userid = userid;  
//     strcpy(newNode->username,username);
// }

void print_list()
{
    struct Scorenode* current=HEAD;
    if(current==NULL)
    {
        printf("---\t---\t---\n");
    }
    else
    {
        while(current!=NULL)
        {
            printf("%d\t%s\t%d\n",current->userid,current->username,current->highscore);
            current=current->next;
        }
    }   
}