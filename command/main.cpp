
#include <iostream>
#include <boost/make_shared.hpp>

#include "light.h"


int main(int argc, char** argv) {
    std::cout << "start!" << std::endl;
    
    pattern_test::Light::Ptr LivingRoomLight = 
        boost::make_shared<pattern_test::Light>("LivingRoom");
    LivingRoomLight->on();
    LivingRoomLight->off();

    return 0;
}