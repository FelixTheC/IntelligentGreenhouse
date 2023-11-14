//
// Created by felix on 04.11.23.
//

#ifndef REUSABLE_CONSOLE_HPP
#define REUSABLE_CONSOLE_HPP

#include <memory>
#include "stm32f303xc.h"


void initUART() noexcept;
int uart_write(int ch);
void send_data(const std::string& val);

#endif //REUSABLE_CONSOLE_HPP
