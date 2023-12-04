
#include <iostream>

using std::cout;
using std::endl;

#include "lion.h"

// default constructor
Lion::Lion( int h, int w )
: Animal( h, w ) 
{
   // empty

} // end class Lion constructor

// function print definition
void Lion::print() const
{
   cout << "This animal is a lion\n";
   Animal::print();

} // end function print
int Lion::getHeight() const
{

    return Animal::getHeight();

} // end function print

// return weight
int Lion::getWeight() const
{
   
    return Animal::getWeight();

}
