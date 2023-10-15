#ifndef CPP3_SMARTCALC_V2_1_MODEL_ELEMENT_H
#define CPP3_SMARTCALC_V2_1_MODEL_ELEMENT_H

#include <string>

namespace s21 {
/// @brief Класс служит для определения того, чем является токен
class Element {
public:
  Element() = default;
  ~Element() = default;
  
  /// @brief Конструктор класса с входными параметрами
  /// @param value  Значение токена
  explicit Element(std::string value);

  // /// @brief Конструктор копирования
  // Element(const Element &e);
  // /// @brief Перегрузка оператора присваивания копированием
  // Element &operator=(const Element &e);

  // /// @brief Конструктор присваивания
  // Element(Element &&e);
  // /// @brief  Перегрузка оператора присваивания перемещением
  // Element &operator=(Element &&e);

  /// @brief Возвращает значения токена типа std::string
  std::string GetData() const noexcept;
  /// @brief Проверяет является ли токен числом 
  bool IsNumber() const noexcept;
  /// @brief  Проверяет является ли токен оператором
  bool IsOperator() const noexcept;
  /// @brief  Проверяет является ли токен плюсом
  bool IsPlus() const noexcept;
  /// @brief  Проверяет является ли токен минусом
  bool IsMinus() const noexcept;
  /// @brief  Проверяет является ли токен оператором умножения
  bool IsMul() const noexcept;
  /// @brief  Проверяет является ли токен оператором деления
  bool IsDiv() const noexcept;
  /// @brief  Проверяет является ли токен оператором возведения в степень
  bool IsExp() const noexcept;
  /// @brief  Проверяет является ли токен оператором остатка от деления
  bool IsMod() const noexcept;
  /// @brief  Проверяет является ли токен функцией
  bool IsFunciotn() const noexcept;
  /// @brief  Проверяет является ли токен синусом
  bool IsSin() const noexcept;
  /// @brief  Проверяет является ли токен косинусом
  bool IsCos() const noexcept;
  /// @brief  Проверяет является ли токен тангенсом
  bool IsTan() const noexcept;
  /// @brief  Проверяет является ли токен арксинусом
  bool IsAsin() const noexcept;
  /// @brief  Проверяет является ли токен арккосинусом
  bool IsAcos() const noexcept;
  /// @brief  Проверяет является ли токен арктангенсом
  bool IsAtan() const noexcept;
  /// @brief  Проверяет является ли токен оператором корня
  bool IsSqrt() const noexcept;
  /// @brief  Проверяет является ли токен функцией натурального логарифма
  bool IsLn() const noexcept;
  /// @brief  Проверяет является ли токен функцей логарифма
  bool IsLog() const noexcept;
  /// @brief  Проверяет является ли токен делителем функции
  bool IsSeparator() const noexcept;
  /// @brief  Проверяет является ли токен левоприоритетным
  bool IsLeftPriority() const noexcept;
  /// @brief  Проверяет условия приоритета и ассоциотивности двух операторв
  bool OperatorCheck(Element &other) const noexcept;
  /// @brief  Устанавливает значение токена
  void SetData(std::string value) noexcept;
  /// @brief  Проверяет является ли токен открытой скобкой
  bool IsOpenBracket() const noexcept;
  /// @brief  Проверяет является ли токен  закрытой скобкой
  bool IsClosedBracket() const noexcept;
  /// @brief  Проверяет является ли токен знаком равно
  bool IsEq() const noexcept;
  /// @brief  Проверяет является ли токен точкой
  bool IsPoint() const noexcept;
  /// @brief  Проверят является ли токен иксом
  bool IsX() const noexcept;

private:
  /// @brief Хранит значение токена
  std::string data_;

private:
  /// @brief Функция меняет значения экземпляров класса
  // void swap(Element &other);
  /// @brief  Возвращает приоритет оператора 
  int GetPriority() const noexcept;
  /// @brief  Сравнивает значения приоритетов 
  bool PriorityComparsion(Element &other) const noexcept;
  /// @brief Проверяет равенство приоритетов 
  bool IsEqualPriority(Element &other) const noexcept;
};
}; // namespace s21

#endif // CPP3_SMARTCALC_V2_1_MODEL_ELEMENT_H
