#include <header.hpp>
#include <Stack.h>
#include <iostream>

using std::cout;
using std::endl;

int main() {
  Stack<double> st;
  double value =12;
  st.push(std::move(5));
  st.push(std::move(value));

  cout<<value<<endl;
}