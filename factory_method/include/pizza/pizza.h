/*****************************************************************************
* file: pizza.h
* author: 
* date: 2020-12-10
* version: V1
* brief: 
* note Copyright c 2020 FORWARDX ROBOTICS, Inc. All rights reserved
* remarks: 
******************************************************************************/

#ifndef FACTORY_METHOD_INCLUDE_PIZZA_H_
#define FACTORY_METHOD_INCLUDE_PIZZA_H_


#include <boost/shared_ptr.hpp>
#include <regex>

namespace pattern_test {

class Pizza {
public:
    typedef boost::shared_ptr<Pizza> Ptr;
    virtual ~Pizza() {};
    virtual std::string GetPizzaName() = 0;

protected:
    Pizza();

    std::string PizzaName_;

private:

};

} /* namespace pattern_test */

#endif /* FACTORY_METHOD_INCLUDE_PIZZA_H_ */
