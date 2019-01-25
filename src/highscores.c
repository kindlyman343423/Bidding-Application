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

/**
 * insert_head()
 * this will insert the node at head of the linked list
 * 
 * @param int for uid
 * @param user string
 * @param int for score
 * 
 * @return void
 * 
 * @tc - O(1)
 * @sc - O(1)
 **/
void insert_head(int uid,char user[20],int score)
{
    struct Scorenode* newNode = (struct Scorenode*)malloc(sizeof(struct Scorenode));
    newNode->userid = uid;
    strcpy(newNode->username,user);
    newNode->highscore = score;

    newNode->next=HEAD;
    HEAD=newNode;
}

/**
 * insert_node()
 * it will insert a new node data in highscore linked list
 * 
 * @param int for user id
 * @param string for username
 * @param int for score
 * 
 * @return void
 * 
 * @tc - O(n)
 * @sc - O(1)
 **/
/*insert the node according to the scores*/
void insert_node(int uid,char user[20],int score)
{
    struct Scorenode* newNode = (struct Scorenode*)malloc(sizeof(struct Scorenode));
    newNode->userid = uid;
    strcpy(newNode->username,user);
    newNode->highscore = score;
    if(HEAD==NULL)
    {
        HEAD=newNode;
        return;
    }
    if(score>HEAD->highscore)
    {
        //insert at head
        newNode->next = HEAD;
        HEAD = newNode;
    }      
    else
    {
        //traverse the list and add
        struct Scorenode* current=HEAD;
        struct Scorenode* prev = HEAD;
        while(current!=NULL)
        {
            if(score>current->highscore)
            {
                break;
            }
            else
            {
                //traverse further
                prev=current;
                current=current->next;
            }
        }
        if(current!=NULL)
        {
            prev->next = newNode;
            newNode->next=current;
        }
        else
        {
            prev->next=newNode;
        }
    }
}

/**
 * freelist()
 * this will free the memory of the list
 * 
 * @param void
 * 
 * @return void
 * 
 * @tc - O(n)
 * @sc - O(1)
 **/
void freelist()
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

/**
 * print_list()
 * this function prints the list
 * 
 * @param void 
 * 
 * @return void
 * 
 * @tc - O(n^2)
 * @sc - O(1)
 **/
void print_list()
{
    struct Scorenode* current=HEAD;
    if(current==NULL)
    {
        printf("---\t\t---\t\t    ---\n");
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
}


/**
 * highscores()
 * this will display the highscores of the users
 * 
 * @param void
 * 
 * @return void
 * 
 * @tc - O(n^2)
 * @sc - O(1)
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
	printf(" ________    _________    _________    __________    __________    ________\n");
	printf("|\\  _____\\  |\\  ______\\  |\\  _____ \\  |\\  ______ \\  |\\  _______\\  |\\  _____\\\n");
	printf("\\ \\ \\______ \\ \\ \\_____|  \\ \\ \\    \\ \\ \\ \\ \\_____\\ \\ \\ \\ \\______|  \\ \\ \\______\n");
	printf(" \\ \\______ \\ \\ \\ \\        \\ \\ \\    \\ \\ \\ \\  _____ _\\ \\ \\  ____\\    \\ \\______ \\\n");
	printf("  \\| _____\\ \\ \\ \\ \\_______ \\ \\ \\____\\ \\ \\ \\ \\  \\ \\ \\  \\ \\ \\___|____ \\| _____\\ \\\n");
	printf("    |\\_______\\ \\ \\________\\ \\ \\________\\ \\ \\_\\  \\ \\_\\  \\ \\_________\\  |\\_______\\\n");
	printf("    \\|_______|  \\|________|  \\|________|  \\|_|   \\|_|   \\|_________|  \\|_______|\n");
	printf("\n");
	line('+',80);
	colorSetting(BLUE);
	printf("UserID\t\tUserName\t    HighScore\n");
	colorSetting(RESET);

    print_list();

    freelist();
    line('+',80);
}