#include "functions.h"
/*FUNCTIONS*/

/**
 * EXIT()
 * @param void
 * @return void
 * @tc - O(n)
 * @sc - O(1)
 **/
void EXIT()
{
	//freeing memory
	for(register int i=0;i<10;i++)
	{
		free(SKILLS[i]);
		free(COMPANIES[i]);
		free(DESIGNATIONS[i]);
	}
	free(SKILLS);
	free(COMPANIES);
	free(DESIGNATIONS);
	SKILLS=NULL;
	COMPANIES=NULL;
	DESIGNATIONS=NULL;
	exit(0);
}

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
 * @tc - O(n)
 * @sc - O(1)
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
 * @tc - O(n^4)
 * @sc - O(1)
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
	printf("4. HIGHSCORES\n");
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
			EXIT();
		case 1:
			playNewGame();							//start new game
			break;
		case 2:
			startSavedGame();						//start saved game
			break;
		case 3:
			settings();								//open settings
			break;
		case 4:
			highscores();							//show highscores
			break;
		default:
			while ( getchar() != '\n' );			//clears the buffer
			colorSetting(RED);
			printf("INVALID OPTION NUMBER\n");
			colorSetting(RESET);
	}
}

void startSavedGame()
{

}

void settings()
{

}

void highscores()
{

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
	char comp[len];
	for(register int j=0;j<len-1;j++)
	{
		comp[j]=company[j];
	}
	comp[len-1]='\0';

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
	design[len-1]='\0';
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
	printf("USER%d: Enter your name please\n",U.userID);
	fgets(U.userName,20,stdin);

	printf("USER%d: Select number of Bid Cards you want out of 5\n",U.userID);
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

	printf("USER%d: Enter %d Bid Cards Player Data\n",U.userID,U.BidCardCount);
	for(register int j=0;j<U.BidCardCount;j++)
	{
		U.BidCards[j] = createBidCard(j+1);

		//display card info for user
		
		printf("USER%d: %sBID CARD NUMBER %d%s\n",U.userID,BLGREEN,j+1,RESET);
		displayBidCard(U.BidCards[j]);
	}
	return U;
}

/**
 * playNewGame()
 * this is the main game
 * @param void
 * @return void
 * @tc - O(n^4)
 * @sc - O(1)
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

	//for single player
	if(numberOfUsers==1)
	{
		singleGame(gameArray,numberOfUsers);	
	}
	else
	{
		multipleGame(gameArray,numberOfUsers);
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


/**
 * singleGame()
 * @param struct User array
 * @param int => for numberOfUsers
 * @return void
 **/
void singleGame(struct User gameArray[],int numberOfUsers)
{
	/*DISPLAY GAME LOGO*/
	line('=',80);
	displayNumberOfPlayers(1);	//display the name of game
	displayPlayersGame(1);
	line('=',80);

	/*SINGLE GAME ALGO*/

	gameOptions(gameArray,numberOfUsers,0);	//calling game options
}

/**
 * multipleGame()
 * it has the main logic of multiple user game
 * @param struct User[] => gameArray 
 * @param int => for number of users
 * @return void
 * @tc => O(n^3)
 * @sc => O(1)
 **/
void multipleGame(struct User gameArray[],int numberOfUsers)
{
	/*DISPLAY GAME LOGO*/
	line('=',80);
	displayNumberOfPlayers(numberOfUsers);									//display number on the game
	displayPlayersGame(numberOfUsers);										//it will display the player game
	line('=',80);

	/*====================> MAIN GAME ALGO<================================*/
	int indextable[numberOfUsers];											//array of storing selected index by users
	int max=-1;																//for finding max value
	int maxindex=-1;														//for finding max index
	
	for(register int i=0;i<numberOfUsers;i++)								//calculating index table values and max values for win
	{
		printf("USER %d TURN:\n",i+1);
		printf("Select the Bid card number out of %d\n",gameArray[i].BidCardCount);
		scanf("%d",&indextable[i]);
		while(indextable[i]<=0 || indextable[i]>gameArray[i].BidCardCount)	//this loop is for handling wrong input
		{
			colorSetting(RED);												//for displaying red color on linux
			printf("ENTER THE VALID BID CARD NUMBER\n");
			colorSetting(RESET);											//for displaying reset color on linux
			scanf("%d",&indextable[i]);
		}
		indextable[i]-=1;													//decrease by one for array index
		displayBidCard(gameArray[i].BidCards[indextable[i]]);				//display the selected bidcard to user
		int value = gameArray[i].BidCards[indextable[i]].points;			//get the card points of selected card
		
		printf("VALUE:%d\n",value);
		if(max<value)														//for calculating max value and max index
		{
			max=value;
			maxindex=i;
		}
	}

	printf("check: %d %d\n",max,maxindex);
	
	/*calculating the points*/
	gameArray[maxindex].scoredpoints+=10;									//add 10 points to the winner
	for(register int i=0;i<numberOfUsers;i++)								//decrease every other points by 1 for losing
	{
		if(i!=maxindex)														//for not decreasing the points of winner
			gameArray[i].scoredpoints-=1;
	}

	for(register int i=0;i<numberOfUsers;i++)								//displaying the scores to the user
	{
		printf("user %d = score:%d\n",i+1,gameArray[i].scoredpoints);
	}

	gameOptions(gameArray,numberOfUsers,1);
}

