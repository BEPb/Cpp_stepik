// task 4.1.1.
#include <string> // std::string


/* Структура Character представляет родительский класс, который содержит две константные функции-члены:

name(), которая возвращает константную ссылку на объект типа std::string. Эта функция не изменяет состояние объекта и может быть вызвана из константных методов.
health(), которая возвращает беззнаковое целое число, представляющее здоровье персонажа. Эта функция также не изменяет
состояние объекта и может быть вызвана из константных методов. */
struct Character  // родительский класс
{
    std::string const & name() const; // возвращает константную ссылку на объект типа std::string
    unsigned health() const;  // возвращает беззнаковое целое число, представляющее здоровье персонажа
};

struct LongRange : Character  // дочерний класс  LongRange наследован от родительского класса Character
{
    std::string const & name() const; // возвращает константную ссылку на объект типа std::string
    unsigned health() const;  // возвращает беззнаковое целое число, представляющее здоровье персонажа

    unsigned range() const;  // возвращает беззнаковое целое число, представляющее ранг персонажа
};

struct SwordsMan : Character
{
    std::string const & name() const;
    unsigned health() const;

    unsigned strength() const;    
};

struct Wizard : LongRange
{
    std::string const & name() const;
    unsigned health() const;

    unsigned range() const;

    unsigned mana() const;
};

struct Archer : LongRange
{
    std::string const & name() const;
    unsigned health() const;

    unsigned range() const;

    unsigned accuracy() const;
};