/*****************************************************************************
* file: command.h
* author: 
* date: 2020-12-13
* version: V1
* brief: 
* note Copyright c 2020 FORWARDX ROBOTICS, Inc. All rights reserved
* remarks: 
******************************************************************************/

#ifndef COMMAND_INCLUDE_COMMAND_COMMAND_H_
#define COMMAND_INCLUDE_COMMAND_COMMAND_H_


#include <boost/shared_ptr.hpp>
#include <regex>

namespace pattern_test {

class Command{
public:
    typedef boost::shared_ptr<Command> Ptr;

    Command() {};
    virtual ~Command() {};
    virtual void Execute() = 0;
    virtual void Undo() = 0;

private:

};

} /* namespace pattern_test */

#endif /* COMMAND_INCLUDE_COMMAND_COMMAND_H_ */
