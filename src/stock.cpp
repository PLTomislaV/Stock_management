#include "stock.h"

ifstream fin;
ofstream fout;
fstream fio;
void get(char nm[20]);
void show_boss();
int name_cmp(char nm[20]);
void withd(double qty);
void refil(double qty);
void sell_info(double qty);
void refill_info(double qty);
using namespace std;

stock::stock(): name("Unnamed"), company("None"),price(0),quant(0),cost(0),tax(0) {

}
ostream& operator<< (ostream& out, const stock& stock)
{
    out << "\n" << stock.name << "\t\t\t" << stock.quant << "\t\t\t" << stock.price << "\t\t\t" << stock.company << "\t\t\t" << stock.tax << "\n";
}
stock stock;
void stock::get(char nm[20]) {
  strcpy(name, nm);
  cout << "\n\nInput the company (max 20 characters): \n\n";
  cin.get(company, 20);
  cin.clear();
  cin.ignore();

  string pr = "price";
  price = input_dbl(pr);

  string qu = "quantity";
  quant = input_dbl(qu);

  string co = "cost";
  cost = input_dbl(co);

  string ta = "tax";
  tax = input_dbl(ta);

}

void stock::show_boss() {
  cout << "\n" << name << "\t\t\t" << quant << "\t\t\t" << price << "\t\t\t" << company << "\t\t\t" << cost << "\t\t\t" << tax << "\n";
}
int stock::name_cmp(char nm[20]) {
  if (strcmp(nm, name) == 0)
    return 0;
  else
    return 1;
}
void stock::withd(double qty) {
  if (quant >= qty) {

    quant -= qty;
    cout << "\n\nStock updated.\n";
    cout << "\n\nTotal priceice to be paid: " << (price * qty + price * qty * tax / 100);
    cout << "\nTax: " << price * qty * tax / 100;

  } else
    cout << "\n\nInsufficient stock.";
  getch();
}
void stock::refil(double qty) {

  quant += qty;
  cout << "\n\nStock updated.";
  getch();

}
void stock::refill_info(double qty) {
  double bal, inc, cos, taxx;
  fio.open("settlement.dat", ios::binary | ios::out | ios:: in );
  fin.open("settlement.dat", ios::binary | ios:: in );
  fin.read((char * ) & bal, sizeof(double));
  fin.read((char * ) & inc, sizeof(double));
  fin.read((char * ) & cos, sizeof(double));
  fin.read((char * ) & taxx, sizeof(double));

  bal = bal - cost * qty;
  cout << "\n Total cost:" << cost * qty;
  cos = cos + cost * qty;
  cout << "\n Total tax:" << cost * qty * tax / 100;
  taxx = taxx - cost * qty * tax / 100;
  fio.seekp(0);

  fio.write((char * ) & bal, sizeof(double));
  fio.write((char * ) & inc, sizeof(double));
  fio.write((char * ) & cos, sizeof(double));
  fio.write((char * ) & taxx, sizeof(double));
  fio.close();
  fin.close();
  cout << "\nSettelement updated.";
  getch();

}
void stock::sell_info(double qty) {
  double bal, inc, cos, taxx;

    fio.open("settlement.dat", ios::binary | ios::out | ios:: in );
    fin.open("settlement.dat", ios::binary | ios:: in );
    fin.read((char * ) & bal, sizeof(double));
    fin.read((char * ) & inc, sizeof(double));
    fin.read((char * ) & cos, sizeof(double));
    fin.read((char * ) & taxx, sizeof(double));

    bal = bal + (price * qty + price * qty * tax / 100);
    inc = inc + (price * qty + price * qty * tax / 100);
    taxx = taxx + price * qty * tax / 100;
    fio.seekp(0);

    fio.write((char * ) & bal, sizeof(double));
    fio.write((char * ) & inc, sizeof(double));
    fio.write((char * ) & cos, sizeof(double));
    fio.write((char * ) & taxx, sizeof(double));
    fio.close();
    fin.close();


}

