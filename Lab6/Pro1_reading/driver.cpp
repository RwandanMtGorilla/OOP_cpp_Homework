// Chapter 9 of C++ How to Program
// driver for inheritance hierarchy
#include <iostream>

using std::cout;
using std::endl;

#include "vehicle.h"
#include "taxi.h"
#include "truck.h"

int main()
{
   Vehicle car( 2, 6, "blue", 14.6, 3 );
   Taxi cab( 3.3 );
   Truck mack( 7.54 );

   mack.setCargo(true);

   // Print all objects in the Vehicle hierarchy
   cout << car << endl;
   cout << cab << endl;
   cout << mack << endl;


   return 0;

} // end main

/**************************************************************************
 * (C) Copyright 1992-2003 by Deitel & Associates, Inc. and Prentice      *
 * Hall. All Rights Reserved.                                             *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 *************************************************************************/

