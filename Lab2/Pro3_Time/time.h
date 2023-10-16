// time.h
#ifndef TIME_H
#define TIME_H

// class Time definition
class Time {

public:
   Time( int = 0, int = 0, int = 0 ); // default constructor
   
   void setTime( int, int, int );
   
   void setHour( int );
   int getHour();
   
   void setMinute( int );
   int getMinute();
   
   void setSecond( int );
   int getSecond();
   
   void printStandard();
   void tick();

private:
   int hour;
   int minute;
   int second;

}; // end class Time

#endif // TIME_H
