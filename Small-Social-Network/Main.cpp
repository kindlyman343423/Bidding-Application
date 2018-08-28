#include <iostream>
#include <string>
#include <cstdlib>
#include "extras.h"
#include <vector>
using namespace std;

int main()
{
    static int random=0;
    int option;
    person per[100];
    int j=0; //for making person object names
    
    //first person
    
    per[j].setName("Gaurav");
    per[j].setId(++random);
    j++;

    //second person
    
    per[j].setName("Anonymous");
    per[j].setId(++random);
    j++;

    //third person
    
    per[j].setName("Joker");
    per[j].setId(++random);
    j++;
    while(1)
    {
        cout << "Enter the option" <<endl;
        cout << "0. exit" << endl;
        cout << "1. add new user in this network" << endl;
        cout << "2. delete existing friend"<<endl;
        cout << "3. print user list"<<endl;
        cout << "4. Tell MUTUAL FRIENDS of two persons"<<endl;
        cout << "5. Two persons are friends or not"<<endl;
        cout << "6. Add friend in the your friendlist"<<endl;
        cout << "7. Friend Suggestions"<<endl;
        cin >> option;
        if(option==0)
        {
            //do nothing
            break;
        }
        else if(option==1)
        {
            cout << "ADD NEW USER" << endl;
            string str;
            cout << "Enter the name of the new user"<<endl;
            cin >> str;
            //making another person
            
            per[j].setName(str);
            per[j].setId(++random);
            j++;
        }
        else if(option==2)
        {
            cout << "DELETING EXISTING FRIEND" << endl;
            string str;
            cout << "Enter the name of the friend yu don't want in your account"<<endl;
            cin >> str;
            cout << "Enter the person index < " << j << " in which u have to perform operation" <<endl;
            int index;
            cin >> index;
            if(index<j)
            {
                per[index].friendlist.delete_existing_friend(str);
            }
            else
            {
                cout << "---------------------"<<endl;
                cout << "Entered index out of range!!!"<<endl;
                cout << "---------------------"<<endl;
            }
        }
        else if(option==3)
        {
            //printing the list;
            cout << "Enter the person index <" << j << " in which u have to perform operation" <<endl;
            int index;
            cin >> index;
            if(index<j)
            {   
                per[index].friendlist.print_list();
            }
            else
            {
                cout << "---------------------"<<endl;
                cout << "Entered index out of range!!!"<<endl;
                cout << "---------------------"<<endl;
            }
        }
        else if(option==4)
        {
            int index1;
            int index2;
            cout << "Enter the first person index < " << j << " in which u have to perform operation"<<endl;
            cin >> index1;
            cout << "Enter the first person index < " << j << " in which u have to perform operation"<<endl;
            cin >> index2;
            if(index1<j && index2<j)
            {
                display_mutual_friends(per[index1].friendlist,per[index2].friendlist);
            }
            else
            {
                cout << "---------------------"<<endl;
                cout << "Entered index out of range!!!"<<endl;
                cout << "---------------------"<<endl;
            }
        }
        else if(option==5)
        {
            int index1;
            int index2;
            cout << "Enter the first person index < " << j << " in which u have to perform operation"<<endl;
            cin >> index1;
            cout << "Enter the first person index < " << j << " in which u have to perform operation"<<endl;
            cin >> index2;
            if(index1<j && index2<j)
            {
                int ans = friends_or_not(per[index1],per[index2]);
                if(ans)
                {
                    cout << "THEY ARE FRIENDS" <<endl;
                }
                else
                {
                    cout << "THEY ARE NOT FRIENDS" <<endl;
                }
            }
            else
            {
                cout << "---------------------"<<endl;
                cout << "Entered index out of range!!!"<<endl;
                cout << "---------------------"<<endl;
            }
        }
        else if(option==6)
        {
            cout << "ADD EXISTING FRIEND TO YOUR FRIENDLIST" << endl;
            string str;
            int ran;
            cout << "Enter the name of the old user"<<endl;
            cin >> str;
            cout << "Enter the index of the user" << endl;
            cin >> ran;
            //find and name id
            int find = search_array(j,per,str,ran);
            if(find)
            {
                cout << "VALID USER" <<endl;
                cout << "WE ARE ADDING THIS PERSON TO YOUR FRIEND LIST" << endl;
                cout << "Enter the person index < " << j << " in which u have to add this friend" <<endl;
                int index;
                cin >> index;
                if(index<j)
                {
                    per[index].friendlist.insert_head(str,ran);
                }
                else
                {
                    cout << "---------------------"<<endl;
                    cout << "Entered index out of range!!!"<<endl;
                    cout << "---------------------"<<endl;
                }
            }
            else
            {
                cout << "USER NOT VALID"<<endl;
            }
        }
        else if(option==7)
        {
            cout << "SUGGESTING FRIENDS" << endl;
            cout << "Enter the person index < " << j <<endl;
            int index;
            cin >> index;
            friend_suggestions(index,per,j);
        }
        else if(option==99)
        {
            cout << "***********************************************"<<endl;
            cout << "MY WHOLE NETWORK" << endl;
            for(int k=0;k<j;k++)
            {
                cout << per[k].getName() <<" "<< per[k].getId() <<endl;
                per[k].friendlist.print_list();
                cout << "==============================="<<endl;    
            }
            
        }
    }
    
    cout << "TOTAL PERSON IN MY DATABASE ARRAY: "<<j<<endl;
}
