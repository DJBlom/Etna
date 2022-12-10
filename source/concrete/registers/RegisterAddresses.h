#ifndef _REGISTER_ADDRESSES_H_
#define _REGISTER_ADDRESSES_H_
#include <cstdint>

using addressType = std::uint32_t;
addressType* GetAddress(addressType address)
{
    return reinterpret_cast<addressType*> (address);
}

namespace registers {
    constexpr addressType BASE{0x40000000U};
    constexpr addressType APB1_BASE{BASE};
    constexpr addressType APB2_BASE{BASE + 0x10000U};
    constexpr addressType AHB1_BASE{BASE + 0x20000U};
    constexpr addressType AHB2_BASE{0x50000000U};
    constexpr addressType RCC_BASE{AHB1_BASE + 0x3800U};


    namespace rcc {
        constexpr addressType APB1_ENABLE	{RCC_BASE + 0x40U};
        constexpr addressType AHB1_ENABLE	{RCC_BASE + 0x30U};
        constexpr addressType AHB2_ENABLE {AHB1_ENABLE + 0x34U};
        constexpr addressType AHB3_ENABLE	{AHB2_ENABLE + 0x38U};
    }


    namespace uart {




        constexpr addressType USART_SR{APB2_BASE + 0x1400U};
        constexpr addressType USART_DR{APB2_BASE + 0x1400U};
        constexpr addressType USART_BRR{APB2_BASE + 0x1400U};
        constexpr addressType USART_CR1{APB2_BASE + 0x1400U};
        constexpr addressType USART_CR2{APB2_BASE + 0x1400U};
        constexpr addressType USART_CR3{APB2_BASE + 0x1400U};
        constexpr addressType USART_GTPR{APB2_BASE + 0x1400U};

        namespace uart1 {
            constexpr addressType USART1{APB2_BASE + 0x1000U};
            constexpr addressType USART1_SR{USART1 + 0x0U};
            constexpr addressType USART1_DR{USART1 + 0x4U};
            constexpr addressType USART1_BRR{USART1 + 0x8U};
            constexpr addressType USART1_CR1{USART1 + 0x0CU};
            constexpr addressType USART1_CR2{USART1 + 0x10U};
            constexpr addressType USART1_CR3{USART1 + 0x14U};
            constexpr addressType USART1_GTPR{USART1 + 0x18U};
        }

        namespace uart2 {
            constexpr addressType USART2{APB1_BASE + 0x4400U};
            constexpr addressType USART2_SR{USART2 + 0x0U};
            constexpr addressType USART2_DR{USART2 + 0x4U};
            constexpr addressType USART2_BRR{USART2 + 0x8U};
            constexpr addressType USART2_CR1{USART2 + 0x0CU};
            constexpr addressType USART2_CR2{USART2 + 0x10U};
            constexpr addressType USART2_CR3{USART2 + 0x14U};
            constexpr addressType USART2_GTPR{USART2 + 0x18U};
        }

        namespace uart3 {
            constexpr addressType USART6{APB2_BASE + 0x1400U};
            constexpr addressType USART6_SR{USART6 + 0x0U};
            constexpr addressType USART6_DR{USART6 + 0x4U};
            constexpr addressType USART6_BRR{USART6 + 0x8U};
            constexpr addressType USART6_CR1{USART6 + 0x0CU};
            constexpr addressType USART6_CR2{USART6 + 0x10U};
            constexpr addressType USART6_CR3{USART6 + 0x14U};
            constexpr addressType USART6_GTPR{USART6 + 0x18U};
        }
    }


    namespace gpio {
        constexpr addressType GPIOA{AHB1_BASE + 0x0000U};
        constexpr addressType GPIOB{AHB1_BASE + 0x0400U};
        constexpr addressType GPIOC{AHB1_BASE + 0x0800U};
        constexpr addressType GPIOD{AHB1_BASE + 0x0C00U};
        constexpr addressType GPIOE{AHB1_BASE + 0x1000U};


        constexpr addressType MODER_OFFSET{0x00U};
        constexpr addressType OTYPER_OFFSET{0x04U};
        constexpr addressType OSPEEDR_OFFSET{0x08U};
        constexpr addressType PUPDR_OFFSET{0x0CU};
        constexpr addressType IDR_OFFSET{0x10U};
        constexpr addressType ODR_OFFSET{0x14U};
        constexpr addressType BSRR_OFFSET{0x18U};
        constexpr addressType LOCKR_OFFSET{0x1CU};
        constexpr addressType AFRL_OFFSET{0x20U};
        constexpr addressType AFRH_OFFSET{0x24U};


