/********************************************************************************
 * Contents: Class GpioAF.
 * Author: Dawid Blom.
 * Date: January 2, 2023.
 *
 * Note: This class is used to set alternate function bit for the various 
 * alternate function modes.
 *******************************************************************************/
#ifndef _GPIO_AF_H_ 
#define _GPIO_AF_H_ 
#include "Registers.h"
namespace Gpio {
    class GpioAF {
        public:
            GpioAF() = default;
            GpioAF(const GpioAF&) = default;
            GpioAF(GpioAF&&) = default;
            GpioAF& operator= (const GpioAF&) = default;
            GpioAF& operator= (GpioAF&&) = default;
            virtual ~GpioAF() = default;

            virtual bool ZeroEnable(Hardware::Registers&, registerType&&);
            virtual bool OneEnable(Hardware::Registers&, registerType&&);
            virtual bool TwoEnable(Hardware::Registers&, registerType&&);
            virtual bool ThreeEnable(Hardware::Registers&, registerType&&);
            virtual bool FourEnable(Hardware::Registers&, registerType&&);
            virtual bool FiveEnable(Hardware::Registers&, registerType&&);
            virtual bool SixEnable(Hardware::Registers&, registerType&&);
            virtual bool SevenEnable(Hardware::Registers&, registerType&&);
            virtual bool EightEnable(Hardware::Registers&, registerType&&);
            virtual bool NineEnable(Hardware::Registers&, registerType&&);
            virtual bool TenEnable(Hardware::Registers&, registerType&&);
            virtual bool TwelveEnable(Hardware::Registers&, registerType&&);
            virtual bool FifteenEnable(Hardware::Registers&, registerType&&);

        private:
            enum class AF {
                zero = 0b0000, one = 0b0001, two = 0b0010, 
                three = 0b0011, four = 0b0100, five = 0b0101, 
                six = 0b0110, seven = 0b0111, eight = 0b1000,
                nine = 0b1001, ten = 0b1010, twelve = 0b1100,
                fifteen = 0b1111
            };

            friend registerType operator<< (const AF& af, const registerType& bit)
            {
                return static_cast<registerType> (af) << bit;
            }
    };
}
#endif
