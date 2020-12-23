#include <header.hpp>
#include <Stack.h>
#include <iostream>

using std::cout;
using std::endl;

int main() {
  Stack<int> st;
st.push_emplace(std::move(3));
  cout<<st.head()<<endl;
}