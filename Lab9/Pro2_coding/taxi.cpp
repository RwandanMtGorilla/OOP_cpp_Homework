// Chapter 10 of C++ How to Program
// taxi.cpp
#include <iostream>

using std::cout;

#include "taxi.h"

// constructor
Taxi::Taxi( double fuel )
   : Vehicle( 4, 6, "yellow", fuel, 5 )
{
   customers = false;

} // end class Taxi constructor

// function setCustomers definition
void Taxi::setCustomers( bool c ) 
{
   customers = c;

} // end function setCustomers

// function hasCustomers definition
bool Taxi::hasCustomers() const 
{
   return customers;

} // end function hasCustomers

// function print definition
void Taxi::print() const
{

   Vehicle::print();

   if ( customers )
      cout << "\tThe taxi currently has passengers.\n";

   else
      cout << "\tThe taxi currently has no passengers.\n";

   cout << "class name: " << getClassName() << "\n";

} // end function print

// function horn definition
void Taxi::horn() const
{
   cout << "beep beep";

} // end function horn

// return className
string Taxi::getClassName() const
{
   return "Taxi";

} // end function getClassName


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

