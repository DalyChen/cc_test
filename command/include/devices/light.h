/*****************************************************************************
* file: light.h
* author: 
* date: 2020-12-13
* version: V1
* brief: 
* note Copyright c 2020 FORWARDX ROBOTICS, Inc. All rights reserved
* remarks: 
******************************************************************************/

#ifndef COMMAND_INCLUDE_DEVICES_LIGHT_H_
#define COMMAND_INCLUDE_DEVICES_LIGHT_H_

#include <boost/shared_ptr.hpp>
#include <regex>

namespace pattern_test {

class Light{
public:
    typedef boost::shared_ptr<Light> Ptr;
    enum LightState_e {
        OFF = 0,
        ON = 1
    };

    Light(std::string Location);
    virtual ~Light() {};
    void on();
    void off();

private:
    std::string Location_;
    LightState_e LightState_;
};

} /* namespace pattern_test */

#endif /* COMMAND_INCLUDE_DEVICES_LIGHT_H_ */
