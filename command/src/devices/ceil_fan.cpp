/*****************************************************************************
* file:ceil_fan.cpp
* author: 
* date: 2020-12-20
* version: V1
* brief: 
* note Copyright c 2020 FORWARDX ROBOTICS, Inc. All rights reserved
* remarks: 
******************************************************************************/


#include "ceil_fan.h"

#include <iostream>

namespace pattern_test {

CeilFan::CeilFan(std::string Location)
    : Location_(Location),
      FanState_(OFF) {
    ;
}

CeilFan::FanState_e CeilFan::GetFanState() {
    return FanState_;
}

void CeilFan::off() {
    std::cout << "trun off " << Location_ << " ceil fan" << std::endl;
    FanState_ = OFF;
}

void CeilFan::low() {
    std::cout << "trun low " << Location_ << " ceil fan" << std::endl;
    FanState_ = LOW;
}

void CeilFan::medium() {
    std::cout << "trun medium " << Location_ << " ceil fan" << std::endl;
    FanState_ = MEDIUM;
}

void CeilFan::high() {
    std::cout << "trun high " << Location_ << " ceil fan" << std::endl;
    FanState_ = HIGH;
}

} /* namespace pattern_test */

/*------------------ end of file ------------------*/
