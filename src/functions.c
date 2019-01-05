#include "functions.h"
/*FUNCTIONS*/

/**
 * line()
 * prints the line
 * @param char for print char
 * @param int for printing upto count
 * @return void
 * @tc - O(n)
 * @sc - O(1)
 **/
void line(char ch,int count)
{
	for(register int k=0;k<count;k++)
	{
		printf("%c",ch);
	}
	printf("\n");
}

/**
 * list()
 * lists the files present in current directory
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
 * colorSetting()
 * this function sets color on stdout for LINUX ONLY
 **/
void colorSetting(char* str)
{
	if(OS=='l')
		printf("%s",str);
}

/**
 * welcome()
 * for greeting the user
 * @param char LINUX/MAC-l WINDOWS-w
 * @tc O(n)
 * @sc O(1)
 **/
void welcome()
{
	colorSetting(BLUE);
	line('=',75);
	colorSetting(RESET);

	colorSetting(BWHITE);
	printf("\t  ---- 	-----	---           /\\    	---- 	---- \n");
	printf("\t  |   |	  |  	|  \\         /  \\  	|   |	|   |\n");
	printf("\t  |--- 	  |  	|  |  ===   /====\\  	|--- 	|--- \n");
	printf("\t  |   |	  |  	|  /       /      \\ 	|    	|    \n");
	printf("\t  ---- 	-----	---       /        \\	|    	|    \n");
	colorSetting(RESET);

	if(OS=='l')
	{
		printf("\t\t\t\t\t\t\t\t%sVERSION 0.1%s\n",BLGREEN,RESET);
		printf("\t\t\t\t\t\t     %sPowered by RAINBOW 0.1%s\n",YELLOW,RESET);
		colorSetting(BLUE);
	}
	else
	{
		printf("\t\t\t\t\t\t\t\tVERSION 0.1\n");
	}

	line('=',75);
	colorSetting(RESET);
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
void greetOptions(char os)
{
	printf("Welcome to our GAME\n\n");
	
	colorSetting(BOLD);
	printf("Enter below option to start\n");
	colorSetting(RESET);

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
	
	colorSetting(BOLD);
	printf("OPTION: ");
	int q;
	scanf("%d",&q);
	colorSetting(RESET);

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
			colorSetting(RED);
			printf("INVALID OPTION NUMBER\n");
			colorSetting(RESET);
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
	int points;					//points of card
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
	colorSetting(BCYAN);
	line('-',75);
	colorSetting(RESET);
	
	colorSetting(BCYAN);
	printf("* Name: ");
	colorSetting(RESET);
	printf("%s",BC.BidCardName);
	
	colorSetting(BCYAN);
	printf("* Skills: ");
	colorSetting(RESET);
	printf("%s",BC.skills);
	
	colorSetting(BCYAN);
	printf("* Work-Place: ");
	colorSetting(RESET);
	printf("%s",BC.companyName);
	
	colorSetting(BCYAN);
	printf("* Designation: ");
	colorSetting(RESET);
	printf("%s",BC.Designation);

	colorSetting(BCYAN);
	line('-',75);
	colorSetting(RESET);
}

/**
 * createBidCard()
 * it will create new bid card for a user
 * @param int => for displaying nthcard
 * @return struct BidCard
 * @tc - O(1)
 * @sc - O(1)
 **/
struct BidCard createBidCard(int nthCard)
{
	struct BidCard card;
	
	card.BidID = BIDCARDID;
	BIDCARDID++;
	
	printf("Enter the name of %d Bid Card Player\n",nthCard);
	fgets(card.BidCardName,20,stdin);

	printf("Enter the skills of %d Bid Card Player separated with commas(,)\n",nthCard);
	// printf("Choose from this list:\n");
	// printf("* C\n");
	// printf("* C++\n");
	// printf("* JAVA\n");
	// printf("* PYTHON\n");
	// printf("* PERL\n");
	// printf("* RUBY\n");
	// printf("* HTML\n");
	// printf("* CSS\n");
	// printf("* JAVASCRIPT\n");
	// printf("* C#\n");
	fgets(card.skills,200,stdin);

	printf("Which company does %d Player work\n",nthCard);
	fgets(card.companyName,50,stdin);

	printf("Enter the designation of %d Bid Card Player\n",nthCard);
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
	int BidCardCount;			//count of total bidcards present out of 5
	struct BidCard BidCards[5];	//array of bidcards for every user
};

/**
 * createNewUser()
 * it will create new user
 * @param void
 * @return struct User
 * @tc - O(n)
 * @sc - O(n)
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
	
	//clear buffer stdin
	while ( getchar() != '\n' );
	
	if(U.BidCardCount<=0 || U.BidCardCount>5)
	{
		colorSetting(RED);
		printf("INVALID NUMBER OF BIDCARDS, So it is set to 1\n");
		colorSetting(RESET);
		U.BidCardCount=1;
	}

	printf("Enter %d Bid Cards Player Data\n",U.BidCardCount);
	for(register int j=0;j<U.BidCardCount;j++)
	{
		U.BidCards[j] = createBidCard(j+1);

		//display card info for user
		printf("%sCARD PLAYER %d%s\n",BLGREEN,j+1,RESET);
		displayBidCard(U.BidCards[j],'l');
	}
	return U;
}

/**
 * playNewGame()
 * this is the main game
 **/
void playNewGame()
{
	int numberOfUsers;
	printf("Enter the number of users you want to play ?\n");
	scanf("%d",&numberOfUsers);

	if(numberOfUsers<=0 || numberOfUsers>99)
	{
		printf("INVALID NUMBER OF USERS!!!\n");
		return;
	}

	/*DISPLAY GAME LOGO*/
	line('=',80);
	displayNumberOfPlayers(numberOfUsers,'l');	//display the name of game
	displayPlayersGame(numberOfUsers,'l');
	line('=',80);

	/*MAIN GAME*/
	struct User gameArray[numberOfUsers];	//array of users in the game
	for(register int i=0;i<numberOfUsers;i++)
	{
		gameArray[i] = createNewUser();
		printf("User Created\n");
	}

	/*GAME ALGO*/
}

/**
 * displayNumberOfPlayers()
 * it will display the number played users on the game
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
	
	char str[3];					//string for converting
	snprintf(str,3,"%d",number);	//converting int to string

	//FOR LINUX/MAC ONLY
	if(os=='l')
	{
		printf("%s",BYELLOW);
	}

	for(register int i=0;i<5;i++)	//loop for lines
	{
		printf("\t\t\t\t");
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

/**
 * displayPlayerGame()
 * it will display player game
 * @param char for os
 * @return void
 * @tc - O(1)
 * @sc - O(1)
 **/
void displayPlayersGame(int number,char os)
{
	if(os=='l')
	{
		printf("%s",BBLUE);
	}
	
	printf("\n");
	if(number==1)
	{
		printf("\t\t====  |         /\\     \\   /  |==== |===  \n");
		printf("\t\t|   | |        /  \\     \\ /   |     |   |  \n");
		printf("\t\t|===  |       /====\\     Y    |==== |===  \n");
		printf("\t\t|     |      /      \\    |    |     | \\	\n");
		printf("\t\t|     ===== /        \\   |    |==== |  \\	\n");
	}
	else
	{
		printf("\t\t====  |         /\\     \\   /  |==== |===    ====\n");
		printf("\t\t|   | |        /  \\     \\ /   |     |   |  |      \n");
		printf("\t\t|===  |       /====\\     Y    |==== |===    ===\n");
		printf("\t\t|     |      /      \\    |    |     | \\        | \n");
		printf("\t\t|     ===== /        \\   |    |==== |  \\   ==== \n");
	}
	printf("\n");

	printf("\t\t     +====      /\\     |\\   /| =====\n");
	printf("\t\t     |         /  \\    | \\ / | |\n");
	printf("\t\t     | ==+    /====\\   |  Y  | |====\n");
	printf("\t\t     |   |   /      \\  |     | |\n");
	printf("\t\t     +===+  /        \\ |     | =====\n");	

	if(os=='l')
	{
		printf("%s",RESET);
	}
}