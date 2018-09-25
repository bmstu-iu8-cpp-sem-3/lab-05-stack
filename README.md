# #3 - Семантика перемещения

## Задание 1
Реализовать некопируемый перемещаемый шаблонный класс stack с методами `pop`, `push`, `top`. *Стандартными контейнерами пользоваться **запрещено**.*
```cpp
template <typename T>
class stack
{
 public:
  void push(const T& value);
  void push(T value);
  void pop();
  const T& head() const;
};
```

## Задание 2
Реализовать некопируемый перемещаемый шаблонный класс stack для некопируемых неперемещаемых объектов с методами:
* `push_emplace`, принимающего те же аргументы, что и конструктор хранящегося в нем объекта;
* `head`, возвращающего ссылку на верхушку стека;
* `pop_destroy`, выполняющего разрушение верхушки стека.
```cpp
template <typename T>
class stack
{
 public:
  template <typename ... Args>
  void push_emplace(Args&&... value);
  T& head() const;
  void pop_destroy();
};
```
*Стандартными контейнерами пользоваться **запрещено**.*

## Задание 3
Реализовать unit-test'ы с использованием gtest реализованного заданиях 1 и 2 классов.

## Рекомендации
Воспользуйтесть [**type traits**](https://en.cppreference.com/w/cpp/types#Type_traits_.28since_C.2B.2B11.29), а именно `is_move_constructible`, `is_move_assignable` и пр.
