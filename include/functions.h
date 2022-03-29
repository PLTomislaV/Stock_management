#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
#include<iostream>
#include<math.h>
#include<string.h>
#include"stock.h"



using namespace std;

double input_dbl(string what_input);
//asking for double input, with input validation and correction.


void disp_settlement();
//opens a settlement file and displays content

void fix_settlement();
//creates a new settlement(and overrites old) file and takes input from user using input_dbl

void addnew();
//asks user for new product and adds to stock.dat file and

void sell();
//user I/O alongside  stock.dat update ///////////TBD SETTELMENT

void disp();
// display a stock without cost

void disp_boss();
//display a stock with cost

void refill();
//change the value of quantity of certain stock

void rmv();
//delete instance stock from file stock.dat

#endif // FUNCTIONS_H_INCLUDED
