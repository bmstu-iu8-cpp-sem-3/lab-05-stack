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
  Element();
  Element(T&& value, Element<T>* p);
  Element(const T& value, Element<T>* p);
};
template <typename T>
Element<T>::Element() :prev(nullptr) {}
template <typename T>
Element<T>::Element(T&& value, Element<T>* p)
    : data(std::move(value)), prev(p) {}

template <typename T>
Element<T>::Element(const T& value, Element<T>* p) : data(value), prev(p) {}


template <typename T>
class Stack {
  Element<T>* head_;


 public:
  std::size_t size_;
  Stack();
  ~Stack();

  Stack(const Stack& stack) = delete;
  Stack(Stack&& stack) noexcept;

  Stack& operator=(const Stack& stack) = delete;
  Stack& operator=(Stack&& stack) noexcept;

  std::size_t size() const;
  void push(T&& value);
  void push(const T& value);
  void pop();
  const T& head() const;

  template <typename... Args>
  void push_emplace(Args&&... value);
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
      --size_;
    }
  }
}

template <typename T>
Stack<T>::Stack(Stack<T>&& stack) noexcept {
  size_ = 0;
  head_ = nullptr;
  std::swap(head_, stack.head_);
  std::swap(size_, stack.size_);
}

template <typename T>
Stack<T>& Stack<T>::operator=(Stack<T>&& stack) noexcept {
  if (this != &stack) {
    std::swap(head_, stack.head_);
    std::swap(size_, stack.size_);
  }
  return *this;
}

template <typename T>
void Stack<T>::push(T&& value) {
  Element<T>* newElement = new Element<T>;
  newElement->data = std::move(value);
  size_++;
  newElement->prev = head_;
  head_ = newElement;
}

template <typename T>
void Stack<T>::push(const T& value) {
  Element<T>* new_element = new Element<T>;
  new_element->data = std::move(value);
  size_++;
  new_element->prev = head_;
  head_ = new_element;
}

template <typename T>
const T& Stack<T>::head() const {
  if (size_)
    return head_->data;
  else
    throw std::invalid_argument("Stack is empty");
}

template <typename T>
std::size_t Stack<T>::size() const {
  return size_;
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
template <typename T>
template <typename... Args>
void Stack<T>::push_emplace(Args&&... value) {
  head_ = new Element<T>{T{std::forward<Args>(value)...}, head_};
  size_++;
}

#endif  // LAB_05_STACK_STACK_H