/**
 * gameOptions()
 * it will show game options after every one game
 **/
void gameOptions(struct User gameArray[],int numberOfUsers,int option)
{
	/*GAME OPTIONS FOR WHAT TO DO AFTER ONE BID GAME*/
	printf("Select one option:\n");
	printf("============================\n");
	printf("0. QUIT\n");
	printf("----------------------------\n");
	printf("1. CONTINUE\n");												//if the user want to continue game
	printf("----------------------------\n");
	printf("2. SAVE AND CONTINUE\n");										//it will first save the game and then continue it
	printf("----------------------------\n");
	printf("3. SAVE AND QUIT\n");											//it will save and quit the game
	printf("============================\n");
	int a;
	scanf("%d",&a);
	//clear buffer stdin
	while ( getchar() != '\n' );
	switch(a)
	{
		case 0:
			return;
		case 1:
			updateInfo(gameArray,numberOfUsers);							//first update info
			if(option==0)
				singleGame(gameArray,numberOfUsers);						//called single user game
			else
				multipleGame(gameArray,numberOfUsers);						//called multiple user game
			break;
		case 2:
			save();															//save game first
			updateInfo(gameArray,numberOfUsers);							//then call update info
			if(option==0)
				singleGame(gameArray,numberOfUsers);						//called single user game
			else
				multipleGame(gameArray,numberOfUsers);						//called multiple user game
			break;
		case 3:
			save();															//save the game and returning
			return;
	}
}

/**
 * updateInfo()
 * it will the update the user info
 * @param struct user array
 * @param int => for number of users
 * @return void
 **/
