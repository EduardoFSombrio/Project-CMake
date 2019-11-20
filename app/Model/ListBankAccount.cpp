#include "ListBankAccount.h"
#include <iostream>


//////////////////////////////////////////////////////////////////////////////// BANKACCOUNTCELL

ListBankAccount::BankAccountCell::BankAccountCell(BankAccount* _current)
{
   currentBankAccount= _current;
   nextBankAccount= nullptr;
   previousBankAccount= nullptr;
}

ListBankAccount::BankAccountCell::BankAccountCell(BankAccount* _current, BankAccountCell* _nextCell, BankAccountCell* _previousCell)
{
   currentBankAccount= _current;
   nextBankAccount= _nextCell;
   previousBankAccount= _previousCell;
}

//////////////////////////////////////////////////////////////////////////////// Getters & Setters

ListBankAccount::BankAccountCell* ListBankAccount::BankAccountCell::getNextCell()
{
   return nextBankAccount;
}

ListBankAccount::BankAccountCell* ListBankAccount::BankAccountCell::getPreviousCell()
{
   return previousBankAccount;
}

BankAccount* ListBankAccount::BankAccountCell::getCurrentBankAccount()
{
   return currentBankAccount;
}

void ListBankAccount::BankAccountCell::setNextCell(BankAccountCell* _Next)
{
   nextBankAccount = _Next;
}

void ListBankAccount::BankAccountCell::setPreviousCell(BankAccountCell* _Previous)
{
   previousBankAccount = _Previous;
}

//BankAccount* ListBankAccount::BankAccountCell::getConsCurrentBankAccount() const
//{
//   return currentBankAccount;
//}

//////////////////////////////////////////////////////////////////////////////// LISTBANKACCOUNT

ListBankAccount::~ListBankAccount()
{
   delete first;
   delete last;
}

ListBankAccount::ListBankAccount()
{
   total= 0;
   first= nullptr;
   last= nullptr;
}

//////////////////////////////////////////////////////////////////////////////// Adders & Removers

void ListBankAccount::clearList()
{
   unsigned c= getTotal();

   for (unsigned i= 0; i < getTotal(); i++) {
      c--;
      delete (getCellByPosition(c)->getCurrentBankAccount());
      delete (getCellByPosition(c));
   }
   first= nullptr;
   last= nullptr;
   total= 0;
}

void ListBankAccount::removeBankAccount(unsigned position)
{
   if (position > getTotal() || getTotal() == 0)
      throw std::range_error("Position not found");
   else
   {
      BankAccountCell* eliminated= getCellByPosition(position);
      BankAccountCell* previous= eliminated->getPreviousCell();
      BankAccountCell* next= eliminated->getNextCell();
      next->setPreviousCell(eliminated->getPreviousCell());
      previous->setNextCell(eliminated->getNextCell());

      //Caso adicione apenas 1 e depois tente remover, ele entra nos 2 ifs
      if (position == getTotal())
         last= previous;
      if (position == 0)
         first= next;

      delete eliminated->getCurrentBankAccount();
      delete eliminated;
      total--;
   }
}

void ListBankAccount::addBankAccount(unsigned _id, int _balance, Client& owner)
{
   if (getTotal() == 0) {
      BankAccount* newBankAccount= new BankAccount(_id, _balance, owner);
      BankAccountCell* newCell= new BankAccountCell(newBankAccount);

      newCell->setNextCell(newCell);
      newCell->setPreviousCell(newCell);
      first= newCell;
      last= newCell;
   }
   else {
      BankAccount* newBankAccount = new BankAccount(_id, _balance, owner);
      BankAccountCell* newCell = new BankAccountCell(newBankAccount, first, last);

      first->setPreviousCell(newCell);
      last->setNextCell(newCell);
      first= newCell;
   }
   total++;
}

void ListBankAccount::addBankAccountPosition(unsigned position, unsigned _id, int _balance, Client& _owner)
{
   if (position != 0) {
      if (position > getTotal()) {
         throw std::range_error("Position not found");
      }
      else {
         BankAccountCell* chainCell= first;

         for (unsigned i= 0 ; i < position ; i++) 
            chainCell= chainCell->getNextCell();

         BankAccount* newBankAccount= new BankAccount(_id, _balance, _owner);
         BankAccountCell* newCell= new BankAccountCell(newBankAccount, chainCell, chainCell->getPreviousCell());

         chainCell->getPreviousCell()->setNextCell(newCell);
         chainCell->setPreviousCell(newCell);
         total++;
      }
   }
   else
      addBankAccount(_id, _balance, _owner);
}

//////////////////////////////////////////////////////////////////////////////// Getters

unsigned ListBankAccount::getTotal() { 
   return total; 
}

std::vector<BankAccount*> ListBankAccount::getList() {
   std::vector<BankAccount*> accountList;
   ListBankAccount::BankAccountCell* cell= getFirstBankAccountCell();

   for (unsigned i= 0; i < getTotal(); i++) {
      accountList.push_back(cell->getCurrentBankAccount());
      cell= cell->getNextCell();
   }
   return accountList;
}

std::vector<BankAccount*> ListBankAccount::getListBackwards() {
   std::vector<BankAccount*> accountList;
   ListBankAccount::BankAccountCell* cell= getLastBankAccountCell();

   for (unsigned i= 0; i < getTotal(); i++) {
      accountList.push_back(cell->getCurrentBankAccount());
      cell= cell->getPreviousCell();
   }
   return accountList;
}

BankAccount* ListBankAccount::getAccount(const unsigned& _position) {
   return getCellByPosition(_position)->getCurrentBankAccount();
}


//////////////////////////////////////////////////////////////////////////////// Cell's Getters

ListBankAccount::BankAccountCell* ListBankAccount::getFirstBankAccountCell() {
   return first;
}
ListBankAccount::BankAccountCell* ListBankAccount::getLastBankAccountCell() {
   return last;
}

unsigned ListBankAccount::getPosition(BankAccountCell* positionCell)
{  
   BankAccountCell* chainCell= first;
   bool condition= false;
   unsigned position= 1;

   for (unsigned i= 0; i <= getTotal(); i++) {
      if (chainCell == positionCell) {
         condition = true;
         position = i;
      }
      chainCell = chainCell->getNextCell();
   }
   if (condition == false) 
      throw std::range_error("Position not found");
   return position;
}

ListBankAccount::BankAccountCell* ListBankAccount::getCellByPosition(unsigned position) {
   if (position >= getTotal()) {
      throw std::range_error("Cell not found");
      return first;
   }
   else {
      BankAccountCell* chainCell = first;
      for (unsigned i= 0; i < position; i++)
         chainCell= chainCell->getNextCell();

      return chainCell;
   }
}
