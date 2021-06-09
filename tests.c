#include "CppUTest/TestHarness.h"
#include <CppUTest/CommandLineTestRunner.h>
#include <CppUTestExt/MockSupport.h>

extern "C"
{
// #include "rent.c"
}

TEST_GROUP(MyCode)
{
    void setup()
    {
    }

    void teardown()
    {
    }
};

TEST(MyCode, test1)
{
    STRCMP_EQUAL("hello", "world!");
}

TEST(MyCode, test2)
{
    LONGS_EQUAL(4, 2+2);
    STRCMP_EQUAL("world!", "world!");
}
int
main(int ac, char** av)
{
  return CommandLineTestRunner::RunAllTests(ac, av);
}
