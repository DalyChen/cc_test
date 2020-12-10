

#include <iostream>
#include <boost/make_shared.hpp>
#include "pizza_store.h"
// #include "ny_cheese_pizza.h"
// #include "ccg_cheese_pizza.h"

int main(int argc, char** argv) {
    pattern_test::PizzaStore TestPizzaStore;

    std::cout << "start!" << std::endl;
#if 0
    pattern_test::Pizza::Ptr MyNyCheesePizza = boost::make_shared<pattern_test::NyCheesePizza>();
    pattern_test::Pizza::Ptr MyCcgCheesePizza = boost::make_shared<pattern_test::CcgCheesePizza>();
#endif
    pattern_test::Pizza::Ptr MyNyCheesePizza = TestPizzaStore.InitPizza("NyCheesePizza");
    pattern_test::Pizza::Ptr MyCcgCheesePizza = TestPizzaStore.InitPizza("CcgCheesePizza");

#if 0
    std::string TempPizzaName = MyNyCheesePizza->GetPizzaName();
    std::cout << TempPizzaName << std::endl;

    TempPizzaName = MyCcgCheesePizza->GetPizzaName();
    std::cout << TempPizzaName << std::endl;
#endif

    return 0;
}