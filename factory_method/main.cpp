
#include <iostream>
#include <boost/make_shared.hpp>
#include "pizza_store.h"

int main(int argc, char** argv) {
    std::cout << "start!" << std::endl;
    pattern_test::PizzaStore::GetInstance()->InitPizza("NyCheesePizza");
    pattern_test::PizzaStore::GetInstance()->InitPizza("CcgCheesePizza");

    return 0;
}