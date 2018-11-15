#include <iostream>
#include <cstdlib>
#include "list.h"
#include <ctime>
using namespace std;
int main()
{
    //DATA STRUCTURE FOR STORING THE SCORES
    //ONE MORE LINK LIST
    int index_highscores=0;
    /*DON'T CHANGE SIZE*/
    int n=20;//rows
    int m=80;//cols
    char board[20][80];
    
    food f; //sample food
    poison p; //sample poison
    bool flagfood = true; //eated food already
    bool flagpoison = true;//eated poison already
    Snake S;

    printSnakeGameLogo(); //printing game logo
    setBoardBoundary(n,m,board); //setting boundary
    intializeBoard(n,m,board); //function for cleaning garbage

    int option;
    cout <<BYELLOW;
    cout << "SELECT ONE CHOICE"<<endl;
    cout << "1. DO YOU WANT TO START A NEW GAME"<<endl;
    cout << "2. DO YOU WANT TO START A EXISTING GAME"<<endl;
    cout << "3. SETTINGS" << endl;
    cout << "0. EXIT SNAKE GAME" <<RESET<<endl;
    cin >> option;
    if(option==0)
    {
        cout <<BBLUE<< "GAME EXITED...." <<RESET<<endl;
        exit(0);
    }
    if(option==1)
    {
        //new game
        //INITALIZE SNAKE
        S.insert_head(2,5,'O');
        S.insert_tail(2,4,'O');
        S.insert_tail(2,3,'O');
        S.insert_tail(2,2,'O');
        S.print();
    }
    else if(option==2)
    {
        //take food,poison and snake from file
        //reading from a file
        FILE *ptr;
        ptr=fopen("file.txt","r");

        fclose(ptr);
    } 
    else if(option==3)
    {
        cout <<BBLUE;
        cout << "SELECT ONE CHOICE" << endl;
        cout << "1. HIGH SCORES" << endl;
        cout << "2. CHANGE BOARD COLOR" << endl;
        cout << "3. RETURN" << endl;
        cout << RESET;
        cin >> option;

        if(option==1)
        {
            main();
            exit(0);
        }
        else if(option==2)
        {
            cout << "SELECT BOARD COLORS" <<endl;
            cout << "0. NO COLOR" <<endl;
            cout << "1. BGGREENISH" <<endl;
            cout << "2. BGRED" <<endl;
            cout << "3. BGLGREEN" <<endl;
            cout << "4. BGORANGE" << endl;
            cout << "5. BGLBLUE" << endl;
            cout << "6. BGPINK" << endl;
            cout << "7. BGDGREEN" << endl;
            cout << "8. BGWHITE" << endl;
            cin >> option;
            switch(option)
            {
                case 0:
                $COLOR="";
                break;
                case 1:
                $COLOR=BGGREENISH;
                break;
                case 2:
                $COLOR=BGRED;
                break;
                case 3:
                $COLOR=BGLGREEN;
                break;
                case 4:
                $COLOR=BGORANGE;
                break;
                case 5:
                $COLOR=BGLBLUE;
                break;
                case 6:
                $COLOR=BGPINK;
                break;
                case 7:
                $COLOR=BGDGREEN;
                break;
                case 8:
                $COLOR=BGWHITE;
                break;
            }
            main();
            exit(0);
        }
        else
        {
            main();
            exit(0);
        }
    }
    //PRINTING SNAKE ON BOARD
    S.insertSnakeOnBoard(n,m,board);
    
    //PRINTING THE BOARD
    printarray(n,m,board);
    
    char input; //for inputing the direction
    while(1)
    {
        intializeBoard(n,m,board); //function for cleaning garbage
        if(S.getHead()==NULL)
        {
            cout <<RED<< "GAME OVER SNAKE DIED!!!!!" <<RESET<<endl;
            break;
        }
        p = createpoison(n,m,S,flagpoison,p); //create,get poison
        board[p.x][p.y]=p.value; //insert poison on board
        flagpoison=false;
        
        f = createfood(n,m,S,flagfood,f); //create,get food
        board[f.x][f.y]=f.value; //inseert food on board
        flagfood=false;

        cout << "Enter the option" << endl;
        cout << "W / w ---- UP" << endl;
        cout << "S / s ---- DOWN" << endl;
        cout << "A / a ---- LEFT" << endl;
        cout << "D / d ---- RIGHT" <<endl;
        cout << "C / c / V / v ---- SAVE GAME" <<endl;
        cout << "X / x ---- EXIT THIS GAME" <<endl;
        cout << "R / r ---- SAVE AND EXIT"<<endl;
        cin >> input;
        if(input=='W' || input=='w') //UP
        {
            S.moveUp(n,m,board,f,p,&flagfood,&flagpoison);
            S.print();
        }
        else if(input=='S' || input=='s') //DOWN
        {
            S.moveDown(n,m,board,f,p,&flagfood,&flagpoison);
            S.print();
        }
        if(input=='D' || input=='d') //right
        {
            S.moveRight(n,m,board,f,p,&flagfood,&flagpoison);
            S.print();
        }
        else if(input=='A' || input=='a') //left
        {
            S.moveLeft(n,m,board,f,p,&flagfood,&flagpoison);    
            S.print();
        }
        else if(input=='C' || input=='c' || input=='V'||input=='v')
        {
            //for saving game
            break;
        }
        else if(input=='X' || input=='x')
        {
            //for exiting game
            main();
        }
        else if(input=='R'||input=='r')
        {
            //for save and exit
            break;
        }
        /*PRINTING SNAKE ON BOARD*/
        S.insertSnakeOnBoard(n,m,board);

        /*PRINTING THE BOARD*/
        printarray(n,m,board);
        cout <<"CURRENT SCORE:" << S.getScore() << endl;
    }
    
    cout << BOLD << "----------------------------" << endl;
    cout << "FINAL SCORE: " << S.getScore() << endl;
    cout << "----------------------------" << RESET << endl;
}