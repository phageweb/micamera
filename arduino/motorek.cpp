/* Interval
 * Version 5-10-2014
 * Copyright (C) 2014  Pavel Brychta http://www.xpablo.cz
 * 
 * This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty
 * of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License along with this program. If not, see http://www.gnu.org/licenses
 
Release Notes
5-10-2014  First public release
*/

#include <arduino.h>
#include "motorek.h"

Motorek::Motorek(void){
    this->setSpeed(500);
}
void Motorek::setSpeed(int speed)
{
	 this->speed=speed;
}
void Motorek::setPin(int enable, int dir, int step)
{
   this->enable=enable;
   this->dir=dir;
   this->step=step;

  pinMode(this->enable, OUTPUT);
  pinMode(this->dir, OUTPUT);
  pinMode(this->step, OUTPUT);
}

void Motorek::stop(void)
{
  
   state=STOP;
}

void Motorek::right(int time)
{
   timeExecute=time;
   state=CMD_RIGHT;
 
}
 void Motorek::left(int time)
{
  timeExecute=time;
  state=CMD_LEFT;
  
}
void Motorek::action(){
switch (state) {
  case STOP:
    this->dirState=0;
    this->stepState=0;
    digitalWrite(this->dir, dirState);
    digitalWrite(this->step, stepState);
    break;
    
  case CMD_LEFT:
    this->dirState=1;
    digitalWrite(this->dir, this->dirState);
    this->intervalExecute.set(timeExecute); 
    state=EXECUTE;
    break;
  case CMD_RIGHT:
    this->dirState=0;
    digitalWrite(this->dir, this->dirState);
    this->intervalExecute.set(timeExecute); 
    state=EXECUTE;
    break;
  case EXECUTE:
    if (this->intervalExecute.expired()) {
      state=STOP;
      
    }else{
      if (this->interval_motor.expired()) {
       this->interval_motor.set(speed); // set new interval period
       this->stepState = !this->stepState;
        
        digitalWrite(this->step, this->stepState);
      }
    }
    break;
  default:
    break;
} 


}

