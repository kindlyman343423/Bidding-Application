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
 * @tc O(n)
 * @sc O(1)
 **/
void welcome(char os)
{
	//FOR LINUX/MAC USER ONLY
	if(os=='l')
	{
		printf("%s",BLUE);
	}
	
	for(register int i=0;i<75;i++)
	{
		printf("=");
	}

	//FOR LINUX/MAC USER ONLY
	if(os=='l')
	{
		printf("%s",RESET);
	}
	printf("\n");

	//FOR LINUX/MAC USER ONLY
	if(os=='l')
	{
		printf("%s",BWHITE);
	}

	printf("\t  ---- 	-----	---           /\\    	---- 	---- \n");
	printf("\t  |   |	  |  	|  \\         /  \\  	|   |	|   |\n");
	printf("\t  |--- 	  |  	|  |  ===   /====\\  	|--- 	|--- \n");
	printf("\t  |   |	  |  	|  /       /      \\ 	|    	|    \n");
	printf("\t  ---- 	-----	---       /        \\	|    	|    \n");
	
	//FOR LINUX/MAC USER ONLY
	if(os=='l')
	{
		printf("%s",RESET);
		printf("\t\t\t\t\t\t\t\t%sVERSION 0.1%s\n",BLGREEN,RESET);
		printf("\t\t\t\t\t\t     %sPowered by RAINBOW 0.1%s\n",YELLOW,RESET);
		printf("%s",BLUE);
	}
	else
	{
		printf("\t\t\t\t\t\t\t\tVERSION 0.1\n");
	}
	for(register int i=0;i<75;i++)
	{
		printf("=");
	}

	//FOR LINUX/MAC USER ONLY
	if(os=='l')
	{
		printf("%s",RESET);
	}
	printf("\n");
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
 * @param char for operating system linux/mac-l windows-w
 * @return void
 * @tc - O(n)
 * @sc - O(1)
 **/
void displayBidCard(struct BidCard BC,char os)
{
	//FOR LINUX/MAC USER ONLY
	if(os=='l')
	{
		printf("%s",BCYAN);
	}
	for(register int i=0;i<75;i++)
	{
		printf("-");
	}

	//FOR LINUX/MAC USER ONLY
	if(os=='l')
	{
		printf("%s",RESET);
	}
	printf("\n");
	
	//FOR LINUX/MAC USER ONLY
	if(os=='l')
	{
		printf("%s* Name:%s ",BCYAN,RESET);
	}
	else
	{
		printf("* Name: ");
	}
	printf("%s",BC.BidCardName);
	
	//FOR LINUX/MAC USER ONLY
	if(os=='l')
	{
		printf("%s* Skills:%s ",BCYAN,RESET);
	}
	else
	{
		printf("* Skills: ");
	}
	printf("%s",BC.skills);
	
	//FOR LINUX/MAC USER ONLY
	if(os=='l')
	{
		printf("%s* Work-Place:%s ",BCYAN,RESET);
	}
	else
	{
		printf("* Work-Place: ");
	}
	printf("%s",BC.companyName);
	
	//FOR LINUX/MAC USER ONLY
	if(os=='l')
	{
		printf("%s* Designation:%s ",BCYAN,RESET);
	}
	else
	{
		printf("* Designation: ");
	}
	printf("%s",BC.Designation);
	
	//FOR LINUX/MAC USER ONLY
	if(os=='l')
	{
		printf("%s",BCYAN);
	}
	for(register int i=0;i<75;i++)
	{
		printf("-");
	}

	//FOR LINUX/MAC USER ONLY
	if(os=='l')
	{
		printf("%s",RESET);
	}
	printf("\n");
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
	fgets(card.BidCardName,20,stdin);

	printf("Enter the skills of the Bid Card Player\n");
	fgets(card.skills,200,stdin);

	printf("Which company does this Player work\n");
	fgets(card.companyName,50,stdin);

	printf("Enter the designation of this Bid Card Player\n");
	fgets(card.Designation,20,stdin);

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
	fgets(U.userName,20,stdin);

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
	
	displayNumberOfPlayers(numberOfUsers,'l');	//display the name of game
	
	exit(0);
	struct User gameArray[numberOfUsers];	//array of users in the game
	for(register int i=0;i<numberOfUsers;i++)
	{
		gameArray[i] = createNewUser();
		printf("User Created\n");
	}

	// displayBidCard(gameArray[0].BidCards[0],'l');
	// exit(0);
}

/**
 * displayNumberOfPlayers()
 * it will display the number on the game
 * @param int
 * @param char for operating system l-linux/mac w-windows
 * @return void
 * @tc - O(n^3)
 * @sc - O(1)
 **/
void displayNumberOfPlayers(int number,char os)
{
	char arr0[5][5] = {
						{ '+' , '=' , '=' , '=' , '+' },
						{ '|' , ' ' , ' ' , ' ' , '|' },
						{ '|' , ' ' , ' ' , ' ' , '|' },
						{ '|' , ' ' , ' ' , ' ' , '|' },
						{ '+' , '=' , '=' , '=' , '+' }
						};
	char arr1[5][5] = {
						{ ' ' , '/' , '|' , ' ' , ' ' },
						{ '/' , ' ' , '|' , ' ' , ' ' },
						{ ' ' , ' ' , '|' , ' ' , ' ' },
						{ ' ' , ' ' , '|' , ' ' , ' ' },
						{ '=' , '=' , '=' , '=' , '=' },
						};
	char arr2[5][5] = {
						{ ' ' , '=' , '=' , '=' , ' ' },
						{ '|' , ' ' , ' ' , ' ' , '|' },
						{ ' ' , ' ' , ' ' , '/' , ' ' },
						{ ' ' , ' ' , '/' , ' ' , ' ' },
						{ ' ' , '=' , '=' , '=' , '=' }
						};
	char arr3[5][5] = {
						{ '=' , '=' , '=' , '=' , '/' },
						{ ' ' , ' ' , ' ' , '/' , ' ' },
						{ ' ' , ' ' , '/' , '=' , '+' },
						{ ' ' , ' ' , ' ' , ' ' , '|' },
						{ '=' , '=' , '=' , '=' , '+' }
						};
	char arr4[5][5] = {
						{ ' ' , ' ' , '/' , '|' , ' ' },
						{ ' ' , '/' , ' ' , '|' , ' ' },
						{ '/' , '=' , '=' , '+' , '=' },
						{ ' ' , ' ' , ' ' , '|' , ' ' },
						{ ' ' , ' ' , ' ' , '|' , ' ' }
						};
	char arr5[5][5] = {
						{ '=' , '=' , '=' , '=' , '=' },
						{ '|' , ' ' , ' ' , ' ' , ' ' },
						{ '=' , '=' , '=' , '=' , ' ' },
						{ ' ' , ' ' , ' ' , ' ' , '|' },
						{ '=' , '=' , '=' , '=' , ' ' }
						};
	char arr6[5][5] = {
						{ ' ' , '=' , '=' , '=' , '|' },
						{ '|' , ' ' , ' ' , ' ' , ' ' },
						{ '|' , '=' , '=' , '=' , ' ' },
						{ '|' , ' ' , ' ' , ' ' , '|' },
						{ ' ' , '=' , '=' , '=' , ' ' }
						};
	char arr7[5][5] = {
						{ '=' , '=' , '=' , '=' , '=' },
						{ ' ' , ' ' , ' ' , ' ' , '/' },
						{ ' ' , ' ' , ' ' , '/' , ' ' },
						{ ' ' , ' ' , '/' , ' ' , ' ' },
						{ ' ' , '/' , ' ' , ' ' , ' ' }
						};
	char arr8[5][5] = {
						{ ' ' , '=' , '=' , '=' , ' ' },
						{ '|' , ' ' , ' ' , ' ' , '|' },
						{ ' ' , '=' , '=' , '=' , ' ' },
						{ '|' , ' ' , ' ' , ' ' , '|' },
						{ ' ' , '=' , '=' , '=' , ' ' }
						};
	char arr9[5][5] = {
						{ ' ' , '=' , '=' , '=' , ' ' },
						{ '|' , ' ' , ' ' , ' ' , '|' },
						{ ' ' , '=' , '=' , '=' , '+' },
						{ ' ' , ' ' , ' ' , ' ' , '|' },
						{ ' ' , '=' , '=' , '=' , ' ' }
						};
	if(number<=0)
	{
		exit(0);
	}
	char str[5];
	snprintf(str,5,"%d",number);	//converting int to string
	// printf("%s\n",str);

	if(os=='l')
	{
		printf("%s",BYELLOW);
	}

	for(register int i=0;i<5;i++)	//loop for lines
	{
		for(register int j=0;j<strlen(str);j++)
		{
			int a = str[j]-'0';
			//printing j row of arrj
			switch(a)
			{
				case 0:
					for(register int k=0;k<5;k++)
					{
						printf("%c",arr0[i][k]);
					}
					break;
				case 1:
					for(register int k=0;k<5;k++)
					{
						printf("%c",arr1[i][k]);
					}
					break;
				case 2:
					for(register int k=0;k<5;k++)
					{
						printf("%c",arr2[i][k]);
					}
					break;
				case 3:
					for(register int k=0;k<5;k++)
					{
						printf("%c",arr3[i][k]);
					}
					break;
				case 4:
					for(register int k=0;k<5;k++)
					{
						printf("%c",arr4[i][k]);
					}
					break;
				case 5:
					for(register int k=0;k<5;k++)
					{
						printf("%c",arr5[i][k]);
					}
					break;
				case 6:
					for(register int k=0;k<5;k++)
					{
						printf("%c",arr6[i][k]);
					}
					break;
				case 7:
					for(register int k=0;k<5;k++)
					{
						printf("%c",arr7[i][k]);
					}
					break;
				case 8:
					for(register int k=0;k<5;k++)
					{
						printf("%c",arr8[i][k]);
					}
					break;
				case 9:
					for(register int k=0;k<5;k++)
					{
						printf("%c",arr9[i][k]);
					}
					break;
			}
			printf(" ");
		}
		printf("\n");
	}
	if(os=='l')
	{
		printf("%s",RESET);
	}
}