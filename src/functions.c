#include "functions.h"
struct detail			//structure for detailed user
{
	char name[20];
	char skills[100];
	int id;
};

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

}

/**
 * welcomeWIND()
 * colored UI for windows
 **/
void welcomeWIND()
{
	
}