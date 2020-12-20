/*****************************************************************************
* file: remote.h
* author: 
* date: 2020-12-20
* version: V1
* brief: 
* note Copyright c 2020 FORWARDX ROBOTICS, Inc. All rights reserved
* remarks: 
******************************************************************************/

#ifndef COMMAND_INCLUDE_H_
#define COMMAND_INCLUDE_H_


#include <map>
#include <boost/shared_ptr.hpp>
#include <regex>

#include "command.h"



namespace pattern_test {

class Remote {
public:
    typedef boost::shared_ptr<Remote> Ptr;

    Remote();
    virtual ~Remote() {};

    void SetCmd(int slot, Command::Ptr OnCmd, Command::Ptr OffCmd);
    void PushOnButton(int slot);
    void PushOffButton(int slot);

private:
    std::map<int, Command::Ptr> OnCmds;
    std::map<int, Command::Ptr> OffCmds;

};

} /* namespace pattern_test */

#endif /* COMMAND_INCLUDE_COMMAND_COMMAND_H_ */
