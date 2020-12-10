/*****************************************************************************
* file: ccg_cheese_pizza.h
* author: 
* date: 2020-12-11
* version: V1
* brief: 
* note Copyright c 2020 FORWARDX ROBOTICS, Inc. All rights reserved
* remarks: 
******************************************************************************/

#ifndef FACTORY_METHOD_INCLUDE_CCG_CHEESE_PIZZA_H_
#define FACTORY_METHOD_INCLUDE_CCG_CHEESE_PIZZA_H_


#include "pizza.h"

namespace pattern_test {

class CcgCheesePizza : public Pizza {
public:
    CcgCheesePizza();
    virtual ~CcgCheesePizza() {};

    virtual std::string GetPizzaName() override { return PizzaName_; };

private:

};

} /* namespace pattern_test */

#endif /* FACTORY_METHOD_INCLUDE_CCG_CHEESE_PIZZA_H_ */
