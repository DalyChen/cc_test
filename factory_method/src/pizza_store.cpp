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

Pizza::Ptr PizzaStore::InitPizza(std::string PizzaName) {
    Pizza::Ptr NewPizza = CreatePizza(PizzaName);

    if (NewPizza != nullptr) {
        std::string TempPizzaName;
        std::cout << "We get a ";
        TempPizzaName = NewPizza->GetPizzaName();
        std::cout << TempPizzaName << std::endl << std::endl;
    }

    return NewPizza;
}

Pizza::Ptr PizzaStore:: CreatePizza(std::string PizzaName) {
    std::cout << "get a name: " << PizzaName << std::endl;
    if (PizzaName == "NyCheesePizza") {
        return boost::make_shared<NyCheesePizza>();
    } else if (PizzaName == "CcgCheesePizza") {
        return boost::make_shared<CcgCheesePizza>();
    } else {
        return nullptr;
    }
}

} /* namespace pattern_test */

