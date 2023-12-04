// Chapter 10 of C++ How to Program
// truck.h
#ifndef TRUCK_H
#define TRUCK_H

#include <iostream>

#include "vehicle.h"

// class Truck definition
class Truck : public Vehicle {

public:
   Truck( double );

   bool hasCargo() const;
   void setCargo( bool );

   virtual void horn() const;
   virtual void print() const;
   virtual string getClassName() const;

private:
   bool cargo;

}; // end class Truck

#endif // TRUCK_H


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

