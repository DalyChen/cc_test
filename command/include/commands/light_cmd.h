/*****************************************************************************
* file: light_cmd.h
* author: 
* date: 2020-12-21
* version: V1
* brief: 
* note Copyright c 2020 FORWARDX ROBOTICS, Inc. All rights reserved
* remarks: 
******************************************************************************/

#ifndef COMMAND_INCLUDE_COMMAND_LIGHT_CMD_H_
#define COMMAND_INCLUDE_COMMAND_LIGHT_CMD_H_


#include "command.h"
#include "light.h"

namespace pattern_test {

class LightCommand : public Command {
public:
    typedef boost::shared_ptr<LightCommand> Ptr;

    LightCommand(Light::Ptr LightPtr);
    virtual ~LightCommand() {};
    virtual void Execute() override {};
    virtual void Undo() override;

protected:
    Light::Ptr LightPtr_;
    Light::LightState_e PreState_;
};

class LightOnCommand : public LightCommand {
public:
    typedef boost::shared_ptr<LightOnCommand> Ptr;

    LightOnCommand(Light::Ptr LightPtr);
    virtual ~LightOnCommand() {};
    virtual void Execute() override;

private:
};

class LightOffCommand : public LightCommand {
public:
    typedef boost::shared_ptr<LightOffCommand> Ptr;

    LightOffCommand(Light::Ptr LightPtr);
    virtual ~LightOffCommand() {};
    virtual void Execute() override;

private:
};

} /* namespace pattern_test */

#endif /* COMMAND_INCLUDE_COMMAND_LIGHT_CMD_H_ */
