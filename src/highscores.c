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

void insert_head(int uid,char user[20],int score)
{
    struct Scorenode* newNode = (struct Scorenode*)malloc(sizeof(struct Scorenode));
    newNode->userid = uid;
    strcpy(newNode->username,user);
    newNode->highscore = score;

    newNode->next=HEAD;
    HEAD=newNode;
}

void freem()
{
    struct Scorenode* current=HEAD;
    while(current!=NULL)
    {
        free(current);
        current=current->next;
    }
    free(HEAD);
    HEAD=NULL;
}

void print_list()
{
    insert_head(1,"walia",122);
    insert_head(2,"gairav walia",1221);

    struct Scorenode* current=HEAD;
    if(current==NULL)
    {
        printf("---\t---\t---\n");
    }
    else
    {
        while(current!=NULL)
        {
            printf("%d\t\t%s",current->userid,current->username);
            int len = strlen(current->username);
            len = 20-len;
            for(register int i=0;i<len;i++)
            {
                printf(" ");
            }
            printf("%d\n",current->highscore);
            current=current->next;
        }
    }
    freem();
}

/**
 * highscores()
 * this will display the highscores of the users
 * 
 * @param void
 * 
 * @return void
 **/
void highscores()
{
    /*printing HIGH*/
	colorSetting(BLGREEN);
	printf(" __       __      __      _________      __       __\n");
	printf("|\\ \\     |\\ \\    |\\ \\    |\\  ______\\    |\\ \\     |\\ \\               \n");
	printf("\\ \\ \\____\\_\\ \\   \\ \\ \\   \\ \\ \\    ___   \\ \\ \\____\\_\\ \\               \n");
	printf(" \\ \\  _______ \\   \\ \\ \\   \\ \\ \\  |__ \\   \\ \\  _______ \\\n");
	printf("  \\ \\ \\_____ \\ \\   \\ \\ \\   \\ \\ \\_\\|_\\ \\   \\ \\ \\_____ \\ \\            \n");
	printf("   \\ \\_\\    \\ \\_\\   \\ \\_\\   \\ \\________\\   \\ \\_\\    \\ \\_\\      \n");
	printf("    \\|_|     \\|_|    \\|_|    \\|________|    \\|_|     \\|_|                        \n");
	colorSetting(RESET);
	printf("\n");

	/*printing SCORES*/
	printf(" _________    __________    __________    __________    __________    __________\n");
	printf("|\\  ______\\  |\\  _______\\  |\\  ______ \\  |\\  ______ \\  |\\  _______\\  |\\  _______\\\n");
	printf("\\ \\ \\_______ \\ \\ \\______|  \\ \\ \\     \\ \\ \\ \\ \\_____\\ \\ \\ \\ \\______|_ \\ \\ \\________\n");
	printf(" \\ \\_______ \\ \\ \\ \\         \\ \\ \\     \\ \\ \\ \\  _____ _\\ \\ \\  _______\\ \\ \\________ \\\n");
	printf("  \\| ______\\ \\ \\ \\ \\________ \\ \\ \\_____\\ \\ \\ \\ \\  \\ \\ \\  \\ \\ \\______|_ \\| _______\\ \\\n");
	printf("    |\\________\\ \\ \\_________\\ \\ \\_________\\ \\ \\_\\  \\ \\_\\  \\ \\_________\\  |\\_________\\\n");
	printf("    \\|________|  \\|_________|  \\|_________|  \\|_|   \\|_|   \\|_________|  \\|_________|\n");
	printf("\n");
	line('+',85);
	colorSetting(BLUE);
	printf("UserID\t\tUserName\t    HighScore\n");
	colorSetting(RESET);
	print_list();
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}