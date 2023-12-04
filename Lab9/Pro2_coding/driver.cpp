// Chapter 10 of C++ How to Program
// driver for vehicle
#include <iostream>

using std::cout;
using std::endl;

#include <vector>

using std::vector;

#include "vehicle.h"
#include "taxi.h"
#include "truck.h"

int main()
{
   Taxi cab( 3.3 );
   Truck mack( 7.54 );

   /* Write code to indicate that truck is carrying cargo */
   vector<Vehicle*> parkingLot(2);  // Declare the vector with size 2

   mack.setCargo(true);  // Indicate that the truck is carrying cargo
   /* Declare a vector, parkingLot, of base-class pointers */

   parkingLot[ 0 ] = &cab;
   parkingLot[ 1 ] = &mack;

   cout << "\nThe vehicles cannot get out of their parking spaces because of "
        << "traffic,\nso they respond: \n";

   for ( int i = 0; i < parkingLot.size(); i++ ) {

      /* Write code to call member function horn */

      parkingLot[i]->horn();  // Call horn function
      cout << endl;
      parkingLot[i]->print();  // Call print function
      cout << endl;
      /* Write code to display information about the vehicle honking its horn */


   } // end for

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
