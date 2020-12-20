/*****************************************************************************
* file: ceil_fan_cmd.cpp
* author: 
* date: 2020-12-20
* version: V1
* brief: 
* note Copyright c 2020 FORWARDX ROBOTICS, Inc. All rights reserved
* remarks: 
******************************************************************************/


#include "ceil_fan_cmd.h"


namespace pattern_test {


CeilFanCmd::CeilFanCmd(CeilFan::Ptr CeilFanPtr)
    : CeilFanPtr_(CeilFanPtr),
      PreState_(CeilFan::FanState_e::OFF) {
    ;
}

void CeilFanCmd::Undo() {
    if (PreState_ == CeilFan::FanState_e::OFF) {
        CeilFanPtr_->off();
    } else if (PreState_ == CeilFan::FanState_e::LOW) {
        CeilFanPtr_->low();
    } else if (PreState_ == CeilFan::FanState_e::MEDIUM) {
        CeilFanPtr_->medium();
    } else if (PreState_ == CeilFan::FanState_e::HIGH) {
        CeilFanPtr_->high();
    }
}

// off
CeilFanOffCmd::CeilFanOffCmd(CeilFan::Ptr CeilFanPtr)
    : CeilFanCmd(CeilFanPtr) {
    ;
}

void CeilFanOffCmd::Execute() {
    PreState_ = CeilFanPtr_->GetFanState();
    CeilFanPtr_->off();
}

// low
CeilFanLowCmd::CeilFanLowCmd(CeilFan::Ptr CeilFanPtr)
    : CeilFanCmd(CeilFanPtr) {
    ;
}

void CeilFanLowCmd::Execute() {
    PreState_ = CeilFanPtr_->GetFanState();
    CeilFanPtr_->low();
}

// medium
CeilFanMediumCmd::CeilFanMediumCmd(CeilFan::Ptr CeilFanPtr)
    : CeilFanCmd(CeilFanPtr) {
    ;
}

void CeilFanMediumCmd::Execute() {
    PreState_ = CeilFanPtr_->GetFanState();
    CeilFanPtr_->medium();
}

// high
CeilFanHighCmd::CeilFanHighCmd(CeilFan::Ptr CeilFanPtr)
    : CeilFanCmd(CeilFanPtr) {
    ;
}

void CeilFanHighCmd::Execute() {
    PreState_ = CeilFanPtr_->GetFanState();
    CeilFanPtr_->high();
}
} /* namespace pattern_test */


/*------------------ end of file ------------------*/
