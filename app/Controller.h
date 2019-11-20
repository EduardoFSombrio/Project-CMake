#ifndef INCLUDED_CONTROLLER_H
#define INCLUDED_CONTROLLER_H

#ifndef INCLUDED_MEMORY_H
#define INCLUDED_MEMORY_H
   #include <memory>
#endif 

#ifndef INCLUDED_LISTBANKACCOUNT_H
   #include "ListBankAccount.h"
#endif
#ifndef INCLUDED_LISTCLIENT_H
   #include "ListClient.h"
#endif

class Controller
{
public:
   ~Controller() {}
   Controller() {}

   std::vector<Client*> getClientList();  //// Getters
   std::vector<Client*> getClientListBackwards();
   std::vector<BankAccount*> getBankAccountList();
   std::vector<BankAccount*> getBankAccountListBackwards();

   std::vector<Client*> sortClientList(); /// Sort
   std::vector<BankAccount*> sortBankAccount();

   void clearList();  //// Add & Remove
   bool removeByPosition(unsigned _position);
   bool addClientAndBankAccountByPosition(unsigned _position, std::string _name, unsigned _rg, unsigned _age, unsigned _id, int _balance);

   //std::string PrintClientListFirst(); //// X
   //std::string PrintBankAccountListFirst(); //// X
   //std::string PrintClientListLast(); ///// X
   //std::string PrintBankAccountListLast();  //// X
   //std::string sortClientListByName(); //// X
   //std::string sortBankAccountbyBalance(); //// X
   //std::string concatenateLists(); //// X

private:
   ListClient listClient;
   ListBankAccount listBankAccount;

};
#endif // INCLUDED_CONTROLLER_H
