/*****************************************************************************
* file: light_off_cmd.h
* author: 
* date: 2020-12-20
* version: V1
* brief: 
* note Copyright c 2020 FORWARDX ROBOTICS, Inc. All rights reserved
* remarks: 
******************************************************************************/

#ifndef COMMAND_INCLUDE_COMMAND_LIGHT_OFF_CMD_H_
#define COMMAND_INCLUDE_COMMAND_LIGHT_OFF_CMD_H_


#include "command.h"
#include "light.h"

namespace pattern_test {

class LightOffCommand : public Command {
public:
    typedef boost::shared_ptr<LightOffCommand> Ptr;

    LightOffCommand(Light::Ptr LightPtr);
    virtual ~LightOffCommand() {};
    virtual void Execute() override;
    virtual void Undo() override;

private:
    Light::Ptr LightPtr_;
};

} /* namespace pattern_test */

#endif /* COMMAND_INCLUDE_COMMAND_LIGHT_ON_CMD_H_ */
