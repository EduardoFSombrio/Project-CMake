#ifndef INCLUDED_COMMANDEDITWINDOW_H
#define INCLUDED_COMMANDEDITWINDOW_H

#ifndef INCLUDED_COMMANDAPP_H
   #include "CommandApp.h"
#endif

class CommandEditWindow : public CommandApp
{
public:
   using CommandApp::CommandApp;

   void execute();

protected:
   void addClientAndBankAccount(); // adders
   void addClientAndBankAccountByPosition();

   void removeClientByPosition(); // removers
   void clearList();
};
#endif //INCLUDED_COMMANDEDITWINDOW_H
