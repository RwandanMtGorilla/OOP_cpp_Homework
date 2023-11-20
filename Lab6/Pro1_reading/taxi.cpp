// Chapter 9 of C++ How to Program
// taxi.cpp
#include "taxi.h"

// constructor
Taxi::Taxi( double f )
   : Vehicle( 4, 6, "yellow", f, 5 )
{
   customers = false;
   setClassName( "Taxi" );

} // end class Taxi constructor

void Taxi::setCustomers( bool hasCustomers )
{
   customers = hasCustomers;
}

// function hasCustomers definition
bool Taxi::hasCustomers() const
{
   return customers;
}

// function operator<< definition
ostream &operator<<( ostream &output, const Taxi &t )
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

   if ( t.hasCustomers() )
      output << "\tThe taxi has passengers.\n";

   else
      output << "\tThe taxi has no passengers.\n";

   return output;

} // end function operator


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
