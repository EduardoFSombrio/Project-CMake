#include "Controller.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

//////////////////////////////////////////////////////////////////////////////// Getters

std::vector<Client*> Controller::getClientList()
{
   return listClient.getList();
}

std::vector<Client*> Controller::getClientListBackwards()
{
   return listClient.getListBackwards();
}

std::vector<BankAccount*> Controller::getBankAccountList()
{
   return listBankAccount.getList();
}

std::vector<BankAccount*> Controller::getBankAccountListBackwards()
{
   return listBankAccount.getListBackwards();
}

//////////////////////////////////////////////////////////////////////////////// Sort

bool wayToSortClientList(const Client* i, const Client* j)
{
   return i->getConsName() < j->getConsName();
};

std::vector<Client*> Controller::sortClientList()
{
   std::vector<Client*> list = getClientList();
   sort(list.begin(), list.end(), wayToSortClientList);
   return list;
}

bool wayToSortBankAccountList(const BankAccount* i, const BankAccount* j)
{
   return i->getConsBalance() > j->getConsBalance();
};

std::vector<BankAccount*> Controller::sortBankAccount()
{
   std::vector<BankAccount*> list = getBankAccountList();
   sort(list.begin(), list.end(), wayToSortBankAccountList);
   return list;
}

//////////////////////////////////////////////////////////////////////////////// Add & Remove

void Controller::clearList()
{
   if (listClient.getTotal() > 0) {
      listClient.clearList();
      listBankAccount.clearList();
   }
}

bool Controller::removeByPosition(unsigned _position)
{
   bool canRemove= false;

   if (_position <= listClient.getTotal()) {
      listClient.removeClient(_position);
      listBankAccount.removeBankAccount(_position);
      canRemove= true;
   }
   return canRemove;
}

bool Controller::addClientAndBankAccountByPosition(unsigned _position, std::string _name, unsigned _rg, unsigned _age, unsigned _id, int _balance)
{
   bool canAdd= false;

   if (_position <= listClient.getTotal()) {
      listClient.addClientPosition(_position, _name, _rg, _age);
      Client* c = listClient.getClient(_position);
      listBankAccount.addBankAccountPosition(_position, _id, _balance, *(c));
      canAdd= true;
   }
   return canAdd;
}

////////////////////////////////////////////////////////////////////////////////














