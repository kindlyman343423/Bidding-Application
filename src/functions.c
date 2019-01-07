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
 * @param char* => for color string
 * @return void
 * @tc - O(1)
 * @sc - O(1)
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
void greetOptions()
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
	printf("3. SETTINGS\n");
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
	char BidCardName[20];		//name of the person on bidcard
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
void displayBidCard(struct BidCard BC)
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
 * displaySkills()
 * it will display all skills
 * @param void
 * @return void
 * @tc - O(n)
 * @sc - O(1)
 **/
void displaySkills()
{
	colorSetting(BBLUE);
	line('*',25);
	for(register int i=0;i<10;i++)
	{
		if(i==8)
			printf("*\t%s\t*\n",SKILLS[i]);	
		else
			printf("*\t%s\t\t*\n",SKILLS[i]);
	}
	line('*',25);
	colorSetting(RESET);
}

/**
 * findSkills()
 * it will find specific skill in out table
 * @param skill
 * @return bool
 * @tc - O(n)
 * @sc - O(1)
 **/
bool findSkills(char* skill,int** points)
{
	int arr[10]={60,70,80,90,50,40,30,20,100,10};
	for(register int i=0;i<10;i++)
	{
		if(strcmp(SKILLS[i],skill)==0)
		{
			**points=**points + arr[i];
			return true;
		}
	}
	return false;
}

/**
 * checkValidSkills()
 * it will check whether it is caps or not
 * it will find whether it is in our skills tables or not
 * @param skills
 * @return bool
 * @tc - O(n^2)
 * @sc - O(1)
 **/
bool checkValidSkills(char* skills,int *pts)
{
	//check skill is valid or not
	int i=0;
	while(skills[i]!='\0')
	{
		if((skills[i]==',' || skills[i]=='+' || skills[i]=='\n')||(skills[i]>='A' && skills[i]<='Z'))
		{
			//		
		}
		else
		{
			return false;
		}
		i++;
	}
	//parsing
	i=0;
	int j=0;
	char str[10];
	while(skills[i]!='\0')
	{
		if(skills[i]==' ' || skills[i]=='\n' || skills[i]==',')
		{
			str[j]='\0';
			// printf("%s\n",str);
			if(!findSkills(str,&pts))
			{
				return false;
			}
			j=0;
		}
		else
		{
			str[j]=skills[i];
			j++;
		}
		i++;
	}
	return true;
}

/**
 * displayCompanies()
 * it will display all companies
 * @param void
 * @return void
 * @tc - O(n)
 * @sc - O(1)
 **/
void displayCompanies()
{
	colorSetting(BBLUE);
	line('*',25);
	for(register int i=0;i<10;i++)
	{
		if(i==5)
			printf("*\t%s\t*\n",COMPANIES[i]);	
		else
			printf("*\t%s\t\t*\n",COMPANIES[i]);
	}
	line('*',25);
	colorSetting(RESET);
}

/**
 * checkValidCompany()
 * it will check in company array if match find points will be calculated
 * @param char* => for company name
 * @param int* => for points calculation
 * @tc - O(n)
 * @sc - O(1)
 **/
bool checkValidCompany(char* company,int *points)
{
	int len = strlen(company);
	char comp[len-1];
	for(register int j=0;j<len-1;j++)
	{
		comp[j]=company[j];
	}
	
	int arr[10]={100,90,70,75,50,95,30,80,40,15};
	for(register int i=0;i<10;i++)
	{
		if(strcmp(COMPANIES[i],comp)==0)
		{
			*points=*points + arr[i];
			return true;
		}
	}
	return false;
} 

/**
 * displayDesignations()
 * it will display all designations
 * @param void
 * @return void
 * @tc - O(n)
 * @sc - O(1)
 **/
void displayDesignations()
{
	colorSetting(BBLUE);
	line('*',33);
	for(register int i=0;i<10;i++)
	{
		if(i==2)
			printf("*\t%s\t*\n",DESIGNATIONS[i]);
		else if(i==4 || i==7)
			printf("*\t%s\t\t*\n",DESIGNATIONS[i]);	
		else
			printf("*\t%s\t\t\t*\n",DESIGNATIONS[i]);
	}
	line('*',33);
	colorSetting(RESET);
}

/**
 * checkValidDesignations()
 * it will find designations is present or not in the table
 * @param char* => designation
 * @param int** => points
 * @return bool
 * @tc - O(n)
 * @sc - O(1)
 **/
bool checkValidDesignation(char* designation,int *points)
{
	int len = strlen(designation);
	char design[len-1];
	for(register int j=0;j<len-1;j++)
	{
		design[j]=designation[j];
	}

	int arr[10]={85,100,75,50,65,70,80,45,30,12};
	for(register int i=0;i<10;i++)
	{
		if(strcmp(DESIGNATIONS[i],design)==0)
		{
			*points=*points + arr[i];
			return true;
		}
	}
	return false;
}

/**
 * createBidCard()
 * it will create new bid card for a user
 * @param int => for displaying nthcard
 * @return struct BidCard
 * @tc - O(n^3)
 * @sc - O(1)
 **/
struct BidCard createBidCard(int nthCard)
{
	struct BidCard card;
	card.BidID=0;
	card.points=0;

	card.BidID = BIDCARDID;
	BIDCARDID++;
	
	colorSetting(DGREEN);
	printf("Enter the name of %d Bid Card Player\n",nthCard);
	colorSetting(RESET);
	fgets(card.BidCardName,20,stdin);

