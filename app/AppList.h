#ifndef INCLUDED_APPLIST_H
#define INCLUDED_APPLIST_H

#ifndef INCLUDED_IOSTREAM_H
#define INCLUDED_IOSTREAM_H
   #include <iostream>
#endif 

#ifndef INCLUDED_MAINVIEW_H
   #include "MainView.h"
#endif
#ifndef INCLUDED_CONTROLLER_H
   #include "Controller.h"
#endif
#ifndef INCLUDED_COMMANDAPP_H
   #include "CommandApp.h"
#endif

class AppList
{
public:
   ~AppList()= default;

   void run();

private:
   MainView view;
   Controller control;
   
   void startMainWindow();
};

#endif //INCLUDED_APPLIST_H