#include "functions.h"
/*FUNCTIONS*/

/**
 * line()
 * prints the line
 * @return none
 **/
void line()
{
	int k;
	for(k=0;k<80;k++)
	{
		printf("#");
	}
	printf("\n");
}

/**
 * list()
 * lists the files present in current directory
 * @return void
 **/
void list()
{
	printf("\n");
	//CREATING POINTER TO A DIRECTORY
	DIR *pdir = NULL;
	//USING DIRENT STRUCTURE
	struct dirent *pent = NULL;
	//OPENING DIRECTORY
	pdir = opendir(".");
	if(pdir == NULL)
	{
		printf("ERROR !!!!!!!\n");
		exit(1);
	}
	while(pent = readdir(pdir))
	{
		if(pent == NULL)
		{
			printf("pent ERROR");
			exit(3);
		}
		printf("%s\n",pent->d_name);
	}
	//CLOSING DIRECTORY
	closedir(pdir);
	printf("\n");
}

/**
 * searchDB()
 * it will search the current string in the database
 * @param find[20]
 * @return bool boolean for searching
 * @complexity tc-O(n) sc-O(1)
 **/
bool searchDB(char find[20])
{
	int strcounter=0;				 //string counter for counting
	char str[50];					 //string for reading
	FILE *db;
	db = fopen("database.txt","r");  //reading database file
	while(!feof(db))
	{
		char ch = fgetc(db);
		if(ch==' ' || ch=='\n')
		{
			str[strcounter]='\0';
			if(strcmp(str,find)==0)
			{
				return true;
			}
			strcounter=0;			//resetting string counter
		}
		else
		{
			str[strcounter]=ch;
			strcounter++;
		}
	}
	fclose(db);
	return false;
}

/**
 * welcome()
 * for greeting the user
 * @param void
 * @tc O(1)
 * @sc O(1)
 **/
void welcome()
{
	for(register int i=0;i<75;i++)
	{
		printf("=");
	}
	printf("\n");

	printf("\t  ---- 	-----	---           /\\    	---- 	---- \n");
	printf("\t  |   |	  |  	|  \\         /  \\  	|   |	|   |\n");
	printf("\t  |--- 	  |  	|  |  ===   /====\\  	|--- 	|--- \n");
	printf("\t  |   |	  |  	|  /       /      \\ 	|    	|    \n");
	printf("\t  ---- 	-----	---       /        \\	|    	|    \n");
	printf("\t\t\t\t\t\t\t\tVERSION 0.1\n");
	for(register int i=0;i<75;i++)
	{
		printf("=");
	}
	printf("\n");
}

/**
 * welcomeLINUX()
 * colored UI for LINUX
 **/
void welcomeLINUX()
{
	printf("%s",BLUE);
	for(register int i=0;i<75;i++)
	{
		printf("=");
	}
	printf("%s\n",RESET);

	printf("%s",BWHITE);
	printf("\t  ---- 	-----	---           /\\    	---- 	---- \n");
	printf("\t  |   |	  |  	|  \\         /  \\  	|   |	|   |\n");
	printf("\t  |--- 	  |  	|  |  ===   /====\\  	|--- 	|--- \n");
	printf("\t  |   |	  |  	|  /       /      \\ 	|    	|    \n");
	printf("\t  ---- 	-----	---       /        \\	|    	|    \n");
	printf("%s",RESET);
	printf("\t\t\t\t\t\t\t\t%sVERSION 0.1%s\n",BLGREEN,RESET);
	printf("\t\t\t\t\t\t     %sPowered by RAINBOW 0.1%s\n",YELLOW,RESET);
	printf("%s",BLUE);
	for(register int i=0;i<75;i++)
	{
		printf("=");
	}
	printf("%s\n",RESET);
}

/**
 * greetOptions()
 * show greet options to the user
 * @param void
 * @return void
 * @tc O(1)
 * @sc O(1)
 **/
void greetOptions()
{
	printf("Welcome to our GAME\n\n");
	printf("%s",BOLD);
	printf("Enter below option to start%s\n",RESET);
	
	printf("----------------------------\n");
	printf("1. PLAY NEW GAME\n");
	printf("----------------------------\n");
	printf("2. START SAVED GAME\n");
	printf("----------------------------\n");
	printf("3. SAVE\n");
	printf("----------------------------\n");
	printf("4. SAVE AND EXIT\n");
	printf("----------------------------\n");
	printf("5. SETTINGS\n");
	printf("----------------------------\n");
	printf("0. EXIT\n");
	printf("----------------------------\n");
	printf("%sOPTION: ",BOLD);
	int q;
	scanf("%d",&q);
	printf("%s",RESET);
	switch(q)
	{
		case 0:
			exit(0);
		case 1:
			playNewGame();
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		default:
			break;
	}
}

/**
 * BidCard structure
 * for making bid cards
 **/
struct BidCard			
{
	int BidID;					//unique ID of bidcards
	char BidCardName[20];				//name of the person on bidcard
	char skills[200];			//skills of the person on bidcard
	char companyName[50];		//company name in which person work
	char Designation[20];		//designation of the person
};

/**
 * displayBidCard()
 * it will display the cards of the user
 * @param struct BidCard
 * @return void
 **/
void displayBidCard(struct BidCard BC)
{
	printf("-----------\n");
	puts(BC.BidCardName);
	puts(BC.skills);
	puts(BC.companyName);
	puts(BC.Designation);
	printf("-----------\n");
}

/**
 * displayBidCardLINUX
 * it will display card in linux
 * @param struct BidCard
 * @return void
 **/
void displayBidCardLINUX(struct BidCard BC)
{
	//same as above with colors
}

/**
 * createBidCard()
 * it will create new bid card for a user
 * @param void
 * @return struct BidCard
 **/
struct BidCard createBidCard()
{
	struct BidCard card;
	
	card.BidID = BIDCARDID;
	BIDCARDID++;
	
	getchar();
	printf("Enter the name of the Bid Card Player\n");
	gets(card.BidCardName);

	printf("Enter the skills of the Bid Card Player\n");
	gets(card.skills);

	printf("Which company does this Player work\n");
	gets(card.companyName);

	printf("Enter the designation of this Bid Card Player\n");
	gets(card.Designation);

	return card;
}

/**
 * User structure
 * for making new users
 **/
struct User
{
	int userID;					//user id for uniqueness for users
	char userName[20];			//username of the user
	struct BidCard BidCards[5];	//array of bidcards for every user
	int BidCardCount;			//count of total bidcards present out of 5
};

/**
 * createNewUser()
 * it will create new user
 * @param void
 * @return struct User
 **/
struct User createNewUser()
{
	struct User U;
	U.userID = USERID; 
	USERID++;

	getchar();
	printf("Enter your name\n");
	gets(U.userName);

	printf("Select number of players you want out of 5\n");
	scanf("%d",&U.BidCardCount);

	printf("Enter your Bid Players Data\n");
	for(register int j=0;j<U.BidCardCount;j++)
	{
		U.BidCards[j] = createBidCard();	
	}
	return U;
}

/**
 * playNewGame
 * this is the main game
 **/
void playNewGame()
{
	int numberOfUsers;
	printf("Enter the number of users you want to play ?\n");
	scanf("%d",&numberOfUsers);
	
	struct User gameArray[numberOfUsers];	//array of users in the game
	for(register int i=0;i<numberOfUsers;i++)
	{
		gameArray[i] = createNewUser();
		printf("User Created\n");
	}

	// displayBidCard(gameArray[0].BidCards[0]);
}