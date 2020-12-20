/*****************************************************************************
* file: no_cmd.h
* author: 
* date: 2020-12-20
* version: V1
* brief: 
* note Copyright c 2020 FORWARDX ROBOTICS, Inc. All rights reserved
* remarks: 
******************************************************************************/

#ifndef COMMAND_INCLUDE_COMMAND_NO_CMD_H_
#define COMMAND_INCLUDE_COMMAND_NO_CMD_H_


#include "command.h"

namespace pattern_test {

class NoCommand : public Command {
public:
    typedef boost::shared_ptr<NoCommand> Ptr;

    NoCommand();
    virtual ~NoCommand() {};
    virtual void Execute() override;
    virtual void Undo() override;

private:
};

} /* namespace pattern_test */

#endif /* COMMAND_INCLUDE_COMMAND_LIGHT_OFF_CMD_H_ */
