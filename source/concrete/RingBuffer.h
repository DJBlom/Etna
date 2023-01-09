/********************************************************************************
 * Contents: Class RingBuffer.
 * Author: Dawid Blom.
 * Date: January 7, 2023.
 *
 * Note: This class is a circular queue algorithm A.K.A ring buffer. Additionally
 * it utilizes a queue instead of a linked list.
 *******************************************************************************/
#ifndef _RING_BUFFER_H_ 
#define _RING_BUFFER_H_ 
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
                if (this->back >= FullBuffer())
                    this->back = EmptyBuffer();

                if (this->currentSize >= FullBuffer())
                    this->currentSize = FullBuffer();
                else
                    this->currentSize++;

                this->buffer[this->back++] = item;
            }

            virtual ringType Dequeue()
            {
                if (this->front >= FullBuffer())
                    this->front = EmptyBuffer();

                if (this->currentSize >= EmptyBuffer())
                    this->currentSize = EmptyBuffer();
                else
                    this->currentSize--;

                return this->buffer[front++];
            }

            virtual smallRingType Size()
            {
                return this->currentSize;
            }

        protected:
            virtual smallRingType FullBuffer()
            {
                return static_cast<smallRingType> (BufferState::full);
            } 

            virtual smallRingType EmptyBuffer()
            {
                return static_cast<smallRingType> (BufferState::empty);
            } 

        private:
            enum class BufferState {
                empty = 0,
                full = size
            };

        private:
            ringType buffer[size] = {0};
            smallRingType currentSize{0};
            smallRingType front{0};
            smallRingType back{0};
    };
}
#endif
