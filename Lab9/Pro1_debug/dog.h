#ifndef DOG_H
#define DOG_H

#include "animal.h"
// class Dog definition
class Dog : public Animal {

public:
   Dog( int = 0, int = 0, string = "Toto" );
       
   virtual void print() const;
   virtual int getHeight() const ;
   virtual int getWeight() const ;
   string getName() const;
   void setName( string );
   virtual void setHeight(int);
   virtual void setWeight(int);
private:
   bool useMetric( string ) const;
   string name;
   int metricHeight;
   int metricWeight;

}; // end class Dog
#endif 
