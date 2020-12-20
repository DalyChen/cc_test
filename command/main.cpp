
#include <iostream>
#include <boost/make_shared.hpp>

#include "light_on_cmd.h"
#include "light.h"


int main(int argc, char** argv) {
    std::cout << "start!" << std::endl;
    
    pattern_test::Light::Ptr LivingRoomLight = 
        boost::make_shared<pattern_test::Light>("LivingRoom");
    pattern_test::LightOnCommand::Ptr Cmd1 = 
        boost::make_shared<pattern_test::LightOnCommand>(LivingRoomLight);
    
    Cmd1->Execute();

#if 0
    pattern_test::Light::Ptr OutdoorLight = 
        boost::make_shared<pattern_test::Light>("Outdoor");
    OutdoorLight->on();
    OutdoorLight->off();
#endif

    return 0;
}