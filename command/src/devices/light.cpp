/*****************************************************************************
* file: light.c
* author: 
* date: 2020-12-13
* version: V1
* brief: 
* date: 2020-12-21
* version: V1.1
* brief: 添加状态记录
* note Copyright c 2020 FORWARDX ROBOTICS, Inc. All rights reserved
* remarks: 
******************************************************************************/


#include "light.h"

#include <iostream>

namespace pattern_test {

Light::Light(std::string Location)
    : Location_(Location),
      LightState_(OFF) {
    ;
}

void Light::on() {
    std::cout << "trun on " << Location_ << " light" << std::endl;
    LightState_ = ON;
}

void Light::off() {
    std::cout << "trun off " << Location_ << " light" << std::endl;
    LightState_ = OFF;
}

} /* namespace pattern_test */

/*------------------ end of file ------------------*/