void updateInfo(struct User gameArray[],int numberOfUsers)
{
	for(register int i=0;i<numberOfUsers;i++)
	{
		printf("USER %d Do you want to update info Y/N\n",i+1);
		char ch = getchar();
		getchar();											//for \n char
		while(ch=='Y')										//update options
		{
			printf("Which info you want to update\n");
			printf("----------------------------\n");
			printf("0. NO CHANGE\n");
			printf("----------------------------\n");
			printf("1. DISPLAY ALL CARDS\n");
			printf("----------------------------\n");
			printf("2. ADD NEW CARD\n");
			printf("----------------------------\n");
			printf("3. UPDATE CARD INFO\n");
			printf("----------------------------\n");
			printf("4. DELETE CARD\n");
			printf("----------------------------\n");
			int a;
			scanf("%d",&a);
			getchar();
			switch(a)
			{
				case 0:
					break;													//no change
				case 1:
					for(register int j=0;j<gameArray[i].BidCardCount;j++)	//displaying all the cards
					{
						displayBidCard(gameArray[i].BidCards[j]);
					}
					break;
				case 2:
					if(gameArray[i].BidCardCount<5)
					{
						printf("Adding new card......\n\n"); 
						int index = gameArray[i].BidCardCount;
						gameArray[i].BidCardCount++;
						gameArray[i].BidCards[index] = createBidCard(gameArray[i].BidCardCount);
						displayBidCard(gameArray[i].BidCards[index]);	
					}
					else
					{
						colorSetting(RED);
						printf("SORRY CAPACITY FULL\n");
						colorSetting(RESET);
					}
					break;
				case 3:
					printf("update card info\n");
					printf("Which card you want to update currently you have %d\n",gameArray[i].BidCardCount);
					int index;
					scanf("%d",&index);
					while(index<=0 || index>gameArray[i].BidCardCount)			//for wrong input for updating
					{
						colorSetting(RED);
						printf("WRONG INPUT ENTER AGAIN\n");
						colorSetting(RESET);
						scanf("%d",&index);
					}
					
					printf("Select one option\n");
					printf("Which one option you want to update\n");
					printf("...........................\n");
					printf("0. No Change\n");
					printf("...........................\n");
					printf("1. Update Bid Card Name\n");
					printf("...........................\n");
					printf("2. Update Skills\n");
					printf("...........................\n");
					printf("3. Update Company Name\n");
					printf("...........................\n");
					printf("4. Update Designation\n");
					printf("...........................\n");
					printf("%d\n",index);
					int option;
					scanf("%d",&option);
					while(option<0 || option>4)
					{
						colorSetting(RED);
						printf("WRONG OPTION SELECTION\n");
						colorSetting(RESET);
						scanf("%d",&option);
					}
					//clear buffer
					while(getchar()!='\n');
					switch(option)
					{
						case 0:								//no change
							break;
						case 1:
							//update card name
							colorSetting(DGREEN);
							printf("Enter the name of %d Bid Card Player\n",i+1);
							colorSetting(RESET);
							fgets(gameArray[i].BidCards[index-1].BidCardName,20,stdin);
							break;
						case 2:
							//update skills
							colorSetting(DGREEN);
							printf("Enter the skills of %d Bid Card Player in format i.e C,C++\n",i+1);
							colorSetting(RESET);
							displaySkills();
							fgets(gameArray[i].BidCards[index-1].skills,200,stdin);
							while(!checkValidSkills(gameArray[i].BidCards[index-1].skills,&gameArray[i].BidCards[index-1].points))
							{
								colorSetting(RED);
								printf("INVALID SKILL ENTER AGAIN\n");
								colorSetting(RESET);
								fgets(gameArray[i].BidCards[index-1].skills,200,stdin);
							}
							break;
						case 3:
							//update company name
							colorSetting(DGREEN);
							printf("Which company does %d Player work\n",i+1);
							colorSetting(RESET);
							displayCompanies();
							fgets(gameArray[i].BidCards[index-1].companyName,50,stdin);
							while(!checkValidCompany(gameArray[i].BidCards[index-1].companyName,&gameArray[i].BidCards[index-1].points))
							{
								colorSetting(RED);
								printf("INVALID COMPANY NAME ENTER AGAIN\n");
								colorSetting(RESET);
								fgets(gameArray[i].BidCards[index-1].companyName,50,stdin);
							}
							break;
						case 4:
							//update designation
							colorSetting(DGREEN);
							printf("Enter the designation of %d Bid Card Player\n",i+1);
							colorSetting(RESET);
							displayDesignations();
							fgets(gameArray[i].BidCards[index-1].Designation,20,stdin);
							while(!checkValidDesignation(gameArray[i].BidCards[index-1].Designation,&gameArray[i].BidCards[index-1].points))
							{
								colorSetting(RED);
								printf("INVALID DESIGNATION ENTER AGAIN\n");
								colorSetting(RESET);
								fgets(gameArray[i].BidCards[index-1].Designation,50,stdin);
							}
							break;
					}
					break;
				case 4:
					printf("delete card info\n");
					if(gameArray[i].BidCardCount<0)
					{
						colorSetting(RED);
						printf("SORRY ZERO CAPACITY\n");
						colorSetting(RESET);
					}
					else
					{
						int in;
						printf("Which card you want to delete out of %d\n",gameArray[i].BidCardCount);
						scanf("%d",&in);
						while(in<0 || in>gameArray[i].BidCardCount)
						{
							colorSetting(RED);
							printf("SOORY WRONG CARD NUMBER\n");
							colorSetting(RESET);
							scanf("%d",&in);
						}
						//clear buffer
						while(getchar()!='\n');
						printf("WE ARE DELETING THIS CARD\n");
						displayBidCard(gameArray[i].BidCards[in-1]);
						printf("ARE YOU SURE !!! Y/N");
						char ans = getchar();
						if(ans=='Y')
						{
							//delete the card
						}
						else
						{
							printf("Its OK\n");
						}
					}
					//clear buffer
					while(getchar()!='\n');
					break;
			}
			printf("USER %d Do you want to update more info Y/N\n",i+1);
			ch = getchar();getchar();										//extra getchar for reading \n
		}
		printf("done with user\n");
	}
}



/*================================> DATABASE FUNCTIONS <=======================*/
void save()
{

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