	colorSetting(DGREEN);
	printf("Enter the skills of %d Bid Card Player in format i.e C,C++\n",nthCard);
	colorSetting(RESET);
	displaySkills();
	fgets(card.skills,200,stdin);
	while(!checkValidSkills(card.skills,&card.points))
	{
		colorSetting(RED);
		printf("INVALID SKILL ENTER AGAIN\n");
		colorSetting(RESET);
		fgets(card.skills,200,stdin);
	}
	// printf("points:%d\n",card.points);

	colorSetting(DGREEN);
	printf("Which company does %d Player work\n",nthCard);
	colorSetting(RESET);
	displayCompanies();
	fgets(card.companyName,50,stdin);
	while(!checkValidCompany(card.companyName,&card.points))
	{
		colorSetting(RED);
		printf("INVALID COMPANY NAME ENTER AGAIN\n");
		colorSetting(RESET);
		fgets(card.companyName,50,stdin);
	}
	// printf("points:%d\n",card.points);

	colorSetting(DGREEN);
	printf("Enter the designation of %d Bid Card Player\n",nthCard);
	colorSetting(RESET);
	displayDesignations();
	fgets(card.Designation,20,stdin);
	while(!checkValidDesignation(card.Designation,&card.points))
	{
		colorSetting(RED);
		printf("INVALID DESIGNATION ENTER AGAIN\n");
		colorSetting(RESET);
		fgets(card.Designation,50,stdin);
	}
	// printf("points:%d\n",card.points);

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
	int scoredpoints;			//score of the user
};

/**
 * createNewUser()
 * it will create new user
 * @param void
 * @return struct User
 * @tc - O(n^4)
 * @sc - O(n)
 **/
struct User createNewUser()
{
	struct User U;
	U.BidCardCount=0;
	U.scoredpoints=0;
	U.userID=0;

	U.userID = USERID; 
	USERID++;

	// getchar();
	// while ( getchar() != '\n' );
	printf("$%d: Enter your name please\n",U.userID);
	fgets(U.userName,20,stdin);

	printf("$%d: Select number of Bid Cards you want out of 5\n",U.userID);
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

	printf("$%d: Enter %d Bid Cards Player Data\n",U.userID,U.BidCardCount);
	for(register int j=0;j<U.BidCardCount;j++)
	{
		U.BidCards[j] = createBidCard(j+1);

		//display card info for user
		
		printf("$%d: %sBID CARD NUMBER %d%s\n",U.userID,BLGREEN,j+1,RESET);
		displayBidCard(U.BidCards[j]);
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
	
	// getchar();
	while ( getchar() != '\n' );

	if(numberOfUsers<=0 || numberOfUsers>99)
	{
		printf("INVALID NUMBER OF USERS!!!\n");
		return;
	}

	/*DISPLAY GAME LOGO*/
	line('=',80);
	displayNumberOfPlayers(numberOfUsers);	//display the name of game
	displayPlayersGame(numberOfUsers);
	line('=',80);

	/*MAIN GAME*/
	struct User gameArray[numberOfUsers];	//array of users in the game
	
	for(register int i=0;i<numberOfUsers;i++)	//reseting the 0 values
	{
		gameArray[i].BidCardCount=0;
		gameArray[i].scoredpoints=0;
		gameArray[i].userID=0;	
	}
	
	for(register int i=0;i<numberOfUsers;i++)	//Entering values in gameArray
	{
		gameArray[i] = createNewUser();
		printf("User Created\n");
	}

	printf("LET US START THE GAME !!!\n\n");
	line('_',80);

	//for single player
	if(numberOfUsers==1)
	{
		
	}
	else
	{
		/*GAME ALGO*/
		/*************************************************************/
		int indextable[numberOfUsers];			//array of storing selected index by users
		while(true)
		{
			//scores
			for(register int i=0;i<numberOfUsers;i++)
			{
				printf("user %d = score:%d\n",i+1,gameArray[i].scoredpoints);
			}
			int max=-1;
			int maxindex=-1;
			//for one turn only
			for(register int i=0;i<numberOfUsers;i++)
			{
				//user gameArray[i]
				printf("USER %d TURN:\n",i+1);
				printf("Select the Bid card number out of %d\n",gameArray[i].BidCardCount);
				scanf("%d",&indextable[i]);
				while(indextable[i]<=0 || indextable[i]>gameArray[i].BidCardCount)
				{
					colorSetting(RED);
					printf("ENTER THE VALID BID CARD NUMBER\n");
					colorSetting(RESET);
					scanf("%d",&indextable[i]);
				}
				indextable[i]-=1;
				displayBidCard(gameArray[i].BidCards[indextable[i]]);
				int value = gameArray[i].BidCards[indextable[i]].points;	//get the card points of selected card
				printf("VALUE:%d\n",value);
				//calculations
				if(max<value)
				{
					max=value;
					maxindex=i;
				}
			}
			printf("check: %d %d\n",max,maxindex);
			gameArray[maxindex].scoredpoints+=10;
		}
	}
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
void displayNumberOfPlayers(int number)
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
	colorSetting(BYELLOW);

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
	colorSetting(RESET);
}

/**
 * displayPlayerGame()
 * it will display player game
 * @param char for os
 * @return void
 * @tc - O(1)
 * @sc - O(1)
 **/
void displayPlayersGame(int number)
{
	colorSetting(BBLUE);
	
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

	colorSetting(RESET);
}