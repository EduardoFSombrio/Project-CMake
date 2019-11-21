#ifndef INCLUDED_COMMANDAPP_H
#define INCLUDED_COMMANDAPP_H

#ifndef INCLUDED_MAINVIEW_H
   #include "MainView.h"
#endif
#ifndef INCLUDED_CONTROLLER_H
   #include "Controller.h"
#endif

class CommandApp
{
public:
   CommandApp(Controller& _control,MainView& _view) : control(_control),view(_view) {}

   virtual void execute()= 0;

protected:
   MainView& view;
   Controller& control;
};

#endif //INCLUDED_COMMANDAPP_H