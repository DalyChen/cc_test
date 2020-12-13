/*****************************************************************************
* file: light_on_cmd.h
* author: 
* date: 2020-12-13
* version: V1
* brief: 
* note Copyright c 2020 FORWARDX ROBOTICS, Inc. All rights reserved
* remarks: 
******************************************************************************/

#ifndef COMMAND_INCLUDE_COMMAND_LIGHT_ON_CMD_H_
#define COMMAND_INCLUDE_COMMAND_LIGHT_ON_CMD_H_


#include "command.h"

namespace pattern_test {

class LightONCommand : public Command {
public:
    LightONCommand();
    virtual ~LightONCommand() {};
    virtual void Execute() override;
    virtual void Undo() override;

private:

};

} /* namespace pattern_test */

#endif /* COMMAND_INCLUDE_COMMAND_LIGHT_ON_CMD_H_ */