double input_dbl(string what_input) {
  double input;
  inputdbl:
    cout << "Please input " << what_input << ":";

  cin >> input;
  if (input < 0) {
    cerr << "Error: Please input a positive number:";
    cin.clear();
    cin.ignore();
    goto inputdbl;
  } else if (input == 0) {
    cin.clear();
    cin.ignore();
    cout << "\nAre you sure you want to input '0' ? To confirm please input 0 and press enter.\n";
    int y_n;
    cin >> y_n;
    if (y_n == 0) {
      cout << "\nInput is '0' .\n";
      cin.clear();
      cin.ignore();
    } else {
      cout << "\nInput '0' not confirmed.\n";
      cin.clear();
      cin.ignore();
      goto inputdbl;
    }

  } else {
    cout << "Correct input.\n";
  }
  cin.clear();
  cin.ignore();
  return input;
}

void disp_settlement() {
  int i(1);
  cout << "Balance:\t\tIncome:\t\t\tCosts:\t\t\tTax:\n";
  double dbl;
  fin.open("settlement.dat", ios::binary);
  while (!fin.eof()) {
    fin.read((char * ) & dbl, sizeof(double));
    if (!fin.eof()) {
      if (fin.tellg() < 0) {
        i = 0;
        break;
      }
      cout << dbl;
      cout << "\t\t\t";
    }
  }
  if (i == 0) {
    cout << "\n\nNo more data.\n\nPress any key to continue.";
    getch();
  }
  fin.close();
}

void fix_settlement() {
  double balance, income, costs, tax;
  fout.open("temp_s.dat", ios::binary);

  string bal = "balance";
  balance = input_dbl(bal);
  fout.write((char * ) & balance, sizeof(double));

  string inc = "income";
  income = input_dbl(inc);
  fout.write((char * ) & income, sizeof(double));

  string cost = "costs";
  costs = input_dbl(cost);
  fout.write((char * ) & costs, sizeof(double));

  string taxx = "tax";
  tax = input_dbl(taxx);
  fout.write((char * ) & tax, sizeof(double));
  cout << "\nSettlement updated.\nPress any key to continue.";

  fout.close();
  remove("settlement.dat");
  rename("temp_s.dat", "settlement.dat");
}

void addnew() {
  system("cls");
  disp_boss();
  getch();
  system("cls");
  double n;
  n_of_products:
    cout << "\nEnter the number of products that you wish to add: ";
  cin >> n;
  if (n < 0) {
    cerr << "Error: Please input a number:";
    cin.clear();
    cin.ignore();
    goto n_of_products;
  } else {
    cout << "Correct input.\n";
  }
  cin.clear();
  cin.ignore();
  if (n != 0) {

    for (int i(0); i < n; i++)

    {

      fout.open("stock.dat", ios::binary | ios::app | ios::out);

      inputname:
        fin.open("stock.dat", ios:: in );
      char nm[20] = "";
      cin.clear();
      cin.ignore();
      cout << "\n\nInput the name (max 20 characters): \n\n";

      cin.get(nm, 20);

      while (fin) {
        fin.read((char * ) & stock, sizeof(stock));
        if (stock.name_cmp(nm) == 0) {
          cout << "\n\n!!You cannot use the same name!!";
          getch();
          cin.clear();
          cin.ignore();
          fin.close();

          goto inputname;
        }
        if (fin.eof()) {
          fin.close();
          break;
        }

      }
      cin.clear();
      cin.ignore();
      stock.get(nm);
      fout.write((char * ) & stock, sizeof(stock));
      cout << "\n\nItem updated";

      getch();

      fout.close();
    }
    cout << "\n\nStock Updated!!";

    getch();
    system("cls");
    disp_boss();
  } else {

    fout.close();
    getch();
    system("cls");
    cout << "\n\nNo items to be added";

  }
}
void sell() {
  system("cls");
  char temp[20];
  double qty;
  int i(0);
  long pos(0);
  disp();
  productname:
    cin.ignore();
  cin.clear();
  cout << "\n\nEnter the product's name \n" << endl;
  cin.get(temp, 20);

  string q = "quantity";
  qty = input_dbl(q);
  fio.open("stock.dat", ios::binary | ios::out | ios:: in );
  while (fio) {
    pos = fio.tellp();
    fio.read((char * ) & stock, sizeof(stock));
    if (stock.name_cmp(temp) == 0) {

      stock.withd(qty);
      fio.seekp(pos);
      fio.write((char * ) & stock, sizeof(stock));
      i++;
      fio.close();

      stock.sell_info(qty);
      break;
    }
  }

  if (i != 1) {
    cout << "\n\n!!Record not found!!";

    fio.close();
    getch();
    system("cls");
    disp();
    getch();
    goto productname;
  }
}
void disp() {
  int i(1);
  cout << "\n --------- THE STOCK LIST --------- \n--------- PRESS ANY KEY TO CONTINUE --------- \n\nName:\t\t\tStock:\t\t\tPrice[$]:\t\t\tCompany:\t\t\tTax[%]:\n";
  fin.open("stock.dat", ios::binary);
  while (!fin.eof()) {
    fin.read((char * ) & stock, sizeof(stock));
    if (!fin.eof()) {
      if (fin.tellg() < 0) {
        i = 0;
        break;
      }
      cout << stock;
    }
  }
  if (i == 0) {
    cout << "\n\n Empty stock or file not found.\n\n Press any key to continue.";
    getch();
  }
  fin.close();

}
void disp_boss() {
  int i(1);
  cout << "\n --------- THE STOCK LIST --------- \n--------- PRESS ANY KEY TO CONTINUE --------- \n\nName:\t\t\tStock:\t\t\tPrice:\t\t\tCompany:\t\t\tCost:\t\t\tTax:\n";
  fin.open("stock.dat", ios::binary);
  while (!fin.eof()) {
    fin.read((char * ) & stock, sizeof(stock));
    if (!fin.eof()) {
      if (fin.tellg() < 0) {
        i = 0;
        break;
      }
      stock.show_boss();
    }
  }
  if (i == 0) {
    cout << "\n\n Empty stock or file not found.\n\n Press any key to continue.";
    getch();
  }
  fin.close();

}

