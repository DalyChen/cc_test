/*****************************************************************************
* file: pizza_store.cpp
* author: 
* date: 2020-12-10
* version: V1
* brief: 
* note Copyright c 2020 FORWARDX ROBOTICS, Inc. All rights reserved
* remarks: 
******************************************************************************/

#include "pizza_store.h"

#include <stdio.h>
#include <boost/make_shared.hpp>

#include "ny_cheese_pizza.h"
#include "ccg_cheese_pizza.h"

namespace pattern_test {

PizzaStore::PizzaStore() {
    ;
}

Pizza::Ptr PizzaStore::createBoardCard(std::string PizzaName) {
    if (PizzaName == "NyCheese") {
        return boost::make_shared<NyCheesePizza>();
    } else if (PizzaName == "CcgCheesePizza") {
        return boost::make_shared<CcgCheesePizza>();
    } else {
        return nullptr;
    }
}



} /* namespace pattern_test */

