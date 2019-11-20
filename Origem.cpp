#include <stdlib.h>
#include <crtdbg.h>
#include <iostream>
#include "AppList.h"

int main() 
{
   _CrtMemState s1;
   _CrtMemCheckpoint(&s1);
 
   {
      AppList().run();
   }

   _CrtMemState s2;
   _CrtMemCheckpoint(&s2);

   _CrtMemState s3;
   if (_CrtMemDifference(&s3, &s1, &s2)) {
      std::cout << "\n!!!!!!!!\nBe careful, memory was leak\n";
      _CrtMemDumpStatistics(&s3);
   }
   else
      std::cout << "\n!!!!!!!!\nNo memory was lost!\n";

   return 0;
}
