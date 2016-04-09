
#ifndef motorek_h
#define motorek_h





#include <inttypes.h>
#include "interval.h"

enum State {CMD_LEFT,CMD_RIGHT, STOP,EXECUTE}; 

class Motorek
{
  

  public:
    Motorek();
    IntervalMillis intervalExecute;
    IntervalMicros interval_motor;
    int CONST_interval_motor, timeExecute;

 
 
    public:
    State state;
    int speed, dir, step, enable, stepState,dirState;
    void setPin(int enable, int dir, int step);
    void setSpeed(int speed);
    void right(int time);
    void left(int time);
    void stop();
    void action();
    
 private:
};

#endif
// EOF
