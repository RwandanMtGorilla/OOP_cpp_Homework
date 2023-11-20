// Chapter 9 of C++ How to Program
// truck.cpp
#include "truck.h"

// Truck's constructor
Truck::Truck( double initialFuel )
   : Vehicle( 2, 8, "red", initialFuel, 6 ), cargo(false)
{
   setClassName( "Truck" );
}


// function hasCargo definition
bool Truck::hasCargo() const
{
   return cargo;

} // end function hasCargo

// function setCargo definition
void Truck::setCargo( bool c ) 
{
   cargo = c;

} // end function setCargo

// function operator<< definition
ostream &operator<<( ostream &output, const Truck &t )
{
   output << t.getClassName() << "\n"
          << "\tNumber of doors: " 
          << t.getNumberOfDoors()
          << "\n\tNumber of cylinders: " 
          << t.getNumberOfCylinders()
          << "\n\tTransmission type: " 
          << t.getTransmissionType()
          << "\n\tColor: " << t.getColor()
          << "\n\tFuel level: " 
          << t.getFuelLevel() << "\n";

   if ( t.cargo )
      output << "\tThe truck is carrying cargo.\n";

   else
      output << "\tThe truck is not carrying cargo.\n";

   return output;

} // end function operator<<

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

