# Лабораторная работа №4

## Задание 1
Реализовать некопируемый перемещаемый шаблон класса **stack** с методами `pop`, `push`, `head`. 
```cpp
template <typename T>
class stack
{
public:
  void push(T&& value);
  void push(const T& value);
  void pop();
  const T& head() const;
};
```
⚠️ *Стандартными контейнерами пользоваться **запрещено**.*

## Задание 2
Реализовать некопируемый перемещаемый шаблон класса **stack** для некопируемых перемещаемых типов с методами:
* `push_emplace`, принимающего те же аргументы, что и конструктор для `T`, где `T` - пареметр шаблона;
* `head`, возвращающего ссылку на верхушку стека;
* `pop`, выполняющего снятие элемента с верхушки стека.
```cpp
template <typename T>
class stack
{
public:
  template <typename ... Args>
  void push_emplace(Args&&... value);
  void push(T&& value);
  const T& head() const;
  T pop();
};
```
⚠️ *Стандартными контейнерами пользоваться **запрещено**.*

## Задание 3
Реализовать **unit-test**'ы с использованием фреймворка **Google Test** для реализованных шаблонов в заданиях 1 и 2.

## Рекомендации
💡 Воспользуйтесть [**type traits**](https://en.cppreference.com/w/cpp/types#Type_traits_.28since_C.2B.2B11.29), а именно `is_move_constructible`, `is_move_assignable` и пр.
