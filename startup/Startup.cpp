#include<algorithm>
#include<cstdint>

#define DEFAULT_ISR(name) \
      extern "C" \
      __attribute__((interrupt)) \
      __attribute__((weak)) \
      __attribute__((noreturn)) \
      void name()\
      { \
          while(true); \
      }  





DEFAULT_ISR(NMI_Handler)
DEFAULT_ISR(HardFault_Handler)
DEFAULT_ISR(MemManage_Handler)
DEFAULT_ISR(BusFault_Handler)
DEFAULT_ISR(UsageFault_Handler)
DEFAULT_ISR(SVC_Handler)
DEFAULT_ISR(DebugMon_Handler)
DEFAULT_ISR(PendSV_Handler)
DEFAULT_ISR(SysTick_Handler)
DEFAULT_ISR(WWDG_IRQHandler)                                                           
DEFAULT_ISR(PVD_IRQHandler)                                           
DEFAULT_ISR(TAMP_STAMP_IRQHandler)                         
DEFAULT_ISR(RTC_WKUP_IRQHandler)                                     
DEFAULT_ISR(FLASH_IRQHandler)                                                            
DEFAULT_ISR(RCC_IRQHandler)                                                                
DEFAULT_ISR(EXTI0_IRQHandler)                                          
DEFAULT_ISR(EXTI1_IRQHandler)                                            
DEFAULT_ISR(EXTI2_IRQHandler)                                            
DEFAULT_ISR(EXTI3_IRQHandler)                                            
DEFAULT_ISR(EXTI4_IRQHandler)                                            
DEFAULT_ISR(DMA1_Stream0_IRQHandler)                             
DEFAULT_ISR(DMA1_Stream1_IRQHandler)                              
DEFAULT_ISR(DMA1_Stream2_IRQHandler)                              
DEFAULT_ISR(DMA1_Stream3_IRQHandler)                              
DEFAULT_ISR(DMA1_Stream4_IRQHandler)                              
DEFAULT_ISR(DMA1_Stream5_IRQHandler)                              
DEFAULT_ISR(DMA1_Stream6_IRQHandler)                              
DEFAULT_ISR(ADC_IRQHandler)                                       
DEFAULT_ISR(EXTI9_5_IRQHandler)                                          
DEFAULT_ISR(TIM1_BRK_TIM9_IRQHandler)                   
DEFAULT_ISR(TIM1_UP_TIM10_IRQHandler)                   
DEFAULT_ISR(TIM1_TRG_COM_TIM11_IRQHandler)  
DEFAULT_ISR(TIM1_CC_IRQHandler)                                          
DEFAULT_ISR(TIM2_IRQHandler)                                      
DEFAULT_ISR(TIM3_IRQHandler)                                      
DEFAULT_ISR(TIM4_IRQHandler)                                      
DEFAULT_ISR(I2C1_EV_IRQHandler)                                          
DEFAULT_ISR(I2C1_ER_IRQHandler)                                          
DEFAULT_ISR(I2C2_EV_IRQHandler)                                          
DEFAULT_ISR(I2C2_ER_IRQHandler)                                            
DEFAULT_ISR(SPI1_IRQHandler)                                      
DEFAULT_ISR(SPI2_IRQHandler)                                      
DEFAULT_ISR(USART1_IRQHandler)                                    
DEFAULT_ISR(USART2_IRQHandler)                                    
DEFAULT_ISR(EXTI15_10_IRQHandler)                               
DEFAULT_ISR(RTC_Alarm_IRQHandler)                              
DEFAULT_ISR(OTG_FS_WKUP_IRQHandler)                                 
DEFAULT_ISR(DMA1_Stream7_IRQHandler)                                     
DEFAULT_ISR(SDIO_IRQHandler)                                      
DEFAULT_ISR(TIM5_IRQHandler)                                      
DEFAULT_ISR(SPI3_IRQHandler)                                      
DEFAULT_ISR(DMA2_Stream0_IRQHandler)                              
DEFAULT_ISR(DMA2_Stream1_IRQHandler)                              
DEFAULT_ISR(DMA2_Stream2_IRQHandler)                              
DEFAULT_ISR(DMA2_Stream3_IRQHandler)                              
DEFAULT_ISR(DMA2_Stream4_IRQHandler)                              
DEFAULT_ISR(OTG_FS_IRQHandler)                                    
DEFAULT_ISR(DMA2_Stream5_IRQHandler)                              
DEFAULT_ISR(DMA2_Stream6_IRQHandler)                              
DEFAULT_ISR(DMA2_Stream7_IRQHandler)                              
DEFAULT_ISR(USART6_IRQHandler)                                     
DEFAULT_ISR(I2C3_EV_IRQHandler)                                          
DEFAULT_ISR(I2C3_ER_IRQHandler)                                          
DEFAULT_ISR(FPU_IRQHandler)                    
DEFAULT_ISR(SPI4_IRQHandler)                   
DEFAULT_ISR(SPI5_IRQHandler)                     

