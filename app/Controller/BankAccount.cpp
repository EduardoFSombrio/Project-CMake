#include "BankAccount.h"
#include <iostream>

//////////////////////////////////////////////////////////////////////////////// Getters

unsigned BankAccount::getId()
{
   return id;
}
int BankAccount::getBalance()
{ 
   return balance; 
}
int BankAccount::getConsBalance() const
{
   return balance;
}
Client& BankAccount::getOwner() 
{ 
   return owner; 
}
////////////////////////////////////////////////////////////////////////////////

void BankAccount::cashOut(unsigned value)
{
   if ((balance- value) < 0) 
      throw std::range_error("Value not valid");
   else
      balance-= value; 
}

void BankAccount::deposit(unsigned value)
{ 
   balance+= value; 
}

////////////////////////////////////////////////////////////////////////////////
