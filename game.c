//this is main program which is a game
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h> 
#include "functions.c"
#include <time.h>
/*
n-no.of members
*/
int main()
{	
	int n,m;   //number of users
	int count=0;
	int bid=0;
	int bidding[count]; //NEEDED ARRAY FOR BIDS
	char q='N'; //FIRST QUESTION
	register int i,j;
	//int count1=0,count2=0,count3=0;    //no. of bid done
	char find[20];
	char data[20];
	int f=0; //f for checking a database file
	int flag=0;
	time_t raw;
  	struct tm * timeinfo;
	FILE *logptr; //POINTER FOR LOG FILE
	FILE *db;   //POINTER FOR DATABASE FILE
	//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$//
	
	printf("Do you want to add members in database(Y/N)\n");
	scanf("%c",&q);
	if(q=='Y')
	{
		printf("Enter the number of users\n");
		scanf("%d",&n);
		//n count array
		char arr[n][20];
		logptr = fopen("log.txt","a");   //OPENED LOG FILE
		db = fopen("database.txt","a+");  //OPENED DATABASE FILE FOR READING AND APPENDING 
		fprintf(logptr,"Members entered in DATABASE:\n");
		for(i=0;i<n;i++)
		{
			printf("Enter the names of the members\n");
			scanf("%s",arr[i]); //gets(arr[i]);
			//ADDING DATE AND TIME
			time (&raw);
	  		timeinfo = localtime (&raw);
			fprintf(logptr,"%s\t\t%s",arr[i],asctime(timeinfo));  //ADD DATA IN LOG FILE
			//CHECK DATA IN DATABASE FILE THEN ADD #######################
			for(j=0;j<20;j++)
			{
				//READING DATA FROM A DATABASE FILE
				fscanf(db,"%s",data);
				if(strcmp(data,arr[i])==0)
				{
					//DO NOTHING
					f=1;
					break;
				}
				else
				{
					f=0;
				}
			}
			if(f==0) //IF 0 THEN ADD DATA
			{
				fprintf(db,"%s\n",arr[i]);  //ADD DATA IN DATABASE	FILE
			}
			else if(f==1)
			{
				printf("THE USER IS ALREADY PRESENT\n");
			}
		}
		fprintf(logptr,"\n");
		fclose(logptr);  //CLOSING LOG FILE
		fclose(db);	 //CLOSING DATABASE FILE
		line();
	}
	//CHECKING DATA WITH THE NAME ARRAY
	printf("ENTER YOUR NAME TO START ENTERING DATA\n");
	scanf("%s",find);
	db = fopen("database.txt","r");  //OPENED FILE FOR READING
	
	for(j=0;j<20;j++)
	{
		//READING DATA FROM DATABASE FILE
		fscanf(db,"%s",data);
		//printf("%s\n",data);
		q =fgetc(db); 
		if(q == EOF)
		{
			break;
		}
		if(strcmp(data,find)==0)
		{
			flag=1;
			//USER VERIFIED
			break;	
		}
		else
		{
			flag=0;
			//NOT VERIFIED	
		}
	}
	fclose(db);
	/////////////////////////////////////THE DATA ENTRY////////////////////////////////////////////
	if(flag==1)
	{
		printf("User Verified\n");
		printf("Lets get started\n");
		line();
		
		while(1)
		{
			//###################################STARTING THE GAME HERE###################################
			//BIDING SYSTEM
			printf("THE GAME STARTS HERE!!!!!!\n");
			count=0;
			db = fopen("database.txt","r");  //OPENED FILE FOR COUNTING
			for(j=0;j<10;j++)
			{
				//READING DATA FROM DATABASE FILE
				fscanf(db,"%s",data);
				count++;
				q =fgetc(db);
				if(q == EOF)
				{
					break;
				}
			}
			fclose(db);
			count=count-1; //COUNT THE NUMBER OF USERS IN THE DATABASE FILE
			
			db = fopen("database.txt","r");
			char naming[count][20]; //STORING NAMES OF DATABASE 
			for(j=0;j<count;j++)
			{
				//STORING NAMES IN AN ARRAY
				fscanf(db,"%s",naming[j]);
			}
			fclose(db);
	
			for(j=0;j<count;)
			{
				printf("Enter the bid %s\n",naming[j]);
				scanf("%d",&bid);
				bidding[j]=bid;
				j=j+1;
			}
			
			//VALUES TAKEN IN ARRAY
			//################################################################################### ERRORS HERE// 
			//ARRAY COMPUTATION
			//FINDING MAX VALUE
			n=bidding[0];
			for(j=0;j<count;j++)
			{
				if(n<bidding[j])
				{
					//swapping values
					int temp;
					temp = bidding[j];
					bidding[j] = n;
					n = temp;
					m=j; 
				}
			}
			//n-max,m-index
			strcpy(naming[m],find);
			printf("%d %d %s\n\n",n,m,find);
			//find = naming[m];
			//OPENING A FIND FILE
			//FILE *ptr; //ALL POINTER
		   //ptr = fopen(find,"a");	
		   //fclose(ptr);
			//CHECKING DATABASE
			for(j=0;j<count;j++)
			{
				printf(" %s %d \n",naming[j],bidding[j]);
			}	
		}
	}
	else
	{
		printf("User Not verified\n");
		line();
		printf("SRRY U CANNOT PLAY THE GAME\n\n");
	}
	return 0;
}
