#ifndef INCLUDED_CLIENT_H
#define INCLUDED_CLIENT_H

#ifndef INCLUDED_STDSTRING_H
#define INCLUDED_STDSTRING_H
   #include <string>
#endif 

class Client
{
public:
   ~Client() {}
   Client() : name(" "), rg(0), age(0) {}
   Client(std::string _name, unsigned _rg, unsigned _age) : name(_name), rg(_rg), age(_age) {}

   void setRg(unsigned _rg); //Getters
   void setAge(unsigned _age);
   void setName(std::string _name);

   unsigned getRg(); //Setters
   unsigned getAge();
   std::string getName();
   std::string getConsName() const;

private:
   std::string name;
   unsigned rg;
   unsigned age;
};

#endif // INCLUDED_CLIENT_H
