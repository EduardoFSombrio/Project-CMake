#include "Client.h"

//////////////////////////////////////////////////////////////////////////////// Setters

void Client::setRg(unsigned _rg)
{
   rg= _rg;
}

void Client::setAge(unsigned _age)
{
   age= _age;
}

void Client::setName(std::string _name)
{ 
   name= _name; 
}

//////////////////////////////////////////////////////////////////////////////// Getters

unsigned Client::getRg()
{
   return rg;
}

unsigned Client::getAge()
{
   return age;
}

std::string Client::getName() 
{ 
   return name; 
}

std::string Client::getConsName() const
{
   return name;
}
