#ifndef _GREEN_USER_LED_H_ 
#define _GREEN_USER_LED_H_ 
#include "LED.h"
namespace HAL {
    class GreenUserLED : public LED {
        public:
            GreenUserLED() = default;
            GreenUserLED(volatile ledType*, volatile ledType*, volatile ledType*);
            GreenUserLED(const GreenUserLED&) = delete;
            GreenUserLED(GreenUserLED&&) = delete;
            GreenUserLED& operator= (const GreenUserLED&) = delete;
            GreenUserLED& operator= (GreenUserLED&&) = delete;
            ~GreenUserLED() = default;

            void EnableLED(ledType&);
            void DisableLED(ledType&);

        protected:
            void ConfigureUserLED(ledType, ledType);

        private:
            volatile ledType* clockAddress{nullptr};
            volatile ledType* modeAddress{nullptr};
            volatile ledType* odrAddress{nullptr};

            enum class position {
                gpioaClock = 0,
                outputMode = 10
            };

            enum class bits {
                gpioaClockOn = 0b1,
                setModeOn = 0b01
            };

            friend ledType operator<< (const bits& bit, const position& bitPosition)
            {
                return static_cast<ledType>(bit) << static_cast<ledType>(bitPosition);
            }
    };
}
#endif
