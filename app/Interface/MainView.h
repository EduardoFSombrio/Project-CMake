#ifndef INCLUDED_MAINVIEW_H
#define INCLUDED_MAINVIEW_H

#ifndef INCLUDED_STDSTRING_h
#define INCLUDED_STDSTRING_H
   #include <string>
#endif 

class MainView
{
public:
   MainView() {}

   unsigned showMainView(); //Lists
   unsigned showManageLists();
   unsigned showViewLists();

   void showList(const std::string& list); //ShowList

   void clearList(); // Adders & Removers
   unsigned removeClientByPosition();
   void addClientAndBankAccount(std::string& _name, unsigned& _rg, unsigned& _age, unsigned& _id, int& _balance);
   void addClientAndBankAccountByPosition(unsigned& _position, std::string& _name, unsigned& _rg, unsigned& _age, unsigned& _id, int& _balance);

};

#endif // INCLUDED_MAINVIEW_H