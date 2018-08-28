#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
/******************/
struct node
{
    string name;
    int id;
    node *next;
};
//THIS IS FRIEND LIST CLASS
class list
{
    public:
    node *head;
    list()
    {
        head=NULL;
    }
    node *create(string n,int pid)
    {
        node *newNode = new node;
        newNode->name=n;
        newNode->id=pid;
        newNode->next=NULL;
        return newNode;
    }
    void insert_head(string str,int id)
    {
        node *newNode = create(str,id);
        if(head == NULL)
        {
            head = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }
    void deletefromhead()
    {
        node *temp=head;
        head=head->next;
        temp->next=NULL;
        delete(temp);
    }
    void delete_existing_friend(string input)
    {
        int flag=0;
        if(head==NULL)
        {
            cout << "---------------------"<<endl;
            cout << "That person is not your friend" << endl;
            cout << "---------------------"<<endl;
        }
        else if(head->name==input)
        {
            deletefromhead();
        }
        else
        {
            node *current = head;
            node *prev;
            while(current!=NULL)
            {
                if(current->name==input)
                {
                    flag=1;
                    break;
                }
                prev=current;
                current=current->next;
            }
            // cout <<"test:"<< prev->data << endl;
            // cout <<"test:"<< current->data << endl;
            prev->next = current->next;
            if(flag==0)
            {
                cout << "SORRY YOU HAVE ENTERED WRONG NAME!!!"<<endl;
            }
        }
    }
    void print_list()
    {
        cout << "FRIEND LIST" <<endl;
        cout << "---------------------"<<endl;
        node *current=head;
        while(current!=NULL)
        {
            cout << current->name << current->id; //printing person data
            cout << " -> ";
            current=current->next;
        }
        cout<<"NULL"<<endl;
        cout << "---------------------"<<endl;
    }
    bool search_list(string str,int pid)
    { 
        node *current=head;
        while(current!=NULL)
        {
            if(current->name==str && current->id==pid)
            {
                return true;
            }
            current=current->next;
        }
        return false;
    }
};
/******************/
// class list;
class person
{
    string name;
    int id;
    public:
    list friendlist;
    person()
    {
        name="";
        id=0;
    }
    //getters
    string getName()
    {
        return name;
    }
    int getId()
    {
        return id;
    }
    void setName(string str)
    {
        name=str;
    }
    void setId(int pid)
    {
        id=pid;
    }
    person(string n,int pid)
    {
        name = n;
        id = pid;
    }
    void print_person_friend_list()
    {   
        //printing the friend list
        friendlist.print_list();
    }
};
//ADDITIONAL METHODS
void display_mutual_friends(list a,list b)
{
    if(a.head==NULL && b.head==NULL)
    {
        cout << "---------------------"<<endl;
        cout << "THEY HAVE SAME NAME OR DON'T HAVE MUTUAL FRIENDS" <<endl;
        cout << "---------------------"<<endl;
        return;
    }
    node *current1=a.head;
    node *current2=b.head;
    // a.print();
    // b.print();
    cout << "---------------------"<<endl;
    cout << "MUTUAL FRIENDS" << endl;
    while(current1!=NULL)
    {
        node *current2=b.head;
        while(current2!=NULL)
        {
            if(current1->name == current2->name)
            {
                cout << current2->name << endl;
                break;
            }
            current2=current2->next;
        }
        current1 = current1->next;
    }
    cout << "---------------------"<<endl;
}

bool friends_or_not(person a,person b)
{
    int flag=0;
    //search name of a person a in person b
    string trial = a.getName();
    node *current = b.friendlist.head;
    while(current!=NULL)
    {
        if(current->name==trial)
        {
            flag=1;
            break;
        }
        current=current->next;
    }
    if(flag==1)
    {
        return true;
    }
    //search name of a person b in person a
    trial = b.getName();
    current = a.friendlist.head;
    while(current!=NULL)
    {
        if(current->name==trial)
        {
            flag=1;
            break;
        }
        current=current->next;
    }
    if(flag==1)
    {
        return true;
    }
    //else
    return false;
}
bool search_array(int j,person arr[100],string srch,int search)
{
    for(int l=0;l<j;l++)
    {
        if(arr[l].getName()==srch && arr[l].getId()==search)
        {
            return true;
        }
    }
    return false;
}
void friend_suggestions(int index,person arr[100],int j)
{
    //traversing array
    for(int k=0;k<j;k++)
    {
        if(k!=index)
        {
            int val = arr[k].friendlist.search_list(arr[k].getName(),arr[k].getId());
            if(val)
            {
                //finded in list then do nothing
            }
            else
            {
                cout << arr[k].getName() << " ";
                cout << arr[k].getId() << endl;
                cout << "######################"<<endl;
            }
        }
    }
}