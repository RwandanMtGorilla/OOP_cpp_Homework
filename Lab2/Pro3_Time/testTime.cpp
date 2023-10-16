// testTime.cpp
#include <iostream> 

using std::cout; 
using std::endl; 

#include "time.h"

const int MAX_TICKS = 200;

int main()
{
   Time t;

   t.setTime( 23, 59, 57 );

   for ( int ticks = 1; ticks < MAX_TICKS; ++ticks ) {
      t.printStandard();
      cout << endl;
      t.tick();

   } // end for

   return 0;

} // end main
