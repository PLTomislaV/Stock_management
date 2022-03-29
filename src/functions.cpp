#include <iostream>
#include<fstream>
#include<conio.h>
#include"functions.h"
#include"stock.h"

using namespace std;
stock stock();
int i,n;
ifstream fin;
ofstream fout;
fstream fio;
double input_dbl(string what_input)
{
    double input;
    inputdbl:
    cout<<"Please input "<<what_input<<":";

    cin>>input;
	    if (input<0){
            cerr << "Error: Please input a positive number:";
            cin.clear();
            cin.ignore();
            goto inputdbl;
	    }
        else if(input==0){
            cin.clear();
            cin.ignore();
            cout << "\nAre you sure you want to input '0' ? To confirm please input 0 and press enter.\n";
            int y_n;
            cin>>y_n;
            if (y_n==0){
                cout <<"\nInput is '0' .\n";
                cin.clear();
                cin.ignore();
            }
            else{
                cout <<"\nInput '0' not confirmed.\n";
                cin.clear();
                cin.ignore();
                goto inputdbl;
            }

        }
	    else{cout<<"Correct input.\n";}
	    cin.clear();
	    cin.ignore();
	    return input;
}

void disp_settlement()
{
    int i=1;
    cout<<"Balance:\t\tIncome:\t\t\tCosts:\t\t\tTax:\n";
        double dbl;
    	 fin.open("settlement.dat",ios::binary);
     while(!fin.eof())//end of file
     {
	  fin.read((char*)&dbl,sizeof(double));
	  if(!fin.eof())
	  {
	     if(fin.tellg()<0)//tellg Get position in input sequence (if file empty or no file)
	     {	i=0; break;}
	     cout<<dbl;
         cout<<"\t\t\t";
	  }
     }
     if(i==0)
     {	cout<<"\n\nNo more data.\n\nPress any key to continue.";
	getch();
     }
     fin.close();
}

void fix_settlement()
{
    double balance,income,costs,tax;
    fout.open("temp_s.dat",ios::binary);

    string bal="balance";
	balance=input_dbl(bal);
    fout.write((char*)&balance,sizeof(double));

    string inc="income";
	income=input_dbl(inc);
    fout.write((char*)&income,sizeof(double));

    string cost="costs";
    costs=input_dbl(cost);
    fout.write((char*)&costs,sizeof(double));

    string taxx="tax";
    tax=input_dbl(taxx);
    fout.write((char*)&tax,sizeof(double));
    cout<<"\nSettlement updated.\nPress any key to continue.";

    fout.close();
         remove("settlement.dat");
     rename("temp_s.dat","settlement.dat");
}

