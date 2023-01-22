/********************************************************************************
 * Contents: Test Fixture for algorithms.
 * Author: Dawid Blom.
 * Date: January 6, 2023.
 *
 * Note: 
 *******************************************************************************/
#include "RingBuffer.h"
#include <cstdint>

#include "CppUTest/TestHarness.h"

extern "C" 
{

}

using genericType = std::uint32_t;

/**
 * RIGN BUFFER TEST LIST
 *
 * 1) Create a ring buffer with a specified size (Done)
 * 2) Add a element to the ring buffer (Done)
 * 3) Remove a element from the ring buffer (Done)
 * 4) Add multiple items to the ring buffer (Done)
 * 5) Remove multiple items from the ring buffer (Done)
 * 6) Ensure circular behaviour when enqueueing to many items
 * 7) Ensure circular behaviour when dequeueing to many items
 **/
TEST_GROUP(RingBufferTest)
{
    genericType item{0};
    genericType expected{0};
    Algorithms::RingBuffer<genericType, 5> ringBuffer;
    void setup()
    {
        item = 0;
        expected = 0;
    }

    void teardown()
    {
    }
};

//TEST(RingBufferTest, Failed)
//{
//    FAIL("Failed Here");
//}

TEST(RingBufferTest, AddAElementToTheRingBuffer)
{
    item = 1;
    expected = 1;
    ringBuffer.Enqueue(item);

    CHECK_EQUAL(expected, ringBuffer.Size());
}

TEST(RingBufferTest, RemoveAElementFromTheRingBuffer)
{
    item = 4;
    expected = 0;
    ringBuffer.Enqueue(item);
    ringBuffer.Dequeue();

    CHECK_EQUAL(expected, ringBuffer.Size());
}

TEST(RingBufferTest, AddMultipleItemsToTheRingBuffer)
{
    expected = 5;
    for (genericType i = 0; i < 5; i++)
        ringBuffer.Enqueue(i);

    CHECK_EQUAL(expected, ringBuffer.Size()); 
}

TEST(RingBufferTest, RemoveMultipleItemsFromTheRingBuffer)
{
    expected = 0;
    for (genericType i = 0; i < 5; i++)
        ringBuffer.Enqueue(i);
    for (genericType i = 0; i < 5; i++)
        item = ringBuffer.Dequeue();

    CHECK_EQUAL(expected, ringBuffer.Size());
}

TEST(RingBufferTest, EnsureCircularBehaviourWhenEnqueueingToManyItems)
{
    expected = 5;
    for (genericType i = 0; i < 10; i++)
        ringBuffer.Enqueue(i);

    CHECK_EQUAL(expected, ringBuffer.Size());
}

TEST(RingBufferTest, EnsureCircularBehaviourWhenDequeueingToManyItems)
{
    expected = 0;
    for (genericType i = 0; i < 10; i++)
        ringBuffer.Enqueue(i);
    for (genericType i = 0; i < 15; i++)
        item = ringBuffer.Dequeue();

    CHECK_EQUAL(expected, ringBuffer.Size());
}

TEST(RingBufferTest, EnsureCircularBehaviourWhenDequeueingLessItems)
{
    expected = 0;
    for (genericType i = 0; i < 10; i++)
        ringBuffer.Enqueue(i);
    for (genericType i = 0; i < 7; i++)
        item = ringBuffer.Dequeue();

    CHECK_EQUAL(expected, ringBuffer.Size());
}
