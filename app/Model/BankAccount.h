#ifndef INCLUDED_BANKACCOUNT_H
#define INCLUDED_BANKACCOUNT_H

#ifndef INCLUDED_CLIENTE_H
   #include "Client.h"
#endif

class BankAccount
{
public:
   ~BankAccount()= default;
   BankAccount(unsigned _id, int _balance,Client& _owner) : id(_id), balance(_balance), owner(_owner) { }
   
   unsigned getId(); //Getters
   int getBalance();
   int getConsBalance() const;
   Client& getOwner();

   void cashOut(unsigned value);
   void deposit(unsigned value);

private:
   Client& owner;
   unsigned id;
   int balance;
};

#endif // INCLUDED_BANKACCOUNT_H