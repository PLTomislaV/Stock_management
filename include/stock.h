#ifndef STOCK_H
#define STOCK_H
#include<math.h>
#include <iostream>
#include<conio.h>
#include<math.h>
#include<string>
#include<string.h>
#include<fstream>

using namespace std;

class stock{
    // item class
private:
    char name[20],company[20];
	double price, quant, cost; int tax;

public:

    stock();
    //constructor

    friend ostream& operator<< (ostream& out, const stock& stock);
    // displays product without the cost visible

	void get(char nm[20]);
	//this function gets information from user about the product
	//name comes from addnew

	void show_boss();
    //displays product with cost visible

    int name_cmp(char nm[20]);
    //compare names

    void withd(double qty);
    // as part of selling process, shows how much to pay tax

    void refil(double qty);
    //change quantiy

    void sell_info(double qty);
    //saving payment information for boss into settlement.dat

    void refill_info(double qty);
    //saving refill information for boss into settlement.dat

};



double input_dbl(string what_input);
//asking for double input, with input validation and correction.


void disp_settlement();
//opens a settlement file and displays content

void fix_settlement();
//creates a new settlement(and overrites old) file and takes input from user using input_dbl

void addnew();
//asks user for new product and adds to stock.dat file and
//cheks correctness of name

void sell();
//user I/O alongside  stock.dat update

void disp();
// display a stock without cost

void disp_boss();
//display a stock with cost

void refill();
//change the value of quantity of certain stock

void rmv();
//delete instance stock from file stock.dat


#endif // STOCK_H
