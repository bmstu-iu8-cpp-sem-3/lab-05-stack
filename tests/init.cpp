#include <gtest/gtest.h>

#include <stack.hpp>

TEST(StackTest, InitWithDefaultCtor) {
  EXPECT_NO_THROW( Stack{} );
}
