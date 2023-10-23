// Chapter 6 of C++ How to Program
// Debugging Problem (card.h)

#ifndef CARD_H
#define CARD_H

// class card definition
class Card {
public:
   // void Card();
   // void Card( int, int );
   // void ~Card();
   Card();
   Card(int, int);
   ~Card();

   void setSuit( int );
   int getSuit() const;

   void setValue( int );
   int getValue() const;

   void print() const;

private:
   int suit = 4;
   int value = 1;
   bool validCard() const;

}; // end class Card

#endif // CARD_H


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