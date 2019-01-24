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
	// print_list();

    insert_node(12,"ffs",5);
    insert_node(23,"sdgf",3);
    insert_node(13,"dsfa",5);
    insert_node(23,"fsd",45);
    print_list();

    freelist();
    line('+',85);
}