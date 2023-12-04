
#ifndef LION_H
#define LION_H

#include "animal.h"

// class Lion definition
class Lion : public Animal {

public:
   Lion( int = 0, int = 0 );
   virtual int getHeight() const ;
   virtual int getWeight() const ;
   virtual void print() const;

}; // end class Lion

#endif 
