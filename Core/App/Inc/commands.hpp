//
// Created by felix on 04.11.23.
//

#ifndef REUSABLE_COMMANDS_HPP
#define REUSABLE_COMMANDS_HPP


#include <cstdlib>
#include <functional>
#include <iostream>
#include <memory>
#include <string>
#include <vector>


struct Command
{
    explicit Command(std::string _name, const std::function<std::string(void)> &_command);
    
    std::string name {};
    std::function<std::string(void)> command;
};

struct Commands
{
    Commands();
    std::vector<std::shared_ptr<Command>> commands {};
    
    [[ nodiscard ]] std::string execute_command(std::string cmd) noexcept;
};


#endif //REUSABLE_COMMANDS_HPP
