

#include <iostream>
#include <boost/make_shared.hpp>
#include "pizza_store.h"
#include "ny_cheese_pizza.h"


int main(int argc, char** argv) {
    pattern_test::PizzaStore TestPizzaStore;

	pattern_test::Pizza::Ptr MyNyCheesePizza = boost::make_shared<pattern_test::NyCheesePizza>();

    std::string TempPizzaName = MyNyCheesePizza->GetPizzaName();

    std::cout << TempPizzaName << std::endl;

    return 0;
}