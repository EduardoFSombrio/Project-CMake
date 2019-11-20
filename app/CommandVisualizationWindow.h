#ifndef INCLUDED_COMMANDVISUALIZATIONWINDOW_H
#define INCLUDED_COMMANDVISUALIZATIONWINDOW_H

#ifndef INCLUDED_COMMANDAPP_H
   #include "CommandApp.h"
#endif

class CommandVisualizationWindow : public CommandApp
{
public:
   using CommandApp::CommandApp;

   void execute();

protected:
   std::string PrintClientListFirst(); //Printers
   std::string PrintClientListLast();
   std::string PrintBankAccountListFirst();
   std::string PrintBankAccountListLast();

   std::string sortBankAccountList(); //Sortters
   std::string sortClientList();

   std::string concatenateLists(); //Concatenate
};
#endif//INCLUDED_COMMANDVISUALIZATIONWINDOW_H
