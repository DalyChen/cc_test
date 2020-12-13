/*****************************************************************************
* file: pizza_store.h
* author: 
* date: 2020-12-10
* version: V1
* brief: 
* note Copyright c 2020 FORWARDX ROBOTICS, Inc. All rights reserved
* remarks: 
******************************************************************************/

#ifndef FACTORY_METHOD_INCLUDE_PIZZA_STORE_H_
#define FACTORY_METHOD_INCLUDE_PIZZA_STORE_H_

#include <iostream>
#include <stdio.h>

#include "pizza.h"

namespace pattern_test {

class PizzaStore {
public:
    static PizzaStore* GetInstance();
    virtual ~PizzaStore(){};

    Pizza::Ptr InitPizza(std::string PizzaName);

private:
    PizzaStore();
    Pizza::Ptr CreatePizza(std::string PizzaName);

};

} /* namespace pattern_test */

#endif /* FACTORY_METHOD_INCLUDE_PIZZA_STORE_H_ */
