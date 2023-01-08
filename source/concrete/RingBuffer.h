
#ifndef _RING_BUFFER_H_ 
#define _RING_BUFFER_H_ 
#include <iostream>
#include <cstdint>
using smallRingType = std::uint8_t; 
namespace Algorithms {
    template<typename ringType, std::size_t size>
    class RingBuffer {
        public:
            RingBuffer() = default;
            RingBuffer(const RingBuffer&) = default;
            RingBuffer(RingBuffer&&) = default;
            RingBuffer& operator= (const RingBuffer&) = default;
            RingBuffer& operator= (RingBuffer&&) = default;
            virtual ~RingBuffer() = default;

            virtual void Enqueue(ringType& item)
            {
                if (this->back >= BufferFull())
                    this->back = BufferEmpty();

                if (this->currentSize == BufferFull())
                    this->currentSize = BufferFull();
                else
                    this->currentSize++;

                this->buffer[this->back++] = item;
            }

            virtual ringType Dequeue()
            {
                if (this->front >= BufferFull())
                    this->front = BufferEmpty();

                if (this->currentSize == BufferEmpty())
                    this->currentSize = BufferEmpty();
                else
                    this->currentSize--;

                return this->buffer[front++];
            }

            virtual smallRingType Size()
            {
                return (smallRingType)this->currentSize;
            }

        private:
            enum class BufferState {
                empty = 0,
                full = size
            };

            virtual smallRingType BufferFull()
            {
                return static_cast<smallRingType> (BufferState::full);
            } 

            virtual smallRingType BufferEmpty()
            {
                return static_cast<smallRingType> (BufferState::empty);
            } 


        private:
            ringType buffer[size] = {0};
            smallRingType currentSize{0};
            smallRingType front{0};
            smallRingType back{0};
    };
}
#endif
