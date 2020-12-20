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
#include "light.h"

namespace pattern_test {

class LightOnCommand : public Command {
public:
    typedef boost::shared_ptr<LightOnCommand> Ptr;

    LightOnCommand(Light::Ptr LightPtr);
    virtual ~LightOnCommand() {};
    virtual void Execute() override;
    virtual void Undo() override;

private:
    Light::Ptr LightPtr_;
};

} /* namespace pattern_test */

#endif /* COMMAND_INCLUDE_COMMAND_LIGHT_ON_CMD_H_ */
