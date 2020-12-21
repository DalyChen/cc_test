/*****************************************************************************
* file: remote.cpp
* author: 
* date: 2020-12-20
* version: V1
* brief: 
* note Copyright c 2020 FORWARDX ROBOTICS, Inc. All rights reserved
* remarks: 
******************************************************************************/

#include <iostream>
#include <boost/make_shared.hpp>
#include "remote.h"
#include "no_cmd.h"

namespace pattern_test {


Remote::Remote() {
    ;
}

void  Remote::SetCmd(int slot, Command::Ptr OnCmd, Command::Ptr OffCmd) {
    OnCmds.insert(std::map<int, Command::Ptr>::value_type(slot, OnCmd));
    OffCmds.insert(std::map<int, Command::Ptr>::value_type(slot, OffCmd));

    UndoCmd = boost::make_shared<NoCommand>();
}

void Remote::PushOnButton(int slot) {
    if (OnCmds.find(slot) != OnCmds.end()) {
        OnCmds[slot]->Execute();
        UndoCmd = OnCmds[slot];
    }
}

void Remote::PushOffButton(int slot) {
    if (OffCmds.find(slot) != OffCmds.end()) {
        OffCmds[slot]->Execute();
        UndoCmd = OffCmds[slot];
    }
}

void Remote::PushUndoButton() {
    std::cout << "Undo: ";
    UndoCmd->Undo();
}

} /* namespace pattern_test */

/*------------------ end of file ------------------*/
