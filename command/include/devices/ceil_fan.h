/*****************************************************************************
* file: ceil_fan.h
* author: 
* date: 2020-12-20
* version: V1
* brief: 
* note Copyright c 2020 FORWARDX ROBOTICS, Inc. All rights reserved
* remarks: 
******************************************************************************/

#ifndef COMMAND_INCLUDE_DEVICES_CEIL_FAN_H_
#define COMMAND_INCLUDE_DEVICES_CEIL_FAN_H_

#include <boost/shared_ptr.hpp>

namespace pattern_test {

class CeilFan{
public:
    typedef boost::shared_ptr<CeilFan> Ptr;
    enum  FanState_e{
        OFF = 0,
        LOW = 1,
        MEDIUM = 2,
        HIGH = 3
    };

    CeilFan(std::string Location);
    virtual ~CeilFan() {};

    FanState_e GetFanState();
    void off();
    void low();
    void medium();
    void high();

private:
    std::string Location_;
    FanState_e FanState_;
};

} /* namespace pattern_test */

#endif /* COMMAND_INCLUDE_DEVICES_LIGHT_H_ */