extern std::uint32_t _estack;
extern "C" void ResetHandler();




const volatile std::uintptr_t ISRVectorTable[] __attribute__((section(".isr_vector")))
{
    reinterpret_cast<std::uintptr_t> (&_estack),
    reinterpret_cast<std::uintptr_t> (ResetHandler),
    reinterpret_cast<std::uintptr_t> (NMI_Handler),
    reinterpret_cast<std::uintptr_t> (HardFault_Handler),
    reinterpret_cast<std::uintptr_t> (MemManage_Handler),
    reinterpret_cast<std::uintptr_t> (BusFault_Handler),
    reinterpret_cast<std::uintptr_t> (UsageFault_Handler),
    reinterpret_cast<std::uintptr_t> (nullptr),
    reinterpret_cast<std::uintptr_t> (nullptr),
    reinterpret_cast<std::uintptr_t> (nullptr),
    reinterpret_cast<std::uintptr_t> (nullptr),
    reinterpret_cast<std::uintptr_t> (SVC_Handler),
    reinterpret_cast<std::uintptr_t> (DebugMon_Handler),
    reinterpret_cast<std::uintptr_t> (nullptr),
    reinterpret_cast<std::uintptr_t> (PendSV_Handler),
    reinterpret_cast<std::uintptr_t> (SysTick_Handler),
    reinterpret_cast<std::uintptr_t> (WWDG_IRQHandler),                                                          
    reinterpret_cast<std::uintptr_t> (PVD_IRQHandler),                                          
    reinterpret_cast<std::uintptr_t> (TAMP_STAMP_IRQHandler),                         
    reinterpret_cast<std::uintptr_t> (RTC_WKUP_IRQHandler),                                     
    reinterpret_cast<std::uintptr_t> (FLASH_IRQHandler),                                                            
    reinterpret_cast<std::uintptr_t> (RCC_IRQHandler),                                                                
    reinterpret_cast<std::uintptr_t> (EXTI0_IRQHandler),                                      
    reinterpret_cast<std::uintptr_t> (EXTI1_IRQHandler),                                        
    reinterpret_cast<std::uintptr_t> (EXTI2_IRQHandler),                                        
    reinterpret_cast<std::uintptr_t> (EXTI3_IRQHandler),                                        
    reinterpret_cast<std::uintptr_t> (EXTI4_IRQHandler),                                        
    reinterpret_cast<std::uintptr_t> (DMA1_Stream0_IRQHandler),                             
    reinterpret_cast<std::uintptr_t> (DMA1_Stream1_IRQHandler),                              
    reinterpret_cast<std::uintptr_t> (DMA1_Stream2_IRQHandler),                              
    reinterpret_cast<std::uintptr_t> (DMA1_Stream3_IRQHandler),                              
    reinterpret_cast<std::uintptr_t> (DMA1_Stream4_IRQHandler),                              
    reinterpret_cast<std::uintptr_t> (DMA1_Stream5_IRQHandler),                              
    reinterpret_cast<std::uintptr_t> (DMA1_Stream6_IRQHandler),                              
    reinterpret_cast<std::uintptr_t> (ADC_IRQHandler),                                       
    reinterpret_cast<std::uintptr_t> (nullptr),               				                           
    reinterpret_cast<std::uintptr_t> (nullptr),              				                              
    reinterpret_cast<std::uintptr_t> (nullptr),                                                           
    reinterpret_cast<std::uintptr_t> (nullptr),                                                           
    reinterpret_cast<std::uintptr_t> (EXTI9_5_IRQHandler),                                       
    reinterpret_cast<std::uintptr_t> (TIM1_BRK_TIM9_IRQHandler),                   
    reinterpret_cast<std::uintptr_t> (TIM1_UP_TIM10_IRQHandler),                   
    reinterpret_cast<std::uintptr_t> (TIM1_TRG_COM_TIM11_IRQHandler),   
    reinterpret_cast<std::uintptr_t> (TIM1_CC_IRQHandler),                                          
    reinterpret_cast<std::uintptr_t> (TIM2_IRQHandler),                                      
    reinterpret_cast<std::uintptr_t> (TIM3_IRQHandler),                                      
    reinterpret_cast<std::uintptr_t> (TIM4_IRQHandler),                                      
    reinterpret_cast<std::uintptr_t> (I2C1_EV_IRQHandler),                                          
    reinterpret_cast<std::uintptr_t> (I2C1_ER_IRQHandler),                                          
    reinterpret_cast<std::uintptr_t> (I2C2_EV_IRQHandler),                                          
    reinterpret_cast<std::uintptr_t> (I2C2_ER_IRQHandler),                                            
    reinterpret_cast<std::uintptr_t> (SPI1_IRQHandler),                                      
    reinterpret_cast<std::uintptr_t> (SPI2_IRQHandler),                                      
    reinterpret_cast<std::uintptr_t> (USART1_IRQHandler),                                    
    reinterpret_cast<std::uintptr_t> (USART2_IRQHandler),                                    
    reinterpret_cast<std::uintptr_t> (nullptr),               				             
    reinterpret_cast<std::uintptr_t> (EXTI15_10_IRQHandler),                               
    reinterpret_cast<std::uintptr_t> (RTC_Alarm_IRQHandler),                              
    reinterpret_cast<std::uintptr_t> (OTG_FS_WKUP_IRQHandler),                                
    reinterpret_cast<std::uintptr_t> (nullptr),                                         
    reinterpret_cast<std::uintptr_t> (nullptr),                                         
    reinterpret_cast<std::uintptr_t> (nullptr),                                 
    reinterpret_cast<std::uintptr_t> (nullptr),                                                           
    reinterpret_cast<std::uintptr_t> (DMA1_Stream7_IRQHandler),                                     
    reinterpret_cast<std::uintptr_t> (nullptr),                                                    
    reinterpret_cast<std::uintptr_t> (SDIO_IRQHandler),                                      
    reinterpret_cast<std::uintptr_t> (TIM5_IRQHandler),                                      
    reinterpret_cast<std::uintptr_t> (SPI3_IRQHandler),                                      
    reinterpret_cast<std::uintptr_t> (nullptr),                                                    
    reinterpret_cast<std::uintptr_t> (nullptr),                                                    
    reinterpret_cast<std::uintptr_t> (nullptr),                                                    
    reinterpret_cast<std::uintptr_t> (nullptr),                                 
    reinterpret_cast<std::uintptr_t> (DMA2_Stream0_IRQHandler),                              
    reinterpret_cast<std::uintptr_t> (DMA2_Stream1_IRQHandler),                              
    reinterpret_cast<std::uintptr_t> (DMA2_Stream2_IRQHandler),                              
    reinterpret_cast<std::uintptr_t> (DMA2_Stream3_IRQHandler),                              
    reinterpret_cast<std::uintptr_t> (DMA2_Stream4_IRQHandler),                              
    reinterpret_cast<std::uintptr_t> (nullptr),                    			                 
    reinterpret_cast<std::uintptr_t> (nullptr),              				                       
    reinterpret_cast<std::uintptr_t> (nullptr),              				                            
    reinterpret_cast<std::uintptr_t> (nullptr),             					                        
    reinterpret_cast<std::uintptr_t> (nullptr),              				                            
    reinterpret_cast<std::uintptr_t> (nullptr),              				                            
    reinterpret_cast<std::uintptr_t> (OTG_FS_IRQHandler),                                    
    reinterpret_cast<std::uintptr_t> (DMA2_Stream5_IRQHandler),                              
    reinterpret_cast<std::uintptr_t> (DMA2_Stream6_IRQHandler),                              
    reinterpret_cast<std::uintptr_t> (DMA2_Stream7_IRQHandler),                              
    reinterpret_cast<std::uintptr_t> (USART6_IRQHandler),                                     
    reinterpret_cast<std::uintptr_t> (I2C3_EV_IRQHandler),                                          
    reinterpret_cast<std::uintptr_t> (I2C3_ER_IRQHandler),                                          
    reinterpret_cast<std::uintptr_t> (nullptr),                                                    
    reinterpret_cast<std::uintptr_t> (nullptr),                                                    
    reinterpret_cast<std::uintptr_t> (nullptr),                                                          
    reinterpret_cast<std::uintptr_t> (nullptr),                                                    
    reinterpret_cast<std::uintptr_t> (nullptr),                                                    
    reinterpret_cast<std::uintptr_t> (nullptr),                                                    
    reinterpret_cast<std::uintptr_t> (nullptr),                                 
    reinterpret_cast<std::uintptr_t> (FPU_IRQHandler),                    
    reinterpret_cast<std::uintptr_t> (nullptr),                                                    
    reinterpret_cast<std::uintptr_t> (nullptr),                                 
    reinterpret_cast<std::uintptr_t> (SPI4_IRQHandler),                   
    reinterpret_cast<std::uintptr_t> (SPI5_IRQHandler),                     
};


void ResetHandler()
{
    extern std::uint32_t _sdata;
    extern std::uint32_t _edata;
    extern std::uint32_t _etext;

    std::size_t size = static_cast<std::size_t>(&_edata - &_sdata);
    std::copy(&_etext, &_etext + size, &_sdata);

    extern std::uint32_t _sbss;
    extern std::uint32_t _ebss;
    std::fill(&_sbss, &_ebss, 0);

    typedef void (*function_t)();
    extern function_t __init_array_start;
    extern function_t __init_array_end;
    std::for_each(&__init_array_start, &__init_array_end, [](const function_t runner)
    {
        runner(); 
    });


    asm("bl main");

    while (true)
    {

    }
}
