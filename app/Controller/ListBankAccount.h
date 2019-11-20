#ifndef INCLUDED_LISTBANKACCOUNT_H
#define INCLUDED_LISTBANKACCOUNT_H

#ifndef INCLUDED_VECTOR_H
#define INCLUDED_VECTOR_H
#include <vector>
#endif 

#ifndef INCLUDED_BANKACCOUNT_H
   #include "BankAccount.h"
#endif

class ListBankAccount
{
public:
   class BankAccountCell
   {
   public:
      ~BankAccountCell()= default;
      BankAccountCell(BankAccount* _current);
      BankAccountCell(BankAccount* _current, BankAccountCell* _nextCell, BankAccountCell* _previousCell);

      BankAccountCell* getNextCell(); // Getters & Setters
      BankAccountCell* getPreviousCell();
      BankAccount* getCurrentBankAccount();
      void setNextCell(BankAccountCell* _next);
      void setPreviousCell(BankAccountCell* _previous);
      //BankAccount* getConsCurrentBankAccount() const;

private:
      BankAccount* currentBankAccount;
      BankAccountCell* nextBankAccount;
      BankAccountCell* previousBankAccount;
   };

public:
   ~ListBankAccount();
   ListBankAccount();
   ListBankAccount(unsigned _Id, int _Balance, Client& _Owner) { addBankAccount(_Id, _Balance, _Owner); }

   void clearList(); // Adders & Removers
   void removeBankAccount(unsigned position);
   void addBankAccount(unsigned _Id, int _Balance, Client& _Owner);
   void addBankAccountPosition(unsigned position, unsigned _Id, int _Balance, Client& _Owner);

   unsigned getTotal(); // Getters
   std::vector<BankAccount*> getList();
   std::vector<BankAccount*> getListBackwards();
   BankAccount* getAccount(const unsigned& _position);

private:
   unsigned total;
   BankAccountCell* first;
   BankAccountCell* last;

   BankAccountCell* getFirstBankAccountCell(); //Cell's Getters
   BankAccountCell* getLastBankAccountCell();
   unsigned getPosition(BankAccountCell* positionCell);
   BankAccountCell* getCellByPosition(unsigned position);
};

#endif //INCLUDED_LISTBANKACCOUNT_H