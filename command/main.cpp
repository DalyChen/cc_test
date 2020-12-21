
#include <iostream>
#include <boost/make_shared.hpp>

#include "remote.h"
#include "light_cmd.h"
#include "light.h"
#include "ceil_fan_cmd.h"
#include "ceil_fan.h"



#define LIVING_ROOM_LIGHT           1
#define OUTDOOR_LIGHT               2
#define LIVING_ROOM_CEIL_FAN_LOW    3
#define LIVING_ROOM_CEIL_FAN_MEDIUM 4
#define LIVING_ROOM_CEIL_FAN_HIGH   5

int main(int argc, char** argv) {
    std::cout << "start!" << std::endl;

    pattern_test::Remote::Ptr SimpleRemote = 
        boost::make_shared<pattern_test::Remote>();

    // creat lights
    pattern_test::Light::Ptr LivingRoomLight = 
        boost::make_shared<pattern_test::Light>("LivingRoom");
    pattern_test::Light::Ptr OutdoorLight = 
        boost::make_shared<pattern_test::Light>("Outdoor");
    // creat ceil fan
    pattern_test::CeilFan::Ptr LivingRoomCeilFan =
        boost::make_shared<pattern_test::CeilFan>("LivingRoom");

    // creat cmds
    pattern_test::LightOnCommand::Ptr LivingRoomLightOn = 
        boost::make_shared<pattern_test::LightOnCommand>(LivingRoomLight);
    pattern_test::LightOffCommand::Ptr LivingRoomLightOff = 
        boost::make_shared<pattern_test::LightOffCommand>(LivingRoomLight);
    pattern_test::LightOnCommand::Ptr OutdoorLightOn = 
        boost::make_shared<pattern_test::LightOnCommand>(OutdoorLight);
    pattern_test::LightOffCommand::Ptr OutdoorLightOff =
        boost::make_shared<pattern_test::LightOffCommand>(OutdoorLight);

    pattern_test::CeilFanOffCmd::Ptr LivingRoomCeilFanOff =
        boost::make_shared<pattern_test::CeilFanOffCmd>(LivingRoomCeilFan);
    pattern_test::CeilFanLowCmd::Ptr LivingRoomCeilFanLow =
        boost::make_shared<pattern_test::CeilFanLowCmd>(LivingRoomCeilFan);
    pattern_test::CeilFanMediumCmd::Ptr LivingRoomCeilFanMedium =
        boost::make_shared<pattern_test::CeilFanMediumCmd>(LivingRoomCeilFan);
    pattern_test::CeilFanHighCmd::Ptr LivingRoomCeilFanHigh = 
        boost::make_shared<pattern_test::CeilFanHighCmd>(LivingRoomCeilFan);

    // bind cmds
    SimpleRemote->SetCmd(LIVING_ROOM_LIGHT, LivingRoomLightOn, LivingRoomLightOff);
    SimpleRemote->SetCmd(OUTDOOR_LIGHT, OutdoorLightOn, OutdoorLightOff);
    SimpleRemote->SetCmd(LIVING_ROOM_CEIL_FAN_LOW, LivingRoomCeilFanLow, LivingRoomCeilFanOff);
    SimpleRemote->SetCmd(LIVING_ROOM_CEIL_FAN_MEDIUM, LivingRoomCeilFanMedium, LivingRoomCeilFanOff);
    SimpleRemote->SetCmd(LIVING_ROOM_CEIL_FAN_HIGH, LivingRoomCeilFanHigh, LivingRoomCeilFanOff);

    // use it
    SimpleRemote->PushUndoButton();
#if 1
    SimpleRemote->PushOffButton(LIVING_ROOM_LIGHT);
    SimpleRemote->PushUndoButton();
    SimpleRemote->PushOnButton(LIVING_ROOM_LIGHT);
    SimpleRemote->PushUndoButton();
    SimpleRemote->PushOnButton(OUTDOOR_LIGHT);
    SimpleRemote->PushUndoButton();
    SimpleRemote->PushOffButton(OUTDOOR_LIGHT);
    SimpleRemote->PushUndoButton();
#else
    SimpleRemote->PushOnButton(LIVING_ROOM_CEIL_FAN_LOW);
    SimpleRemote->PushOnButton(LIVING_ROOM_CEIL_FAN_MEDIUM);
    SimpleRemote->PushOnButton(LIVING_ROOM_CEIL_FAN_HIGH);
    SimpleRemote->PushOffButton(LIVING_ROOM_CEIL_FAN_LOW);
    SimpleRemote->PushOffButton(LIVING_ROOM_CEIL_FAN_MEDIUM);
    SimpleRemote->PushOnButton(LIVING_ROOM_CEIL_FAN_LOW);
    SimpleRemote->PushUndoButton();
#endif

    return 0;
}