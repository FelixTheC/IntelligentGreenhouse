#include <string>
#include "../App/Inc/console.hpp"
#include "stm32f303xc.h"

int uart_write(int ch);
void uart_read(std::string &val);
void send_data(const std::string& val);

int main()
{
    initUART();
    // initSPI();
    // ethernetCommunication();
    
    // send_data("Intelligent Greenhouse...");

    while (true)
    {
    }
    
	return 0;
}
