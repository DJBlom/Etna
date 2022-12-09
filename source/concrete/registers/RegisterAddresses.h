#ifndef _REGISTER_ADDRESSES_H_
#define _REGISTER_ADDRESSES_H_
#include <cstdint>




using generic_t = std::uint32_t;

generic_t* GetAddress(generic_t address)
{
    return reinterpret_cast<generic_t*> (address);
}


namespace registers {
    constexpr generic_t BASE{0x40000000U};
    constexpr generic_t APB1_BASE{BASE};
    constexpr generic_t APB2_BASE{BASE + 0x10000U};
    constexpr generic_t AHB1_BASE{BASE + 0x20000U};
    constexpr generic_t AHB2_BASE{0x50000000U};
    constexpr generic_t RCC_BASE{AHB1_BASE + 0x3800U};


    namespace rcc {
        constexpr generic_t APB1_ENABLE	{RCC_BASE + 0x40U};
        constexpr generic_t AHB1_ENABLE	{RCC_BASE + 0x30U};
        constexpr generic_t AHB2_ENABLE {AHB1_ENABLE + 0x34U};
        constexpr generic_t AHB3_ENABLE	{AHB2_ENABLE + 0x38U};
    }


    namespace uart {




        constexpr generic_t USART_SR{APB2_BASE + 0x1400U};
        constexpr generic_t USART_DR{APB2_BASE + 0x1400U};
        constexpr generic_t USART_BRR{APB2_BASE + 0x1400U};
        constexpr generic_t USART_CR1{APB2_BASE + 0x1400U};
        constexpr generic_t USART_CR2{APB2_BASE + 0x1400U};
        constexpr generic_t USART_CR3{APB2_BASE + 0x1400U};
        constexpr generic_t USART_GTPR{APB2_BASE + 0x1400U};

        namespace uart1 {
            constexpr generic_t USART1{APB2_BASE + 0x1000U};
            constexpr generic_t USART1_SR{USART1 + 0x0U};
            constexpr generic_t USART1_DR{USART1 + 0x4U};
            constexpr generic_t USART1_BRR{USART1 + 0x8U};
            constexpr generic_t USART1_CR1{USART1 + 0x0CU};
            constexpr generic_t USART1_CR2{USART1 + 0x10U};
            constexpr generic_t USART1_CR3{USART1 + 0x14U};
            constexpr generic_t USART1_GTPR{USART1 + 0x18U};
        }

        namespace uart2 {
            constexpr generic_t USART2{APB1_BASE + 0x4400U};
            constexpr generic_t USART2_SR{USART2 + 0x0U};
            constexpr generic_t USART2_DR{USART2 + 0x4U};
            constexpr generic_t USART2_BRR{USART2 + 0x8U};
            constexpr generic_t USART2_CR1{USART2 + 0x0CU};
            constexpr generic_t USART2_CR2{USART2 + 0x10U};
            constexpr generic_t USART2_CR3{USART2 + 0x14U};
            constexpr generic_t USART2_GTPR{USART2 + 0x18U};
        }

        namespace uart3 {
            constexpr generic_t USART6{APB2_BASE + 0x1400U};
            constexpr generic_t USART6_SR{USART6 + 0x0U};
            constexpr generic_t USART6_DR{USART6 + 0x4U};
            constexpr generic_t USART6_BRR{USART6 + 0x8U};
            constexpr generic_t USART6_CR1{USART6 + 0x0CU};
            constexpr generic_t USART6_CR2{USART6 + 0x10U};
            constexpr generic_t USART6_CR3{USART6 + 0x14U};
            constexpr generic_t USART6_GTPR{USART6 + 0x18U};
        }
    }


    namespace gpio {
        constexpr generic_t GPIOA{AHB1_BASE + 0x0000U};
        constexpr generic_t GPIOB{AHB1_BASE + 0x0400U};
        constexpr generic_t GPIOC{AHB1_BASE + 0x0800U};
        constexpr generic_t GPIOD{AHB1_BASE + 0x0C00U};
        constexpr generic_t GPIOE{AHB1_BASE + 0x1000U};


        constexpr generic_t MODER_OFFSET{0x00U};
        constexpr generic_t OTYPER_OFFSET{0x04U};
        constexpr generic_t OSPEEDR_OFFSET{0x08U};
        constexpr generic_t PUPDR_OFFSET{0x0CU};
        constexpr generic_t IDR_OFFSET{0x10U};
        constexpr generic_t ODR_OFFSET{0x14U};
        constexpr generic_t BSRR_OFFSET{0x18U};
        constexpr generic_t LOCKR_OFFSET{0x1CU};
        constexpr generic_t AFRL_OFFSET{0x20U};
        constexpr generic_t AFRH_OFFSET{0x24U};


