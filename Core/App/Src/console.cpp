//
// Created by felix on 04.11.23.
//
#include <string>
#include "../Inc/console.hpp"
#include "../Inc/commands.hpp"

namespace
{
	Commands commands {};
	static std::string received_chars {};
}


void initUART() noexcept
{
    // enable clock for AHB for PA & PB
    RCC->AHBENR |= RCC_AHBENR_GPIOCEN;
    RCC->APB2ENR |= RCC_APB2ENR_USART1EN;
    
    // set alternate function mode on PC4 & PC5
    GPIOC->AFR[0] |= 0x0770000;
    GPIOC->MODER |= GPIO_MODER_MODER4_1;
    GPIOC->MODER |= GPIO_MODER_MODER5_1;
    
    // enable clock for APB1->USART2
    RCC->APB1ENR |= RCC_APB1ENR_USART2EN;
    
    /*
     * Set USART baudrate
     * SYSCLK(Hz) | 8000000 from `Core/Src/system_stm32f3xx.c`
     * Calculation was 8000000 ÷ 9600 => 833,333333333
     * 833 to hex => 341
     * 0,3 to hex => 3
     * adding both together 341 + 3 => 344
     */
    USART1->BRR = 0x344;    // 9600 @ 16Mhz
    
    // enable RE/TX
    USART1->CR1 |= USART_CR1_TE;
    USART1->CR1 |= USART_CR1_RE;
    USART1->CR1 |= USART_CR1_RXNEIE;
    
    // enable USART
    USART1->CR1 |= USART_CR1_UE;
    
    // set 1 Stop bit
    USART1->CR2 &= ~USART_CR2_STOP;
    
    // reset CR3
    USART1->CR3 = 0x00000000;
    
    // Enable USART interrupt in NVIC
    NVIC_EnableIRQ(USART1_IRQn);
}

int uart_write(int ch)
{
    while (!(USART1->ISR & 0x0080)) {}
    
    USART1->TDR = (ch & 0xFFU);
    
    return 1;
}

void uart_read(std::string &val)
{
    std::string tmp {};
    auto recv = '\0';
    
    while (recv != '!')
    {
        while (!(USART1->ISR & 0x0020)) {}
        recv = (char)USART1->RDR;
        tmp.push_back(recv);
    }
    
    val = tmp;
}

void send_data(const std::string& val)
{
    if (val.empty())
        return;
    const std::string hello_txt = val + "\r\n";
    
    for (auto chr : hello_txt)
    {
        if (chr == '!')
            continue;
        
        uart_write(chr);
        for(int tmp = 0; tmp < 180000; ++tmp) {}
    }
}

/// @brief Interrupt service routine
/// can be found in g_pfnVectors in file startup_stm32f303vctx.s
extern "C"
void USART1_IRQHandler(void)
{
    auto recv = (char)USART1->RDR;

    if (recv == '!')
    {
    	std::string cmd = std::move(received_chars);
        received_chars = "";

    	auto result = commands.execute_command(cmd);
        if (!result.empty())
        {
            send_data(result);
        }
        else
        {
        	send_data(cmd + " unknown command.");
        }
    }
    else if ((int)recv >= 20)
    {
        received_chars.push_back(recv);
    }
}
