#include <iostream>
#include <cstdlib>
#include "list.h"
#include <ctime>
using namespace std;
int main()
{
    /*DON'T CHANGE SIZE*/
    int n=20;//rows
    int m=80;//cols
    char board[20][80];
    
    food f; //sample food
    poison p; //sample poison

    setBoardBoundary(n,m,board); //setting boundary
    intializeBoard(n,m,board); //function for cleaning garbage

    // cout << "SELECT ONE CHOICE"<<endl;
    // cout << "DO YOU WANT TO START A NEW GAME"<<endl;
    // cout << "DO YOU WANT TO START A EXISTING GAME"<<endl;
    /*INITALIZE SNAKE*/
    Snake S;
    S.insert_head(2,5,'O');
    S.insert_tail(2,4,'O');
    S.insert_tail(2,3,'O');
    S.insert_tail(2,2,'O');
    // S.delete_tail();
    S.print();

    /*PRINTING SNAKE ON BOARD*/
    S.insertSnakeOnBoard(n,m,board);
    
    /*PRINTING THE BOARD*/
    printarray(n,m,board);
    
    

    bool flagfood = true; //eated food
    bool flagpoison = true;//eated poison 
    
    char input; //for inputing the direction
    while(1)
    {
        intializeBoard(n,m,board); //function for cleaning garbage
        
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
        cout << "D | d ---- RIGHT" <<endl;
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

        /*PRINTING SNAKE ON BOARD*/
        S.insertSnakeOnBoard(n,m,board);

        /*PRINTING THE BOARD*/
        printarray(n,m,board);
    }
    
}