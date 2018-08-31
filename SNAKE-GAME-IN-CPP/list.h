#include <iostream>
#include <cstdlib>
using namespace std;
//node food for snake
struct food
{
    int x;
    int y;
    char value;
};
struct poison
{
    int x;
    int y;
    char value;
};
struct node
{
    int x;
    int y;
    char value;
    node* next;
};
class Snake
{
    node *head;
    public:
    Snake()
    {
        head = NULL;
    }
    node* getHead()
    {
        return head;
    }
    //FUNCTIONS
    node *create(int a,int b,char val)
    {
        node *newNode = new node;
        newNode->x = a;
        newNode->y = b;
        newNode->value=val;
        return newNode;
    }
    /*INSERT AT HEAD OF THE SNAKE*/
    void insert_head(int x,int y,char value)
    {
        node *newNode = create(x,y,value);
        if(head==NULL)
        {
            //null linked list
            head = newNode;
            head->value='H';
        }
        else
        {
            newNode->next = head;
            head->value='O';
            head = newNode;
            head->value='H';
        }
    }
    /*INSERT AT TAIL OF THE SNAKE*/
    void insert_tail(int x,int y,int value)
    {
        node* newNode = create(x,y,value);
        if(head==NULL)
        {
            head=newNode;
        }
        else
        {
            node *current=head;
            while(current->next!=NULL)
            {
                current=current->next;
            }
            current->next=newNode;
            newNode->next=NULL;
        }
    }
    /*DELETE FROM HEAD IN A SNAKE*/
    void delete_head()
    {
        if(head==NULL)
        {
            return;
        }
        node *temp=head;
        head=head->next;
        temp->next=NULL;
        delete(temp);
    }
    /*DELETE TAIL OF SNAKE*/
    void delete_tail()
    {
        if(head==NULL)
        {
            return;
        }
        else if(head->next==NULL)
        {
            head=NULL;
        }
        else
        {
            node *current=head;
            node *prev=head;
            while(current->next!=NULL)
            {
                prev=current;
                current=current->next;
            }
            prev->next=NULL;
            delete(current);
        }
    }
    /*PRINTING THE SNAKE*/
    void print()
    {
        node *current = head;
        while(current!=NULL)
        {
            cout << current->x;
            cout << current->y;
            cout << current->value;
            cout << " -> ";
            current=current->next;
        }
        cout<< "NULL" << endl; 
    }

    /******************************************/
    void insertSnakeOnBoard(int n,int m,char board[][80])
    {
        node *current=head;
        while(current!=NULL)
        {    
            board[current->x][current->y]=current->value;
            current=current->next;
        }
    }
    void moveRight(int n,int m)
    {
        int a = head->x;
        int b = head->y+1;
        checkandadd(a,b,n,m);
    }
    void moveLeft(int n,int m)
    {
        int a = head->x;
        int b = head->y-1;
        checkandadd(a,b,n,m);
    }
    void moveUp(int n,int m)
    {
        int a = head->x - 1;
        int b = head->y;
        checkandadd(a,b,n,m);
    }
    void moveDown(int n,int m)
    {
        int a = head->x + 1;
        int b = head->y;
        checkandadd(a,b,n,m);
    }
    /*FUNCTION FOR CHECKING ITS VALID OR NOT*/
    void checkandadd(int a,int b,int n,int m)
    {
        int flag=0;
        int check=0;
        //traversing the list
        node *current=head;
        while(current!=NULL)
        {
            if(current->x == a && current->y == b)
            {
                flag=1;
                break;
            }
            current=current->next;
        }
        //FOR STOPPING GAME
        if(a==0 || a==n-1 || b==m-1 || b==0 || flag==1)
        {
            cout << "GAME OVER" <<endl;
            exit(0);
        }
        //FOR VALID BUT ENTERING AGAIN
        if(a > 0 && a < n-1 && b < m-1 && b>0 && flag==0)
        {
            check=1;
        }
        else
        {
            check=0;
        }
        cout << "CHECK" << check<<endl;
        if(check)
        {
            insert_head(a,b,'O');
            delete_tail();
        }
        else
        {
            cout << "ENTER VALID COORDINATES" << endl;
        }
    }
};