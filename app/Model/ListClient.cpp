#include "ListClient.h"
#include <iostream>

/////////////////////////////////////////////////////////////////////////////// CLIENTCELL 

ListClient::ClientCell* ListClient::ClientCell::getNextCell()
{
   return nextCell;
}

Client* ListClient::ClientCell::getCurrentClient()
{
   return currentClient;
}

ListClient::ClientCell* ListClient::ClientCell::getPreviousCell()
{
   return previousCell;
}

void ListClient::ClientCell::setNextCell(ClientCell* _next)
{
   nextCell= _next;
}

void ListClient::ClientCell::setPreviousCell(ClientCell* _previous)
{
   previousCell= _previous;
}

//Client* ListClient::ClientCell::getConsCurrentClient() const
//{
//   return currentClient;
//}

/////////////////////////////////////////////////////////////////////////////// LISTCLIENT

ListClient::~ListClient()
{
   delete firstCell;
   delete lastCell;
}

ListClient::ListClient()
{ 
   total= 0;
   firstCell= nullptr;
   lastCell= nullptr;
}

///////////////////////////////////////////////////////////////////////////////  adders & removers

void ListClient::addClient(std::string _name, unsigned _rg, unsigned _age)
{
   Client* newClient = new Client(_name, _rg, _age);
   ListClient::ClientCell* newCell = new ListClient::ClientCell(newClient, firstCell, lastCell);
   if (getTotal() == 0){
      firstCell = newCell;
      lastCell = newCell;
      }
   firstCell->setPreviousCell(newCell);
   lastCell->setNextCell(newCell);
   firstCell = newCell;
   total++;
}

void ListClient::addClientPosition(unsigned position, std::string _name, unsigned _rg, unsigned _age)
{
   if (position == 0) 
      addClient(_name, _rg, _age); 
   else if (position > getTotal()) 
      throw std::range_error("Position not found");
   else {
      ListClient::ClientCell* chainCell = firstCell;
      for (unsigned i= 0; i < position; i++)
      {
         chainCell= chainCell->getNextCell();
      }
      Client* newClient= new Client(_name, _rg, _age);
      ListClient::ClientCell* newCell= new ListClient::ClientCell(newClient, chainCell, chainCell->getPreviousCell());
      chainCell->getPreviousCell()->setNextCell(newCell);
      chainCell->setPreviousCell(newCell);
      total++;
   }
}

void ListClient::removeClient(unsigned position)
{
   if (position > getTotal() || getTotal() == 0) { 
      throw std::range_error("Position not found");
   }
   else {
      ListClient::ClientCell* eliminated= getCellByPosition(position);
      ListClient::ClientCell* previous= eliminated->getPreviousCell();
      ListClient::ClientCell* next= eliminated->getNextCell();
      next->setPreviousCell(eliminated->getPreviousCell());
      previous->setNextCell(eliminated->getNextCell());

      //Caso adicione apenas 1 e depois tente remover, ele entra nos 2 ifs
      if (position == getTotal()) 
         lastCell = previous; 
      if (position == 0) 
         firstCell= next; 

      delete eliminated->getCurrentClient();
      delete eliminated;
      total--;
   }
}

void ListClient::clearList()
{
   unsigned c = getTotal();
   for (unsigned i = 0; i < getTotal(); i++) {
      c--;
      delete (getCellByPosition(c)->getCurrentClient());
      delete (getCellByPosition(c));
   }
   firstCell = nullptr;
   lastCell = nullptr;
   total = 0; 
}

/////////////////////////////////////////////////////////////////////////////// getters

unsigned ListClient::getTotal() 
{ 
   return total; 
}

std::vector<Client*> ListClient::getList()
{
   std::vector<Client*> clientList;
   ListClient::ClientCell* cell = getFirstClientCell();

   for (unsigned i= 0; i < getTotal(); i++) {
      clientList.push_back(cell->getCurrentClient());
      cell = cell->getNextCell();
   }
   return clientList;
}
std::vector<Client*> ListClient::getListBackwards()
{
   std::vector<Client*> clientList;
   ListClient::ClientCell* cell = getLastClientCell();

   for (unsigned i= 0; i < getTotal(); i++) {
      clientList.push_back(cell->getCurrentClient());
      cell = cell->getPreviousCell();
   }
   return clientList;
}

Client* ListClient::getClient(const unsigned& _position)
{
	return getCellByPosition(_position)->getCurrentClient();
}

/////////////////////////////////////////////////////////////////////////////// Cell's getters

ListClient::ClientCell* ListClient::getFirstClientCell()
{ 
   return firstCell; 
}
ListClient::ClientCell* ListClient::getLastClientCell() 
{ 
   return lastCell; 
}

unsigned ListClient::getPosition(ListClient::ClientCell* positionCell)
{ 
   ListClient::ClientCell* chainCell = firstCell;
	bool condition= false;
	unsigned position= 1; 
	for (unsigned i= 0; i <= getTotal(); i++) {
		if (chainCell == positionCell) 
      {
         condition= true;
         position= i;
		}
      chainCell= chainCell->getNextCell();
	}
   if (condition == false) 
      throw std::range_error("Position not found");
	return position; 
}

ListClient::ClientCell* ListClient::getCellByPosition(unsigned position)
{
	if(position >= getTotal())
	{
      throw std::range_error("Cell not found");
		return firstCell;
	}
	else 
	{
      ListClient::ClientCell* chainCell = firstCell;
		for (unsigned i= 0; i < position; i++) 
         chainCell= chainCell->getNextCell();
		return chainCell;
	}
}

///////////////////////////////////////////////////////////////////////////////
