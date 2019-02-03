/*contains all declarations*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h> 
#include <time.h>
#include <stdbool.h>
#include "../RAINBOW-0.1/src/C/rainbow.h"
#define USERS 500   //max users in application formed

int BIDCARDID=1;        //default setting bid ids
int USERID = 1;         //default setting user ids
char OS='w';            //environment variable for os
char **SKILLS;          //env variable for SKILLS array
char **COMPANIES;       //env variable for COMPANIES array
char **DESIGNATIONS;    //env variable for DESIGNATIONS array

void EXIT();
/*STRUCTURES NEEDED FOR THE GAME*/
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

/*GREET FUNCTIONS*/
void line(char,int);
void welcome();
void greetOptions();

/*GREET OPTION FUNCTIONS*/

void playNewGame();
void startSavedGame();
void settings();

/*SAVED GAME FUNCTIONS*/

char* readSavedGames();

/*UPDATE FUNCTIONS*/
void updateInfo(struct User*,int);

void displayNumberOfPlayers(int);
void displayPlayersGame(int);
void colorSetting(char*);

/*BID CARD FUNCTIONS*/
void displayBidCard(struct BidCard);
struct BidCard getBidCardName(struct BidCard,int);
struct BidCard getBidCardSkills(struct BidCard,int);
struct BidCard getBidCardCompanyName(struct BidCard,int);
struct BidCard getBidCardDesignation(struct BidCard,int);
struct BidCard createBidCard(int);

/*SKILL FUNCTIONS*/
void displaySkills();
bool findSkills(char*,int**,char);
bool checkValidSkills(char*,int*,char);

/*COMPANIES FUNCTIONS*/
void displayCompanies();
bool checkValidCompany(char*,int*,char);

/*DESIGNATION FUNCTIONS*/
void displayDesignations();
bool checkValidDesignation(char*,int*,char);

/*GAME FUNCTION*/
void singleGame(struct User*,int);
void multipleGame(struct User*,int);
void gameOptions(struct User*,int,int);

/*USER FUNCTIONS*/
struct User createNewUser();

//DATABASE FUNCTIONS
bool searchDB(char*);
void list();
void save(struct User*,int);
void readDBIndex();