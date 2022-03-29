#include <iostream>

#include "stock.h"


using namespace std;

int main() {
  char pass[9], pass2[8];
  int i, j;
  cout << "\n\n \t\t\t --------- WELCOME TO STOCK MANAGEMENT SYSTEM --------- \n \t\t\t --------- PLEASE USE IN FULL-SCREEN MODE --------- \n \t\t\t     --------- PRESS ANY KEY TO CONTINUE --------- ";
  getch();
  system("cls");
  mainmenu:
    cout << "\n --------- STOCK MANAGEMENT SYSTEM --------- \n\n\n\n\t   1. Boss menu\n\n\t   2. Client menu\n\n\t   3. Employee menu\n\n\t   4. Close program \n\n\n\nType in number of Your Choice and press Enter:";
  cin >> j;
  if (j == 1) //BOSS MENU
  {
    system("cls");
    cout << "\nEnter the password: ";

    for (int z = 0; z < 8; z++) {
      pass[z] = getch();
      system("cls");
      cout << "\nEnter the password: ";
      for (i = 1; i <= (z + 1); i++) {
        cout << "*";
      }
    }
    if (strcmp(pass, "bosspass") == 0) {
      bossmenu: system("cls");
      cout << "\n --------- BOSS MENU --------- \n\n\n\n\t   1. Add new product\n\n\t   2. Display stock\n\n\t   3. Refill\n\n\t   4. Remove item\n\n\t   5. Main menu\n\n\t   6. Fix settlement\n\n\t   7. Display settlement \n\n\n\nType in number of Your Choice and press Enter:";
      cin >> i;
      if (i == 1) {
        addnew();
        getch();
        goto bossmenu;
      } else if (i == 2) {
        system("cls");
        disp_boss();
        getch();
        goto bossmenu;
      } else if (i == 3) {
        refill();
        goto bossmenu;
      } else if (i == 4) {
        rmv();
        getch();
        goto bossmenu;
      } else if (i == 5) {
        system("cls");
        goto mainmenu;
      } else if (i == 6) {
        fix_settlement();
        getch();
        system("cls");
        goto bossmenu;
      } else if (i == 7) {
        disp_settlement();
        getch();
        system("cls");
        goto bossmenu;
      } else {
        cout << "\nWrong input.\n";
        cin.clear();
        cin.ignore();
        goto bossmenu;
      }
    }
    else {
      cout << "\nACCES DENIED !!\nPress any key to continue.";
      getch();
      system("cls");
      goto mainmenu;
    }
  }
  if (j == 2) {
    custmenu: system("cls");
    cout << "\n --------- CLIENT MENU --------- \n\n\n\n\t   1. Buy\n\n\t   2. Display stock\n\n\t   3. Exit\n\n\n\nType in number of Your Choice and press Enter:";
    cin >> i;

    if (i == 1) {
      sell();
      getch();
      goto custmenu;
    } else if (i == 2) {
      system("cls");
      disp();
      getch();
      goto custmenu;
    } else if (i == 3) {
      system("cls");
      cin.clear();
      cin.ignore();
      goto mainmenu;
    } else {
      system("cls");
      cout << "\n\n \t\t\t\t --------- WRONG INPUT --------- \n \t\t\t  --------- PRESS ANY KEY TO CONTINUE --------- ";
      cin.clear();
      cin.ignore();
      getch();
      system("cls");
      goto mainmenu;
    }

  }
  if (j == 3)

  {
    system("cls");
    cout << "\nEnter the password: ";

    for (int z = 0; z < 7; z++) {
      pass2[z] = getch();
      system("cls");
      cout << "\nEnter the password: ";
      for (i = 1; i <= (z + 1); i++) {
        cout << "*";
      }
    }
    if (strcmp(pass2, "emppass") == 0) {
      empmenu: system("cls");
      cout << "\n --------- EMPLOYE MENU --------- \n\n\n\n\t   1. Display stock\n\n\t   2. Refill\n\n\t   3. Exit\n\n\t   4. Sell\n\n\n\nType in number of Your Choice and press Enter:";
      cin >> i;
      if (i == 1) {
        system("cls");
        disp();
        getch();
        goto empmenu;
      } else if (i == 2) {
        refill();
        goto empmenu;
      } else if (i == 3) {
        system("cls");
        cin.clear();
        cin.ignore();
        goto mainmenu;

      } else if (i == 4) {
        sell();
        cin.clear();
        cin.ignore();
        getch();
        system("cls");
        goto empmenu;
      } else {
        system("cls");
        cout << "\n\n \t\t\t\t --------- WRONG INPUT --------- \n \t\t\t  --------- PRESS ANY KEY TO CONTINUE --------- ";
        cin.clear();
        cin.ignore();
        getch();
        system("cls");
        goto mainmenu;
      }
    }
    else {
      cout << "\nACCES DENIED !!\nPress any key to continue.";
      getch();
      system("cls");
      goto mainmenu;
    }

  }
  if (j == 4) {
    system("cls");
    exit(0);
  } else {
    system("cls");
    cout << "\n\n \t\t\t\t --------- WRONG INPUT --------- \n \t\t\t  --------- PRESS ANY KEY TO CONTINUE --------- ";
    cin.clear();
    cin.ignore();

    getch();
    system("cls");
    goto mainmenu;

  }

  getch();

}
