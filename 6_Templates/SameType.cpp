#include <iostream>
/*
* В качестве упражнения на частичную специализацию шаблонов классов
* вам предлагается реализовать простой шаблон SameType.
* Этот шаблон не содержит никаких методов,
* а только одно статическое константное поле типа bool, с именем value.
* Шаблон принимает два типовых параметра,
* и если два типовых параметра шаблона являются одним и тем же типом,
* то статическое поле value должно хранить значение true, в противном случае значение false.
*
* Примеры:
struct Dummy { };
typedef int type;
std::cout << SameType<int, int>::value << std::endl; // выведет 1, т. е. true
std::cout << SameType<int, type>::value << std::endl; // 1, type == int
std::cout << SameType<int, int&>::value << std::endl; // 0, int и ссылка на int - различные типы
std::cout << SameType<Dummy, Dummy>::value << std::endl; // 1
std::cout << SameType<int, const int>::value << std::endl; // 0, const - часть типа
Hint: задание простое, решение занимает порядка десяти строк кода.
*/


// Определите шаблон SameType с двумя типовыми
// параметрами. В шаблоне должна быть определена
// одна статическая константа типа bool с именем
// value

template <typename T, typename V>
struct SameType
{ static const bool value = false; };

template <typename W>
struct SameType<W, W>
{ static const bool value = true; };