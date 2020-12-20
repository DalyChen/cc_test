
#include <iostream>
#include <boost/make_shared.hpp>

#include "remote.h"
#include "light_on_cmd.h"
#include "light_off_cmd.h"
#include "light.h"



#define LIVING_ROOM_LIGHT 1
#define OUTDOOR_LIGHT 2

int main(int argc, char** argv) {
    std::cout << "start!" << std::endl;

    pattern_test::Remote::Ptr SimpleRemote = 
        boost::make_shared<pattern_test::Remote>();

    // creat lights
    pattern_test::Light::Ptr LivingRoomLight = 
        boost::make_shared<pattern_test::Light>("LivingRoom");
    pattern_test::Light::Ptr OutdoorLight = 
        boost::make_shared<pattern_test::Light>("Outdoor");

    // creat cmds
    pattern_test::LightOnCommand::Ptr LivingRoomLightOn = 
        boost::make_shared<pattern_test::LightOnCommand>(LivingRoomLight);
    pattern_test::LightOffCommand::Ptr LivingRoomLightOff = 
        boost::make_shared<pattern_test::LightOffCommand>(LivingRoomLight);
    pattern_test::LightOnCommand::Ptr OutdoorLightOn = 
        boost::make_shared<pattern_test::LightOnCommand>(OutdoorLight);
    pattern_test::LightOffCommand::Ptr OutdoorLightOff =
        boost::make_shared<pattern_test::LightOffCommand>(OutdoorLight);

    // bind cmds
    SimpleRemote->SetCmd(LIVING_ROOM_LIGHT, LivingRoomLightOn, LivingRoomLightOff);
    SimpleRemote->SetCmd(OUTDOOR_LIGHT, OutdoorLightOn, OutdoorLightOff);

    // use it
    SimpleRemote->PushUndoButton();
    SimpleRemote->PushOffButton(LIVING_ROOM_LIGHT);
    SimpleRemote->PushUndoButton();
    SimpleRemote->PushOnButton(LIVING_ROOM_LIGHT);
    SimpleRemote->PushUndoButton();
    SimpleRemote->PushOnButton(OUTDOOR_LIGHT);
    SimpleRemote->PushUndoButton();
    SimpleRemote->PushOffButton(OUTDOOR_LIGHT);
    SimpleRemote->PushUndoButton();

    return 0;
}