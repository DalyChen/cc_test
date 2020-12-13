/*****************************************************************************
* file: light.c
* author: 
* date: 2020-12-13
* version: V1
* brief: 
* note Copyright c 2020 FORWARDX ROBOTICS, Inc. All rights reserved
* remarks: 
******************************************************************************/


#include "light.h"

#include <iostream>

namespace pattern_test {

Light::Light(std::string Location)
    : Location_(Location) {
    ;
}

void Light::on() {
    std::cout << "trun on " << Location_ << " light" << std::endl;
}

void Light::off() {
    std::cout << "trun off " << Location_ << " light" << std::endl;
}

} /* namespace pattern_test */

/*------------------ end of file ------------------*/
