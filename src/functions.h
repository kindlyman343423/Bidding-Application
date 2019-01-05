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

/*STRUCTURES NEEDED FOR THE GAME*/
struct BidCard;
struct User;

/*GREET FUNCTIONS*/
void line(char,int);
void list();
void welcome();
void greetOptions(char);

/*OPTION FUNCTIONS*/
void playNewGame();
void startSavedGame();
void save();
void saveAndExit();
void settings();

void displayNumberOfPlayers(int,char);
void displayPlayersGame(int,char);
void colorSetting(char*);

/*BID CARD FUNCTIONS*/
void displayBidCard(struct BidCard,char);
struct BidCard createBidCard(int);

/*USER FUNCTIONS*/
struct User createNewUser();

//DATABASE FUNCTIONS
bool searchDB();