void addnew()
{
    system("cls");
	disp_boss();
	getch();
	system("cls");

    n_of_products:
	cout<<"\nEnter the number of products that you wish to add: ";
    cin>>n;
	    if (n<0){
            cerr << "Error: Please input a positive number:";
            cin.clear();
            cin.ignore();
            goto n_of_products;
	    }
	    else{cout<<"Correct input.\n";}
	    cin.clear();
	    cin.ignore();
    if (n!=0)
    {

	fout.open("stock.dat",ios::binary|ios::app);
	for(i=0;i<n;i++)

	{

	    stock.get();
	    fout.write((char*)&stock,sizeof(stock));
        cout<<"\n\nItem updated";
		cin.get();


    }
    cout<<"\n\nStock Updated!!";


    fout.close();
    cin.get();
    system("cls");
    disp_boss();
}

	else
{

	fout.close();
	cin.get();
	system("cls");
	cout<<"\n\nNo items to be added";

}
}
void sell(){
system("cls");
	char temp[20];double qty;
	int i=0;
	long pos=0;
	disp();
    productname:
	cin.ignore();
	cin.clear();
	cout<<"\n\nEnter the product's name \n"<<endl;
	cin.get(temp,20);
	inputqty:
	cout<<"\n\nEnter quantity: \n"<<endl;
	cin>>qty;
	    if (qty<=0){
            cerr << "Error: Please input a positive number:";
            cin.clear();
            cin.ignore();
            goto inputqty;
	    }
	    else{cout<<"Correct input.\n";}
	    cin.clear();
	    cin.ignore();
	fio.open("stock.dat",ios::binary|ios::out|ios::in);
     while(fio)
     {
	    pos=fio.tellp();
	    fio.read((char*)&stock,sizeof(stock));
	    if(stock.name_cmp(temp)==0)
	    {
            stock.sell_info(qty);
		  stock.withd(qty);
		  fio.seekp(pos);
		  fio.write((char*)&stock,sizeof(stock));
		  i++;break;
	    }
     }


     if(i!=1){
       cout<<"\n\n!!Record not found!!";

     fio.close();
            getch();
    system("cls");
	 disp();
	getch();
    goto productname;
     }
}
void disp()
{
	int i=1;
cout<<"\n --------- THE STOCK LIST --------- \n--------- PRESS ANY KEY TO CONTINUE --------- \n\nName:\t\t\tStock:\t\t\tPrice[$]:\t\t\tCompany:\t\t\tTax[%]:\n";
	 fin.open("stock.dat",ios::binary);
     while(!fin.eof())//end of file
     {
	  fin.read((char*)&stock,sizeof(stock));
	  if(!fin.eof())
	  {
	     if(fin.tellg()<0)//tellg Get position in input sequence (if file empty or no file)
	     {	i=0; break;}
	     stock.show();
	  }
     }
     if(i==0)
     {	cout<<"\n\n Empty stock or file not found.\n\n Press any key to continue.";
	getch();
     }
     fin.close();

}
void disp_boss()
{
	int i=1;
cout<<"\n --------- THE STOCK LIST --------- \n--------- PRESS ANY KEY TO CONTINUE --------- \n\nName:\t\t\tStock:\t\t\tPrice:\t\t\tCompany:\t\t\tCost:\t\t\tTax:\n";
	 fin.open("stock.dat",ios::binary);
     while(!fin.eof())//end of file
     {
	  fin.read((char*)&stock,sizeof(stock));
	  if(!fin.eof())
	  {
	     if(fin.tellg()<0)//tellg Get position in input sequence (if file empty or no file)
	     {	i=0; break;}
	     stock.show_boss();
	  }
     }
     if(i==0)
     {	cout<<"\n\n Empty stock or file not found.\n\n Press any key to continue.";
	getch();
     }
     fin.close();

}
void refill()
{
	system("cls");
	char temp[20];double qty;
	int i=0;
	long pos=0;
	disp();
	cout<<"\n\nEnter the product name \n"<<endl;
	cin.get(temp,20);
	entquant:
	cout<<"\n\nEnter quantity: \n"<<endl;
	cin>>qty;
    if(qty==0){
            cin.clear();
            cin.ignore();
            cout << "\nAre you sure you want to input '0' ? To confirm please input 0 and press enter.\n";
            int y_n;
            cin>>y_n;
            if (y_n==0){
                cout <<"\nInput is '0' .\n";
                cin.clear();
                cin.ignore();
            }
            else{
                cin.clear();
            cin.ignore();
                goto entquant;
            }
	fio.open("stock.dat",ios::binary|ios::out|ios::in);
     while(fio)
     {
	    pos=fio.tellp();
	    fio.read((char*)&stock,sizeof(stock));
	    if(stock.name_cmp(temp)==0)
	    {

		  stock.refil(qty);
		  fio.seekp(pos);
		  fio.write((char*)&stock,sizeof(stock));
		  i++;break;
	    }
     }
     if(i!=1){
       cout<<"\n\n!!Record not found!!\nPress any key to continue.";
     }
       getch();
     fio.close();
    system("cls");
    cin.get();
	 disp(); cin.get();


}
}
void rmv()
{
	system("cls");
	 int i=0;
     char temp[20];
     cout<<"\nDelete Instance";
     cout<<"\n\nEnter the name of the product:";
     cin.get(temp,20);
     fout.open("temp.dat",ios::binary);
     fin.open("stock.dat",ios::binary);
     while(!fin.eof())
     {

        fin.read((char*)&stock,sizeof(stock));

	  if(!fin.eof()){
	    if(stock.name_cmp(temp)==0)
	    {
		  stock.show();
		  cout<<"\n\nInstance deleted.";
		  i++;
	    }
	    else{
		  fout.write((char*)&stock,sizeof(stock));
	    }
        }
     }
     if(i==0)
       cout<<"\n\n!!Record not found!!";
     fin.close();
     fout.close();
     remove("stock.dat");
     rename("temp.dat","stock.dat");
}

