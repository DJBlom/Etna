

#ifndef _SYSTEM_LOGGER_H_ 
#define _SYSTEM_LOGGER_H_ 
#include "Usart.h"
#include "Uart2DmaController.h"
#include "MCURegisters.h"
namespace Hal {
    class SystemLogger {
        public:
            SystemLogger() = default;
            SystemLogger(const SystemLogger&) = default;
            SystemLogger(SystemLogger&&) = default;
            SystemLogger& operator= (const SystemLogger&) = default;
            SystemLogger& operator= (SystemLogger&&) = default;
            virtual ~SystemLogger() = default;

            virtual bool InitializeSystemLogger();
            virtual bool LogMessage(const char*);

        protected:
            virtual registerType MessageToRegisterType(const char*);

        private:
            enum class Bit {
                mask = 0xffff
            };
            friend registerType operator& (const registerType& length, const Bit& mask)
            {
                return length & static_cast<registerType> (mask);
            }

            Hardware::MCURegisters uart2Control1;
            Hardware::MCURegisters uart2Control2;
            Hardware::MCURegisters uart2Control3;
            Hardware::MCURegisters uart2BaudRate;
            Hardware::MCURegisters uart2Status;
            Hardware::MCURegisters uart2Data;

            Hardware::MCURegisters uart2DmaControl;
            Hardware::MCURegisters uart2DmaNdtr;
            Hardware::MCURegisters uart2DmaPar;
            Hardware::MCURegisters uart2DmaMar;

        private:
            Dma::Uart2DmaController uart2Dma;
            Communication::Usart uart2;
    };
}
#endif
