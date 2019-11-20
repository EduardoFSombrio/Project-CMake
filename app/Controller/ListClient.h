#ifndef INCLUDED_LISTCLIENT_H
#define INCLUDED_LISTCLIENT_H

#ifndef INCLUDED_VECTOR_H
#define INCLUDED_VECTOR_H
   #include <vector>
#endif 

#ifndef INCLUDED_CLIENTE_H
   #include "Client.h"
#endif

class ListClient
{
public:
   class ClientCell
   {
   public:
      ~ClientCell()= default;
      ClientCell(Client* _currentClient) : currentClient(_currentClient) {};
      ClientCell(Client* _currentClient, ClientCell* _nextCell, ClientCell* _previousCell) : currentClient(_currentClient), nextCell(_nextCell), previousCell(_previousCell) { }

      ClientCell* getNextCell(); // getters & setters
      Client* getCurrentClient();
      ClientCell* getPreviousCell();
      void setNextCell(ClientCell* _Next);
      void setPreviousCell(ClientCell* _Previous);
      //Client* getConsCurrentClient() const;

private:
      Client* currentClient;
      ClientCell* nextCell;
      ClientCell* previousCell;
   };

public:
   ~ListClient();
   ListClient();

   void clearList(); //adders & removers
   void removeClient(unsigned position);
   void addClient(std::string _name, unsigned _rg, unsigned _age);
   void addClientPosition(unsigned position, std::string _name, unsigned _rg, unsigned _age);

   unsigned getTotal(); // getters
   std::vector<Client*> getList();
   std::vector<Client*> getListBackwards(); 
   Client* getClient(const unsigned& _position); 

private:
   unsigned total;
   ClientCell* firstCell;
   ClientCell* lastCell;

   ClientCell* getLastClientCell(); //Cell's getters
   ClientCell* getFirstClientCell();
   unsigned getPosition(ClientCell* positionCell);
   ClientCell* getCellByPosition(unsigned position);
};

#endif // INCLUDED_LISTCLIENT_H