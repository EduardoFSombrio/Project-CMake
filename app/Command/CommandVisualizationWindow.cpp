#include "CommandVisualizationWindow.h"

void CommandVisualizationWindow::execute()
{
   enum commands3 { CLIENT_FIRST= 1, CLIENT_LAST, BANK_FIRST, BANK_LAST, SORT_CLIENT, SORT_BANK, CONCATENATE, RETURN };
   while (true) {
      unsigned op= view.showViewLists();
      switch (op) {
      case CLIENT_FIRST: view.showList(PrintClientListFirst()); break;
      case CLIENT_LAST:  view.showList(PrintClientListLast()); break;
      case BANK_FIRST:   view.showList(PrintBankAccountListFirst()); break;
      case BANK_LAST:    view.showList(PrintBankAccountListLast()); break;
      case SORT_CLIENT:  view.showList(sortClientList()); break;
      case SORT_BANK:    view.showList(sortBankAccountList()); break;
      case CONCATENATE:  view.showList(concatenateLists()); break;
      case RETURN:       return;
      }
   }
}

//////////////////////////////////////////////////////////////////////////////// Printers

std::string CommandVisualizationWindow::PrintClientListFirst()
{
   std::vector<Client*> listClient= control.getClientList();
   std::string list= "   List of Clients\n\n";

   for (Client* c : listClient)
      list += "   Name: " + c->getName() + "  Age: " + std::to_string(c->getAge()) + "  RG: " + std::to_string(c->getRg()) + "\n";

   list+= "\n\n   END OF LIST\n\n\n";
   return list;
}

std::string CommandVisualizationWindow::PrintClientListLast()
{
   std::vector<Client*> listClient= control.getClientListBackwards();
   std::string list= "   List of Clients Backwards\n\n";

   for (Client* c : listClient)
      list+= "   Name: " + c->getName() + "  Age: " + std::to_string(c->getAge()) + "  RG: " + std::to_string(c->getRg()) + "\n";

   list+= "\n\n   END OF LIST\n\n\n";
   return list;
}

std::string CommandVisualizationWindow::PrintBankAccountListFirst()
{
   std::vector<BankAccount*> listAccount= control.getBankAccountList();
   std::string list= "   List of Account\n\n";

   for (BankAccount* a : listAccount)
      list+= "   Owner: " + a->getOwner().getName() + "  ID: " + std::to_string(a->getId()) + "  Balance: " + std::to_string(a->getBalance()) + "\n";

   list+= "\n\n   END OF LIST\n\n\n";
   return list;
}

std::string CommandVisualizationWindow::PrintBankAccountListLast()
{
   std::vector<BankAccount*> listAccount= control.getBankAccountListBackwards();
   std::string list= "   List of Account Backwards\n\n";

   for (BankAccount* a : listAccount)
      list+= "   Owner: " + a->getOwner().getName() + "  ID: " + std::to_string(a->getId()) + "  Balance: " + std::to_string(a->getBalance()) + "\n";

   list+= "\n\n   END OF LIST\n\n\n";
   return list;
}

////////////////////////////////////////////////////////////////////////////////// Sortters

std::string CommandVisualizationWindow::sortBankAccountList()
{
   std::vector<BankAccount*> listSorted= control.sortBankAccount();
   std::string list;
   unsigned cont= 0;

   for (BankAccount* b : listSorted) {
      list += "   [" + std::to_string((++cont)) + "] ";
      list += "Name: " + b->getOwner().getName() + "  ";
      list += "ID: " + std::to_string(b->getId()) + "  ";
      list += "Balance: " + std::to_string(b->getBalance()) + "\n";
   }
   list+= "\n\n";
   return list;
}

std::string CommandVisualizationWindow::sortClientList()
{
   std::vector<Client*> listSorted= control.sortClientList();
   std::string list;
   unsigned cont= 0;

   for (Client* c : listSorted) {
      list += "   [" + std::to_string((++cont)) + "] ";
      list += "Name: " + c->getName() + "  ";
      list += "RG: " + std::to_string(c->getRg()) + "\n";
   }
   list+= "\n\n";
   return list;
}

////////////////////////////////////////////////////////////////////////////////// Concatenate

std::string CommandVisualizationWindow::concatenateLists()
{
   std::string list;
   std::vector<Client*> listClient= control.getClientList();
   std::vector<BankAccount*> listAccount= control.getBankAccountListBackwards();

   list+= "   Concatenate Lists \n\n\n";
   for (unsigned i= 0; i < listClient.size(); i++) {
      list += "Owner: " + listClient.at(i)->getName()
      + "   Balance: " + std::to_string(listAccount.at(i)->getBalance())
      + "\n\n";
   }
   list+= "\n\n   END OF LIST\n\n\n";
   return list;
}

////////////////////////////////////////////////////////////////////////////////