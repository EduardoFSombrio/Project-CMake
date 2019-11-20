#include "MainView.h"
#include <iostream>

//////////////////////////////////////////////////////////////////////////////// Lists

unsigned MainView::showMainView()
{
   unsigned resp = 0;

   while(true) {
      system("cls");
      std::cout << "    ---MENU---\n   Chose an option\n\n   (1)Manage Lists\n   (2)View Lists\n   (3)Exit program\n" << std::endl;
      std::cin >> resp;
      if ((resp < 4) && (resp != 0)) 
         return resp;

      system("cls");
      std::cout << "Not a valid answer, please try again" << std::endl;
   } 
}

unsigned MainView::showManageLists()
{
   unsigned resp = 0;

   while (true) {
      std::cout << "  ---MENU Manage Lists---\n   Chose an option\n\n   (1)Add new Client\n   (2)Add new Client by Position\n   (3)Remove Client\n   (4)Clear List\n   (5)Exit\n" << std::endl;
      std::cin >> resp;
      if ((resp < 6) && (resp != 0))
         return resp;

      system("cls");
      std::cout << "Not a valid answer, please try again \n\n" << std::endl;
   }
}

unsigned MainView::showViewLists()
{
   unsigned resp = 0;

   while(true) {
      std::cout << "  ---MENU View Lists---\n   Chose an option\n\n   (1)Show Client List\n   (2)Show Client List Backwards\n   (3)Show BankAccount List\n   (4)Show BankAccount List Backwards\n   (5)Sort Client List\n   (6)Sort BankAccount List\n   (7)Concatenate\n   (8)Exit" << std::endl;
      std::cin >> resp;
      if ((resp < 9) && (resp != 0))
         return resp;

      system("cls");
      std::cout << "Not a valid answer, please try again \n\n" << std::endl;
   }
}

//////////////////////////////////////////////////////////////////////////////// ShowList

void MainView::showList(const std::string& list)
{
   std::cout << list;
}

//////////////////////////////////////////////////////////////////////////////// Adders & Removers

void MainView::clearList()
{
   std::cout << "\n\nList Clear\n\n\n";
}

unsigned MainView::removeClientByPosition()
{
   unsigned _position;

   std::cout << "Position: ";
   std::cin >> _position;
   return _position;
}

void MainView::addClientAndBankAccount(std::string& _name, unsigned& _rg, unsigned& _age, unsigned& _id, int& _balance)
{
   system("cls");
   std::cout << "Name:  ";
   std::cin >> _name;
   std::cout << "RG:  ";
   std::cin >> _rg;
   std::cout << "Age:  ";
   std::cin >> _age;
   std::cout << "Id:  ";
   std::cin >> _id;
   std::cout << "Balance:  ";
   std::cin >> _balance;
   system("cls");
}

void MainView::addClientAndBankAccountByPosition(unsigned& _position, std::string& _name, unsigned& _rg, unsigned& _age, unsigned& _id, int& _balance)
{
   system("cls");
   std::cout << "Position: ";
   std::cin >> _position;
   std::cout << "Name:  ";
   std::cin >> _name;
   std::cout << "RG:  ";
   std::cin >> _rg;
   std::cout << "Age:  ";
   std::cin >> _age;
   std::cout << "Id:  ";
   std::cin >> _id;
   std::cout << "Balance:  ";
   std::cin >> _balance;
   system("cls");
}

//////////////////////////////////////////////////////////////////////////////// 