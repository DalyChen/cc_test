/*****************************************************************************
* file: light_off_cmd.cpp
* author: 
* date: 2020-12-20
* version: V1
* brief: 
* note Copyright c 2020 FORWARDX ROBOTICS, Inc. All rights reserved
* remarks: 
******************************************************************************/


#include "light_off_cmd.h"


namespace pattern_test {


LightOffCommand::LightOffCommand(Light::Ptr LightPtr)
    : LightPtr_(LightPtr) {
    ;
}

void LightOffCommand::Execute() {
    LightPtr_->off();
}

void LightOffCommand::Undo() {
    LightPtr_->on();
}

} /* namespace pattern_test */


/*------------------ end of file ------------------*/