//std::string Controller::PrintClientListFirst()
//{
//   std::string list = "   List of Clients\n\n";
//   ListClient::ClientCell* cell = listClient.getFirstClientCell();
//
//   for (unsigned i = 0; i < listClient.getTotal(); i++) {
//      Client& c = *cell->getCurrentClient();
//      list += "   Name: " + c.getName() + "  Age: " + std::to_string(c.getAge()) + "  RG: " + std::to_string(c.getRg()) + "\n";
//      cell = cell->getNextCell();
//   }
//   list += "\n\n   END OF LIST\n\n\n";
//   return list;
//}
//
//std::string Controller::PrintBankAccountListFirst()
//{
//   std::string list;
//   ListBankAccount::BankAccountCell* cell = listBankAccount.getFirstBankAccountCell();
//   list += "   List of BankAccount\n\n";
//   for (unsigned i = 0; i < listBankAccount.getTotal(); i++)
//   {
//      Client& c = cell->getCurrentBankAccount()->getOwner();
//      BankAccount& b = *cell->getCurrentBankAccount();
//      list += "   Owner: " + c.getName() + "  ID: " + std::to_string(b.getId()) + "  Balance: " + std::to_string(b.getBalance()) + "\n";
//      cell = cell->getNextCell();
//   }
//   list += "\n\n   END OF LIST\n\n\n";
//
//   return list;
//}
//
//std::string Controller::PrintClientListLast()
//{
//   std::string list;
//   ListClient::ClientCell* cell = listClient.getLastClientCell();
//   list += "   List of Clients backwards\n\n";
//   for (unsigned i = 0; i < listClient.getTotal(); i++)
//   {
//      Client& c = *cell->getCurrentClient();
//      list += "   Name: " + c.getName() + "  Age: " + std::to_string(c.getAge()) + "  RG: " + std::to_string(c.getRg()) + "\n";
//      cell = cell->getPreviousCell();
//   }
//   list += "\n\n   END OF LIST\n\n\n";
//
//   return list;
//}
//
//std::string Controller::PrintBankAccountListLast()
//{
//   std::string list;
//   ListBankAccount::BankAccountCell* cell = listBankAccount.getLastBankAccountCell();
//   list += "   List of BankAccount backwards\n\n";
//   for (unsigned i = 0; i < listBankAccount.getTotal(); i++)
//   {
//      Client& c = cell->getCurrentBankAccount()->getOwner();
//      BankAccount& b = *cell->getCurrentBankAccount();
//      list += "   Owner: " + c.getName() + "  ID: " + std::to_string(b.getId()) + "  Balance: " + std::to_string(b.getBalance()) + "\n";
//      cell = cell->getPreviousCell();
//   }
//   list += "\n\n   END OF LIST\n\n\n";
//   return list;
//}
//
//bool wayToSortClient(const ListClient::ClientCell* i, const ListClient::ClientCell* j)
//{
//   return i->getConsCurrentClient()->getName() < j->getConsCurrentClient()->getName();
//};
//
//std::string Controller::sortClientListByName()
//{
//   std::vector<ListClient::ClientCell*> vectorCell(listClient.getTotal());
//
//   std::string list;
//   ListClient::ClientCell* cell = listClient.getFirstClientCell();
//   list += "   Sort Client List\n\n";
//   for (unsigned i = 0; i < listClient.getTotal(); i++)
//   {
//      vectorCell[i] = cell;
//      cell = cell->getNextCell();
//   }
//
//   sort(vectorCell.begin(), vectorCell.end(), wayToSortClient);
//
//   unsigned cont = 0;
//   for (ListClient::ClientCell* n : vectorCell) {
//      list += "   [" + std::to_string((++cont)) + "] ";
//      list += "Name: " + n->getConsCurrentClient()->getName() + "  ";
//      list += "RG: " + std::to_string(n->getCurrentClient()->getRg()) + "\n";
//   }
//   list += "\n\n";
//   return list;
//}
//
//bool wayToSortBankAccount(const ListBankAccount::BankAccountCell* i, const ListBankAccount::BankAccountCell* j)
//{
//   return i->getConsCurrentBankAccount()->getBalance() > j->getConsCurrentBankAccount()->getBalance();
//};
//
//std::string Controller::sortBankAccountbyBalance()
//{
//
//   std::vector<ListBankAccount::BankAccountCell*> vectorCell(listBankAccount.getTotal());
//
//   std::string list;
//   ListBankAccount::BankAccountCell* cell = listBankAccount.getFirstBankAccountCell();
//   list += "   Sort List by Balance\n\n";
//   for (int i = 0; i < listBankAccount.getTotal(); i++)
//   {
//      vectorCell[i] = cell;
//      cell = cell->getNextCell();
//   }
//
//   sort(vectorCell.begin(), vectorCell.end(), wayToSortBankAccount);
//
//   unsigned cont = 0;
//   for (ListBankAccount::BankAccountCell* n : vectorCell) {
//      list += "   [" + std::to_string((++cont)) + "] ";
//      list += "Name: " + n->getConsCurrentBankAccount()->getOwner().getName() + "  ";
//      list += "ID: " + std::to_string(n->getCurrentBankAccount()->getId()) + "  ";
//      list += "Balance: " + std::to_string(n->getConsCurrentBankAccount()->getBalance()) + "\n";
//   }
//   list += "\n\n";
//   return list;
//}
//
//std::string Controller::concatenateLists()
//{
//   std::string list;
//   list += "   Concatenate Lists \n\n\n";
//   for (unsigned i = 0; i < listClient.getTotal(); i++) {
//      list += "Owner: " + listClient.getClient(i)->getName()
//         + "   Balance: " + std::to_string(listBankAccount.getCellByPosition(i)->getCurrentBankAccount()->getBalance())
//         + "\n\n";
//   }
//   list += "\n\n   END OF LIST\n\n\n";
//   return list;
//}