void refill() {

  refillsearch: system("cls");
  char temp[20];double qty;
  int i(0);
  long pos(0);
  disp_boss();
  getch();
  cin.clear();
  cin.ignore();
  cout<<"\nRefill.";
  cout << "\n\nEnter the product name: \n" << endl;
  cin.get(temp, 20);
  entquant: cout << "\n\nEnter quantity: \n" << endl;
  cin >> qty;
  if (qty == 0) {
    cin.clear();
    cin.ignore();
    cout << "\nAre you sure you want to input '0' ? To confirm please input 0 and press enter.\n";
    int y_n;
    cin >> y_n;
    if (y_n == 0) {
      cout << "\nInput is '0' .\n";
      cin.clear();
      cin.ignore();
    } else {
      cin.clear();
      cin.ignore();
      goto entquant;
    }
  }

  fio.open("stock.dat", ios::binary | ios::out | ios:: in );
  while (fio) {
    pos = fio.tellp();

    fio.read((char * ) & stock, sizeof(stock));
    if (stock.name_cmp(temp) == 0) {

      stock.refil(qty);
      fio.seekp(pos);
      fio.write((char * ) & stock, sizeof(stock));
      fio.close();

      disp_boss();

      cout << "\n\nWould You like to include that refill into settelment? \n\nPut in 0 or any letter to confirm. Any number to cancel. \n" << endl;
      int test;
      cin >> test;
      if (test == 0) {
        cin.clear();
        cin.ignore();
        stock.refill_info(qty);
        getch();
      } else {
        cin.clear();
        cin.ignore();
        cout << "No changes to settelement.";
        getch();

      }
      system("cls");

      disp_settlement();
      getch();

      i++;
      break;
    }
  }
  if (i != 1) {
    cout << "\n\n!!Record not found!!\nPress any key to continue.";
    fio.close();
    getch();
    cin.clear();
    cin.ignore();
    goto refillsearch;
  }

}
void rmv() {
  system("cls");
  disp_boss();
  int i(0);
  char temp[20];
  cout << "\nDelete Instance";
  cout << "\n\nEnter the name of the product:";
  cin.ignore();
  cin.clear();
  cin.get(temp, 20);
  fout.open("temp.dat", ios::binary);
  fin.open("stock.dat", ios::binary);
  while (!fin.eof()) {

    fin.read((char * ) & stock, sizeof(stock));

    if (!fin.eof()) {
      if (stock.name_cmp(temp) == 0) {
        cout << stock;
        cout << "\n\nInstance deleted.";
        i++;
      } else {
        fout.write((char * ) & stock, sizeof(stock));
      }
    }
  }
  if (i == 0) {
    cout << "\n\n!!Record not found!!";
    getch();
  }
  fin.close();
  fout.close();
  remove("stock.dat");
  rename("temp.dat", "stock.dat");
}