        namespace gpioa {
            constexpr addressType GPIOA_MODER{GPIOA + MODER_OFFSET};
            constexpr addressType GPIOA_OTYPER{GPIOA + OTYPER_OFFSET};
            constexpr addressType GPIOA_OSPEEDR{GPIOA + OSPEEDR_OFFSET};
            constexpr addressType GPIOA_PUPDR{GPIOA + PUPDR_OFFSET};
            constexpr addressType GPIOA_IDR{GPIOA + IDR_OFFSET};
            constexpr addressType GPIOA_ODR{GPIOA + ODR_OFFSET};
            constexpr addressType GPIOA_BSRR{GPIOA + BSRR_OFFSET};
            constexpr addressType GPIOA_LOCKR{GPIOA + LOCKR_OFFSET};
            constexpr addressType GPIOA_AFRL{GPIOA + AFRL_OFFSET};
            constexpr addressType GPIOA_AFRH{GPIOA + AFRH_OFFSET};
        }


        namespace gpiob {
            constexpr addressType GPIOB_MODER{GPIOB + MODER_OFFSET};
            constexpr addressType GPIOB_OTYPER{GPIOB + OTYPER_OFFSET};
            constexpr addressType GPIOB_OSPEEDR{GPIOB + OSPEEDR_OFFSET};
            constexpr addressType GPIOB_PUPDR{GPIOB + PUPDR_OFFSET};
            constexpr addressType GPIOB_IDR{GPIOB + IDR_OFFSET};
            constexpr addressType GPIOB_ODR{GPIOB + ODR_OFFSET};
            constexpr addressType GPIOB_BSRR{GPIOB + BSRR_OFFSET};
            constexpr addressType GPIOB_LOCKR{GPIOB + LOCKR_OFFSET};
            constexpr addressType GPIOB_AFRL{GPIOB + AFRL_OFFSET};
            constexpr addressType GPIOB_AFRH{GPIOB + AFRH_OFFSET};
        }


        namespace gpioc {
            constexpr addressType GPIOC_MODER{GPIOC + MODER_OFFSET};
            constexpr addressType GPIOC_OTYPER{GPIOC + OTYPER_OFFSET};
            constexpr addressType GPIOC_OSPEEDR{GPIOC + OSPEEDR_OFFSET};
            constexpr addressType GPIOC_PUPDR{GPIOC + PUPDR_OFFSET};
            constexpr addressType GPIOC_IDR{GPIOC + IDR_OFFSET};
            constexpr addressType GPIOC_ODR{GPIOC + ODR_OFFSET};
            constexpr addressType GPIOC_BSRR{GPIOC + BSRR_OFFSET};
            constexpr addressType GPIOC_LOCKR{GPIOC + LOCKR_OFFSET};
            constexpr addressType GPIOC_AFRL{GPIOC + AFRL_OFFSET};
            constexpr addressType GPIOC_AFRH{GPIOC + AFRH_OFFSET};
        }


        namespace gpiod {
            constexpr addressType GPIOD_MODER{GPIOD + MODER_OFFSET};
            constexpr addressType GPIOD_OTYPER{GPIOD + OTYPER_OFFSET};
            constexpr addressType GPIOD_OSPEEDR{GPIOD + OSPEEDR_OFFSET};
            constexpr addressType GPIOD_PUPDR{GPIOD + PUPDR_OFFSET};
            constexpr addressType GPIOD_IDR{GPIOD + IDR_OFFSET};
            constexpr addressType GPIOD_ODR{GPIOD + ODR_OFFSET};
            constexpr addressType GPIOD_BSRR{GPIOD + BSRR_OFFSET};
            constexpr addressType GPIOD_LOCKR{GPIOD + LOCKR_OFFSET};
            constexpr addressType GPIOD_AFRL{GPIOD + AFRL_OFFSET};
            constexpr addressType GPIOD_AFRH{GPIOD + AFRH_OFFSET};
        }


        namespace gpioe {
            constexpr addressType GPIOE_MODER{GPIOE + MODER_OFFSET};
            constexpr addressType GPIOE_OTYPER{GPIOE + OTYPER_OFFSET};
            constexpr addressType GPIOE_OSPEEDR{GPIOE + OSPEEDR_OFFSET};
            constexpr addressType GPIOE_PUPDR{GPIOE + PUPDR_OFFSET};
            constexpr addressType GPIOE_IDR{GPIOE + IDR_OFFSET};
            constexpr addressType GPIOE_ODR{GPIOE + ODR_OFFSET};
            constexpr addressType GPIOE_BSRR{GPIOE + BSRR_OFFSET};
            constexpr addressType GPIOE_LOCKR{GPIOE + LOCKR_OFFSET};
            constexpr addressType GPIOE_AFRL{GPIOE + AFRL_OFFSET};
            constexpr addressType GPIOE_AFRH{GPIOE + AFRH_OFFSET};
        }
    }
}

#endif
