// Copyright 2020 Your Name <your_email>

#include <gtest/gtest.h>

#include <iostream>
#include <string>

#include "Stack.h"

TEST(Stack, Opertor_Perem_Rvalue) {
  Stack<int> st;
  st.push(5);
  st.push(12);
  Stack<int> st2;
  st2 = std::move(st);

  EXPECT_TRUE(st2.head() == 12);
  EXPECT_TRUE(st2.size() == 2);
  EXPECT_TRUE(st.size() == 0);
}

TEST(Stack, Constructor_Rvalue) {
  Stack<int> st;
  st.push(5);
  st.push(12);
  Stack<int> st2(std::move(st));

  EXPECT_TRUE(st2.head() == 12);
  EXPECT_TRUE(st2.size_ == 2);
  EXPECT_TRUE(st.size() == 0);
}

TEST(Stack, head) {
  Stack<int> st;
  st.push(5);
  EXPECT_TRUE(st.head() == 5);
  st.push(12);
  EXPECT_TRUE(st.head() == 12);
}

TEST(Stack, push_lvalue) {
  Stack<int> st;
  st.push(5);
  st.push(12);

  EXPECT_TRUE(st.head() == 12);
  EXPECT_TRUE(st.size() == 2);
}

TEST(Stack, push_rvalue) {
  Stack<double> st;
  double value = 12;
  st.push(std::move(5));
  st.push(std::move(value));

  EXPECT_TRUE(st.head() == 12);
  EXPECT_TRUE(st.size() == 2);
}

TEST(Stack, pop) {
  Stack<int> st;
  st.push(5);
  st.push(12);

  EXPECT_TRUE(st.head() == 12);
  EXPECT_TRUE(st.size() == 2);
  st.pop();
  EXPECT_TRUE(st.head() == 5);
  EXPECT_TRUE(st.size() == 1);
}
TEST(Stack, push_emplace) {
  Stack<std::string> st;
  st.push_emplace("1");

  EXPECT_TRUE(st.head() == "1");
  EXPECT_TRUE(st.size() == 1);

  st.push_emplace("top");

  EXPECT_TRUE(st.head() == "top");
  EXPECT_TRUE(st.size() == 2);
}