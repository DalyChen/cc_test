/*****************************************************************************
* file: no_cmd.cpp
* author: 
* date: 2020-12-20
* version: V1
* brief: 
* note Copyright c 2020 FORWARDX ROBOTICS, Inc. All rights reserved
* remarks: 
******************************************************************************/

#include <iostream>
#include "no_cmd.h"


namespace pattern_test {


NoCommand::NoCommand() {
    ;
}

void NoCommand::Execute() {
    std::cout << "Execute: do nothing!" << std::endl;
}

void NoCommand::Undo() {
    std::cout << "Undo: do nothing!" << std::endl;
}

} /* namespace pattern_test */


/*------------------ end of file ------------------*/
