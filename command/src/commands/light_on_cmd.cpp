/*****************************************************************************
* file: light_on_cmd.cpp
* author: 
* date: 2020-12-13
* version: V1
* brief: 
* note Copyright c 2020 FORWARDX ROBOTICS, Inc. All rights reserved
* remarks: 
******************************************************************************/


#include "light_on_cmd.h"


namespace pattern_test {


LightOnCommand::LightOnCommand(Light::Ptr LightPtr)
    : LightPtr_(LightPtr) {
    ;
}

void LightOnCommand::Execute() {
    LightPtr_->on();
}

void LightOnCommand::Undo() {
    ;
}

} /* namespace pattern_test */


/*------------------ end of file ------------------*/
