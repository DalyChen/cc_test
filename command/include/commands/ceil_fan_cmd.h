/*****************************************************************************
* file: ceil_fan_cmd.h
* author: 
* date: 2020-12-20
* version: V1
* brief: 
* note Copyright c 2020 FORWARDX ROBOTICS, Inc. All rights reserved
* remarks: 
******************************************************************************/

#ifndef COMMAND_INCLUDE_COMMAND_CEIL_FAN_CMD_H_
#define COMMAND_INCLUDE_COMMAND_CEIL_FAN_CMD_H_


#include "command.h"
#include "ceil_fan.h"

namespace pattern_test {

class CeilFanCmd: public Command {
public:
    typedef boost::shared_ptr<CeilFanCmd> Ptr;

    CeilFanCmd(CeilFan::Ptr CeilfanPtr);
    virtual ~CeilFanCmd() {};
    virtual void Execute() override {};
    virtual void Undo() override;

protected:
    CeilFan::Ptr CeilFanPtr_;
    CeilFan::FanState_e PreState_;
};

class CeilFanOffCmd: public CeilFanCmd {
public:
    typedef boost::shared_ptr<CeilFanOffCmd> Ptr;

    CeilFanOffCmd(CeilFan::Ptr CeilfanPtr);
    virtual ~CeilFanOffCmd() {};
    virtual void Execute() override;

private:
};

class CeilFanLowCmd: public CeilFanCmd {
public:
    typedef boost::shared_ptr<CeilFanLowCmd> Ptr;

    CeilFanLowCmd(CeilFan::Ptr CeilfanPtr);
    virtual ~CeilFanLowCmd() {};
    virtual void Execute() override;

private:
};

class CeilFanMediumCmd: public CeilFanCmd {
public:
    typedef boost::shared_ptr<CeilFanMediumCmd> Ptr;

    CeilFanMediumCmd(CeilFan::Ptr CeilfanPtr);
    virtual ~CeilFanMediumCmd() {};
    virtual void Execute() override;

private:
};

class CeilFanHighCmd: public CeilFanCmd {
public:
    typedef boost::shared_ptr<CeilFanHighCmd> Ptr;

    CeilFanHighCmd(CeilFan::Ptr CeilfanPtr);
    virtual ~CeilFanHighCmd() {};
    virtual void Execute() override;

private:
};

} /* namespace pattern_test */

#endif /* COMMAND_INCLUDE_COMMAND_CEIL_FAN_CMD_H_ */
