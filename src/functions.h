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
#define USERS 100

static int BIDCARDID=1; //for setting bid ids
static int USERID = 1;  //for setting user ids
char OS='w';           //environment variable for os
char **SKILLS;
char **COMPANIES;
char **DESIGNATIONS;

/*STRUCTURES NEEDED FOR THE GAME*/
struct BidCard;
struct User;

/*GREET FUNCTIONS*/
void line(char,int);
void list();
void welcome();
void greetOptions();

/*OPTION FUNCTIONS*/
void playNewGame();
// void startSavedGame();
// void settings();

void save();

/*UPDATE FUNCTIONS*/
void updateInfo(struct User*,int);

void displayNumberOfPlayers(int);
void displayPlayersGame(int);
void colorSetting(char*);

/*BID CARD FUNCTIONS*/
void displayBidCard(struct BidCard);
struct BidCard createBidCard(int);

/*SKILL FUNCTIONS*/
void displaySkills();
bool findSkills(char*,int**);
bool checkValidSkills(char*,int*);

/*COMPANIES FUNCTIONS*/
void displayCompanies();
bool checkValidCompany(char*,int*);

/*DESIGNATION FUNCTIONS*/
void displayDesignations();
bool checkValidDesignation(char*,int*);

/*GAME FUNCTION*/
void singleGame(struct User*,int);
void multipleGame(struct User*,int);
void gameOptions(struct User*,int,int);

/*USER FUNCTIONS*/
struct User createNewUser();

//DATABASE FUNCTIONS
bool searchDB();