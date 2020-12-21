/*****************************************************************************
* file: light_cmd.cpp
* author: 
* date: 2020-12-20
* version: V1
* brief: 
* note Copyright c 2020 FORWARDX ROBOTICS, Inc. All rights reserved
* remarks: 
******************************************************************************/


#include "light_cmd.h"


namespace pattern_test {

LightCommand::LightCommand(Light::Ptr LightPtr)
    : LightPtr_(LightPtr),
      PreState_(Light::LightState_e::OFF) {
    ;
}

void LightCommand::Undo() {
    if (PreState_ == Light::LightState_e::OFF) {
        LightPtr_->off();
    } else {
        LightPtr_->on();
    }
}

// on
LightOnCommand::LightOnCommand(Light::Ptr LightPtr)
    : LightCommand(LightPtr) {
    ;
}

void LightOnCommand::Execute() {
    LightPtr_->on();
}

// off
LightOffCommand::LightOffCommand(Light::Ptr LightPtr)
    : LightCommand(LightPtr) {
    ;
}

void LightOffCommand::Execute() {
    LightPtr_->off();
}


} /* namespace pattern_test */


/*------------------ end of file ------------------*/
