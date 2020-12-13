
#include <iostream>
#include <boost/make_shared.hpp>
#include "pizza_store.h"

int main(int argc, char** argv) {
    // pattern_test::PizzaStore TestPizzaStore;
    std::cout << "start!" << std::endl;
    pattern_test::PizzaStore::GetInstance()->InitPizza("NyCheesePizza");
    pattern_test::PizzaStore::GetInstance()->InitPizza("CcgCheesePizza");


    // pattern_test::Pizza::Ptr MyNyCheesePizza = TestPizzaStore.InitPizza("NyCheesePizza");
    // pattern_test::Pizza::Ptr MyCcgCheesePizza = TestPizzaStore.InitPizza("CcgCheesePizza");

    return 0;
}