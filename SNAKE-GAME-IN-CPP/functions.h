//FUNCTIONS
void intializeBoard(int n,int m,char board[][80])
{
    for(register int i=1;i<n-1;i++)
    {
        for(register int j=1;j<m-1;j++)
        {
            board[i][j]=' ';
        }
    }
}
void setBoardBoundary(int n,int m,char board[][80])
{
    /*MAKIING BOARD BOUNDARY*/
    //horizontal
    for(register int i=0;i<m;i++)
    {
        board[0][i]='X';
        board[n-1][i]='X';
    }
    //left vertical
    for(register int i=1;i<n-1;i++)
    {
        board[i][0]='X';
        board[i][m-1]='X';
    }
}
// //function printing the board
void printarray(int n,int m,char board[][80])
{
    for(register int i=0;i<n;i++)
    {
        for(register int j=0;j<m;j++)
        {
            cout << board[i][j];
        }
        cout << endl;
    }
    cout << endl;
}