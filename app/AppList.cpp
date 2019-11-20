#include "AppList.h"
#include "CommandEditWindow.h"
#include "CommandVisualizationWindow.h"

void AppList::run()
{
   startMainWindow();
}

void AppList::startMainWindow()
{
   enum commands1 { EDIT = 1, DISPLAY, RETURN };
   CommandApp* cmd= nullptr;
   
   while (true) {
      if (cmd) {
         delete cmd;
         cmd= nullptr;
      }
      unsigned op= view.showMainView();
      switch (op) {
      case EDIT:    cmd= new CommandEditWindow(control,view); break;
      case DISPLAY: cmd= new CommandVisualizationWindow(control,view); break;
      case RETURN:  control.clearList(); return;
      }
      if (cmd)
         cmd->execute();
   }
}
