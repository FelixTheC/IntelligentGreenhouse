//
// Created by felix on 04.11.23.
//
#include <algorithm>
#include <utility>

#include "../Inc/commands.hpp"

static std::string getVersion() noexcept
{
    return "0.0.1";
}

Command::Command(std::string _name, const std::function<std::string(void)> &_command) : name(std::move(_name)), command(_command)
{
}

Commands::Commands()
{
    commands.emplace_back(
            std::make_shared<Command>(
                    Command(
                            "version",
                            [=]()
                            {
                                return "Version: " +  getVersion();
                            }
                    )));
    commands.emplace_back(
            std::make_shared<Command>(
                    Command(
                            "tempsensor_on",
                            [=]()
                            {
                                return "Temperatur Sensor enabled: ";
                            }
                    )));
    commands.emplace_back(
            std::make_shared<Command>(
                    Command(
                            "tempsensor_off",
                            [=]()
                            {
                                return "Temperatur Sensor disabled: ";
                            }
                    )));
    commands.emplace_back(
            std::make_shared<Command>(
                    Command(
                            "tempsensor_data",
                            [=]()
                            {
                                return "Temperatur Sensor data: 12";
                            }
                    )));
    commands.emplace_back(
            std::make_shared<Command>(
                    Command(
                            "soil_on",
                            [=]()
                            {
                                return "Soil Sensor enabled: ";
                            }
                    )));
    commands.emplace_back(
            std::make_shared<Command>(
                    Command(
                            "soil_off",
                            [=]()
                            {
                                return "Soil Sensor disabled: ";
                            }
                    )));
    commands.emplace_back(
            std::make_shared<Command>(
                    Command(
                            "soil_data",
                            [=]()
                            {
                               return "Soil Sensor data: 0.12";
                            }
                    )));
    commands.emplace_back(
            std::make_shared<Command>(
                    Command(
                            "humiditysensor_on",
                            [=]()
                            {
                                return "Humidity Sensor enabled: ";
                            }
                    )));
    commands.emplace_back(
            std::make_shared<Command>(
                    Command(
                            "humiditysensor_off",
                            [=]()
                            {
                                return "Humidity Sensor disabled: ";
                            }
                    )));
    commands.emplace_back(
            std::make_shared<Command>(
                    Command(
                            "humiditysensor_data",
                            [=]()
                            {
                                return "Humidity Sensor data: 65";
                            }
                    )));
    commands.emplace_back(
            std::make_shared<Command>(
                    Command(
                            "waterpump_ic2_on", // rlmotor => external roof-light motor
                            [=]()
                            {
                                return "Send open to external water pump.";
                            }
                    )));
    
    commands.emplace_back(
            std::make_shared<Command>(
                    Command(
                            "waterpump_ic2_off", // rlmotor => external roof-light motor
                            [=]()
                            {
                                return "Send close to external water pump.";
                            }
                    )));
    
    commands.emplace_back(
            std::make_shared<Command>(
                    Command(
                            "roof_light_ic2_on",
                            [=]()
                            {
                                return "Send open to external water pump.";
                            }
                    )));
    
    commands.emplace_back(
            std::make_shared<Command>(
                    Command(
                            "roof_light_ic2_off",
                            [=]()
                            {
                                return "Send open to external water pump.";
                            }
                    )));
    
    commands.emplace_back(
            std::make_shared<Command>(
                    Command(
                            "send_test_request",
                            [=]()
                            {
                                return "Send test data to server.";
                            }
                    )));
    
}

[[ nodiscard ]] std::string Commands::execute_command(std::string cmd) noexcept
{
    std::string result {};
    
    std::for_each(commands.begin(),
                  commands.end(),
                  [&result, &cmd](const std::shared_ptr<Command> &command){
        if (command->name == cmd)
        {
            result = command->command();
        }
    });
    
    return result;
}
