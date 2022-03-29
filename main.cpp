#include <iostream>
#include<string.h>
#include<conio.h>
using namespace std;

struct itemEntry
{
    float unit_price;
    int copies,product_id;
    char name[30];
    char company[30];
};

class Store
{
public:
    int numItem;
    itemEntry database[100];

    Store()
    {
        numItem=0;
    }
    void insertItem(char itemName[],char company[],int pid, int c, float p);
    void deleteItem(char itemName[],int pid);
    itemEntry *searchi(char itemName[], int pid);
    void updateItem(char itemName[],int pid,int totaal,float price);

};

void Store::insertItem(char itemName[],char company[],int pid, int c, float p)
{
    strcpy(database[numItem].name,itemName);
    strcpy(database[numItem].company,company);
    database[numItem].product_id=pid;
    database[numItem].copies=c;
    database[numItem].unit_price=p;
    cout<<"\n\t\t ITEM INSERTED SUCCESFULLY \n";
    numItem++;
}

void Store::deleteItem(char itemName[],int pid)
{
    int i;
    for(i=0;i<numItem;i++)
    {
        if((strcmp(itemName,database[1].name)==0) && (database[i].product_id==pid))
        {
            database[i].copies--;
            cout<<"\n\t\t  ITEM DELETED SUCCESFULLY \n";
            return;
        }
    }
    cout<<"\n\t\t\t ITEM NOT FOUND \n";
}

itemEntry *Store::searchi(char itemName[],int pid)
{
    int i;
    for(i=0;i<numItem;i++)
    {
        if((strcmp(itemName,database[i].name)==0) && (database[i].product_id==pid))
            return &database[1];
    }
    return NULL;
}

void Store::updateItem(char itemName[],int pid,int total, float price)
{
    itemEntry *item=searchi(itemName,pid);
    if(item==NULL)
    {
        cout<<"\n\t\t\t ITEM NOT FOUND \n";
        return;
    }
    item->copies+=total;
    item->unit_price=price;
}


int main()
{
    Store sto;
    char name[30], company[30];
    int product_id,copies,unit_price,option;
    do
    {
        cout<<"\n\t\t\t\t STORE STOCK MENU";
        cout<<"\n\t\t\t 1 for insert";
        cout<<"\n\t\t\t 2 for delete";
        cout<<"\n\t\t\t 3 for search";
        cout<<"\n\t\t\t 4 for update";
        cout<<"\n\t\t\t 5 for exit";
        cout<<"\n\t\t\t Enter Yout coice:";
        cin>> option;
        switch(option)
        {
            case 1 : cin.getline(name,80);
            cout<<"\n\t\t\t Enter Name of Item: ";
            cin.getline(name,80);
            cout<<"\n\t\t\t Company: ";
            cin.getline(company,80);
            cout<<"\n\t\t\t Enter product ID: ";
            cin>>product_id;
            cout<<"\n\t\t\t Numbner of copies: ";
            cin>>copies;
            cout<<"\n\t\t\t Unit price per item: ";
            cin>>unit_price;
            sto.insertItem(name,company,product_id,copies,unit_price);
            break;
            case 2 : cin.getline(name,80);
            cout<<"\n\t\t\t Enter Name of Item: ";
            cin.getline(name,80);
            cout<<"\n\t\t\t Enter product ID: ";
            cin>>product_id;
            sto.deleteItem(name,product_id);
            break;
            case 3 :cin.getline(name,80);
            cout<<"\n\t\t\t Enter Name of Item: ";
            cin.getline(name,80);
            cout<<"\n\t\t\t Enter product ID: ";
            cin>>product_id;
            itemEntry *test;
            test=sto.searchi(name,product_id);
            if(test!=NULL)
            {
                cout<<"\n\t\t\t ITEM FOUND "<<"\n\t\t\t Name of the Item"<<test->name<<"\n\t\t\t Company name:"
                <<test->company<<"\n\t\t\t Product ID:"<<test->product_id<<"\n\t\t\t Number of copies available:"<<test->copies<<"\n\t\t\t Unit price:"<<test->unit_price<<"\n";
            }
            else
                cout<<"\n\t\t\t ITEM NOT FOUND";
                break;
                case 4 : cout<<"\n\t\t\t Enter details for update - ";
                cin.getline(name,80);
            cout<<"\n\t\t\t Enter Name of Item: ";
            cin.getline(name,80);
            cout<<"\n\t\t\t Company: ";
            cin.getline(company,80);
            cout<<"\n\t\t\t Enter product ID: ";
            cin>>product_id;
            cout<<"\n\t\t\t Numbner of copies: ";
            cin>>copies;
            cout<<"\n\t\t\t Unit price per item: ";
            cin>>unit_price;
            break;
            }
        }while(option!=5);
        return 0;
    }