        namespace gpioa {
            constexpr generic_t GPIOA_MODER{GPIOA + MODER_OFFSET};
            constexpr generic_t GPIOA_OTYPER{GPIOA + OTYPER_OFFSET};
            constexpr generic_t GPIOA_OSPEEDR{GPIOA + OSPEEDR_OFFSET};
            constexpr generic_t GPIOA_PUPDR{GPIOA + PUPDR_OFFSET};
            constexpr generic_t GPIOA_IDR{GPIOA + IDR_OFFSET};
            constexpr generic_t GPIOA_ODR{GPIOA + ODR_OFFSET};
            constexpr generic_t GPIOA_BSRR{GPIOA + BSRR_OFFSET};
            constexpr generic_t GPIOA_LOCKR{GPIOA + LOCKR_OFFSET};
            constexpr generic_t GPIOA_AFRL{GPIOA + AFRL_OFFSET};
            constexpr generic_t GPIOA_AFRH{GPIOA + AFRH_OFFSET};
        }


        namespace gpiob {
            constexpr generic_t GPIOB_MODER{GPIOB + MODER_OFFSET};
            constexpr generic_t GPIOB_OTYPER{GPIOB + OTYPER_OFFSET};
            constexpr generic_t GPIOB_OSPEEDR{GPIOB + OSPEEDR_OFFSET};
            constexpr generic_t GPIOB_PUPDR{GPIOB + PUPDR_OFFSET};
            constexpr generic_t GPIOB_IDR{GPIOB + IDR_OFFSET};
            constexpr generic_t GPIOB_ODR{GPIOB + ODR_OFFSET};
            constexpr generic_t GPIOB_BSRR{GPIOB + BSRR_OFFSET};
            constexpr generic_t GPIOB_LOCKR{GPIOB + LOCKR_OFFSET};
            constexpr generic_t GPIOB_AFRL{GPIOB + AFRL_OFFSET};
            constexpr generic_t GPIOB_AFRH{GPIOB + AFRH_OFFSET};
        }


        namespace gpioc {
            constexpr generic_t GPIOC_MODER{GPIOC + MODER_OFFSET};
            constexpr generic_t GPIOC_OTYPER{GPIOC + OTYPER_OFFSET};
            constexpr generic_t GPIOC_OSPEEDR{GPIOC + OSPEEDR_OFFSET};
            constexpr generic_t GPIOC_PUPDR{GPIOC + PUPDR_OFFSET};
            constexpr generic_t GPIOC_IDR{GPIOC + IDR_OFFSET};
            constexpr generic_t GPIOC_ODR{GPIOC + ODR_OFFSET};
            constexpr generic_t GPIOC_BSRR{GPIOC + BSRR_OFFSET};
            constexpr generic_t GPIOC_LOCKR{GPIOC + LOCKR_OFFSET};
            constexpr generic_t GPIOC_AFRL{GPIOC + AFRL_OFFSET};
            constexpr generic_t GPIOC_AFRH{GPIOC + AFRH_OFFSET};
        }


        namespace gpiod {
            constexpr generic_t GPIOD_MODER{GPIOD + MODER_OFFSET};
            constexpr generic_t GPIOD_OTYPER{GPIOD + OTYPER_OFFSET};
            constexpr generic_t GPIOD_OSPEEDR{GPIOD + OSPEEDR_OFFSET};
            constexpr generic_t GPIOD_PUPDR{GPIOD + PUPDR_OFFSET};
            constexpr generic_t GPIOD_IDR{GPIOD + IDR_OFFSET};
            constexpr generic_t GPIOD_ODR{GPIOD + ODR_OFFSET};
            constexpr generic_t GPIOD_BSRR{GPIOD + BSRR_OFFSET};
            constexpr generic_t GPIOD_LOCKR{GPIOD + LOCKR_OFFSET};
            constexpr generic_t GPIOD_AFRL{GPIOD + AFRL_OFFSET};
            constexpr generic_t GPIOD_AFRH{GPIOD + AFRH_OFFSET};
        }


        namespace gpioe {
            constexpr generic_t GPIOE_MODER{GPIOE + MODER_OFFSET};
            constexpr generic_t GPIOE_OTYPER{GPIOE + OTYPER_OFFSET};
            constexpr generic_t GPIOE_OSPEEDR{GPIOE + OSPEEDR_OFFSET};
            constexpr generic_t GPIOE_PUPDR{GPIOE + PUPDR_OFFSET};
            constexpr generic_t GPIOE_IDR{GPIOE + IDR_OFFSET};
            constexpr generic_t GPIOE_ODR{GPIOE + ODR_OFFSET};
            constexpr generic_t GPIOE_BSRR{GPIOE + BSRR_OFFSET};
            constexpr generic_t GPIOE_LOCKR{GPIOE + LOCKR_OFFSET};
            constexpr generic_t GPIOE_AFRL{GPIOE + AFRL_OFFSET};
            constexpr generic_t GPIOE_AFRH{GPIOE + AFRH_OFFSET};
        }
    }
}

#endif
