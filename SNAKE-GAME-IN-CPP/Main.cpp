#include <iostream>
#include <cstdlib>
#include "list.h"
#include "functions.h"
using namespace std;
int main()
{
    /*DON'T CHANGE SIZE*/
    int n=20;//rows
    int m=80;//cols
    char board[20][80];
    
    setBoardBoundary(n,m,board); //setting boundary
    intializeBoard(n,m,board); //function for cleaning garbage
    /*INITALIZE SNAKE*/
    Snake S;
    S.insert_head(2,5,'O');
    S.insert_tail(2,4,'O');
    S.insert_tail(2,3,'O');
    S.insert_tail(2,2,'O');
    /*PRINTING SNAKE ON BOARD*/
    S.insertSnakeOnBoard(n,m,board);
    
    /*PRINTING THE BOARD*/
    printarray(n,m,board);
    
    char input;
    while(1)
    {
        intializeBoard(n,m,board); //function for cleaning garbage
        cout << "Enter the option" << endl;
        cout << "W / w ---- UP" << endl;
        cout << "S / s ---- DOWN" << endl;
        cout << "A / a ---- LEFT" << endl;
        cout << "D | d ---- RIGHT" <<endl;
        cin >> input;
        if(input=='W' || input=='w') //UP
        {
            S.moveUp(n,m);
            S.print();
        }
        else if(input=='S' || input=='s') //DOWN
        {
            S.moveDown(n,m);
            S.print();
        }
        if(input=='D' || input=='d') //right
        {
            S.moveRight(n,m);
            S.print();
        }
        else if(input=='A' || input=='a') //left
        {
            S.moveLeft(n,m);    
            S.print();
        }

        
        /*PRINTING SNAKE ON BOARD*/
        S.insertSnakeOnBoard(n,m,board);

        /*PRINTING THE BOARD*/
        printarray(n,m,board);
        // break;
    }
}