//
// Created by elisey on 22.12.2020.
//
#ifndef LAB_05_STACK_STACK_H
#define LAB_05_STACK_STACK_H

#include <stdexcept>
#include <type_traits>
#include <utility>

template <typename T>
struct Element {
  T data;
  Element* prev;
};
template <typename T>
class Stack {
 public:
  Element<T>* head_;
  std::size_t size_;

  Stack();
  ~Stack();

  Stack(Stack const& stack);
  Stack(Stack&& stack);

  Stack& operator=(Stack const& stack);
  Stack& operator=(Stack&& stack);

  void push(T&& value);
  void push(const T& value);
  void pop();
  const T& head() const;
};

template <typename T>
Stack<T>::Stack() {
  size_ = 0;
  head_ = nullptr;
}

template <typename T>
Stack<T>::~Stack<T>() {
  auto top = head_;
  if (top != nullptr) {
    while (top != nullptr) {
      auto next = top->prev;
      delete top;
      top = next;
    }
  }
}

template <typename T>
void Stack<T>::push(T&& value) {
  Element<T>* newElement = new Element<T>;
  newElement->data = value;
  size_++;
  newElement->prev = head_;
  head_ = newElement;
}

template <typename T>
void Stack<T>::push(const T& value) {
  Element<T>* new_element = new Element<T>;
  new_element->data = std::move(value);
  ++size_;
  new_element->prev = head_;
  head_ = new_element;
}

template <typename T>
const T& Stack<T>::head() const {
  if (!head_)
    return head_->data;
  else
    throw std::invalid_argument("Stack is empty");
}

template <typename T>
void Stack<T>::pop() {
  auto old_top = head_;
  if (old_top == nullptr) {
    throw std::invalid_argument("Stack is empty");
  } else {
    if (size_ == 1) {
      head_ = nullptr;
      size_--;
    } else {
      head_ = old_top->prev;
      size_--;
    }
  }
  delete old_top;
}

#endif  // LAB_05_STACK_STACK_H
