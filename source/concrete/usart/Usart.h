/********************************************************************************
 * Contents: Class Usart.
 * Author: Dawid Blom.
 * Date: January 4, 2023.
 *
 * Note: This class is used to setup a usart communication protocol to a device
 *******************************************************************************/
#ifndef _USART_H_ 
#define _USART_H_ 
#include "Registers.h"
namespace Communication {
    class Usart {
        public:
            Usart() = default;
            Usart(const Usart&) = default;
            Usart(Usart&&) = default;
            Usart& operator= (const Usart&) = default;
            Usart& operator= (Usart&&) = default;
            virtual ~Usart() = default;

            virtual bool UsartEnable(Hardware::Registers&);
            virtual bool EightBitWordLengthUsed(Hardware::Registers&);
            virtual bool OneStopBitUsed(Hardware::Registers&);
            virtual bool HighBaudRateUsed(Hardware::Registers&);
            virtual bool EnableDmaTransmission(Hardware::Registers&);
            virtual bool EnableDmaReceiver(Hardware::Registers&);
            virtual bool TransmitterEnable(Hardware::Registers&);
            virtual bool WriteData(Hardware::Registers&, const char&);
            virtual bool TransmissionIsCompleted(Hardware::Registers&);
            virtual bool DMATransmissionIsCompleted(Hardware::Registers&);
            
        private:
            enum class Mask {
                write = 0xff,
            };
            enum class Set {
                low = 0U,
                high = 1U,
                stop = 0b00,
                baud = 0x8b,
            };
            enum class Bit {
                re = 2,
                te = 3,
                tc = 6,
                dmar = 6,
                dmat = 7,
                st = 12,
                m = 12,
                eu = 13,
            };

            friend registerType operator& (const Mask& mask, const Set& set)
            {
                return static_cast<registerType> (mask) & static_cast<registerType> (set);
            }

            friend registerType operator& (const char& character, const Mask& mask)
            {
                return static_cast<registerType> (character) & static_cast<registerType> (mask);
            }

            friend registerType operator<< (const Set& set, const Bit& bit)
            {
                return static_cast<registerType> (set) << static_cast<registerType> (bit);
            }
    };
}
#endif
