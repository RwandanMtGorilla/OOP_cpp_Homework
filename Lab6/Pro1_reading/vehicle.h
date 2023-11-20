// Chapter 9 of C++ How to Program
// vehicle.h
#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>

using std::ostream;

#include <string>

using std::string;

// class Vehicle definition
class Vehicle {
   friend ostream& operator<<( ostream &, const Vehicle & );

public:
   Vehicle( const int, const int, string, double, const int ); 
   
   void setColor( string );
   string getColor() const;

   void setFuelLevel( double );
   double getFuelLevel() const;

   void setClassName( string );
   string getClassName() const;

   int getTransmissionType() const;
   int getNumberOfDoors() const;
   int getNumberOfCylinders() const; 

private:
   const int numberOfDoors;
   const int numberOfCylinders;
   string vehicleColor;
   double fuelLevel;
   const int transmissionType;
   string className;

}; // end class Vehicle

#endif // VEHICLE_H


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

