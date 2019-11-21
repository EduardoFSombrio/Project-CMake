#include "CommandEditWindow.h"

void CommandEditWindow::execute()
{
   enum commands2 { ADD= 1, ADD_BY_POSITION, REMOVE, CLEAR, RETURN };

   while (true) {
      unsigned op= view.showManageLists();
      switch (op) {
      case ADD:             addClientAndBankAccount(); break;
      case ADD_BY_POSITION: addClientAndBankAccountByPosition(); break;
      case REMOVE:          removeClientByPosition(); break;
      case CLEAR:           clearList(); break;
      case RETURN:          return;
      }
   }
}

//////////////////////////////////////////////////////////////////////////////// Adders

void CommandEditWindow::addClientAndBankAccount()
{
   unsigned position= 0;
   std::string name;
   unsigned rg;
   unsigned age;
   unsigned id;
   int balance;

   view.addClientAndBankAccount(name, rg, age, id, balance);
   control.addClientAndBankAccountByPosition(position, name, rg, age, id, balance);
}

void CommandEditWindow::addClientAndBankAccountByPosition()
{
   unsigned position;
   std::string name;
   unsigned rg;
   unsigned age;
   unsigned id;
   int balance;

   view.addClientAndBankAccountByPosition(position, name, rg, age, id, balance);
   control.addClientAndBankAccountByPosition(position, name, rg, age, id, balance);
}

//////////////////////////////////////////////////////////////////////////////// Removers

void CommandEditWindow::removeClientByPosition()
{
   unsigned position;
   position= view.removeClientByPosition();
   bool wasDelete= control.removeByPosition(position);

   if (wasDelete == true)
      view.showList("\n\n\n\n Removed suceffuly \n\n\n\n");
   else
      view.showList("\n\n\n\n Position not found! \n\n\n\n");
}

void CommandEditWindow::clearList()
{
   control.clearList();
   view.showList("\n\nList Clear\n\n\n");
}

////////////////////////////////////////////////////////////////////////////////